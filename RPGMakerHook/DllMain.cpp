// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <Windows.h>
#include <cstdio>
#include <tchar.h>

#include "RPGXP.h"
#include "RPGVXAce.h"

#ifdef HOOKAPI_EXPORTS
#define HOOKAPI extern "C" __declspec(dllexport)
#else
#define HOOKAPI extern "C" __declspec(dllexport)
#endif

#define _countof(array) (sizeof(array) / sizeof(array[0]))

namespace RPGXP
{
	extern CommandInfo gCommands[];
}

namespace RPGVXAce
{
	extern CommandInfo gCommands[];
}

struct RPGMakerInfo
{
	DWORD ProcessId;
	int RGSSVersion;
	wchar_t RGSSLibraryFileName[256];
	wchar_t GameTitleName[256];
	HWND WindowHandle;
	HANDLE ProcessHandle;
};

const HMODULE IMAGE_BASE = (HMODULE)0x00400000;

typedef int (*RGSSEval_t)(const char* const pRubyScript);

bool CreateInfo(const wchar_t* const lpGameIniFilePath, RPGMakerInfo* const pOutInfo);
HOOKAPI int HookRPGXPSave(const wchar_t* const lpGameIniFilePath);
HOOKAPI int HookRPGVXAceSave(const wchar_t* const lpGameIniFilePath);
HOOKAPI int RPGXPEval(const wchar_t* const lpGameIniFilePath, const char* const pRubyScript);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReasonForCall, LPVOID lpReserved)
{
	switch (ulReasonForCall)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:

		break;
	}
	return TRUE;
}

bool CreateInfo(const wchar_t* const lpGameIniFilePath, RPGMakerInfo* const pOutInfo)
{
	DWORD ret;
	RPGMakerInfo info = { 0, };

	// Load RGSS Library Name
	ret = GetPrivateProfileStringW(L"Game", L"Library", nullptr, info.RGSSLibraryFileName, _countof(info.RGSSLibraryFileName), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"[Error] GetPrivateProfileStringW(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return false;
	}
	wprintf_s(L"info.RGSSLibraryFileName = %s\n", info.RGSSLibraryFileName);

	// Decide RGSS Version, 1 or 3
	if (wcsstr(info.RGSSLibraryFileName, L"RGSS10") != nullptr)
	{
		info.RGSSVersion = 1;
	}
	else if (wcsstr(info.RGSSLibraryFileName, L"RGSS30") != nullptr)
	{
		info.RGSSVersion = 3;
	}
	else
	{
		wprintf_s(L"[Error] %s is incompatible\n", info.RGSSLibraryFileName);
		return false;
	}
	wprintf_s(L"info.RGSSVersion = %d\n", info.RGSSVersion);

	// Load Game Title Name
	ret = GetPrivateProfileStringW(L"Game", L"Title", nullptr, info.GameTitleName, _countof(info.GameTitleName), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"[Error] GetPrivateProfileStringW(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return false;
	}
	wprintf_s(L"info.GameTitleName = %s\n", info.GameTitleName);

	// CreateInfo RPG Maker Window Text
	wchar_t lpRPGMakerWindowText[512] = { '\0' };
	switch (info.RGSSVersion)
	{
	case 1:
		swprintf_s(lpRPGMakerWindowText, _countof(lpRPGMakerWindowText), L"%s - RPG Maker XP", info.GameTitleName);
		break;
	case 3:
		swprintf_s(lpRPGMakerWindowText, _countof(lpRPGMakerWindowText), L"%s - RPG Maker VX Ace", info.GameTitleName);
		break;
	default:
		return false;
	}
	wprintf_s(L"RPGMakerWindowText = %s\n", lpRPGMakerWindowText);

	// Get RPG Maker Window Handle
	info.WindowHandle = FindWindowW(nullptr/* variant */, lpRPGMakerWindowText);
	if (info.WindowHandle == nullptr)
	{
		wprintf_s(L"[Error] FindWindowW(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return false;
	}
	wprintf_s(L"info.WindowHandle = 0x%p\n", info.WindowHandle);

	// Get RPG Maker Process Id
	ret = GetWindowThreadProcessId(info.WindowHandle, &info.ProcessId);
	if (ret == 0)
	{
		wprintf_s(L"[Error] GetWindowThreadProcessId(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return false;
	}
	wprintf_s(L"info.ProcessId = %d\n", info.ProcessId);
	
	// Get RPG Maker Process Handle
	info.ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, info.ProcessId);
	if (info.ProcessHandle == nullptr)
	{
		wprintf_s(L"[Error] OpenProcess(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return false;
	}
	wprintf_s(L"info.ProcessHandle = %d\n", reinterpret_cast<int>(info.ProcessHandle));

	// Copy info
	*pOutInfo = info;
	return true;
}

HOOKAPI int HookRPGXPSave(const wchar_t* const lpGameIniFilePath)
{
	RPGMakerInfo info;
	if (!CreateInfo(lpGameIniFilePath, &info))
	{
		return false;
	}

	DWORD ret;

	RPGXP::CommandInfo* pSaveCommand = &RPGXP::gCommands[RPGXP::eCommandType::DEFINE_AND_CALL_RPGXP_SAVE_WITHOUT_SCRIPTS];
	SIZE_T scriptLength = strlen(pSaveCommand->Scripts);
	DWORD oldProtect1 = 0;
	VOID* pAddr = (VOID*)((char*)(IMAGE_BASE)+pSaveCommand->Offset);

	ret = VirtualProtectEx(info.ProcessHandle, pAddr, scriptLength, PAGE_EXECUTE_READWRITE, &oldProtect1);
	{
		if (ret == 0)
		{
			wprintf_s(L"1 VirtualProtectEx(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}

		SIZE_T outSize = 0;
		ret = WriteProcessMemory(info.ProcessHandle, pAddr, pSaveCommand->Scripts, scriptLength, &outSize);
		if (ret == 0)
		{
			wprintf_s(L"1 WriteProcessMemory(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	RPGXP::CommandInfo* pCallSaveCommand = &RPGXP::gCommands[RPGXP::eCommandType::PTR_CALL_RPGXP_SAVE];
	scriptLength = strlen(pCallSaveCommand->Scripts);
	DWORD oldProtect2 = 0;
	VOID* pSaveAddr = (VOID*)((char*)(IMAGE_BASE) + pCallSaveCommand->Offset);

	ret = VirtualProtectEx(info.ProcessHandle, pSaveAddr, sizeof(pAddr), PAGE_EXECUTE_READWRITE, &oldProtect2);
	{
		if (ret == 0)
		{
			wprintf_s(L"2 VirtualProtectEx(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
		SIZE_T outSize = 0;
		ret = WriteProcessMemory(info.ProcessHandle, pSaveAddr, &pAddr, sizeof(pAddr), &outSize);
		if (ret == 0)
		{
			wprintf_s(L"2 WriteProcessMemory(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	return 0;
}

HOOKAPI int HookRPGVXAceSave(const wchar_t* const lpGameIniFilePath)
{
	RPGMakerInfo info;
	if (!CreateInfo(lpGameIniFilePath, &info))
	{
		return false;
	}

	DWORD ret;

	RPGVXAce::CommandInfo* pSaveCommand = &RPGVXAce::gCommands[RPGVXAce::eCommandType::DEFINE_AND_CALL_RPGVX_SAVE_WITHOUT_SCRIPTS];
	SIZE_T scriptLength = strlen(pSaveCommand->Scripts);
	DWORD oldProtect1 = 0;
	VOID* pAddr = (VOID*)((char*)(IMAGE_BASE) + pSaveCommand->Offset);

	ret = VirtualProtectEx(info.ProcessHandle, pAddr, scriptLength, PAGE_EXECUTE_READWRITE, &oldProtect1);
	{
		if (ret == 0)
		{
			wprintf_s(L"1 VirtualProtectEx(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}

		SIZE_T outSize = 0;
		ret = WriteProcessMemory(info.ProcessHandle, pAddr, pSaveCommand->Scripts, scriptLength, &outSize);
		if (ret == 0)
		{
			wprintf_s(L"1 WriteProcessMemory(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	RPGVXAce::CommandInfo* pCallSaveCommand = &RPGVXAce::gCommands[RPGVXAce::eCommandType::PTR_CALL_RPGVX_SAVE];
	scriptLength = strlen(pCallSaveCommand->Scripts);
	DWORD oldProtect2 = 0;
	VOID* pSaveAddr = (VOID*)((char*)(IMAGE_BASE)+pCallSaveCommand->Offset);

	ret = VirtualProtectEx(info.ProcessHandle, pSaveAddr, sizeof(pAddr), PAGE_EXECUTE_READWRITE, &oldProtect2);
	{
		if (ret == 0)
		{
			wprintf_s(L"2 VirtualProtectEx(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
		SIZE_T outSize = 0;
		ret = WriteProcessMemory(info.ProcessHandle, pSaveAddr, &pAddr, sizeof(pAddr), &outSize);
		if (ret == 0)
		{
			wprintf_s(L"2 WriteProcessMemory(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	return 0;
}

HOOKAPI int RPGXPEval(const wchar_t* const lpGameIniFilePath, const char* const pRubyScript)
{
	RPGMakerInfo info;
	if (!CreateInfo(lpGameIniFilePath, &info))
	{
		return false;
	}

	DWORD ret;
	HMODULE hModule = LoadLibraryExW(info.RGSSLibraryFileName, nullptr, DONT_RESOLVE_DLL_REFERENCES);
	if (hModule == nullptr)
	{
		wprintf_s(L"LoadLibraryExW(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"hModule = 0x%p\n", hModule);

	RGSSEval_t pRGSSEval = (RGSSEval_t)GetProcAddress(hModule, "RGSSEval");
	if (pRGSSEval == nullptr)
	{
		wprintf_s(L"GetProcAddress(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pRGSSEval = 0x%p\n", pRGSSEval);

	HANDLE hThread = nullptr;

	LPVOID pAllocScriptBuf = VirtualAllocEx(info.ProcessHandle, nullptr, strlen(pRubyScript), MEM_COMMIT, PAGE_READWRITE);
	if (pAllocScriptBuf == nullptr)
	{
		wprintf_s(L"VirtualAllocEx(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pAllocScriptBuf = 0x%p\n", pAllocScriptBuf);

	ret = WriteProcessMemory(info.ProcessHandle, pAllocScriptBuf, pRubyScript, strlen(pRubyScript), nullptr);
	if (ret == 0)
	{
		wprintf_s(L"WriteProcessMemory(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	hThread = CreateRemoteThread(info.ProcessHandle, nullptr, 0, (LPTHREAD_START_ROUTINE)pRGSSEval, pAllocScriptBuf, 0, nullptr);
	if (hThread == nullptr)
	{
		wprintf_s(L"CreateRemoteThread(), GetLastError: %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"hThread = 0x%p\n", hThread);
	WaitForSingleObject(hThread, INFINITE);

	FreeLibrary(hModule);

	return 0;
}