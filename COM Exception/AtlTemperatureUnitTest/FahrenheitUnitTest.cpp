#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AtlTemperature/AtlTemperature_i.h"
#include "../AtlTemperature/AtlTemperature_i.c"
#include "ComDojoError.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AtlTemperatureUnitTest
{		
	TEST_CLASS(FahrenheitUnitTest)
	{
	public:
		
		TEST_METHOD(ToCelsiusTestMethod)
		{
			CComPtr<IFahrenheit> converter;
			HRESULT hr = converter.CoCreateInstance(CLSID_Fahrenheit);
			Assert::IsFalse(FAILED(hr));
			double input = 100;
			hr = converter->ToCelsius(input, nullptr);
			Assert::IsTrue(FAILED(hr));
			this->CheckErrorInfo(
				converter,
				L"摂氏のポインタがnullptrです",
				IID_IFahrenheit,
				L"{ecb6161a-bd68-4656-8e80-01fe1622cef3}",
				ERROR_COMDOJO_INVALID_POINTER_CELSIUS
			);
		}

		TEST_METHOD(FromCelsiusTestMethod)
		{
			CComPtr<IFahrenheit> converter;
			HRESULT hr = converter.CoCreateInstance(CLSID_Fahrenheit);
			Assert::IsFalse(FAILED(hr));
			double input = 100;
			hr = converter->FromCelsius(input, nullptr);
			Assert::IsTrue(FAILED(hr));
			this->CheckErrorInfo(
				converter,
				L"華氏のポインタがnullptrです",
				IID_IFahrenheit,
				L"{ecb6161a-bd68-4656-8e80-01fe1622cef3}",
				ERROR_COMDOJO_INVALID_POINTER_FAHRENHEIT
			);
		}
	private:
		void CheckErrorInfo(IUnknown* obj, wchar_t *description, const GUID& iid, wchar_t *src, long errorCode)
		{
			CComQIPtr<ISupportErrorInfo> supportErrorInfo = obj;
			Assert::IsNotNull<ISupportErrorInfo>(supportErrorInfo);
			HRESULT hr = supportErrorInfo->InterfaceSupportsErrorInfo(IID_IFahrenheit);
			Assert::IsTrue(S_OK == hr);
			CComPtr<IErrorInfo> errorInfo;
			hr = ::GetErrorInfo(0, &errorInfo);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsNotNull<IErrorInfo>(errorInfo);
			CComQIPtr<IComDojoErrorInfo> comDojoErrorInfo = errorInfo;
			Assert::IsNotNull<IComDojoErrorInfo>(comDojoErrorInfo);
			CComBSTR desc;
			hr = comDojoErrorInfo->GetDescription(&desc);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(0 == ::wcscmp(desc, description));
			GUID guid = { 0 };
			hr = comDojoErrorInfo->GetGUID(&guid);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(::IsEqualGUID(guid, iid));
			CComBSTR source;
			hr = comDojoErrorInfo->GetSource(&source);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(0 == ::_wcsicmp(source, src));
			long comDojoErrorCode = 0;
			hr = comDojoErrorInfo->GetErrorCode(&comDojoErrorCode);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::AreEqual<long>(comDojoErrorCode, errorCode);
		}

	};
}