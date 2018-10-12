// Greeting2.cpp : CGreeting2 ‚ÌŽÀ‘•

#include "stdafx.h"
#include "Greeting2.h"


// CGreeting2

STDMETHODIMP CGreeting2::SayHello(BSTR * pBstr)
{
	return this->_spGreeting->SayHello(pBstr);
}


STDMETHODIMP CGreeting2::SayGoodbye(BSTR* pBstr)
{
	if (nullptr == pBstr)
	{
		return E_POINTER;
	}
	*pBstr = ::SysAllocString(L"Goodbye, world\r\n");
	if (nullptr == *pBstr)
	{
		return E_OUTOFMEMORY;
	}

	return S_OK;
}
