#include "stdafx.h"
#include "DojoCommon.h"

ComDojo::ComInitializer::ComInitializer(COINIT flag) throw(...): _hr(S_OK)
{
	this->_hr = ::CoInitializeEx(nullptr, flag);

	if (FAILED(this->_hr))
	{
		throw _com_error(this->_hr);
	}
}

ComDojo::ComInitializer::~ComInitializer() throw()
{
	if (SUCCEEDED(this->_hr))
	{
		::CoUninitialize();
	}
}

ComDojo::ComInitializer::operator HRESULT() const throw()
{
	return this->_hr;
}
