// dllmain.cpp : DllMain �̎����ł��B

#include "stdafx.h"
#include "resource.h"
#include "DojoGreeting_i.h"
#include "dllmain.h"

CDojoGreetingModule _AtlModule;

// DLL �G���g�� �|�C���g
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
