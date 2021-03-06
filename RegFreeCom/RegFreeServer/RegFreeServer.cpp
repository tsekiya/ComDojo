// RegFreeServer.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

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
