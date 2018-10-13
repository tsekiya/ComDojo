// GoodbyeWorld.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

//#import "DojoGreeting2.dll" rename_namespace("ComDojo")
//#import "progid:ComDojo.Greeting.2" rename_namespace("ComDojo")
#import "libid:9FC8DCBC-F451-4936-82D0-A04E7AC770DD" version("1.1") rename_namespace("ComDojo")

int main()
{
	using _com_util::ConvertBSTRToString;
	using ComDojo::ComInitializer;
	using ComDojo::Greeting2;
	using ComDojo::IGreeting2Ptr;
	using std::cerr;
	using std::cout;
	using std::endl;

	int result = S_OK;

	ComInitializer comInitializer(COINIT_APARTMENTTHREADED);

	try
	{
		IGreeting2Ptr pGreeting2;
		
		result = pGreeting2.CreateInstance(__uuidof(Greeting2));
		
		if (FAILED(result))
		{
			_com_raise_error(result);
		}
		
		_bstr_t hello = pGreeting2->SayHello();
		_bstr_t goodbye = pGreeting2->SayGoodbye();
		
		cout << (PCSTR)hello;
		cout << (PCSTR)goodbye;
	}
	catch (const _com_error& e)
	{
		result = e.Error();
		CStringA message(e.ErrorMessage());
		cerr << (PCSTR)message << endl;
	}
	return result;
}
