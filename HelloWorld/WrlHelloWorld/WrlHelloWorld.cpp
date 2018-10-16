// WrlHelloWorld.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "../DojoWrlGreeting/DojoWrlGreeting_i.h"
#include "../DojoWrlGreeting/DojoWrlGreeting_i.c"

using Microsoft::WRL::ComPtr;
using Microsoft::WRL::Wrappers::HString;
using Microsoft::WRL::Wrappers::RoInitializeWrapper;
using std::cout;

int main()
{
	RoInitializeWrapper initializer(RO_INIT_SINGLETHREADED);
	HRESULT hr = initializer;
	if (FAILED(hr))
	{
		return hr;
	}
	ComPtr<IWrlGreeting> greeting;
	hr = ::CoCreateInstance(CLSID_WrlGreeting, nullptr, CLSCTX_ALL, IID_IWrlGreeting, &greeting);
	if (FAILED(hr))
	{
		return hr;
	}
	HString message;
	hr = greeting->SayHello(message.GetAddressOf());
	cout << CStringA(message.GetRawBuffer(nullptr));
	return hr;
}

