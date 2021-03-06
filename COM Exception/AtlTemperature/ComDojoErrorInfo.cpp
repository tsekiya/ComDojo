// ComDojoErrorInfo.cpp : CComDojoErrorInfo の実装

#include "stdafx.h"
#include "ComDojoErrorInfo.h"


// CComDojoErrorInfo

STDMETHODIMP CComDojoErrorInfo::SetGUID(REFGUID rguid) noexcept
{
	this->_iid = rguid;
	return S_OK;
}

STDMETHODIMP CComDojoErrorInfo::SetSource(LPOLESTR szSource) noexcept
{
	this->_source = szSource;
	return S_OK;
}

STDMETHODIMP CComDojoErrorInfo::SetDescription(LPOLESTR szDescription) noexcept
{
	this->_description = szDescription;
	return S_OK;
}

STDMETHODIMP CComDojoErrorInfo::SetHelpFile(LPOLESTR szHelpFile) noexcept
{
	return E_NOTIMPL;
}

STDMETHODIMP CComDojoErrorInfo::SetHelpContext(DWORD dwHelpContext) noexcept
{
	return E_NOTIMPL;
}

STDMETHODIMP CComDojoErrorInfo::GetGUID(GUID * pGUID) noexcept
{
	if (nullptr == pGUID)
	{
		return E_POINTER;
	}
	*pGUID = this->_iid;
	return S_OK;
}

STDMETHODIMP CComDojoErrorInfo::GetSource(BSTR * pBstrSource) noexcept
{
	if (nullptr == pBstrSource)
	{
		return E_POINTER;
	}
	*pBstrSource = this->_source.AllocSysString();
	return S_OK;
}

STDMETHODIMP CComDojoErrorInfo::GetDescription(BSTR * pBstrDescription) noexcept
{
	if (nullptr == pBstrDescription)
	{
		return E_POINTER;
	}
	*pBstrDescription = this->_description.AllocSysString();
	return S_OK;
}

STDMETHODIMP CComDojoErrorInfo::GetHelpFile(BSTR * pBstrHelpFile) noexcept
{
	return E_NOTIMPL;
}

STDMETHODIMP CComDojoErrorInfo::GetHelpContext(DWORD * pdwHelpContext) noexcept
{
	return E_NOTIMPL;
}

STDMETHODIMP CComDojoErrorInfo::GetErrorCode(long * errorCode) noexcept
{
	if (nullptr == errorCode)
	{
		return E_POINTER;
	}
	*errorCode = this->_errorCode;
	return S_OK;
}

STDMETHODIMP CComDojoErrorInfo::SetErrorCode(long errorCode) noexcept
{
	this->_errorCode = errorCode;
	return S_OK;
}
