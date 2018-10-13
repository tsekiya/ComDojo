// GoodbyeWorldWrl.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#import "DojoGreeting2.dll" rename_namespace("ComDojo")

int main()
{
	using ComDojo::ComInitializer;
	using ComDojo::Greeting2;
	using ComDojo::IGreeting2;
	using Microsoft::WRL::ComPtr;
	using std::cerr;
	using std::cout;
	using std::endl;
	
	HRESULT hr = S_OK;
	
	ComInitializer oInitializer(COINIT_APARTMENTTHREADED);
	
	try
	{
		ComPtr<IGreeting2> pGreeting;
		hr = ::CoCreateInstance(__uuidof(Greeting2), nullptr, CLSCTX_ALL, __uuidof(IGreeting2), &pGreeting);
		if (FAILED(hr))
		{
			_com_raise_error(hr);
		}
		_bstr_t hello = pGreeting->SayHello();
		_bstr_t goodbye = pGreeting->SayGoodbye();
		cout << (PCSTR)hello;
		cout << (PCSTR)goodbye;
	}
	catch (const _com_error& e)
	{
		hr = e.Error();
		cerr << (PCSTR)CStringA(e.ErrorMessage()) << endl;
	}
	return hr;
}

