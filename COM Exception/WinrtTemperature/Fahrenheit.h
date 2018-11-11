#pragma once

struct Fahrenheit : winrt::implements<::Fahrenheit, ::IFahrenheit, ::IClassFactory, ::ISupportErrorInfo>
{
	Fahrenheit() = default;
	~Fahrenheit();

	// IFahrenheit

	// �؎���ێ��ɕϊ�
	STDMETHOD(ToCelsius)(double fahrenheit, double* celsius) noexcept override;

	// �ێ����؎��ɕϊ�
	STDMETHOD(FromCelsius)(double celsius, double* fahrenheit) noexcept override;

	// IClassFactory

	// �C���X�^���X��Ԃ�
	STDMETHOD(CreateInstance)(IUnknown* outer, IID const& iid, void** ppv) noexcept override;

	// COM�T�[�o�̃��b�N���C���N�������g�A�܂��̓f�N�������g����
	STDMETHOD(LockServer)(BOOL) noexcept override;

	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) noexcept override;

private:
	void HandleError(REFIID iid, UINT rezid, long errorCode) const noexcept;
};
