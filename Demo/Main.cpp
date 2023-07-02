#include <Windows.h>
#include <cstdio>

typedef BOOL (*HookRPGXPSave_t)(const wchar_t* const lpGameIniFilePath);
typedef BOOL (*HookRPGVXAceSave_t)(const wchar_t* const lpGameIniFilePath);
typedef BOOL (*RPGXPEval_t)(const wchar_t* const lpGameIniFilePath, const char* const pRubyScript);

int wmain()
{
	HINSTANCE hInstance = nullptr;

	HookRPGXPSave_t pHookRPGXPSave = nullptr;
	HookRPGVXAceSave_t pHookRPGVXAceSave = nullptr;
	RPGXPEval_t pRPGXPEval = nullptr;

	hInstance = LoadLibraryW(L"RPGMakerHook.dll");
	if (hInstance == nullptr)
	{
		wprintf_s(L"hInstance is nullptr\n");
		return 1;
	}

	pHookRPGXPSave = (HookRPGXPSave_t)GetProcAddress(hInstance, "HookRPGXPSave");
	if (pHookRPGXPSave == nullptr)
	{
		wprintf_s(L"HookRPGXPSave: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	pHookRPGVXAceSave = (HookRPGVXAceSave_t)GetProcAddress(hInstance, "HookRPGVXAceSave");
	if (pHookRPGVXAceSave == nullptr)
	{
		wprintf_s(L"HookRPGVXAceSave: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	pRPGXPEval = (RPGXPEval_t)GetProcAddress(hInstance, "RPGXPEval");
	if (pRPGXPEval == nullptr)
	{
		wprintf_s(L"RPGXPEval: GetProcAddress GetLastError() = %d\n", GetLastError());
		return 1;
	}

	pHookRPGXPSave(L"./RPGXPGame.ini");
	pHookRPGVXAceSave(L"./RPGVXAceGame.ini");
	pRPGXPEval(L"./RPGXPGame.ini", "Win32API.new('user32','MessageBox','lppl','l').call(0,'hello world!','RPGXP',0)");

	FreeLibrary(hInstance);

	return 0;
}