#include "pch.h"
#include "UniversalGreeting.h"
#include "UniversalGreeting_h.h"

using namespace winrt;

_Check_return_
STDAPI CreateGreetingInstance(_Outptr_ IGreeting** ppv)
{
	try
	{
		com_ptr<IGreeting> greeting = winrt::make<Greeting>();
		winrt::check_hresult(greeting->QueryInterface <IGreeting>(ppv));
	}
	catch (...)
	{
		return winrt::to_hresult();
	}
	return S_OK;
}

