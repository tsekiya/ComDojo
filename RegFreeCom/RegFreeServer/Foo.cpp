#include "stdafx.h"
#include "Foo.h"

#define OUTPUT_STRING L"This is Foo"

Foo::Foo()
{
}


Foo::~Foo()
{
}

STDMETHODIMP_(HRESULT __stdcall) Foo::SayHello(HSTRING *message)
{
	if (nullptr == message)
	{
		return E_POINTER;
	}
	size_t length = 0;
	HRESULT hr = ::StringCchLength(OUTPUT_STRING, STRSAFE_MAX_CCH, &length);
	if (FAILED(hr))
	{
		return hr;
	}
#pragma warning(push)
#pragma warning(disable:4267)
	hr = ::WindowsCreateString(OUTPUT_STRING, length, message);
#pragma warning(pop)
	if (FAILED(hr))
	{
		return hr;
	}
	return S_OK;
}

CoCreatableClass(Foo);