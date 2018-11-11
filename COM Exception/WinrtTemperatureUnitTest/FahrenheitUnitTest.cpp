#include "pch.h"
#include "CppUnitTest.h"
#include "../WinrtTemperature/WinrtTemperature_h.h"
#include "../WinrtTemperature/WinrtTemperature_i.c"
#include "ComDojoError.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace winrt;

namespace WinrtTemperatureUnitTest
{		
	TEST_CLASS(Fahrenheit)
	{
	public:
		
		TEST_METHOD(ToCelsiusTestMethod)
		{
			com_ptr<IFahrenheit> fah;
			Assert::IsTrue(SUCCEEDED(CoCreateInstance(
				CLSID_Fahrenheit, nullptr, CLSCTX_ALL, IID_IFahrenheit, fah.put_void())));
			Assert::IsTrue(FAILED(fah->ToCelsius(100, nullptr)));
			this->CheckErrorInfo(
				fah.get(),
				L"摂氏のポインタがnullptrです",
				IID_IFahrenheit,
				L"{3D1C8D2F-66F3-4798-918B-BE7F363F12DC}",
				ERROR_COMDOJO_INVALID_POINTER_CELSIUS);
		}

		TEST_METHOD(FromCelsiusTestMethod)
		{
			com_ptr<IFahrenheit> fah;
			HRESULT hr = CoCreateInstance(
				CLSID_Fahrenheit, nullptr, CLSCTX_ALL, IID_IFahrenheit, fah.put_void());
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(FAILED(fah->FromCelsius(100, nullptr)));
			this->CheckErrorInfo(
				fah.get(),
				L"華氏のポインタがnullptrです",
				IID_IFahrenheit,
				L"{3D1C8D2F-66F3-4798-918B-BE7F363F12DC}",
				ERROR_COMDOJO_INVALID_POINTER_FAHRENHEIT);
		}
	private:
		void CheckErrorInfo(
			IUnknown* obj, wchar_t *description, const GUID& iid, wchar_t *src, long errorCode)
		{
			Assert::IsNotNull<IUnknown>(obj);
			com_ptr<ISupportErrorInfo> supportErrorInfo;
			HRESULT hr = obj->QueryInterface<ISupportErrorInfo>(supportErrorInfo.put());
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(supportErrorInfo != nullptr);
			hr = supportErrorInfo->InterfaceSupportsErrorInfo(IID_IFahrenheit);
			Assert::IsTrue(S_OK == hr);
			com_ptr<IErrorInfo> errorInfo;
			hr = ::GetErrorInfo(0, errorInfo.put());
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(errorInfo != nullptr);
			com_ptr<IComDojoErrorInfo> comDojoErrorInfo = errorInfo.as<IComDojoErrorInfo>();
			Assert::IsTrue(comDojoErrorInfo != nullptr);
			BSTR desc;
			hr = comDojoErrorInfo->GetDescription(&desc);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue((0 == ::wcscmp(desc, description)));
			::SysFreeString(desc);
			GUID guid = { 0 };
			hr = comDojoErrorInfo->GetGUID(&guid);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(::IsEqualGUID(guid, iid));
			BSTR source;
			hr = comDojoErrorInfo->GetSource(&source);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::IsTrue(0 == ::_wcsicmp(source, src));
			::SysFreeString(source);
			long comDojoErrorCode = 0;
			hr = comDojoErrorInfo->GetErrorCode(&comDojoErrorCode);
			Assert::IsTrue(SUCCEEDED(hr));
			Assert::AreEqual<long>(comDojoErrorCode, errorCode);
		}

	};
}