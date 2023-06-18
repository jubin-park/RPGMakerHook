#include <Windows.h>
#include <cstdio>
#include <tchar.h>

#include "RPGXP.h"

namespace RPGXP
{
	extern CommandInfo gCommands[];
}

int HookRPGXP(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGXPFilePath)
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

	HMODULE hRPGXPLibrary = LoadLibraryW(lpRPGXPFilePath);
	if (hRPGXPLibrary == 0)
	{
		wprintf_s(L"LoadLibraryW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	wprintf_s(L"HMODULE hRPGXPLibrary = %p\n", hRPGXPLibrary);
	if (hRPGXPLibrary != (void*)0x00400000)
	{
		wprintf_s(L"hRPGXPLibrary must be %p\n", (void*)0x00400000);
		return 1;
	}

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
	VOID* pAddr = (VOID*)((char*)(hRPGXPLibrary) + pSaveCommand->Offset);

	Sleep(1000);
	ret = VirtualProtectEx(hProcess, pAddr, scriptLength, PAGE_EXECUTE_READWRITE, &oldProtect1);
	{
		if (ret == 0)
		{
			wprintf_s(L"1 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}

		SIZE_T outSize = 0;
		Sleep(1000);
		ret = WriteProcessMemory(hProcess, pAddr, pSaveCommand->Scripts, scriptLength, &outSize);
		if (ret == 0)
		{
			wprintf_s(L"1 WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}	

	RPGXP::CommandInfo* pCallSaveCommand = &RPGXP::gCommands[RPGXP::eCommandType::CALL_RPGXP_SAVE];
	scriptLength = strlen(pCallSaveCommand->Scripts);
	DWORD oldProtect2 = 0;
	VOID* pSaveAddr = (VOID*)((char*)(hRPGXPLibrary) + pCallSaveCommand->Offset);
	char bytes[4] = { (int)pAddr & 0xff, ((int)pAddr >> 8) & 0xff, ((int)pAddr >> 16) & 0xff, ((int)pAddr >> 24) & 0xff };

	Sleep(1000);
	ret = VirtualProtectEx(hProcess, pSaveAddr, sizeof(bytes), PAGE_EXECUTE_READWRITE, &oldProtect2);
	{
		if (ret == 0)
		{
			wprintf_s(L"2 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
		SIZE_T outSize = 0;
		Sleep(1000);
		ret = WriteProcessMemory(hProcess, pSaveAddr, bytes, sizeof(bytes), &outSize);
		if (ret == 0)
		{
			wprintf_s(L"2 WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}

	return 0;
}

int wmain()
{
	// RPGXP.exe is a 32-bit application
	HookRPGXP(L"./Game.ini", L"C:\\Program Files (x86)\\Steam\\steamapps\\common\\RPGXP\\RPGXP.exe");

	return 0;
}