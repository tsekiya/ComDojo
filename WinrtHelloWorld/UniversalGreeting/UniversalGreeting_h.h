

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for E:\Users\takeshi\Documents\Visual Studio 2015\Projects\ComDojo\WinrtHelloWorld\UniversalGreeting\UniversalGreeting.idl:
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

#ifndef __UniversalGreeting_h_h__
#define __UniversalGreeting_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(__cplusplus)
#if defined(__MIDL_USE_C_ENUM)
#define MIDL_ENUM enum
#else
#define MIDL_ENUM enum class
#endif
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


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "hstring.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IGreeting_INTERFACE_DEFINED__
#define __IGreeting_INTERFACE_DEFINED__

/* interface IGreeting */
/* [unique][nonextensible][uuid][object] */ 


EXTERN_C const IID IID_IGreeting;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2CEAE5F4-2AE3-4676-9C84-384B51208727")
    IGreeting : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SayHello( 
            /* [retval][out] */ HSTRING *message) = 0;
        
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
        
        HRESULT ( STDMETHODCALLTYPE *SayHello )( 
            IGreeting * This,
            /* [retval][out] */ HSTRING *message);
        
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


#define IGreeting_SayHello(This,message)	\
    ( (This)->lpVtbl -> SayHello(This,message) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGreeting_INTERFACE_DEFINED__ */



#ifndef __UniversalGreetingLib_LIBRARY_DEFINED__
#define __UniversalGreetingLib_LIBRARY_DEFINED__

/* library UniversalGreetingLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_UniversalGreetingLib;

EXTERN_C const CLSID CLSID_Greeting;

#ifdef __cplusplus

class DECLSPEC_UUID("4369B9BC-0F4E-4645-9E83-0B3B18B47DE2")
Greeting;
#endif
#endif /* __UniversalGreetingLib_LIBRARY_DEFINED__ */

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


