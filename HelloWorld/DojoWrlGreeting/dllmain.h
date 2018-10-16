// dllmain.h : モジュール クラスの宣言です。

class CDojoWrlGreetingModule : public ATL::CAtlDllModuleT< CDojoWrlGreetingModule >
{
public :
	DECLARE_LIBID(LIBID_DojoWrlGreetingLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DOJOWRLGREETING, "{FBD98A56-1DF6-4622-9426-A991298C3943}")
};

extern class CDojoWrlGreetingModule _AtlModule;
