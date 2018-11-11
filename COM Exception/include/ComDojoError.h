#pragma once

#ifndef __COMDOJO_ERROR_H__
#define __COMDOJO_ERROR_H__

#define ERROR_COMDOJO_SUCCESS						0L
#define ERROR_COMDOJO_UNKNOWN						-1L
#define ERROR_COMDOJO_INVALID_POINTER_CELSIUS		-2L
#define ERROR_COMDOJO_INVALID_POINTER_FAHRENHEIT	-3L

#define FAILEDEX(hr) if(hr < 0){throw hr;}

#endif // !__COMDOJO_ERROR_H__

