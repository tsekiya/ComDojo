// RawHelloWorld.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "../DojoGreeting/DojoGreeting_i.h"
#include "../DojoGreeting/DojoGreeting_i.c"

int main()
{
	if (SUCCEEDED(::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED)))
	{
		// �C���^�[�t�F�C�X�|�C���^�́Anullptr�ŏ���������
		IUnknown *pUnk = nullptr;
		IUnknown *pUnk2 = nullptr;
		IDispatch *pDisp = nullptr;
		IGreeting *pGreeting = nullptr;
		
		// AddRef/Release�̃��[��2
		if (SUCCEEDED(::CoCreateInstance(CLSID_Greeting, nullptr, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk)) &&
			nullptr != pUnk)
		{
			pUnk2 = pUnk;

			// AddRef/Release�̃��[��1
			pUnk2->AddRef();
			
			// AddRef/Release�̃��[��2
			if (SUCCEEDED(pUnk2->QueryInterface(IID_IDispatch, (void**)&pDisp)) && nullptr != pDisp)
			{
				// AddRef/ReleaseRef�̃��[��2
				if (SUCCEEDED(pDisp->QueryInterface(IID_IGreeting, (void**)&pGreeting)) && nullptr != pGreeting)
				{
					BSTR bstr;

					if (SUCCEEDED(pGreeting->SayHello(&bstr)))
					{
						CStringA szHello(bstr);

						// BSTR�͌Ăяo�����ŉ������
						::SysFreeString(bstr);

						HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);

						::WriteFile(hStdOut, (PCSTR)szHello, szHello.GetLength(), nullptr, nullptr);
					}
					// AddRef/Release�̃��[��6
					pGreeting->Release();
					pGreeting = nullptr;
				}
				// AddRef/Release�̃��[��6
				pDisp->Release();
				pDisp = nullptr;
			}
			// AddRef/Release�̃��[��6
			pUnk2->Release();
			pUnk2 = nullptr;

			// AddRef/Release�̃��[��6
			pUnk->Release();
			pUnk = nullptr;
		}
		::CoUninitialize();
	}
	return 0;
}

