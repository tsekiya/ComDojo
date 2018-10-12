// Greeting2.h : CGreeting2 の宣言

#pragma once
#include "resource.h"       // メイン シンボル



#include "DojoGreeting2_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM の完全サポートを含んでいない Windows Mobile プラットフォームのような Windows CE プラットフォームでは、単一スレッド COM オブジェクトは正しくサポートされていません。ATL が単一スレッド COM オブジェクトの作成をサポートすること、およびその単一スレッド COM オブジェクトの実装の使用を許可することを強制するには、_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA を定義してください。ご使用の rgs ファイルのスレッド モデルは 'Free' に設定されており、DCOM Windows CE 以外のプラットフォームでサポートされる唯一のスレッド モデルと設定されていました。"
#endif

using namespace ATL;


// CGreeting2

class ATL_NO_VTABLE CGreeting2 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGreeting2, &CLSID_Greeting2>,
	public IDispatchImpl<IGreeting2, &IID_IGreeting2, &LIBID_DojoGreeting2Lib, /*wMajor =*/ 1, /*wMinor =*/ 1>
{
public:
	CGreeting2()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GREETING2)


BEGIN_COM_MAP(CGreeting2)
	COM_INTERFACE_ENTRY(IGreeting2)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IGreeting)
	COM_INTERFACE_ENTRY(IUnknown)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return this->_spGreeting.CoCreateInstance(__uuidof(Greeting));
	}

	void FinalRelease()
	{
		this->_spGreeting.Release();
	}

public:
	STDMETHOD(SayHello)(BSTR* pBstr);
	STDMETHOD(SayGoodbye)(BSTR* pBstr);

private:
	CComPtr<IGreeting> _spGreeting;
};

OBJECT_ENTRY_AUTO(__uuidof(Greeting2), CGreeting2)
