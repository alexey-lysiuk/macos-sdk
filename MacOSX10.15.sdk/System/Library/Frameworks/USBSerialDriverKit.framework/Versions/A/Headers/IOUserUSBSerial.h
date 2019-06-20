/* iig(DriverKit-54.0.0.110.1) generated from IOUserUSBSerial.iig */

/* IOUserUSBSerial.iig:1-18 */
//#pragma once

#ifndef _IOUSERSERIAL_IIG_
#define _IOUSERSERIAL_IIG_

#include <DriverKit/IOService.h>  /* .iig include */ 

#define kLineStatusHeaderLengthKey	"LineStatusHeaderLength"
#define usbSerialLineStatusHeaderCount	16

/*!
 @iig implementation
 #if KERNEL
 #include "IOUserUSBSerial.k.h"
 #endif
 @iig end
 */

/* class IOUserUSBSerial IOUserUSBSerial.iig:19-42 */

#define IOUserUSBSerial_SetState_ID            0x9fea840402bb9cd7ULL
#define IOUserUSBSerial_RxError_ID            0x9288a12120dac566ULL
#define IOUserUSBSerial_ProcessLineStatusHeader_ID            0xaffef06d247ef16aULL
#define IOUserUSBSerial_HwActivate_ID            0xc9346a2c4257f0bfULL
#define IOUserUSBSerial_HwResetFIFO_ID            0xa3499f48a5d5fbc4ULL
#define IOUserUSBSerial_HwSendBreak_ID            0xf62581de7aade7f4ULL
#define IOUserUSBSerial_HwResetUART_ID            0xd84f30588e9d3751ULL
#define IOUserUSBSerial_HwProgramUART_ID            0xebc9d73d9d994bdfULL
#define IOUserUSBSerial_HwProgramBaudRate_ID            0x8cd126bb781bad37ULL
#define IOUserUSBSerial_HwProgramMCR_ID            0x8579208859ed88e9ULL
#define IOUserUSBSerial_HwProgramLatencyTimer_ID            0xaa02a5a328f86629ULL
#define IOUserUSBSerial_HwProgramFlowClontrol_ID            0xbb62ad7d71b1dae8ULL

#define IOUserUSBSerial_SetState_Args \
        uint32_t state, \
        uint32_t mask

#define IOUserUSBSerial_RxError_Args \
        bool overrun, \
        bool gotBreak, \
        bool framingError, \
        bool parityError

#define IOUserUSBSerial_ProcessLineStatusHeader_Args \
        const unsigned char * usbSerialLineStatusHeader, \
        uint32_t dataLength

#define IOUserUSBSerial_HwActivate_Args \
        bool bActivate

#define IOUserUSBSerial_HwResetFIFO_Args \
        bool tx, \
        bool rx

#define IOUserUSBSerial_HwSendBreak_Args \
        bool sendBreak

#define IOUserUSBSerial_HwResetUART_Args \


#define IOUserUSBSerial_HwProgramUART_Args \
        uint32_t baudRate, \
        uint8_t nDataBits, \
        uint8_t nHalfStopBits, \
        uint8_t parity

#define IOUserUSBSerial_HwProgramBaudRate_Args \
        uint32_t baudRate

#define IOUserUSBSerial_HwProgramMCR_Args \
        bool dtr, \
        bool rts

#define IOUserUSBSerial_HwProgramLatencyTimer_Args \
        uint32_t latency

#define IOUserUSBSerial_HwProgramFlowClontrol_Args \
        uint32_t arg, \
        uint8_t xon, \
        uint8_t xoff

#define IOUserUSBSerial_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUserUSBSerial * self, const IORPC rpc);\
\
    kern_return_t\
    SetState(\
        uint32_t state,\
        uint32_t mask,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    RxError(\
        bool overrun,\
        bool gotBreak,\
        bool framingError,\
        bool parityError,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    ProcessLineStatusHeader(\
        const unsigned char * usbSerialLineStatusHeader,\
        uint32_t dataLength,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwActivate(\
        bool bActivate,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwResetFIFO(\
        bool tx,\
        bool rx,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwSendBreak(\
        bool sendBreak,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwResetUART(\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwProgramUART(\
        uint32_t baudRate,\
        uint8_t nDataBits,\
        uint8_t nHalfStopBits,\
        uint8_t parity,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwProgramBaudRate(\
        uint32_t baudRate,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwProgramMCR(\
        bool dtr,\
        bool rts,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwProgramLatencyTimer(\
        uint32_t latency,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    HwProgramFlowClontrol(\
        uint32_t arg,\
        uint8_t xon,\
        uint8_t xoff,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    ProcessLineStatusHeader_Impl(IOUserUSBSerial_ProcessLineStatusHeader_Args);\
\
    kern_return_t\
    HwActivate_Impl(IOUserUSBSerial_HwActivate_Args);\
\
    kern_return_t\
    HwResetFIFO_Impl(IOUserUSBSerial_HwResetFIFO_Args);\
\
    kern_return_t\
    HwSendBreak_Impl(IOUserUSBSerial_HwSendBreak_Args);\
\
    kern_return_t\
    HwResetUART_Impl(IOUserUSBSerial_HwResetUART_Args);\
\
    kern_return_t\
    HwProgramUART_Impl(IOUserUSBSerial_HwProgramUART_Args);\
\
    kern_return_t\
    HwProgramBaudRate_Impl(IOUserUSBSerial_HwProgramBaudRate_Args);\
\
    kern_return_t\
    HwProgramMCR_Impl(IOUserUSBSerial_HwProgramMCR_Args);\
\
    kern_return_t\
    HwProgramLatencyTimer_Impl(IOUserUSBSerial_HwProgramLatencyTimer_Args);\
\
    kern_return_t\
    HwProgramFlowClontrol_Impl(IOUserUSBSerial_HwProgramFlowClontrol_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    SetState_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_SetState_Args));\
\
    kern_return_t\
    RxError_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_RxError_Args));\
\
    kern_return_t\
    ProcessLineStatusHeader_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_ProcessLineStatusHeader_Args));\
\
    kern_return_t\
    HwActivate_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwActivate_Args));\
\
    kern_return_t\
    HwResetFIFO_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwResetFIFO_Args));\
\
    kern_return_t\
    HwSendBreak_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwSendBreak_Args));\
\
    kern_return_t\
    HwResetUART_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwResetUART_Args));\
\
    kern_return_t\
    HwProgramUART_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwProgramUART_Args));\
\
    kern_return_t\
    HwProgramBaudRate_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwProgramBaudRate_Args));\
\
    kern_return_t\
    HwProgramMCR_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwProgramMCR_Args));\
\
    kern_return_t\
    HwProgramLatencyTimer_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwProgramLatencyTimer_Args));\
\
    kern_return_t\
    HwProgramFlowClontrol_Invoke(const IORPC rpc,\
        kern_return_t (IOUserUSBSerial::*func)(IOUserUSBSerial_HwProgramFlowClontrol_Args));\
\


#define IOUserUSBSerial_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    SetState_Impl(IOUserUSBSerial_SetState_Args);\
\
    kern_return_t\
    RxError_Impl(IOUserUSBSerial_RxError_Args);\
\


#define IOUserUSBSerial_VirtualMethods \
\
public:\
\


#if !KERNEL

extern OSMetaClass          * gIOUserUSBSerialMetaClass;
extern OSClassLoadInformation IOUserUSBSerial_Class;

class IOUserUSBSerialMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUserUSBSerialInterface : public OSInterface
{
public:
};

struct IOUserUSBSerial_IVars;
struct IOUserUSBSerial_LocalIVars;

class IOUserUSBSerial : public IOService, public IOUserUSBSerialInterface
{
#if !KERNEL
    friend class IOUserUSBSerialMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUserUSBSerial_IVars * ivars;
        IOUserUSBSerial_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    IOUserUSBSerial_Methods
    IOUserUSBSerial_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOUserUSBSerial.iig:44- */
#endif // _IOUSERSERIAL_IIG_
