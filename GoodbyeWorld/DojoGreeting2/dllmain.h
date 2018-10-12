// dllmain.h : モジュール クラスの宣言です。

class CDojoGreeting2Module : public ATL::CAtlDllModuleT< CDojoGreeting2Module >
{
public :
	DECLARE_LIBID(LIBID_DojoGreeting2Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DOJOGREETING2, "{897925C4-455F-4B72-9296-7FA4B9CF4C5E}")
};

extern class CDojoGreeting2Module _AtlModule;
