// Fahrenheit.cpp : CFahrenheit の実装

#include "stdafx.h"
#include "Fahrenheit.h"
#include "ComDojoError.h"
#include "resource.h"

#define MAX_CLSID_LENGTH 256L

// CFahrenheit

STDMETHODIMP CFahrenheit::InterfaceSupportsErrorInfo(REFIID riid) noexcept
{
	static const IID* const arr[] = 
	{
		&IID_IFahrenheit
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CFahrenheit::ToCelsius(double fahrenheit, double * celsius) noexcept
{
	if (nullptr == celsius)
	{
		CComBSTR description;
		description.LoadString(IDS_INVALID_POINTER_CELSIUS);
		this->HandleError(IID_IFahrenheit, description, ERROR_COMDOJO_INVALID_POINTER_CELSIUS);
		return E_POINTER;
	}
	*celsius = (fahrenheit - 32) * 5 / 9;
	return S_OK;
}

STDMETHODIMP CFahrenheit::FromCelsius(double celsius, double * fahrenheit) noexcept
{
	if (nullptr == fahrenheit)
	{
		CComBSTR description;
		description.LoadString(IDS_INVALID_POINTER_FAHRENHEIT);
		this->HandleError(IID_IFahrenheit, description, ERROR_COMDOJO_INVALID_POINTER_FAHRENHEIT);
		return E_POINTER;
	}
	*fahrenheit = celsius * 9 / 5 + 32;
	return S_OK;
}
void CFahrenheit::HandleError(
	REFIID iid, LPOLESTR description, long errorCode = ERROR_COMDOJO_UNKNOWN) const noexcept
{
	try
	{
		CComPtr<ICreateComDojoErrorInfo> createErrorInfo;
		FAILEDEX(createErrorInfo.CoCreateInstance(CLSID_ComDojoErrorInfo));
		FAILEDEX(createErrorInfo->SetGUID(IID_IFahrenheit));
		FAILEDEX(createErrorInfo->SetDescription(description));
		FAILEDEX(createErrorInfo->SetErrorCode(errorCode));
		wchar_t source[MAX_CLSID_LENGTH];
		if (::StringFromGUID2(CLSID_Fahrenheit, source, MAX_CLSID_LENGTH))
		{
			FAILEDEX(createErrorInfo->SetSource(source));
		}
		CComQIPtr<IErrorInfo> errorInfo = createErrorInfo;
		if (errorInfo == nullptr)
		{
			throw E_NOINTERFACE;
		}
		::SetErrorInfo(0, errorInfo);
	}
	catch (...)
	{

	}
	return;
}
