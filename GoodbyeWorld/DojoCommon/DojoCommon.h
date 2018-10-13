#pragma once

#ifdef DOJOCOMMON_EXPORTS
#define DOJO_API __declspec(dllexport)
#else
#define DOJO_API __declspec(dllimport)
#pragma comment(lib, "dojocommon")
#endif

namespace ComDojo
{
	// COMサブシステムのRAIIクラス
	class DOJO_API ComInitializer
	{
	public:
		ComInitializer(COINIT flag) throw(...);
		~ComInitializer() throw();
		operator HRESULT() const throw();

	private:
		HRESULT _hr;

	};
}