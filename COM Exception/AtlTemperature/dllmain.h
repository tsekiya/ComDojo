// dllmain.h : モジュール クラスの宣言です。

class CAtlTemperatureModule : public ATL::CAtlDllModuleT< CAtlTemperatureModule >
{
public :
	DECLARE_LIBID(LIBID_AtlTemperatureLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLTEMPERATURE, "{3e8841c6-a18d-4933-a21a-cbad94cefeea}")
};

extern class CAtlTemperatureModule _AtlModule;
