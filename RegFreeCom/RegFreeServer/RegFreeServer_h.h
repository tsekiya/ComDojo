

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for RegFreeServer.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __RegFreeServer_h_h__
#define __RegFreeServer_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFoo_FWD_DEFINED__
#define __IFoo_FWD_DEFINED__
typedef interface IFoo IFoo;

#endif 	/* __IFoo_FWD_DEFINED__ */


#ifndef __IBar_FWD_DEFINED__
#define __IBar_FWD_DEFINED__
typedef interface IBar IBar;

#endif 	/* __IBar_FWD_DEFINED__ */


#ifndef __Foo_FWD_DEFINED__
#define __Foo_FWD_DEFINED__

#ifdef __cplusplus
typedef class Foo Foo;
#else
typedef struct Foo Foo;
#endif /* __cplusplus */

#endif 	/* __Foo_FWD_DEFINED__ */


#ifndef __Bar_FWD_DEFINED__
#define __Bar_FWD_DEFINED__

#ifdef __cplusplus
typedef class Bar Bar;
#else
typedef struct Bar Bar;
#endif /* __cplusplus */

#endif 	/* __Bar_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "hstring.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFoo_INTERFACE_DEFINED__
#define __IFoo_INTERFACE_DEFINED__

/* interface IFoo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IFoo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4416CC51-9E6F-4314-8574-AAD6210005DE")
    IFoo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SayHello( 
            HSTRING *__MIDL__IFoo0000) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFooVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFoo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFoo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFoo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SayHello )( 
            IFoo * This,
            HSTRING *__MIDL__IFoo0000);
        
        END_INTERFACE
    } IFooVtbl;

    interface IFoo
    {
        CONST_VTBL struct IFooVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFoo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFoo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFoo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFoo_SayHello(This,__MIDL__IFoo0000)	\
    ( (This)->lpVtbl -> SayHello(This,__MIDL__IFoo0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFoo_INTERFACE_DEFINED__ */


#ifndef __IBar_INTERFACE_DEFINED__
#define __IBar_INTERFACE_DEFINED__

/* interface IBar */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("985D91D2-D68C-4EBC-B526-9160E5829C9B")
    IBar : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SayHello( 
            HSTRING *__MIDL__IBar0000) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBar * This);
        
        HRESULT ( STDMETHODCALLTYPE *SayHello )( 
            IBar * This,
            HSTRING *__MIDL__IBar0000);
        
        END_INTERFACE
    } IBarVtbl;

    interface IBar
    {
        CONST_VTBL struct IBarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBar_SayHello(This,__MIDL__IBar0000)	\
    ( (This)->lpVtbl -> SayHello(This,__MIDL__IBar0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBar_INTERFACE_DEFINED__ */



#ifndef __RegFreeComLib_LIBRARY_DEFINED__
#define __RegFreeComLib_LIBRARY_DEFINED__

/* library RegFreeComLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_RegFreeComLib;

EXTERN_C const CLSID CLSID_Foo;

#ifdef __cplusplus

class DECLSPEC_UUID("BDDB5854-7D43-4AFA-A283-1BA00B5B951C")
Foo;
#endif

EXTERN_C const CLSID CLSID_Bar;

#ifdef __cplusplus

class DECLSPEC_UUID("96055C32-2967-4C89-989C-BA099F1AD282")
Bar;
#endif
#endif /* __RegFreeComLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HSTRING_UserSize(     unsigned long *, unsigned long            , HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserMarshal(  unsigned long *, unsigned char *, HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserUnmarshal(unsigned long *, unsigned char *, HSTRING * ); 
void                      __RPC_USER  HSTRING_UserFree(     unsigned long *, HSTRING * ); 

unsigned long             __RPC_USER  HSTRING_UserSize64(     unsigned long *, unsigned long            , HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserMarshal64(  unsigned long *, unsigned char *, HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserUnmarshal64(unsigned long *, unsigned char *, HSTRING * ); 
void                      __RPC_USER  HSTRING_UserFree64(     unsigned long *, HSTRING * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


