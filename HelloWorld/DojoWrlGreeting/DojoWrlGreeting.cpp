// DojoWrlGreeting.cpp : DLL �G�N�X�|�[�g�̎����ł��B


#include "stdafx.h"
#include "resource.h"
#include "DojoWrlGreeting_i.h"
#include "dllmain.h"

using Microsoft::WRL::Module;
using Microsoft::WRL::InProc;

#if !defined(__WRL_CLASSIC_COM__)
STDAPI DllGetActivationFactory(HSTRING activatibleClassId, IActivationFactory** factory)
{
	return Module<InProc>::GetModule().GetActivationFactory(activatibleClassId, factory);
}
#endif

// DLL �� OLE �ɂ���ăA�����[�h�ł���悤�ɂ��邩�ǂ������w�肵�܂��B
STDAPI DllCanUnloadNow(void)
{
	return Module<InProc>::GetModule().Terminate() ? S_OK : S_FALSE;
}

#if !defined(__WRL_WINRT_STRICT__)
// �v�����ꂽ�^�̃I�u�W�F�N�g���쐬����N���X �t�@�N�g����Ԃ��܂��B
_Check_return_
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID* ppv)
{
	return Module<InProc>::GetModule().GetClassObject(rclsid, riid, ppv);
}
#endif

// DllRegisterServer - �G���g�����V�X�e�� ���W�X�g���ɒǉ����܂��B
STDAPI DllRegisterServer(void)
{
	// �I�u�W�F�N�g�A�^�C�v ���C�u��������у^�C�v ���C�u�������̂��ׂẴC���^�[�t�F�C�X��o�^���܂�
	HRESULT hr = _AtlModule.DllRegisterServer();
		return hr;
}

// DllUnregisterServer - �G���g�����V�X�e�� ���W�X�g������폜���܂��B
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
		return hr;
}

// DllInstall - ���[�U�[����уR���s���[�^�[���Ƃ̃V�X�e�� ���W�X�g�� �G���g����ǉ��܂��͍폜���܂��B
STDAPI DllInstall(BOOL bInstall, _In_opt_  LPCWSTR pszCmdLine)
{
	HRESULT hr = E_FAIL;
	static const wchar_t szUserSwitch[] = L"user";

	if (pszCmdLine != NULL)
	{
		if (_wcsnicmp(pszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
		{
			ATL::AtlSetPerUserRegistration(true);
		}
	}

	if (bInstall)
	{	
		hr = DllRegisterServer();
		if (FAILED(hr))
		{
			DllUnregisterServer();
		}
	}
	else
	{
		hr = DllUnregisterServer();
	}

	return hr;
}


