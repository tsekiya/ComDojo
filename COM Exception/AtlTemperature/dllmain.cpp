// dllmain.cpp : DllMain の実装です。

#include "stdafx.h"
#include "resource.h"
#include "AtlTemperature_i.h"
#include "dllmain.h"

CAtlTemperatureModule _AtlModule;

// DLL エントリ ポイント
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved);
}
