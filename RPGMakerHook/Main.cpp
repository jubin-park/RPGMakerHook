#include <Windows.h>
#include <cstdio>
#include <tchar.h>

#include "RPGXP.h"

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


	DWORD oldProtect1 = 0;
	VOID* pAddr = (VOID*)((char*)(hRPGXPLibrary) + 0x2E0);
	ret = VirtualProtectEx(hProcess, pAddr, 256, PAGE_EXECUTE_READWRITE, &oldProtect1);
	{
		if (ret == 0)
		{
			wprintf_s(L"1 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
		const char str[] = "Win32API.new('user32','MessageBox','lppl','l').call(0,'abc','123',0)";

		SIZE_T outSize = 0;
		ret = WriteProcessMemory(hProcess, pAddr, str, sizeof(str), &outSize);
		if (ret == 0)
		{
			wprintf_s(L"1 WriteProcessMemory() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
			return 1;
		}
	}
	//ret = VirtualProtectEx(hProcess, pAddr, 256, oldProtect1, NULL);


	DWORD oldProtect2 = 0;
	VOID* pSaveAddr = (VOID*)((char*)(hRPGXPLibrary) + 0xAEC7);

	ret = VirtualProtectEx(hProcess, pSaveAddr, 5, PAGE_EXECUTE_READWRITE, &oldProtect2);
	if (ret == 0)
	{
		wprintf_s(L"2 VirtualProtectEx() error = %d (%s:%d)\n", GetLastError(), _T(__FILE__), __LINE__);
		return 1;
	}
	
	char bytes[5] = { 0x68, (int)pAddr & 0xff, ((int)pAddr >> 8) & 0xff, ((int)pAddr >> 16) & 0xff, ((int)pAddr >> 24) & 0xff };
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