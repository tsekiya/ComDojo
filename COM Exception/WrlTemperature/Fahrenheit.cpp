#include "stdafx.h"
#include "WrlTemperature_h.h"
#include "Fahrenheit.h"
#include "WrlTemperature_i.c"
#include "ComDojoErrorInfo.h"
#include "resource.h"
#include "ComDojoError.h"

#define MAX_CLSID_LENGTH 256L
#define MAX_DESCRIPTION_LENGTH 256L

extern HMODULE g_hModule;

Fahrenheit::Fahrenheit()
{
}

Fahrenheit::~Fahrenheit()
{
}

STDMETHODIMP Fahrenheit::ToCelsius(double fahrenheit, double *celsius)  noexcept
{
	if (nullptr == celsius)
	{
		this->HandleError(IID_IFahrenheit, IDS_INVALID_POINTER_CELSIUS, ERROR_COMDOJO_INVALID_POINTER_CELSIUS);
		return E_POINTER;
	}
	*celsius = (fahrenheit - 32) * 5 / 9;
	return S_OK;
}

STDMETHODIMP Fahrenheit::FromCelsius(double celsius, double *fahrenheit)  noexcept
{
	if (nullptr == fahrenheit)
	{
		this->HandleError(IID_IFahrenheit, IDS_INVALID_POINTER_FAHRENHEIT, ERROR_COMDOJO_INVALID_POINTER_FAHRENHEIT);
		return E_POINTER;
	}
	*fahrenheit = celsius * 9 / 5 + 32;
	return S_OK;
}

STDMETHODIMP Fahrenheit::InterfaceSupportsErrorInfo(REFIID iid)  noexcept
{
	static const IID* const arr[] =
	{
		&IID_IFahrenheit
	};

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i], iid))
			return S_OK;
	}
	return S_FALSE;
}

void Fahrenheit::HandleError(REFIID iid, UINT rezid, long errorCode) const noexcept
{
	try
	{
		wchar_t description[MAX_DESCRIPTION_LENGTH];
		description[0] = L'\0';
		::LoadString(g_hModule, rezid, description, MAX_DESCRIPTION_LENGTH);
		ComPtr<ComDojoErrorInfo> createErrorInfo = Make<ComDojoErrorInfo>();
		FAILEDEX(createErrorInfo->SetGUID(IID_IFahrenheit));
		FAILEDEX(createErrorInfo->SetDescription(description));
		FAILEDEX(createErrorInfo->SetErrorCode(errorCode));
		wchar_t source[MAX_CLSID_LENGTH];
		if (::StringFromGUID2(CLSID_Fahrenheit, source, MAX_CLSID_LENGTH))
		{
			FAILEDEX(createErrorInfo->SetSource(source));
		}
		ComPtr<IErrorInfo> errorInfo;
		FAILEDEX(createErrorInfo.As<IErrorInfo>(&errorInfo));
		if (errorInfo == nullptr)
		{
			throw E_NOINTERFACE;
		}
		::SetErrorInfo(0, errorInfo.Get());
	}
	catch (...)
	{

	}
	return;
}

CoCreatableClass(Fahrenheit);
