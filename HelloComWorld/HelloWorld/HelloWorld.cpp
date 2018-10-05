// HelloWorld.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "../DojoGreeting/DojoGreeting_i.h"

int main()
{
	::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
	{
		CComPtr<IGreeting> spGreeting;

		spGreeting.CoCreateInstance(CLSID_Greeting, nullptr, CLSCTX_ALL);
		
		CComBSTR bstr;
		
		spGreeting->SayHello(&bstr);

		CStringA szHello(bstr);
		
		HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
		
		::WriteFile(hStdOut, (PCSTR)szHello, szHello.GetLength(), nullptr, nullptr);
	}
	::CoUninitialize();
    return 0;
}

