#pragma once

#include "UniversalGreeting_h.h"

using namespace winrt;

#pragma warning (push)
#pragma warning (disable:4099)
struct Greeting : implements<::Greeting, ::IGreeting>
#pragma warning (pop)
{
	Greeting() = default;
	~Greeting();
	HRESULT __stdcall SayHello(HSTRING *message) noexcept override;
};
