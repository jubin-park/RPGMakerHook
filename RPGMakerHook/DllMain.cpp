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

const HMODULE IMAGE_BASE = (HMODULE)0x00400000;

typedef int (*RGSSEval)(const char* const pRubyScripts);

HOOKAPI int HookRPGXP(const wchar_t* const lpGameIniFilePath);
HOOKAPI int HookRPGVXAce(const wchar_t* const lpGameIniFilePath);
HOOKAPI int HookRGSS1(const wchar_t* const lpGameIniFilePath);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
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

HOOKAPI int HookRPGXP(const wchar_t* const lpGameIniFilePath)
{
	DWORD ret;

	wchar_t lpGameProjectName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Title", nullptr,
		lpGameProjectName, sizeof(lpGameProjectName) / sizeof(lpGameProjectName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpGameProjectName = %s\n", lpGameProjectName);

	wchar_t lpRGSSLibraryFileName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Library", nullptr,
		lpRGSSLibraryFileName, sizeof(lpRGSSLibraryFileName) / sizeof(lpRGSSLibraryFileName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpRGSSLibraryFileName = %s\n", lpRGSSLibraryFileName);

	wchar_t lpRPGXPWindowName[512];
	swprintf_s(lpRPGXPWindowName, sizeof(lpRPGXPWindowName) / sizeof(lpRPGXPWindowName[0]),
		L"%s - RPG Maker XP", lpGameProjectName);
	HWND hRPGXPWindow = FindWindowW(nullptr/* variant */, lpRPGXPWindowName);
	if (hRPGXPWindow == nullptr)
	{
		wprintf_s(L"FindWindowW() error\n");
		return 1;
	}
	wprintf_s(L"HWND hRPGXPWindow = %p\n", hRPGXPWindow);

	HMODULE hRPGXPInstance = (HMODULE)0x00400000;

	DWORD pidRPGXP = 0;
	ret = GetWindowThreadProcessId(hRPGXPWindow, &pidRPGXP);
	if (ret == 0)
	{
		wprintf_s(L"GetWindowThreadProcessId() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pidRPGXP = %d\n", pidRPGXP);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pidRPGXP);
	if (hProcess == nullptr)
	{
		wprintf_s(L"OpenProcess() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"HANDLE hProcess = %d\n", reinterpret_cast<int>(hProcess));

	RPGXP::CommandInfo* pSaveCommand = &RPGXP::gCommands[RPGXP::eCommandType::DEFINE_AND_CALL_RPGXP_SAVE_WITHOUT_SCRIPTS];
	SIZE_T scriptLength = strlen(pSaveCommand->Scripts);
	DWORD oldProtect1 = 0;
	VOID* pAddr = (VOID*)((char*)(hRPGXPInstance)+pSaveCommand->Offset);

	ret = VirtualProtectEx(hProcess, pAddr, scriptLength, PAGE_EXECUTE_READWRITE, &oldProtect1);
	{
		if (ret == 0)
		{
			wprintf_s(L"1 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}

		SIZE_T outSize = 0;
		ret = WriteProcessMemory(hProcess, pAddr, pSaveCommand->Scripts, scriptLength, &outSize);
		if (ret == 0)
		{
			wprintf_s(L"1 WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	RPGXP::CommandInfo* pCallSaveCommand = &RPGXP::gCommands[RPGXP::eCommandType::PTR_CALL_RPGXP_SAVE];
	scriptLength = strlen(pCallSaveCommand->Scripts);
	DWORD oldProtect2 = 0;
	VOID* pSaveAddr = (VOID*)((char*)(hRPGXPInstance)+pCallSaveCommand->Offset);

	ret = VirtualProtectEx(hProcess, pSaveAddr, sizeof(pAddr), PAGE_EXECUTE_READWRITE, &oldProtect2);
	{
		if (ret == 0)
		{
			wprintf_s(L"2 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
		SIZE_T outSize = 0;
		ret = WriteProcessMemory(hProcess, pSaveAddr, &pAddr, sizeof(pAddr), &outSize);
		if (ret == 0)
		{
			wprintf_s(L"2 WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	return 0;
}

HOOKAPI int HookRPGVXAce(const wchar_t* const lpGameIniFilePath)
{
	DWORD ret;

	wchar_t lpGameProjectName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Title", nullptr,
		lpGameProjectName, sizeof(lpGameProjectName) / sizeof(lpGameProjectName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpGameProjectName = %s\n", lpGameProjectName);

	wchar_t lpRGSSLibraryFileName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Library", nullptr,
		lpRGSSLibraryFileName, sizeof(lpRGSSLibraryFileName) / sizeof(lpRGSSLibraryFileName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpRGSSLibraryFileName = %s\n", lpRGSSLibraryFileName);

	wchar_t lpRPGVXAceWindowName[512];
	swprintf_s(lpRPGVXAceWindowName, sizeof(lpRPGVXAceWindowName) / sizeof(lpRPGVXAceWindowName[0]),
		L"%s - RPG Maker VX Ace", lpGameProjectName);
	HWND hRPGVXAceWindow = FindWindowW(nullptr/* variant */, lpRPGVXAceWindowName);
	if (hRPGVXAceWindow == nullptr)
	{
		wprintf_s(L"FindWindowW() error\n");
		return 1;
	}
	wprintf_s(L"HWND hRPGVXAceWindow = %p\n", hRPGVXAceWindow);

	DWORD pidRPGVXAce = 0;
	ret = GetWindowThreadProcessId(hRPGVXAceWindow, &pidRPGVXAce);
	if (ret == 0)
	{
		wprintf_s(L"GetWindowThreadProcessId() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pidRPGVXAce = %d\n", pidRPGVXAce);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pidRPGVXAce);
	if (hProcess == nullptr)
	{
		wprintf_s(L"OpenProcess() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"HANDLE hProcess = %d\n", reinterpret_cast<int>(hProcess));

	RPGVXAce::CommandInfo* pSaveCommand = &RPGVXAce::gCommands[RPGVXAce::eCommandType::DEFINE_AND_CALL_RPGVX_SAVE_WITHOUT_SCRIPTS];
	SIZE_T scriptLength = strlen(pSaveCommand->Scripts);
	DWORD oldProtect1 = 0;
	VOID* pAddr = (VOID*)((char*)(IMAGE_BASE)+pSaveCommand->Offset);

	ret = VirtualProtectEx(hProcess, pAddr, scriptLength, PAGE_EXECUTE_READWRITE, &oldProtect1);
	{
		if (ret == 0)
		{
			wprintf_s(L"1 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}

		SIZE_T outSize = 0;
		ret = WriteProcessMemory(hProcess, pAddr, pSaveCommand->Scripts, scriptLength, &outSize);
		if (ret == 0)
		{
			wprintf_s(L"1 WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	RPGVXAce::CommandInfo* pCallSaveCommand = &RPGVXAce::gCommands[RPGVXAce::eCommandType::PTR_CALL_RPGVX_SAVE];
	scriptLength = strlen(pCallSaveCommand->Scripts);
	DWORD oldProtect2 = 0;
	VOID* pSaveAddr = (VOID*)((char*)(IMAGE_BASE)+pCallSaveCommand->Offset);

	ret = VirtualProtectEx(hProcess, pSaveAddr, sizeof(pAddr), PAGE_EXECUTE_READWRITE, &oldProtect2);
	{
		if (ret == 0)
		{
			wprintf_s(L"2 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
		SIZE_T outSize = 0;
		ret = WriteProcessMemory(hProcess, pSaveAddr, &pAddr, sizeof(pAddr), &outSize);
		if (ret == 0)
		{
			wprintf_s(L"2 WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	return 0;
}

HOOKAPI int HookRGSS1(const wchar_t* const lpGameIniFilePath)
{
	DWORD ret;

	wchar_t lpGameProjectName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Title", nullptr,
		lpGameProjectName, sizeof(lpGameProjectName) / sizeof(lpGameProjectName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpGameProjectName = %s\n", lpGameProjectName);

	wchar_t lpRGSSLibraryFileName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Library", nullptr,
		lpRGSSLibraryFileName, sizeof(lpRGSSLibraryFileName) / sizeof(lpRGSSLibraryFileName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpRGSSLibraryFileName = %s\n", lpRGSSLibraryFileName);

	wchar_t lpRPGXPWindowName[512];
	swprintf_s(lpRPGXPWindowName, sizeof(lpRPGXPWindowName) / sizeof(lpRPGXPWindowName[0]),
		L"%s - RPG Maker XP", lpGameProjectName);
	HWND hRPGXPWindow = FindWindowW(nullptr/* variant */, lpRPGXPWindowName);
	if (hRPGXPWindow == nullptr)
	{
		wprintf_s(L"FindWindowW() error\n");
		return 1;
	}
	wprintf_s(L"HWND hRPGXPWindow = %p\n", hRPGXPWindow);

	HMODULE hRPGXPInstance = (HMODULE)0x00400000;

	DWORD pidRPGXP = 0;
	ret = GetWindowThreadProcessId(hRPGXPWindow, &pidRPGXP);
	if (ret == 0)
	{
		wprintf_s(L"GetWindowThreadProcessId() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pidRPGXP = %d\n", pidRPGXP);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pidRPGXP);
	if (hProcess == nullptr)
	{
		wprintf_s(L"OpenProcess() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"HANDLE hProcess = %d\n", reinterpret_cast<int>(hProcess));

	HMODULE hModule = LoadLibraryExW(L".\\RGSS104E.dll", nullptr,
		DONT_RESOLVE_DLL_REFERENCES);
	if (hModule == nullptr)
	{
		wprintf_s(L"LoadLibraryExW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"hModule = %p\n", hModule);

	LPVOID pRGSSEval = (LPVOID)GetProcAddress(hModule, "RGSSEval");
	if (pRGSSEval == nullptr)
	{
		wprintf_s(L"GetProcAddress() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pRGSSEval = %p\n", pRGSSEval);

	HANDLE hThread = nullptr;

	const char* pTestScript = "Win32API.new('user32','MessageBox','lppl','l').call(0,'hello hook world!','RPGXP',0)";

	LPVOID pAllocScriptBuf = VirtualAllocEx(hProcess, nullptr, strlen(pTestScript), MEM_COMMIT, PAGE_READWRITE);
	if (pAllocScriptBuf == nullptr)
	{
		wprintf_s(L"VirtualAllocEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pAllocScriptBuf = %p\n", pAllocScriptBuf);

	ret = WriteProcessMemory(hProcess, pAllocScriptBuf, pTestScript, strlen(pTestScript), nullptr);
	if (ret == 0)
	{
		wprintf_s(L"WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	hThread = CreateRemoteThread(hProcess, nullptr, 0, (LPTHREAD_START_ROUTINE)pRGSSEval, pAllocScriptBuf, 0, nullptr);
	if (hThread == nullptr)
	{
		wprintf_s(L"CreateRemoteThread() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"hThread = %p\n", hThread);
	WaitForSingleObject(hThread, INFINITE);

	FreeLibrary(hModule);

	return 0;
}