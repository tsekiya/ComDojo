// Greeting.h : CGreeting �̐錾

#pragma once
#include "resource.h"       // ���C�� �V���{��



#include "DojoGreeting_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM �̊��S�T�|�[�g���܂�ł��Ȃ� Windows Mobile �v���b�g�t�H�[���̂悤�� Windows CE �v���b�g�t�H�[���ł́A�P��X���b�h COM �I�u�W�F�N�g�͐������T�|�[�g����Ă��܂���BATL ���P��X���b�h COM �I�u�W�F�N�g�̍쐬���T�|�[�g���邱�ƁA����т��̒P��X���b�h COM �I�u�W�F�N�g�̎����̎g�p�������邱�Ƃ���������ɂ́A_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ���`���Ă��������B���g�p�� rgs �t�@�C���̃X���b�h ���f���� 'Free' �ɐݒ肳��Ă���ADCOM Windows CE �ȊO�̃v���b�g�t�H�[���ŃT�|�[�g�����B��̃X���b�h ���f���Ɛݒ肳��Ă��܂����B"
#endif

using namespace ATL;


// CGreeting

class ATL_NO_VTABLE CGreeting :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGreeting, &CLSID_Greeting>,
	public IDispatchImpl<IGreeting, &IID_IGreeting, &LIBID_DojoGreetingLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CGreeting()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GREETING)


BEGIN_COM_MAP(CGreeting)
	COM_INTERFACE_ENTRY(IGreeting)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IUnknown)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(SayHello)(BSTR* pBstr);
};

OBJECT_ENTRY_AUTO(__uuidof(Greeting), CGreeting)
