#include <Windows.h>
#include <cstdio>

typedef int (*HookRPGXP_t)(const wchar_t* const lpGameIniFilePath);
typedef int (*HookRPGVXAce_t)(const wchar_t* const lpGameIniFilePath);
typedef int (*HookRGSS1_t)(const wchar_t* const lpGameIniFilePath);

int wmain()
{
	HINSTANCE hInstance = nullptr;

	HookRPGXP_t pHookRPGXP = nullptr;
	HookRPGVXAce_t pHookRPGVXAce = nullptr;
	HookRGSS1_t pHookRGSS1 = nullptr;

	hInstance = LoadLibraryW(L"RPGMakerHook.dll");
	if (hInstance == nullptr)
	{
		wprintf_s(L"hInstance is nullptr\n");
		return 1;
	}

	pHookRPGXP = (HookRPGXP_t)GetProcAddress(hInstance, "HookRPGXP");
	if (pHookRPGXP == nullptr)
	{
		wprintf_s(L"HookRPGXP_t: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	pHookRPGVXAce = (HookRPGXP_t)GetProcAddress(hInstance, "HookRPGVXAce");
	if (pHookRPGVXAce == nullptr)
	{
		wprintf_s(L"HookRPGVXAce_t: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	pHookRGSS1 = (HookRGSS1_t)GetProcAddress(hInstance, "HookRGSS1");
	if (pHookRGSS1 == nullptr)
	{
		wprintf_s(L"HookRGSS1_t: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	pHookRPGXP(L"./RPGXPGame.ini");
	pHookRPGVXAce(L"./RPGVXAceGame.ini");
	pHookRGSS1(L"./RPGXPGame.ini");

	FreeLibrary(hInstance);

	return 0;
}