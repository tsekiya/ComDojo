#pragma once

struct ComDojoErrorInfo : winrt::implements<::ComDojoErrorInfo, ::IComDojoErrorInfo, ::ICreateComDojoErrorInfo, ::IClassFactory, ::IErrorInfo>
{
	ComDojoErrorInfo() = default;
	~ComDojoErrorInfo();
	// ICreateErrorInfo

	// エラーが発生したIIDを設定
	STDMETHOD(SetGUID)(/* [in] */  REFGUID rguid) noexcept ;

	// エラーが発生したCLSIDを設定
	STDMETHOD(SetSource)(/* [in] */  LPOLESTR szSource) noexcept ;

	// エラーの詳細
	STDMETHOD(SetDescription)(/* [in] */  LPOLESTR szDescription) noexcept ;

	// ヘルプファイルへのパス
	STDMETHOD(SetHelpFile)(/* [in] */  LPOLESTR szHelpFile) noexcept ;

	// ヘルプのコンテキスト
	STDMETHOD(SetHelpContext)(/* [in] */ DWORD dwHelpContext) noexcept ;


	// IErrorInfo

	// エラーが発生したIIDを取得
	STDMETHOD(GetGUID)(/* [out] */  GUID *pGUID) noexcept ;

	// エラーが発生したCLSIDを取得
	STDMETHOD(GetSource)(/* [out] */  BSTR *pBstrSource) noexcept ;

	// エラーの詳細
	STDMETHOD(GetDescription)(/* [out] */  BSTR *pBstrDescription) noexcept ;

	// ヘルプファイルへのパス
	STDMETHOD(GetHelpFile)(/* [out] */  BSTR *pBstrHelpFile) noexcept ;

	// ヘルプのコンテキスト
	STDMETHOD(GetHelpContext)(/* [out] */  DWORD *pdwHelpContext) noexcept ;

	// IComDojoErrorInfo

	// エラーコードを取得する
	STDMETHOD(GetErrorCode)(long* errorCode) noexcept ;

	// ICreateComDojoErrorInfo

	// エラーコードを取得する
	STDMETHOD(SetErrorCode)(long errorCode) noexcept ;

	// IClassFactory

	// インスタンスを返す
	STDMETHOD(CreateInstance)(IUnknown* outer, IID const& iid, void** ppv) noexcept ;

	// COMサーバのロックをインクリメント、またはデクリメントする
	STDMETHOD(LockServer)(BOOL lock) noexcept ;

private:
	GUID _iid;
	std::wstring _source;
	std::wstring _description;
	long _errorCode;
};
