// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"
#include "WinrtTemperature_h.h"
#include "WinrtTemperature_i.c"
#include "ComDojoError.h"
#include "ComDojoErrorInfo.h"
#include "Fahrenheit.h"

using namespace winrt;
using namespace Microsoft::WRL;

HMODULE g_hModule;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		g_hModule = hModule;
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// DLL を OLE によってアンロードできるようにするかどうかを指定します。
STDAPI DllCanUnloadNow(void)
{
#ifdef _WRL_MODULE_H_
	if (!Module<InProc>::GetModule().Terminate())
	{
		return S_FALSE;
	}
#endif

	if (winrt::get_module_lock())
	{
		return S_FALSE;
	}
	winrt::clear_factory_cache();
	return S_OK;
}

// 要求された型のオブジェクトを作成するクラス ファクトリを返します。
_Check_return_
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID* ppv)
{
	try
	{
		*ppv = nullptr;

		if (::IsEqualCLSID(rclsid, CLSID_Fahrenheit))
		{
			FAILEDEX(winrt::make<Fahrenheit>()->QueryInterface(riid, ppv));
			return S_OK;
		}
		else if (::IsEqualCLSID(rclsid, CLSID_ComDojoErrorInfo))
		{
			FAILEDEX(winrt::make<ComDojoErrorInfo>()->QueryInterface(riid, ppv));
			return S_OK;
		}
#ifdef _WRL_MODULE_H_
		return Module<InProc>::GetModule().GetClassObject(rclsid, riid, ppv);
#endif // _WRL_MODULE_H_
		return winrt::hresult_class_not_available().to_abi();
	}
	catch (HRESULT hr)
	{
		return hr;
	}
	catch (...)
	{
		return winrt::to_hresult();
	}
}
