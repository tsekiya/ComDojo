#pragma once

using Microsoft::WRL::RuntimeClass;
using Microsoft::WRL::RuntimeClassFlags;
using Microsoft::WRL::ClassicCom;

#include "DojoWrlGreeting_i.h"

class WrlGreeting : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IWrlGreeting>
{
public:
	WrlGreeting();
	~WrlGreeting();
	STDMETHOD(SayHello)(HSTRING* message);
};
