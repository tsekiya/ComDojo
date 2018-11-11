#pragma once

using namespace Microsoft::WRL;

class ComDojoErrorInfo : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IComDojoErrorInfo, ICreateComDojoErrorInfo, ICreateErrorInfo, IErrorInfo>
{
public:
	ComDojoErrorInfo();
	~ComDojoErrorInfo();

	// ICreateErrorInfo

	// �G���[����������IID��ݒ�
	STDMETHOD(SetGUID)(/* [in] */  REFGUID rguid) noexcept override;

	// �G���[����������CLSID��ݒ�
	STDMETHOD(SetSource)(/* [in] */  LPOLESTR szSource) noexcept override;

	// �G���[�̏ڍ�
	STDMETHOD(SetDescription)(/* [in] */  LPOLESTR szDescription) noexcept override;

	// �w���v�t�@�C���ւ̃p�X
	STDMETHOD(SetHelpFile)(/* [in] */  LPOLESTR szHelpFile) noexcept override;

	// �w���v�̃R���e�L�X�g
	STDMETHOD(SetHelpContext)(/* [in] */ DWORD dwHelpContext) noexcept override;


	// IErrorInfo

	// �G���[����������IID���擾
	STDMETHOD(GetGUID)(/* [out] */  GUID *pGUID) noexcept override;

	// �G���[����������CLSID���擾
	STDMETHOD(GetSource)(/* [out] */  BSTR *pBstrSource) noexcept override;

	// �G���[�̏ڍ�
	STDMETHOD(GetDescription)(/* [out] */  BSTR *pBstrDescription) noexcept override;

	// �w���v�t�@�C���ւ̃p�X
	STDMETHOD(GetHelpFile)(/* [out] */  BSTR *pBstrHelpFile) noexcept override;

	// �w���v�̃R���e�L�X�g
	STDMETHOD(GetHelpContext)(/* [out] */  DWORD *pdwHelpContext) noexcept override;

	// IComDojoErrorInfo

	// �G���[�R�[�h���擾����
	STDMETHOD(GetErrorCode)(long* errorCode) noexcept override;

	// ICreateComDojoErrorInfo

	// �G���[�R�[�h���擾����
	STDMETHOD(SetErrorCode)(long errorCode) noexcept override;

private:
	GUID _iid;
	std::wstring _source;
	std::wstring _description;
	long _errorCode;

};