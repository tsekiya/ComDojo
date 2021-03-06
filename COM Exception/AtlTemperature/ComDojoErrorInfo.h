// ComDojoErrorInfo.h : CComDojoErrorInfo の宣言

#pragma once
#include "resource.h"       // メイン シンボル



#include "AtlTemperature_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM の完全サポートを含んでいない Windows Mobile プラットフォームのような Windows CE プラットフォームでは、単一スレッド COM オブジェクトは正しくサポートされていません。ATL が単一スレッド COM オブジェクトの作成をサポートすること、およびその単一スレッド COM オブジェクトの実装の使用を許可することを強制するには、_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA を定義してください。ご使用の rgs ファイルのスレッド モデルは 'Free' に設定されており、DCOM Windows CE 以外のプラットフォームでサポートされる唯一のスレッド モデルと設定されていました。"
#endif

using namespace ATL;


// CComDojoErrorInfo

class ATL_NO_VTABLE CComDojoErrorInfo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CComDojoErrorInfo, &CLSID_ComDojoErrorInfo>,
	public IComDojoErrorInfo,
	ICreateComDojoErrorInfo
{
public:
	CComDojoErrorInfo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CComDojoErrorInfo)
	COM_INTERFACE_ENTRY(IComDojoErrorInfo)
	COM_INTERFACE_ENTRY(IErrorInfo)
	COM_INTERFACE_ENTRY(ICreateComDojoErrorInfo)
	COM_INTERFACE_ENTRY(ICreateErrorInfo)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		this->_iid = { 0 };
		this->_errorCode = 0;
		return S_OK;
	}

	void FinalRelease()
	{
	}

	// ICreateErrorInfo

	// エラーが発生したIIDを設定
	STDMETHOD(SetGUID)(/* [in] */  REFGUID rguid) noexcept override;

	// エラーが発生したCLSIDを設定
	STDMETHOD(SetSource)(/* [in] */  LPOLESTR szSource) noexcept override;

	// エラーの詳細
	STDMETHOD(SetDescription)(/* [in] */  LPOLESTR szDescription) noexcept override;

	// ヘルプファイルへのパス
	STDMETHOD(SetHelpFile)(/* [in] */  LPOLESTR szHelpFile) noexcept override;

	// ヘルプのコンテキスト
	STDMETHOD(SetHelpContext)(/* [in] */ DWORD dwHelpContext) noexcept override;


	// IErrorInfo

	// エラーが発生したIIDを取得
	STDMETHOD(GetGUID)(/* [out] */  GUID *pGUID) noexcept override;

	// エラーが発生したCLSIDを取得
	STDMETHOD(GetSource)(/* [out] */  BSTR *pBstrSource) noexcept override;

	// エラーの詳細
	STDMETHOD(GetDescription)(/* [out] */  BSTR *pBstrDescription) noexcept override;

	// ヘルプファイルへのパス
	STDMETHOD(GetHelpFile)(/* [out] */  BSTR *pBstrHelpFile) noexcept override;

	// ヘルプのコンテキスト
	STDMETHOD(GetHelpContext)(/* [out] */  DWORD *pdwHelpContext) noexcept override;

	// IComDojoErrorInfo

	// エラーコードを取得する
	STDMETHOD(GetErrorCode)(long* errorCode) noexcept override;

	// ICreateComDojoErrorInfo

	// エラーコードを取得する
	STDMETHOD(SetErrorCode)(long errorCode) noexcept override;

private:
	GUID _iid;
	CString _source;
	CString _description;
	long _errorCode;
};

OBJECT_ENTRY_AUTO(__uuidof(ComDojoErrorInfo), CComDojoErrorInfo)
