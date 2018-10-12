

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for C:\Users\takeshi\AppData\Local\Temp\IDL9D63.tmp:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0620 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __DojoGreeting_h__
#define __DojoGreeting_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGreeting_FWD_DEFINED__
#define __IGreeting_FWD_DEFINED__
typedef interface IGreeting IGreeting;

#endif 	/* __IGreeting_FWD_DEFINED__ */


#ifndef __Greeting_FWD_DEFINED__
#define __Greeting_FWD_DEFINED__

#ifdef __cplusplus
typedef class Greeting Greeting;
#else
typedef struct Greeting Greeting;
#endif /* __cplusplus */

#endif 	/* __Greeting_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __DojoGreetingLib_LIBRARY_DEFINED__
#define __DojoGreetingLib_LIBRARY_DEFINED__

/* library DojoGreetingLib */
/* [custom][custom][custom][helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_DojoGreetingLib;

#ifndef __IGreeting_INTERFACE_DEFINED__
#define __IGreeting_INTERFACE_DEFINED__

/* interface IGreeting */
/* [object][oleautomation][nonextensible][dual][uuid] */ 


EXTERN_C const IID IID_IGreeting;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1A496C5-C96D-4487-B219-9D5700391384")
    IGreeting : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SayHello( 
            /* [retval][out] */ BSTR *pBstr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGreetingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGreeting * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGreeting * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGreeting * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGreeting * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGreeting * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGreeting * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGreeting * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SayHello )( 
            IGreeting * This,
            /* [retval][out] */ BSTR *pBstr);
        
        END_INTERFACE
    } IGreetingVtbl;

    interface IGreeting
    {
        CONST_VTBL struct IGreetingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGreeting_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGreeting_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGreeting_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGreeting_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGreeting_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGreeting_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGreeting_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGreeting_SayHello(This,pBstr)	\
    ( (This)->lpVtbl -> SayHello(This,pBstr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGreeting_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Greeting;

#ifdef __cplusplus

class DECLSPEC_UUID("A845A6FB-B1D5-4D59-AF48-5983D37B07B0")
Greeting;
#endif
#endif /* __DojoGreetingLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


