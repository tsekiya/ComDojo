// dllmain.h : モジュール クラスの宣言です。

class CDojoGreetingModule : public ATL::CAtlDllModuleT< CDojoGreetingModule >
{
public :
	DECLARE_LIBID(LIBID_DojoGreetingLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DOJOGREETING, "{B4B49B8C-6479-44E7-A161-6F702EB43BD3}")
};

extern class CDojoGreetingModule _AtlModule;
