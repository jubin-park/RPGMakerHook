#include <Windows.h>
#include <cstdio>
#include <tchar.h>

#include "RPGXP.h"

namespace RPGXP
{
	extern CommandInfo gCommands[];
}

int wmain()
{
	DWORD ret;

	wchar_t lpGameProjectName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Title", NULL,
		lpGameProjectName, sizeof(lpGameProjectName) / sizeof(lpGameProjectName[0]), L"./Game.ini");
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	wchar_t lpRGSSLibraryFileName[256];
	ret = GetPrivateProfileStringW(L"Game", L"Library", NULL,
		lpRGSSLibraryFileName, sizeof(lpRGSSLibraryFileName) / sizeof(lpRGSSLibraryFileName[0]), L"./Game.ini");
	if (ret == 0x2)
	{
		wprintf_s(L"GetPrivateProfileStringW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	wchar_t lpRpgMakerXpWindowName[512];
	swprintf_s(lpRpgMakerXpWindowName, sizeof(lpRpgMakerXpWindowName) / sizeof(lpRpgMakerXpWindowName[0]),
		L"%s - RPG Maker XP", lpGameProjectName);

	HWND hRPGXPWindow = FindWindowW(NULL/* variant */, lpRpgMakerXpWindowName);
	if (hRPGXPWindow == NULL)
	{
		wprintf_s(L"FindWindowW() error\n");
		return 1;
	}

	HMODULE hRPGXPLibrary = LoadLibraryW(L"C:\\Program Files (x86)\\Steam\\steamapps\\common\\RPGXP\\RPGXP.exe"); // RPGXP.exe is a 32-bit application
	if (hRPGXPLibrary == 0)
	{
		wprintf_s(L"LoadLibraryW() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	HMODULE hRPGXPModule = GetModuleHandleW(L"RPGXP.exe");

	DWORD pidRPGXP = 0;
	ret = GetWindowThreadProcessId(hRPGXPWindow, &pidRPGXP);
	if (ret == 0)
	{
		wprintf_s(L"GetWindowThreadProcessId() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pidRPGXP);
	if (hProcess == NULL)
	{
		wprintf_s(L"OpenProcess() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	RPGXP::CommandInfo* pSaveCommand = &RPGXP::gCommands[RPGXP::eCommandType::DEFINE_AND_CALL_RPGXP_SAVE_WITHOUT_SCRIPTS];
	SIZE_T scriptLength = strlen(pSaveCommand->Scripts);

	DWORD oldProtect1 = 0;
	VOID* pAddr = (VOID*)((char*)(hRPGXPLibrary) + pSaveCommand->Offset);
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
	//ret = VirtualProtectEx(hProcess, pAddr, 256, oldProtect1, NULL);

	RPGXP::CommandInfo* pCallSaveCommand = &RPGXP::gCommands[RPGXP::eCommandType::CALL_RPGXP_SAVE];
	scriptLength = strlen(pCallSaveCommand->Scripts);

	DWORD oldProtect2 = 0;
	VOID* pSaveAddr = (VOID*)((char*)(hRPGXPLibrary) + pCallSaveCommand->Offset);

	char bytes[4] = { (int)pAddr & 0xff, ((int)pAddr >> 8) & 0xff, ((int)pAddr >> 16) & 0xff, ((int)pAddr >> 24) & 0xff };

	ret = VirtualProtectEx(hProcess, pSaveAddr, sizeof(bytes), PAGE_EXECUTE_READWRITE, &oldProtect2);
	if (ret == 0)
	{
		wprintf_s(L"2 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	
	ret = WriteProcessMemory(hProcess, pSaveAddr, bytes, sizeof(bytes), NULL);
	if (ret == 0)
	{
		wprintf_s(L"2 WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}

	//ret = VirtualProtectEx(hProcess, pSaveAddr, 256, oldProtect2, NULL);

	//CloseHandle(hProcess);

	return 0;
}