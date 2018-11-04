#pragma once

#ifndef __UNIVERSAL_GREETING_H__
#define __UNIVERSAL_GREETING_H__

#ifdef __GREETING_API_IMPL__
#define GREETING_API extern "C" __declspec(dllexport)
#else
#define GREETING_API extern "C" __declspec(dllimport)

#endif // __GREETING_API_IMPL__


#include "Greeting.h"

GREETING_API HRESULT __stdcall CreateGreetingInstance(IGreeting** ppv);
#endif // !__UNIVERSAL_GREETING_H__
