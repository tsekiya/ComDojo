// DojoWrlGreeting.cpp : DLL エクスポートの実装です。


#include "stdafx.h"
#include "resource.h"
#include "DojoWrlGreeting_i.h"
#include "dllmain.h"

using Microsoft::WRL::Module;
using Microsoft::WRL::InProc;

#if !defined(__WRL_CLASSIC_COM__)
STDAPI DllGetActivationFactory(HSTRING activatibleClassId, IActivationFactory** factory)
{
	return Module<InProc>::GetModule().GetActivationFactory(activatibleClassId, factory);
}
#endif

// DLL を OLE によってアンロードできるようにするかどうかを指定します。
STDAPI DllCanUnloadNow(void)
{
	return Module<InProc>::GetModule().Terminate() ? S_OK : S_FALSE;
}

#if !defined(__WRL_WINRT_STRICT__)
// 要求された型のオブジェクトを作成するクラス ファクトリを返します。
_Check_return_
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID* ppv)
{
	return Module<InProc>::GetModule().GetClassObject(rclsid, riid, ppv);
}
#endif

// DllRegisterServer - エントリをシステム レジストリに追加します。
STDAPI DllRegisterServer(void)
{
	// オブジェクト、タイプ ライブラリおよびタイプ ライブラリ内のすべてのインターフェイスを登録します
	HRESULT hr = _AtlModule.DllRegisterServer();
		return hr;
}

// DllUnregisterServer - エントリをシステム レジストリから削除します。
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
		return hr;
}

// DllInstall - ユーザーおよびコンピューターごとのシステム レジストリ エントリを追加または削除します。
STDAPI DllInstall(BOOL bInstall, _In_opt_  LPCWSTR pszCmdLine)
{
	HRESULT hr = E_FAIL;
	static const wchar_t szUserSwitch[] = L"user";

	if (pszCmdLine != NULL)
	{
		if (_wcsnicmp(pszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
		{
			ATL::AtlSetPerUserRegistration(true);
		}
	}

	if (bInstall)
	{	
		hr = DllRegisterServer();
		if (FAILED(hr))
		{
			DllUnregisterServer();
		}
	}
	else
	{
		hr = DllUnregisterServer();
	}

	return hr;
}


