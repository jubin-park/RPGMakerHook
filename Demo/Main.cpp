#include <Windows.h>
#include <cstdio>

typedef int (*HookRPGXP_t)(const wchar_t* const lpGameIniFilePath);
typedef int (*HookRPGVXAce_t)(const wchar_t* const lpGameIniFilePath);
typedef int (*RPGXPEval_t)(const wchar_t* const lpGameIniFilePath, const char* const pRubyScript);

int wmain()
{
	HINSTANCE hInstance = nullptr;

	HookRPGXP_t pHookRPGXP = nullptr;
	HookRPGVXAce_t pHookRPGVXAce = nullptr;
	RPGXPEval_t pRPGXPEval = nullptr;

	hInstance = LoadLibraryW(L"RPGMakerHook.dll");
	if (hInstance == nullptr)
	{
		wprintf_s(L"hInstance is nullptr\n");
		return 1;
	}

	pHookRPGXP = (HookRPGXP_t)GetProcAddress(hInstance, "HookRPGXP");
	if (pHookRPGXP == nullptr)
	{
		wprintf_s(L"HookRPGXP: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	pHookRPGVXAce = (HookRPGVXAce_t)GetProcAddress(hInstance, "HookRPGVXAce");
	if (pHookRPGVXAce == nullptr)
	{
		wprintf_s(L"HookRPGVXAce: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	pRPGXPEval = (RPGXPEval_t)GetProcAddress(hInstance, "RPGXPEval");
	if (pRPGXPEval == nullptr)
	{
		wprintf_s(L"RPGXPEval: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	//pHookRPGXP(L"./RPGXPGame.ini");
	//pHookRPGVXAce(L"./RPGVXAceGame.ini");
	pRPGXPEval(L"./RPGXPGame.ini", "Win32API.new('user32','MessageBox','lppl','l').call(0,'hello world!','RPGXP',0)");

	FreeLibrary(hInstance);

	return 0;
}