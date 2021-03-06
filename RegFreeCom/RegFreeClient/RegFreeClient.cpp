// RegFreeClient.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include "../RegFreeServer/RegFreeServer_h.h"
#include "../RegFreeServer/RegFreeServer_h.c"

using Microsoft::WRL::ComPtr;
using Microsoft::WRL::Wrappers::RoInitializeWrapper;
using std::cout;
using std::endl;

int main()
{
	RoInitializeWrapper initializer(RO_INIT_SINGLETHREADED);
	if (FAILED(initializer))
	{
		return initializer;
	}
	ComPtr<IFoo> foo;
	HRESULT hr = ::CoCreateInstance(CLSID_Foo, nullptr, CLSCTX_ALL, IID_IFoo, &foo);
	if (FAILED(hr))
	{
		return hr;
	}
	HSTRING message;
	hr = foo->SayHello(&message);
	if (FAILED(hr))
	{
		return hr;
	}
	cout << (PCSTR)CStringA(::WindowsGetStringRawBuffer(message, nullptr)) << endl;
	::WindowsDeleteString(message);
	ComPtr<IBar> bar;
	hr = ::CoCreateInstance(CLSID_Bar, nullptr, CLSCTX_ALL, IID_IBar, &bar);
	if (FAILED(hr))
	{
		return hr;
	}
	hr = bar->SayHello(&message);
	if (FAILED(hr))
	{
		return hr;
	}
	cout << (PCSTR)CStringA(::WindowsGetStringRawBuffer(message, nullptr)) << endl;
	::WindowsDeleteString(message);

	return hr;
}
