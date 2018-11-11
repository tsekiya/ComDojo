#pragma once

struct ComDojoErrorInfo : winrt::implements<::ComDojoErrorInfo, ::IComDojoErrorInfo, ::ICreateComDojoErrorInfo, ::IClassFactory, ::IErrorInfo>
{
	ComDojoErrorInfo() = default;
	~ComDojoErrorInfo();
	// ICreateErrorInfo

	// �G���[����������IID��ݒ�
	STDMETHOD(SetGUID)(/* [in] */  REFGUID rguid) noexcept ;

	// �G���[����������CLSID��ݒ�
	STDMETHOD(SetSource)(/* [in] */  LPOLESTR szSource) noexcept ;

	// �G���[�̏ڍ�
	STDMETHOD(SetDescription)(/* [in] */  LPOLESTR szDescription) noexcept ;

	// �w���v�t�@�C���ւ̃p�X
	STDMETHOD(SetHelpFile)(/* [in] */  LPOLESTR szHelpFile) noexcept ;

	// �w���v�̃R���e�L�X�g
	STDMETHOD(SetHelpContext)(/* [in] */ DWORD dwHelpContext) noexcept ;


	// IErrorInfo

	// �G���[����������IID���擾
	STDMETHOD(GetGUID)(/* [out] */  GUID *pGUID) noexcept ;

	// �G���[����������CLSID���擾
	STDMETHOD(GetSource)(/* [out] */  BSTR *pBstrSource) noexcept ;

	// �G���[�̏ڍ�
	STDMETHOD(GetDescription)(/* [out] */  BSTR *pBstrDescription) noexcept ;

	// �w���v�t�@�C���ւ̃p�X
	STDMETHOD(GetHelpFile)(/* [out] */  BSTR *pBstrHelpFile) noexcept ;

	// �w���v�̃R���e�L�X�g
	STDMETHOD(GetHelpContext)(/* [out] */  DWORD *pdwHelpContext) noexcept ;

	// IComDojoErrorInfo

	// �G���[�R�[�h���擾����
	STDMETHOD(GetErrorCode)(long* errorCode) noexcept ;

	// ICreateComDojoErrorInfo

	// �G���[�R�[�h���擾����
	STDMETHOD(SetErrorCode)(long errorCode) noexcept ;

	// IClassFactory

	// �C���X�^���X��Ԃ�
	STDMETHOD(CreateInstance)(IUnknown* outer, IID const& iid, void** ppv) noexcept ;

	// COM�T�[�o�̃��b�N���C���N�������g�A�܂��̓f�N�������g����
	STDMETHOD(LockServer)(BOOL lock) noexcept ;

private:
	GUID _iid;
	std::wstring _source;
	std::wstring _description;
	long _errorCode;
};
