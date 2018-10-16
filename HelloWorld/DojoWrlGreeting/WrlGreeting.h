#pragma once

using Microsoft::WRL::RuntimeClass;
using Microsoft::WRL::RuntimeClassFlags;
using Microsoft::WRL::ClassicCom;

#include "DojoWrlGreeting_i.h"

class WrlGreeting : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IWrlGreeting>
{
public:
	WrlGreeting();
	DECLARE_REGISTRY_RESOURCEID(IDR_WRLGREETING)
	~WrlGreeting();
	STDMETHOD(SayHello)(HSTRING* message);
};
