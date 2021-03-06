// Fahrenheit.h : CFahrenheit の宣言

#pragma once
#include "resource.h"       // メイン シンボル



#include "AtlTemperature_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM の完全サポートを含んでいない Windows Mobile プラットフォームのような Windows CE プラットフォームでは、単一スレッド COM オブジェクトは正しくサポートされていません。ATL が単一スレッド COM オブジェクトの作成をサポートすること、およびその単一スレッド COM オブジェクトの実装の使用を許可することを強制するには、_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA を定義してください。ご使用の rgs ファイルのスレッド モデルは 'Free' に設定されており、DCOM Windows CE 以外のプラットフォームでサポートされる唯一のスレッド モデルと設定されていました。"
#endif

using namespace ATL;


// CFahrenheit

class ATL_NO_VTABLE CFahrenheit :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFahrenheit, &CLSID_Fahrenheit>,
	public ISupportErrorInfo,
	public IFahrenheit
{
public:
	CFahrenheit()
	{
	}

DECLARE_REGISTRY_RESOURCEID(107)


BEGIN_COM_MAP(CFahrenheit)
	COM_INTERFACE_ENTRY(IFahrenheit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) noexcept override;

	// IFahrenheit

	// 華氏を摂氏に変換
	STDMETHOD(ToCelsius)(double fahrenheit, double* celsius) noexcept override;

	// 摂氏を華氏に変換
	STDMETHOD(FromCelsius)(double celsius, double* fahrenheit) noexcept override;

private:
	void HandleError(REFIID iid, LPOLESTR description, long errorCode) const noexcept;

};

OBJECT_ENTRY_AUTO(__uuidof(Fahrenheit), CFahrenheit)
