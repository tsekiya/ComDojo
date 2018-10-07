// Greeting.cpp : CGreeting ‚ÌŽÀ‘•

#include "stdafx.h"
#include "Greeting.h"


// CGreeting



STDMETHODIMP CGreeting::SayHello(BSTR* pBstr)
{
	*pBstr = ::SysAllocString(L"Hello,world\r\n");
	return S_OK;
}
