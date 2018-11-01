#pragma once

#include "RegFreeServer_h.h"

using Microsoft::WRL::RuntimeClass;
using Microsoft::WRL::RuntimeClassFlags;
using Microsoft::WRL::ClassicCom;

class Bar : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IBar>
{
public:
	Bar();
	~Bar();
	STDMETHOD(SayHello)(HSTRING*);
};

