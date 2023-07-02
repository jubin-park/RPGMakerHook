#include <Windows.h>
#include <cstdio>

typedef int (*HookRGSS1)(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGXPFilePath);
typedef int (*HookRPGXP)(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGXPFilePath);
typedef int (*HookRPGVXAce)(const wchar_t* const lpGameIniFilePath, const wchar_t* const lpRPGVXAceFilePath);

int wmain()
{
	HINSTANCE hInstance = NULL;

	HookRGSS1 pHookRGSS1 = NULL;
	HookRPGXP pHookRPGXP = NULL;
	HookRPGVXAce pHookRPGVXAce = NULL;

	hInstance = LoadLibraryW(L"RPGMakerHook.dll");
	if (hInstance == NULL)
	{
		wprintf_s(L"hInstance is NULL\n");
		return 1;
	}

	pHookRPGXP = (HookRPGXP)GetProcAddress(hInstance, "HookRPGXP");
	if (pHookRPGXP == NULL)
	{
		wprintf_s(L"GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	// RPGXP.exe is a 32-bit application
	pHookRPGXP(L"./RPGXPGame.ini", L"C:\\Program Files (x86)\\Steam\\steamapps\\common\\RPGXP\\RPGXP.exe");

	// RPGVXAce.exe, too
	//HookRPGVXAce(L"./RPGVXAceGame.ini", L"C:\\Program Files (x86)\\Steam\\steamapps\\common\\RPGVXAce\\RPGVXAce.exe");

	//HookRGSS1(L"./RPGXPGame.ini", L"C:\\Program Files (x86)\\Steam\\steamapps\\common\\RPGXP\\RPGXP.exe");

	FreeLibrary(hInstance);

	return 0;
}