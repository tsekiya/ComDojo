#pragma once

using namespace Microsoft::WRL;

class Fahrenheit : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IFahrenheit, ISupportErrorInfo>
{
public:
	Fahrenheit();
	~Fahrenheit();

	// 華氏を摂氏に変換
	STDMETHOD(ToCelsius)(double, double*)  noexcept override;

	// 摂氏を華氏に変換
	STDMETHOD(FromCelsius)(double, double*)  noexcept override;

	// インターフェイスがIErrorInfoをサポートしているかチェックする。
	// サポートする場合、S_OKが返る。サポートしない場合、S_FALSEが返る。
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID iid)  noexcept override;

private:
	void HandleError(REFIID iid, UINT rezid, long errorCode) const noexcept;

};
