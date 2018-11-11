#pragma once

using namespace Microsoft::WRL;

class Fahrenheit : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IFahrenheit, ISupportErrorInfo>
{
public:
	Fahrenheit();
	~Fahrenheit();

	// �؎���ێ��ɕϊ�
	STDMETHOD(ToCelsius)(double, double*)  noexcept override;

	// �ێ����؎��ɕϊ�
	STDMETHOD(FromCelsius)(double, double*)  noexcept override;

	// �C���^�[�t�F�C�X��IErrorInfo���T�|�[�g���Ă��邩�`�F�b�N����B
	// �T�|�[�g����ꍇ�AS_OK���Ԃ�B�T�|�[�g���Ȃ��ꍇ�AS_FALSE���Ԃ�B
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID iid)  noexcept override;

private:
	void HandleError(REFIID iid, UINT rezid, long errorCode) const noexcept;

};
