#pragma once

using namespace Microsoft::WRL;

class ComDojoErrorInfo : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IComDojoErrorInfo, ICreateComDojoErrorInfo, ICreateErrorInfo, IErrorInfo>
{
public:
	ComDojoErrorInfo();
	~ComDojoErrorInfo();

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
	std::wstring _source;
	std::wstring _description;
	long _errorCode;

};
