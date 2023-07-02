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

#include "RPGXP.h"
#include "RPGVXAce.h"

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

HOOKAPI int HookRGSS1(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGXPFilePath);
HOOKAPI int HookRPGXP(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGXPFilePath);
HOOKAPI int HookRPGVXAce(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGVXAceFilePath);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

HOOKAPI int HookRGSS1(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGXPFilePath)
{
	DWORD ret;

	wchar_t lpGameProjectName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Title", NULL,
		lpGameProjectName, sizeof(lpGameProjectName) / sizeof(lpGameProjectName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpGameProjectName = %s\n", lpGameProjectName);

	wchar_t lpRGSSLibraryFileName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Library", NULL,
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
	HWND hRPGXPWindow = FindWindowW(NULL/* variant */, lpRPGXPWindowName);
	if (hRPGXPWindow == NULL)
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
	if (hProcess == NULL)
	{
		wprintf_s(L"OpenProcess() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"HANDLE hProcess = %d\n", reinterpret_cast<int>(hProcess));


	//HMODULE hModule = LoadLibraryExW(L"C:\\Program Files (x86)\\Steam\\steamapps\\common\\RPGXP\\RGSS104E.dll", NULL,
	HMODULE hModule = LoadLibraryExW(L".\\RGSS104E.dll", NULL,
		DONT_RESOLVE_DLL_REFERENCES);
	if (hModule == NULL)
	{
		wprintf_s(L"LoadLibraryExW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"hModule = %p\n", hModule);

	LPVOID pRGSSEval = (LPVOID)GetProcAddress(hModule, "RGSSEval");
	if (pRGSSEval == NULL)
	{
		wprintf_s(L"GetProcAddress() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pRGSSEval = %p\n", pRGSSEval);

	HANDLE hThread = NULL;

	const char* pTestScript = "Win32API.new('user32','MessageBox','lppl','l').call(0,'hello hook world!','RPGXP',0)";

	LPVOID pAllocScriptBuf = VirtualAllocEx(hProcess, NULL, strlen(pTestScript), MEM_COMMIT, PAGE_READWRITE);
	if (pAllocScriptBuf == NULL)
	{
		wprintf_s(L"VirtualAllocEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"pAllocScriptBuf = %p\n", pAllocScriptBuf);

	ret = WriteProcessMemory(hProcess, pAllocScriptBuf, pTestScript, strlen(pTestScript), NULL);
	if (ret == 0)
	{
		wprintf_s(L"WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pRGSSEval, pAllocScriptBuf, 0, NULL);
	if (hThread == NULL)
	{
		wprintf_s(L"CreateRemoteThread() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"hThread = %p\n", hThread);
	WaitForSingleObject(hThread, INFINITE);

	FreeLibrary(hModule);

	return 0;
}

HOOKAPI int HookRPGXP(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGXPFilePath)
{
	DWORD ret;

	wchar_t lpGameProjectName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Title", NULL,
		lpGameProjectName, sizeof(lpGameProjectName) / sizeof(lpGameProjectName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpGameProjectName = %s\n", lpGameProjectName);

	wchar_t lpRGSSLibraryFileName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Library", NULL,
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
	HWND hRPGXPWindow = FindWindowW(NULL/* variant */, lpRPGXPWindowName);
	if (hRPGXPWindow == NULL)
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
	if (hProcess == NULL)
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

HOOKAPI int HookRPGVXAce(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGVXAceFilePath)
{
	DWORD ret;

	wchar_t lpGameProjectName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Title", NULL,
		lpGameProjectName, sizeof(lpGameProjectName) / sizeof(lpGameProjectName[0]), lpGameIniFilePath);
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"lpGameProjectName = %s\n", lpGameProjectName);

	wchar_t lpRGSSLibraryFileName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Library", NULL,
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
	HWND hRPGVXAceWindow = FindWindowW(NULL/* variant */, lpRPGVXAceWindowName);
	if (hRPGVXAceWindow == NULL)
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
	if (hProcess == NULL)
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