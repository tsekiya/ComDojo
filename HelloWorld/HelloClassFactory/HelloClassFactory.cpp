// HelloClassFactory.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "../DojoGreeting/DojoGreeting_i.h"
#include "../DojoGreeting/DojoGreeting_i.c"

HRESULT __stdcall MyCreateInstance(
	const CLSID& rclsid,
	IUnknown* pOuterUnk,
	DWORD clsctx,
	const IID& riid,
	void** ppv)
{
	CComPtr<IClassFactory> spFactory;
	::CoGetClassObject(rclsid, clsctx, pOuterUnk, __uuidof(IClassFactory), (void**)&spFactory);
	spFactory->CreateInstance(pOuterUnk, riid, ppv);
	return S_OK;
}

int main()
{
	::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
	{
		CComPtr<IGreeting> spGreeting;

		::MyCreateInstance(
			CLSID_Greeting,
			nullptr,
			CLSCTX_ALL,
			IID_IGreeting,
			(void**)&spGreeting);

		CComBSTR bstr;

		spGreeting->SayHello(&bstr);

		CStringA szHello(bstr);

		HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);

		::WriteFile(hStdOut, (PCSTR)szHello, szHello.GetLength(), nullptr, nullptr);
	}
	::CoUninitialize();
	return 0;
}
