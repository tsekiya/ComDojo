

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IFoo,0x4416CC51,0x9E6F,0x4314,0x85,0x74,0xAA,0xD6,0x21,0x00,0x05,0xDE);


MIDL_DEFINE_GUID(IID, IID_IBar,0x985D91D2,0xD68C,0x4EBC,0xB5,0x26,0x91,0x60,0xE5,0x82,0x9C,0x9B);


MIDL_DEFINE_GUID(IID, LIBID_RegFreeComLib,0xEBDC1200,0xF062,0x4BBE,0x9B,0x12,0xA3,0xC2,0xD8,0x0D,0x2C,0x8C);


MIDL_DEFINE_GUID(CLSID, CLSID_Foo,0xBDDB5854,0x7D43,0x4AFA,0xA2,0x83,0x1B,0xA0,0x0B,0x5B,0x95,0x1C);


MIDL_DEFINE_GUID(CLSID, CLSID_Bar,0x96055C32,0x2967,0x4C89,0x98,0x9C,0xBA,0x09,0x9F,0x1A,0xD2,0x82);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



