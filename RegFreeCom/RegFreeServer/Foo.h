#pragma once

#include "RegFreeServer_h.h"

using Microsoft::WRL::RuntimeClass;
using Microsoft::WRL::RuntimeClassFlags;
using Microsoft::WRL::ClassicCom;

class Foo : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IFoo>
{
public:
	Foo();
	~Foo();
	STDMETHOD(SayHello)(HSTRING*);
};

