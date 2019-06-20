/* iig(DriverKit-54.0.0.111.1) generated from IOUSBHostPipe.iig */

/* IOUSBHostPipe.iig:1-66 */
#ifndef _IOKIT_IOUSBHOSTPIPE_H
#define _IOKIT_IOUSBHOSTPIPE_H

#include <USBDriverKit/AppleUSBDefinitions.h>
#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IOMemoryDescriptor.h>  /* .iig include */ 

/*!
 * @struct      StandardUSBDescriptors
 * @brief       Encapsulates descriptors for a single endpoint
 * @discussion  The StandardUSBDescriptors struct is used to intialize and adjust pipes in the system.  The bcdUSB member
 *              must be initialized to the USB revision supported by the device.  Acceptable values are 0x0110, 0x0200, 0x0300, 0x0310.
 *              The descriptor member must always be initialized with a pointer to a valid endpoint descriptor.
 *              The ssCompanionDescriptor and sspCompanionDescriptor members may be required for bcdUSB versions 0x0300 and greater,
 *              depending on device operating speed and values set in the descriptors.  See USB 3.1 § 9.5 for more information
 *              on when these descriptors may be required.
 */
struct IOUSBStandardEndpointDescriptors
{
    uint16_t                                                  bcdUSB;
    IOUSBEndpointDescriptor                                   descriptor;
    IOUSBSuperSpeedEndpointCompanionDescriptor                ssCompanionDescriptor;
    IOUSBSuperSpeedPlusIsochronousEndpointCompanionDescriptor sspCompanionDescriptor;
};


/*!
 * @brief Options for <code>GetDescriptors</code>
 *
 * @constant kIOUSBGetEndpointDescriptorOriginal - Original descriptor used when creating the pipe
 * @constant kIOUSBGetEndpointDescriptorCurrentPolicy - Descriptor controlling the current endpoint policy,
 *              including changes made via the <code>AdjustPipe</code> method.
 */
enum IOUSBGetEndpointDescriptorOptions
{
    kIOUSBGetEndpointDescriptorOriginal = 0,
    kIOUSBGetEndpointDescriptorCurrentPolicy
};


/*!
 * @struct      IOUSBIsochronousFrame
 * @discussion  Structure representing a single frame in an isochronous transfer.
 * @field       status Completion status for this individual frame.  IOUSBHostFamily will initialize this to kIOReturnInvalid and will update the field with a valid status code upon completion of the frame.
 * @field       requestCount The number of bytes requested to transfer for this frame.  This field must be initialized by the caller before this structure is submitted to IOUSBHostFamily.
 * @field       completeCount The number of bytes actually transferred for this frame.  IOUSBHostFamily will update this field upon completion of the frame.
 * @field       timeStamp The observed AbsoluteTime for this frame's completion.  Note that interrupt latency and system load may result in more than one frame completing with the same timestamp.
 */
struct IOUSBIsochronousFrame
{
    IOReturn     status;
    uint32_t     requestCount;
    uint32_t     completeCount;
    uint64_t     timeStamp;
};
typedef struct IOUSBIsochronousFrame IOUSBIsochronousFrame;

/*!
@iig implementation
#if KERNEL
#include <IOKit/usb/IOUSBHostPipe.h>
#include <IOKit/usb/IOUSBHostIOSource.h>
#endif
@iig end
*/

/* class IOUSBHostPipe IOUSBHostPipe.iig:67-299 */

#define IOUSBHostPipe__IsochIO_ID            0xa142355f3ade7c4fULL
#define IOUSBHostPipe_GetSpeed_ID            0xe1fe37db83c583acULL
#define IOUSBHostPipe_GetDeviceAddress_ID            0x87ac5eade26f9ccaULL
#define IOUSBHostPipe_Abort_ID            0xef24b2fbd2882133ULL
#define IOUSBHostPipe_AdjustPipe_ID            0xdcaaa80dbed30817ULL
#define IOUSBHostPipe_GetDescriptors_ID            0xce8972691e0c689fULL
#define IOUSBHostPipe_SetIdlePolicy_ID            0x9aeab42e58e7bf62ULL
#define IOUSBHostPipe_GetIdlePolicy_ID            0xd980a0f13532038dULL
#define IOUSBHostPipe_ClearStall_ID            0x9d34b4ab73444133ULL
#define IOUSBHostPipe_CompleteAsyncIO_ID            0xc320a3eea932c04aULL
#define IOUSBHostPipe_AsyncIO_ID            0xe566bead3d13d7e0ULL
#define IOUSBHostPipe_IO_ID            0x825d3f5b7ac4351eULL
#define IOUSBHostPipe_CompleteAsyncIsochIO_ID            0xd6c5e31fcec49c24ULL
#define IOUSBHostPipe_CreateMemoryDescriptorRing_ID            0x96299f8363f330f3ULL
#define IOUSBHostPipe_SetMemoryDescriptor_ID            0xe0ce30d41957b747ULL
#define IOUSBHostPipe_AsyncIOBundled_ID            0xa67fb499d6f65f30ULL
#define IOUSBHostPipe_CompleteAsyncIOBundled_ID            0xdd0623caa00a3c04ULL

#define IOUSBHostPipe__IsochIO_Args \
        IOMemoryDescriptor * dataBuffer, \
        IOMemoryDescriptor * frameList, \
        uint64_t firstFrameNumber, \
        uintptr_t frameListAddress, \
        OSAction * completion

#define IOUSBHostPipe_GetSpeed_Args \
        uint8_t * speed

#define IOUSBHostPipe_GetDeviceAddress_Args \
        uint8_t * address

#define IOUSBHostPipe_Abort_Args \
        IOOptionBits options, \
        kern_return_t withError, \
        IOService * forClient

#define IOUSBHostPipe_AdjustPipe_Args \
        const IOUSBStandardEndpointDescriptors * descriptors

#define IOUSBHostPipe_GetDescriptors_Args \
        IOUSBStandardEndpointDescriptors * descriptors, \
        IOUSBGetEndpointDescriptorOptions type

#define IOUSBHostPipe_SetIdlePolicy_Args \
        uint32_t idleTimeoutMs

#define IOUSBHostPipe_GetIdlePolicy_Args \
        uint32_t * idleTimeoutMS

#define IOUSBHostPipe_ClearStall_Args \
        bool withRequest

#define IOUSBHostPipe_CompleteAsyncIO_Args \
        OSAction * action, \
        IOReturn status, \
        uint32_t actualByteCount, \
        uint64_t completionTimestamp

#define IOUSBHostPipe_AsyncIO_Args \
        IOMemoryDescriptor * dataBuffer, \
        uint32_t dataBufferLength, \
        OSAction * completion, \
        uint32_t completionTimeoutMs

#define IOUSBHostPipe_IO_Args \
        IOMemoryDescriptor * dataBuffer, \
        uint32_t dataBufferLength, \
        uint32_t * bytesTransferred, \
        uint32_t completionTimeoutMs

#define IOUSBHostPipe_CompleteAsyncIsochIO_Args \
        OSAction * action, \
        IOReturn status, \
        const IOUSBIsochronousFrame * frameList

#define IOUSBHostPipe_CreateMemoryDescriptorRing_Args \
        uint32_t size

#define IOUSBHostPipe_SetMemoryDescriptor_Args \
        IOMemoryDescriptor * memoryDescriptor, \
        uint32_t index

#define IOUSBHostPipe_AsyncIOBundled_Args \
        uint32_t ioTransferIndex, \
        uint32_t ioTransferCount, \
        uint32_t * ioTransferAcceptedCount, \
        const unsigned int * dataBufferLengthArray, \
        int dataBufferLengthArrayCount, \
        OSAction * completion, \
        uint32_t completionTimeoutMs

#define IOUSBHostPipe_CompleteAsyncIOBundled_Args \
        OSAction * action, \
        uint32_t ioCompletionIndex, \
        uint32_t ioCompletionCount, \
        const unsigned int * actualByteCountArray, \
        int actualByteCountArrayCount, \
        const int * statusArray, \
        int statusArrayCount

#define IOUSBHostPipe_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUSBHostPipe * self, const IORPC rpc);\
\
    kern_return_t\
    _IsochIO(\
        IOMemoryDescriptor * dataBuffer,\
        IOMemoryDescriptor * frameList,\
        uint64_t firstFrameNumber,\
        uintptr_t frameListAddress,\
        OSAction * completion,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetSpeed(\
        uint8_t * speed,\
        OSDispatchMethod supermethod = NULL) const;\
\
    kern_return_t\
    GetDeviceAddress(\
        uint8_t * address,\
        OSDispatchMethod supermethod = NULL) const;\
\
    kern_return_t\
    Abort(\
        IOOptionBits options,\
        kern_return_t withError,\
        IOService * forClient,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    AdjustPipe(\
        const IOUSBStandardEndpointDescriptors * descriptors,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetDescriptors(\
        IOUSBStandardEndpointDescriptors * descriptors,\
        IOUSBGetEndpointDescriptorOptions type,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetIdlePolicy(\
        uint32_t idleTimeoutMs,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    GetIdlePolicy(\
        uint32_t * idleTimeoutMS,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    ClearStall(\
        bool withRequest,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    CompleteAsyncIO(\
        OSAction * action,\
        IOReturn status,\
        uint32_t actualByteCount,\
        uint64_t completionTimestamp,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    AsyncIO(\
        IOMemoryDescriptor * dataBuffer,\
        uint32_t dataBufferLength,\
        OSAction * completion,\
        uint32_t completionTimeoutMs,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    IO(\
        IOMemoryDescriptor * dataBuffer,\
        uint32_t dataBufferLength,\
        uint32_t * bytesTransferred,\
        uint32_t completionTimeoutMs,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    CompleteAsyncIsochIO(\
        OSAction * action,\
        IOReturn status,\
        const IOUSBIsochronousFrame * frameList,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    CreateMemoryDescriptorRing(\
        uint32_t size,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetMemoryDescriptor(\
        IOMemoryDescriptor * memoryDescriptor,\
        uint32_t index,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    AsyncIOBundled(\
        uint32_t ioTransferIndex,\
        uint32_t ioTransferCount,\
        uint32_t * ioTransferAcceptedCount,\
        const unsigned int * dataBufferLengthArray,\
        int dataBufferLengthArrayCount,\
        OSAction * completion,\
        uint32_t completionTimeoutMs,\
        OSDispatchMethod supermethod = NULL);\
\
    void\
    CompleteAsyncIOBundled(\
        OSAction * action,\
        uint32_t ioCompletionIndex,\
        uint32_t ioCompletionCount,\
        const unsigned int * actualByteCountArray,\
        int actualByteCountArrayCount,\
        const int * statusArray,\
        int statusArrayCount,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    _IsochIO_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe__IsochIO_Args));\
\
    kern_return_t\
    GetSpeed_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_GetSpeed_Args));\
\
    kern_return_t\
    GetDeviceAddress_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_GetDeviceAddress_Args));\
\
    kern_return_t\
    Abort_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_Abort_Args));\
\
    kern_return_t\
    AdjustPipe_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_AdjustPipe_Args));\
\
    kern_return_t\
    GetDescriptors_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_GetDescriptors_Args));\
\
    kern_return_t\
    SetIdlePolicy_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_SetIdlePolicy_Args));\
\
    kern_return_t\
    GetIdlePolicy_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_GetIdlePolicy_Args));\
\
    kern_return_t\
    ClearStall_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_ClearStall_Args));\
\
    kern_return_t\
    CompleteAsyncIO_Invoke(const IORPC rpc,\
        void (IOUSBHostPipe::*func)(IOUSBHostPipe_CompleteAsyncIO_Args));\
\
    kern_return_t\
    AsyncIO_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_AsyncIO_Args));\
\
    kern_return_t\
    IO_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_IO_Args));\
\
    kern_return_t\
    CompleteAsyncIsochIO_Invoke(const IORPC rpc,\
        void (IOUSBHostPipe::*func)(IOUSBHostPipe_CompleteAsyncIsochIO_Args));\
\
    kern_return_t\
    CreateMemoryDescriptorRing_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_CreateMemoryDescriptorRing_Args));\
\
    kern_return_t\
    SetMemoryDescriptor_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_SetMemoryDescriptor_Args));\
\
    kern_return_t\
    AsyncIOBundled_Invoke(const IORPC rpc,\
        kern_return_t (IOUSBHostPipe::*func)(IOUSBHostPipe_AsyncIOBundled_Args));\
\
    kern_return_t\
    CompleteAsyncIOBundled_Invoke(const IORPC rpc,\
        void (IOUSBHostPipe::*func)(IOUSBHostPipe_CompleteAsyncIOBundled_Args));\
\


#define IOUSBHostPipe_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    _IsochIO_Impl(IOUSBHostPipe__IsochIO_Args);\
\
    kern_return_t\
    GetSpeed_Impl(IOUSBHostPipe_GetSpeed_Args);\
\
    kern_return_t\
    GetDeviceAddress_Impl(IOUSBHostPipe_GetDeviceAddress_Args);\
\
    kern_return_t\
    Abort_Impl(IOUSBHostPipe_Abort_Args);\
\
    kern_return_t\
    AdjustPipe_Impl(IOUSBHostPipe_AdjustPipe_Args);\
\
    kern_return_t\
    GetDescriptors_Impl(IOUSBHostPipe_GetDescriptors_Args);\
\
    kern_return_t\
    SetIdlePolicy_Impl(IOUSBHostPipe_SetIdlePolicy_Args);\
\
    kern_return_t\
    GetIdlePolicy_Impl(IOUSBHostPipe_GetIdlePolicy_Args);\
\
    kern_return_t\
    ClearStall_Impl(IOUSBHostPipe_ClearStall_Args);\
\
    kern_return_t\
    AsyncIO_Impl(IOUSBHostPipe_AsyncIO_Args);\
\
    kern_return_t\
    IO_Impl(IOUSBHostPipe_IO_Args);\
\
    kern_return_t\
    CreateMemoryDescriptorRing_Impl(IOUSBHostPipe_CreateMemoryDescriptorRing_Args);\
\
    kern_return_t\
    SetMemoryDescriptor_Impl(IOUSBHostPipe_SetMemoryDescriptor_Args);\
\
    kern_return_t\
    AsyncIOBundled_Impl(IOUSBHostPipe_AsyncIOBundled_Args);\
\


#define IOUSBHostPipe_VirtualMethods \
\
public:\
\
    virtual kern_return_t\
    IsochIO(\
        IOMemoryDescriptor * dataBuffer,\
        IOUSBIsochronousFrame * frameList,\
        uint32_t frameListCount,\
        uint64_t firstFrameNumber,\
        OSAction * completion) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOUSBHostPipeMetaClass;
extern OSClassLoadInformation IOUSBHostPipe_Class;

class IOUSBHostPipeMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUSBHostPipeInterface : public OSInterface
{
public:
    virtual kern_return_t
    IsochIO(IOMemoryDescriptor * dataBuffer,
        IOUSBIsochronousFrame * frameList,
        uint32_t frameListCount,
        uint64_t firstFrameNumber,
        OSAction * completion) = 0;

};

struct IOUSBHostPipe_IVars;
struct IOUSBHostPipe_LocalIVars;

class IOUSBHostPipe : public OSObject, public IOUSBHostPipeInterface
{
#if !KERNEL
    friend class IOUSBHostPipeMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUSBHostPipe_IVars * ivars;
        IOUSBHostPipe_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = OSObject;

#if !KERNEL
    IOUSBHostPipe_Methods
    IOUSBHostPipe_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */

/* IOUSBHostPipe.iig:301-302 */


/* IOUSBHostPipe.iig:313- */

#endif /* ! _IOKIT_IOUSBHOSTPIPE_H */

