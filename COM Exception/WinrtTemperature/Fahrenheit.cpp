#include "pch.h"
#include "WinrtTemperature_h.h"
#include "WinrtTemperature_i.c"
#include "Fahrenheit.h"
#include "ComDojoError.h"
#include "resource.h"
#include "ComDojoErrorInfo.h"

#define MAX_CLSID_LENGTH 256L
#define MAX_DESCRIPTION_LENGTH 256L

extern HMODULE g_hModule;

using namespace winrt;
using namespace Microsoft::WRL;


STDMETHODIMP Fahrenheit::ToCelsius(double fahrenheit, double* celsius) noexcept
{
	if (nullptr == celsius)
	{
		this->HandleError(IID_IFahrenheit, IDS_INVALID_POINTER_CELSIUS, ERROR_COMDOJO_INVALID_POINTER_CELSIUS);
		return E_POINTER;
	}
	*celsius = (fahrenheit - 32) * 5 / 9;
	return S_OK;
}

STDMETHODIMP Fahrenheit::FromCelsius(double celsius, double* fahrenheit) noexcept
{
	if (nullptr == fahrenheit)
	{
		this->HandleError(IID_IFahrenheit, IDS_INVALID_POINTER_FAHRENHEIT, ERROR_COMDOJO_INVALID_POINTER_FAHRENHEIT);
		return E_POINTER;
	}
	*fahrenheit = celsius * 9 / 5 + 32;
	return S_OK;
}

STDMETHODIMP Fahrenheit::CreateInstance(IUnknown * outer, IID const & iid, void ** ppv) noexcept
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
	return make<::Fahrenheit>()->QueryInterface(iid, ppv);
}

STDMETHODIMP Fahrenheit::LockServer(BOOL lock) noexcept
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

STDMETHODIMP Fahrenheit::InterfaceSupportsErrorInfo(REFIID riid) noexcept
{
	static const IID* const arr[] =
	{
		&IID_IFahrenheit
	};

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i], riid))
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
		com_ptr<ICreateComDojoErrorInfo> createErrorInfo;
		FAILEDEX(winrt::make<ComDojoErrorInfo>()->QueryInterface(IID_ICreateComDojoErrorInfo, createErrorInfo.put_void()));
		FAILEDEX(createErrorInfo->SetGUID(IID_IFahrenheit));
		FAILEDEX(createErrorInfo->SetDescription(description));
		FAILEDEX(createErrorInfo->SetErrorCode(errorCode));
		wchar_t source[MAX_CLSID_LENGTH];
		if (::StringFromGUID2(CLSID_Fahrenheit, source, MAX_CLSID_LENGTH))
		{
			FAILEDEX(createErrorInfo->SetSource(source));
		}
		com_ptr<IComDojoErrorInfo> comDojoErrorInfo = createErrorInfo.as<IComDojoErrorInfo>();
		if (comDojoErrorInfo == nullptr)
		{
			throw E_NOINTERFACE;
		}
		com_ptr<IErrorInfo> errorInfo = comDojoErrorInfo.as<IErrorInfo>();
		FAILEDEX(::SetErrorInfo(0, errorInfo.get()));
	}
	catch (...)
	{

	}
	return;
}

Fahrenheit::~Fahrenheit()
{

}
