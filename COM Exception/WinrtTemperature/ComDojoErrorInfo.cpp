#include "pch.h"
#include "WinrtTemperature_h.h"
#include "ComDojoErrorInfo.h"

using namespace winrt;
using namespace Microsoft::WRL;

ComDojoErrorInfo::~ComDojoErrorInfo()
{}

STDMETHODIMP ComDojoErrorInfo::SetGUID(REFGUID rguid) noexcept
{
	this->_iid = rguid;
	return S_OK;
}

STDMETHODIMP ComDojoErrorInfo::SetSource(LPOLESTR szSource) noexcept
{
	this->_source = szSource;
	return S_OK;
}

STDMETHODIMP ComDojoErrorInfo::SetDescription(LPOLESTR szDescription) noexcept
{
	this->_description = szDescription;
	return S_OK;
}

STDMETHODIMP ComDojoErrorInfo::SetHelpFile(LPOLESTR szHelpFile) noexcept
{
	return E_NOTIMPL;
}

STDMETHODIMP ComDojoErrorInfo::SetHelpContext(DWORD dwHelpContext) noexcept
{
	return E_NOTIMPL;
}

STDMETHODIMP ComDojoErrorInfo::GetGUID(GUID * pGUID) noexcept
{
	*pGUID = this->_iid;
	return S_OK;
}

STDMETHODIMP ComDojoErrorInfo::GetSource(BSTR * pBstrSource) noexcept
{
	if (nullptr == pBstrSource)
	{
		return E_POINTER;
	}
	*pBstrSource = ::SysAllocString(this->_source.c_str());
	return S_OK;
}

STDMETHODIMP ComDojoErrorInfo::GetDescription(BSTR * pBstrDescription) noexcept
{
	if (nullptr == pBstrDescription)
	{
		return E_POINTER;
	}
	*pBstrDescription = ::SysAllocString(this->_description.c_str());
	return S_OK;
}

STDMETHODIMP ComDojoErrorInfo::GetHelpFile(BSTR * pBstrHelpFile) noexcept
{
	return E_NOTIMPL;
}

STDMETHODIMP ComDojoErrorInfo::GetHelpContext(DWORD * pdwHelpContext) noexcept
{
	return E_NOTIMPL;
}

STDMETHODIMP ComDojoErrorInfo::GetErrorCode(long * errorCode) noexcept
{
	if (nullptr == errorCode)
	{
		return E_POINTER;
	}
	*errorCode = this->_errorCode;
	return S_OK;
}

STDMETHODIMP ComDojoErrorInfo::SetErrorCode(long errorCode) noexcept
{
	this->_errorCode = errorCode;
	return S_OK;
}

STDMETHODIMP ComDojoErrorInfo::CreateInstance(IUnknown * outer, IID const & iid, void ** ppv) noexcept
{
	if (nullptr == ppv)
	{
		return E_POINTER;
	}
	*ppv = nullptr;
	if (outer)
	{
		return CLASS_E_NOAGGREGATION;
	}
	return make<::ComDojoErrorInfo>()->QueryInterface(iid, ppv);
}

STDMETHODIMP ComDojoErrorInfo::LockServer(BOOL lock) noexcept
{
	if (lock)
	{
		Module<InProc>::GetModule().IncrementObjectCount();
	}
	else
	{
		Module<InProc>::GetModule().DecrementObjectCount();
	}
	return S_OK;
}
