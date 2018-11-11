#pragma once

struct Fahrenheit : winrt::implements<::Fahrenheit, ::IFahrenheit, ::IClassFactory, ::ISupportErrorInfo>
{
	Fahrenheit() = default;
	~Fahrenheit();

	// IFahrenheit

	// 華氏を摂氏に変換
	STDMETHOD(ToCelsius)(double fahrenheit, double* celsius) noexcept override;

	// 摂氏を華氏に変換
	STDMETHOD(FromCelsius)(double celsius, double* fahrenheit) noexcept override;

	// IClassFactory

	// インスタンスを返す
	STDMETHOD(CreateInstance)(IUnknown* outer, IID const& iid, void** ppv) noexcept override;

	// COMサーバのロックをインクリメント、またはデクリメントする
	STDMETHOD(LockServer)(BOOL) noexcept override;

	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) noexcept override;

private:
	void HandleError(REFIID iid, UINT rezid, long errorCode) const noexcept;
};
