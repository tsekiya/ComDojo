#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WrlTemperature/WrlTemperature_h.h"
#include "../WrlTemperature/WrlTemperature_i.c"
#include "ComDojoError.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Microsoft::WRL;

namespace WrlTemperatureUnitTest
{		
	TEST_CLASS(FahrenheitUnitTest)
	{
	public:
		
		TEST_METHOD(FromCelsiusTestMethod)
		{
			ComPtr<IFahrenheit> fah;
			HRESULT hr = CoCreateInstance(CLSID_Fahrenheit, nullptr, CLSCTX_ALL, IID_IFahrenheit, &fah);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(FAILED(fah->FromCelsius(100, nullptr)));
			this->CheckErrorInfo(
				fah.Get(),
				L"華氏のポインタがnullptrです",
				IID_IFahrenheit,
				L"{492D5FF2-C462-48FD-BE9C-8E689BFDE16C}",
				ERROR_COMDOJO_INVALID_POINTER_FAHRENHEIT
			);
			//ComPtr<ISupportErrorInfo> supportErrorInfo;
			//Assert::IsTrue(SUCCEEDED(fah->QueryInterface<ISupportErrorInfo>(&supportErrorInfo)));
			//Assert::IsTrue(S_OK == supportErrorInfo->InterfaceSupportsErrorInfo(IID_IFahrenheit));
			//ComPtr<IErrorInfo> errorInfo;
			//Assert::IsTrue(SUCCEEDED(::GetErrorInfo(0, &errorInfo)));
			//ComPtr<IComDojoErrorInfo> comdojoErrorInfo;
			//Assert::IsTrue(SUCCEEDED(errorInfo->QueryInterface<IComDojoErrorInfo>(&comdojoErrorInfo)));
			//BSTR desc = nullptr;
			//Assert::IsTrue(SUCCEEDED(comdojoErrorInfo->GetDescription(&desc)));
			//Assert::AreEqual(L"華氏のポインタがnullptrです", desc);
			//::SysFreeString(desc);
			//long errorCode = ERROR_COMDOJO_SUCCESS;
			//Assert::IsTrue(SUCCEEDED(comdojoErrorInfo->GetErrorCode(&errorCode)));
			//Assert::IsTrue(ERROR_COMDOJO_INVALID_POINTER_FAHRENHEIT == errorCode);
			//GUID guid = { 0 };
			//Assert::IsTrue(SUCCEEDED(comdojoErrorInfo->GetGUID(&guid)));
			//Assert::IsTrue(IsEqualGUID(guid, IID_IFahrenheit));
			//BSTR source = nullptr;
			//Assert::IsTrue(SUCCEEDED(comdojoErrorInfo->GetSource(&source)));
			//Assert::AreEqual(source, L"{492D5FF2-C462-48FD-BE9C-8E689BFDE16C}");
		}

		TEST_METHOD(ToCelsiusTestMethod)
		{
			ComPtr<IFahrenheit> fah;
			Assert::IsTrue(SUCCEEDED(CoCreateInstance(CLSID_Fahrenheit, nullptr, CLSCTX_ALL, IID_IFahrenheit, &fah)));
			Assert::IsTrue(FAILED(fah->ToCelsius(100, nullptr)));
			this->CheckErrorInfo(
				fah.Get(),
				L"摂氏のポインタがnullptrです",
				IID_IFahrenheit,
				L"{492D5FF2-C462-48FD-BE9C-8E689BFDE16C}",
				ERROR_COMDOJO_INVALID_POINTER_CELSIUS);
		}
	private:
		void CheckErrorInfo(
			IUnknown* fah, wchar_t *description, const GUID& iid, wchar_t *src, long errorCode)
		{
			ComPtr<ISupportErrorInfo> supportErrorInfo;
			Assert::IsTrue(SUCCEEDED(fah->QueryInterface<ISupportErrorInfo>(&supportErrorInfo)));
			Assert::IsTrue(S_OK == supportErrorInfo->InterfaceSupportsErrorInfo(IID_IFahrenheit));
			ComPtr<IErrorInfo> errorInfo;
			Assert::IsTrue(SUCCEEDED(::GetErrorInfo(0, &errorInfo)));
			ComPtr<IComDojoErrorInfo> comdojoErrorInfo;
			Assert::IsTrue(SUCCEEDED(errorInfo->QueryInterface<IComDojoErrorInfo>(&comdojoErrorInfo)));
			BSTR desc = nullptr;
			Assert::IsTrue(SUCCEEDED(comdojoErrorInfo->GetDescription(&desc)));
			Assert::IsTrue(0 == ::wcscmp(description, desc));
			::SysFreeString(desc);
			long _errorCode = ERROR_COMDOJO_SUCCESS;
			Assert::IsTrue(SUCCEEDED(comdojoErrorInfo->GetErrorCode(&_errorCode)));
			Assert::IsTrue(_errorCode == errorCode);
			GUID guid = { 0 };
			Assert::IsTrue(SUCCEEDED(comdojoErrorInfo->GetGUID(&guid)));
			Assert::IsTrue(IsEqualGUID(guid, iid));
			BSTR source = nullptr;
			Assert::IsTrue(SUCCEEDED(comdojoErrorInfo->GetSource(&source)));
			Assert::IsTrue(0 == ::_wcsicmp(source, src));
			::SysFreeString(source);
		}
	};
}