/* iig(DriverKit-427.120.2) generated from IOUSBHostPipe.iig */

/* IOUSBHostPipe.iig:1-100 */
/*
 * Copyright (c) 2018-2019 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _IOKIT_IOUSBHOSTPIPE_H
#define _IOKIT_IOUSBHOSTPIPE_H

#include <TargetConditionals.h>
#if TARGET_OS_DRIVERKIT
#include <USBDriverKit/AppleUSBDefinitions.h>
#else
#include <IOKit/usb/AppleUSBDefinitions.h>
#endif
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
 * @field       reserved Reserved for future use.
 * @field       timeStamp The observed AbsoluteTime for this frame's completion.  Note that interrupt latency and system load may result in more than one frame completing with the same timestamp.
 */
struct IOUSBIsochronousFrame
{
    IOReturn     status;
    uint32_t     requestCount;
    uint32_t     completeCount;
    uint32_t     reserved;
    uint64_t     timeStamp;
} __attribute__((packed));
typedef struct IOUSBIsochronousFrame IOUSBIsochronousFrame;


/*!
 * @brief Bundling Constants
 *
 * @constant kIOUSBHostPipeBundlingMax - Maximum number of transfers for AsyncIOBundled()
 */
enum{ kIOUSBHostPipeBundlingMax = 16 };

/* source class IOUSBHostPipe IOUSBHostPipe.iig:101-336 */

#if __DOCUMENTATION__
#define KERNEL IIG_KERNEL

/*!
*/

class KERNEL IOUSBHostPipe: public OSObject
{
public:
    /*!
     * @brief   Retrieve the device's operational speed
     * @param   speed uint8_t pointer to be updated with the device's speed.
     * @return  KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    GetSpeed (uint8_t *speed) const;


    /*!
     * @brief   Retrieve the device's address
     * @param   address uint8_t pointer to be updated with the device's address.
     * @return  KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    GetDeviceAddress (uint8_t *address) const;

    /*!
     * @brief       Abort pending I/O requests.
     * @discussion  This method will abort all pending I/O requests.  If <code>options</code> includes <code>kAbortSynchronous</code>, this method will block any new IO requests unless they are submitted from an aborted IO's completion routine.
     * @param       options tAbortOptions
     * @param       withError IOReturn error value to return with the requests.  The default value of kIOReturnAborted should be used.
     * @param       forClient Service for which to abort requests.  If NULL, all requests will be aborted.  Only control endpoints can specify a non-NULL value.
     * @return      IOReturn result code
     */
    virtual kern_return_t
    Abort (IOOptionBits  options,
           kern_return_t withError,
           IOService    *forClient);


    /*!
     * @brief       Adjust behavior of periodic endpoints to consume a different amount of bus bandwidth
     * @discussion  Periodic (interrupt and isochronous) endpoints reserve bus bandwidth when they are created, which takes into account
     *              max packet size, burst size, and the endpoint service interval.  If a function driver knows the endpoint will not use
     *              all of the allocated bandwidth, the <code>AdjustPipe</code> method may be used to reduce the bandwidth reserved for
     *              the endpoint.  The original endpoint descriptors should be copied and modified to adjust max packet size, mult, burst,
     *              and interval, and then passed to <code>AdjustPipe</code>.
     * @param       descriptors Pointer to a StandardUSBDescriptors structure describing the new endpoint policy
     * @return      KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    AdjustPipe (const IOUSBStandardEndpointDescriptors *descriptors);


    /*!
     * @brief   Retrieve the descriptors associated with this object
     * @param   descriptors StandardUSBDescriptors pointer to populate
     * @param   type tGetEndpointDescriptorOptions indicating which descriptors to retrieve
     * @return  KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    GetDescriptors (IOUSBStandardEndpointDescriptors *descriptors,
                    IOUSBGetEndpointDescriptorOptions type);


    /*!
     * @brief       Sets the desired idle timeout for the pipe
     * @discussion  When a bulk or interrupt pipe is actively servicing an IO request, it will be considered "busy" for idleTimeoutMs.  For a more complete discussion of idle policies, refer to "Pausing IO" in IOUSBHostFamily.h.
     * @param       idleTimeoutMs The amount of time, in milliseconds, before an active transfer is considered idle.  If 0 the pipe will not be considered idle if there is an IO request enqueued.
     * @return      KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    SetIdlePolicy (uint32_t idleTimeoutMs);

    /*!
     * @brief       Retrieve the current idle timeout for the pipe
     * @param       uint32_t pointer to be updated with the current idle timeout in milliseconds.
     * @return      KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    GetIdlePolicy (uint32_t *idleTimeoutMS);


    /*!
     * @brief       Clear the halt condition of the pipe.
     * @discussion  When a bulk or interrupt USB endpoint encounters any IO error other than a timeout, it transitions to a Halted state which must be cleared to perform additional IO on the endpoint.  This method will clear the halted condition for the endpoint, including sending a CLEAR_TT_BUFFER control request  (USB 2.0 11.24.2.3) to an intermediate hub if required.  All pending IO on the endpoint will be aborted, and the data toggle for the endpoint will also be reset.  To keep the device's data toggle synchronized with the host's data toggle, it is recommended that the withRequest parameter is always set to true, which causes the <code>clearStall</code> call to send a CLEAR_FEATURE ENDPOINT_HALT (USB 2.0 9.4.1) command to the device.  clearStall is not required for control endpoints.
     * @param       withRequest If true a CLEAR_FEATURE ENDPOINT_HALT (USB 2.0 9.4.1) will be sent to the device.
     *
     * @return  KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    ClearStall (bool withRequest);

    
    /*!
     * @brief       Type definition for asynchronous completion routines.
     * @param       action Pointer to the OSAction object of the async request
     * @param       status Result of the operation
     * @param       actualByteCount Byte could of the completed data phase.
     * @param       completionTimestamp The absolute time that the transfer completed
     * @return      void
     */
    virtual void
    CompleteAsyncIO (OSAction             *action TARGET,
                     IOReturn              status,
                     uint32_t              actualByteCount,
                     uint64_t              completionTimestamp ) = 0;


    /*!
     * @brief       Enqueue an asynchronous request on a bulk or interrupt endpoint
     * @discussion  See IOUSBHostIOSource::io for documentation
     * @param       completionTimeoutMs Must be 0 for interrupt endpoints.
     * @return      KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    AsyncIO (IOMemoryDescriptor            *dataBuffer,
             uint32_t                       dataBufferLength,
             OSAction                      *completion TYPE(CompleteAsyncIO),
             uint32_t                       completionTimeoutMs);


    /*!
     * @brief       Perform a synchronous request on a bulk or interrupt endpoint
     * @discussion  See IOUSBHostIOSource::io for documentation
     * @param       completionTimeoutMs Must be 0 for interrupt endpoints.
     * @return      KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    IO (IOMemoryDescriptor *dataBuffer,
        uint32_t            dataBufferLength,
        uint32_t           *bytesTransferred,
        uint32_t            completionTimeoutMs);


    /*!
     * @brief       Type definition for asynchronous completion routines.
     * @param       action Pointer to the OSAction object of the async request
     * @param       status Result of the operation
     * @return      void
     */
    virtual void
    CompleteAsyncIsochIO (OSAction      *action           TARGET,
                          IOReturn                        status  ) = 0;


    /*!
     * @brief       Enqueue or perform a request on an isochronous endpoint
     * @discussion  This method is used to issue isochronous requests.  The caller allocates and initializes an array of IOUSBHostIsochronousFrame structures, which is used to describe the frames that will be transferred.
     * See @link IOUSBHostIsochronousFrame @/link for information regarding structure initialization requirements and usage.
     * @param       dataBuffer Pointer to a valid memory descriptor to be used as the backing store for the I/O.
     * @param       frameList Pointer to a valid memory descriptor containing the frame list which is an array of IOUSBIsochronousFrame ( e.g. A frame list with 8 frames should be of size : sizeof(IOUSBIsochronousFrame) * 8).   Use frameList->Map() to read/write the frame list.
     * @param       firstFrameNumber Frame number which this request should begin on.  The current frame number can be queried via <code>IOUSHostDevice::getFrameNumber()</code> or <code>IOUSBHostInterface::getFrameNumber()</code>.  If 0, the transfer will start on the next available frame (XHCI only).
     * @param       completion To create a synchronous I/O request, this parameter must be NULL.  For an asynchronous request this paramater must be properly filled out prior to calling this method.  If not NULL, this parameter will be copied and can therefore be stack-allocated.
     * @return      IOReturn result code
     */
    virtual kern_return_t
    IsochIO (IOMemoryDescriptor            *dataBuffer,
             IOMemoryDescriptor            *frameList,
             uint64_t                       firstFrameNumber,
             OSAction                      *completion TYPE(CompleteAsyncIsochIO));


    /*!
     * @brief       Create a memory descriptor ring to use with AsyncIOBundled().
     * @discussion  The ring size should be large enough to hold all the memory descriptors to be used with the pipe.
     * The ring must only be created once, and will be freed by the kernel driver when the pipe is destroyed.
     * @param       size  Size of the ring.
     * @return      KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    
    virtual kern_return_t
    CreateMemoryDescriptorRing(uint32_t size);

    /*!
     * @brief       Add a memory descriptor to the ring.
     * @discussion  Caller must fill the ring starting at index 0. The entire ring must be populated up to index size-1
     * @param       memoryDescriptor The memory descriptor associated with the ring index. Must not be NULL.
     * @param       index Ring index to be populated
     * @return      KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    virtual kern_return_t
    SetMemoryDescriptor( IOMemoryDescriptor *memoryDescriptor,
                         uint32_t             index );

    /*!
     * @brief       Enqueue a contiguous group of requests from the descriptor ring.
     * @discussion  AsyncIOBundled allows the caller to enqueue contiguous groups of transfers in order to reduce
     * messaging overhead.  Before use, a ring must be created using CreateMemoryDescriptorRing() and populated using SetMemoryDescriptor().
     * AsyncIOBundled will automatically handle the wrap condition once the end of the ring has been reached.  Once transfers complete, CompleteAsyncIOBundled
     * will be called. The size of the completion bundles may not match the bundle size specified in AsyncIOBundled(). This method should only be used with bulk pipes.
     * @param       ioTransferIndex  Ring index of first transfer
     * @param       ioTransferCount  Number of transfers to euqueue.
     * @param       ioTransferAcceptedCount Number of transfers successfully enqueued.
     * @param       dataBufferLengthArray Contains lengths for all individual transfers in the bundle
     * @param       dataBufferLengthArrayCount Set this to ioTransferCount
     * @param       completion specifies the callback function to use. Must not be NULL
     * @param       completionTimeoutMs Must be 0 for interrupt endpoints.
     * @return      KERN_SUCCESS is successful see IOReturn.h for error codes.
     */
    
    virtual kern_return_t
    AsyncIOBundled ( uint32_t               ioTransferIndex,
                     uint32_t               ioTransferCount,
                     uint32_t              *ioTransferAcceptedCount,
                     const uint32_t         dataBufferLengthArray[kIOUSBHostPipeBundlingMax],
                     int                    dataBufferLengthArrayCount,
                     OSAction              *completion TYPE(CompleteAsyncIOBundled),
                     uint32_t               completionTimeoutMs);

    
    /*!
     * @brief       Type definition for bundled asynchronous completion routines.
     * @discussion  The callback is called when one or more transfers issued via AsyncIOBundled() have completed. ioCompletionCount specifies the number of transfers completed, starting at position ioCompletionIndex.
     * ioCompletionCount will be at least 1, and no more than kIOUSBHostPipeBundlingMax. The actualByteCountArray and statusArray is used to return the individual length and status of the requests.
     * @param       action  Pointer to the OSAction object of the async request
     * @param       ioCompletionIndex  Ring index of the first completion
     * @param       ioCompletionCount  Number of request completions in this callback
     * @param       actualByteCountArray  Array holding the length of each transfer
     * @param       actualByteCountArrayCount Is set to ioCompletionCount
     * @param       statusArray Array holding the status for each transfer
     * @param       statusArrayCount Is set to ioCompletionCount
     * @return      void
     */
    virtual void
    CompleteAsyncIOBundled (OSAction              *action TARGET,
                            uint32_t               ioCompletionIndex,
                            uint32_t               ioCompletionCount,
                            const uint32_t         actualByteCountArray[kIOUSBHostPipeBundlingMax],
                            int                    actualByteCountArrayCount,
                            const kern_return_t    statusArray[kIOUSBHostPipeBundlingMax],
                            int                    statusArrayCount) = 0;
    
};

#undef KERNEL
#else /* __DOCUMENTATION__ */

/* generated class IOUSBHostPipe IOUSBHostPipe.iig:101-336 */

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
#define IOUSBHostPipe_IsochIO_ID            0xe50e498877f210d7ULL
#define IOUSBHostPipe_CreateMemoryDescriptorRing_ID            0x96299f8363f330f3ULL
#define IOUSBHostPipe_SetMemoryDescriptor_ID            0xe0ce30d41957b747ULL
#define IOUSBHostPipe_AsyncIOBundled_ID            0xa67fb499d6f65f30ULL
#define IOUSBHostPipe_CompleteAsyncIOBundled_ID            0xdd0623caa00a3c04ULL

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
        IOReturn status

#define IOUSBHostPipe_IsochIO_Args \
        IOMemoryDescriptor * dataBuffer, \
        IOMemoryDescriptor * frameList, \
        uint64_t firstFrameNumber, \
        OSAction * completion

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
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    IsochIO(\
        IOMemoryDescriptor * dataBuffer,\
        IOMemoryDescriptor * frameList,\
        uint64_t firstFrameNumber,\
        OSAction * completion,\
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
public:\
    /* _Invoke methods */\
\
    typedef kern_return_t (*GetSpeed_Handler)(OSMetaClassBase * target, IOUSBHostPipe_GetSpeed_Args);\
    static kern_return_t\
    GetSpeed_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        GetSpeed_Handler func);\
\
    typedef kern_return_t (*GetDeviceAddress_Handler)(OSMetaClassBase * target, IOUSBHostPipe_GetDeviceAddress_Args);\
    static kern_return_t\
    GetDeviceAddress_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        GetDeviceAddress_Handler func);\
\
    typedef kern_return_t (*Abort_Handler)(OSMetaClassBase * target, IOUSBHostPipe_Abort_Args);\
    static kern_return_t\
    Abort_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        Abort_Handler func);\
\
    typedef kern_return_t (*AdjustPipe_Handler)(OSMetaClassBase * target, IOUSBHostPipe_AdjustPipe_Args);\
    static kern_return_t\
    AdjustPipe_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        AdjustPipe_Handler func);\
\
    typedef kern_return_t (*GetDescriptors_Handler)(OSMetaClassBase * target, IOUSBHostPipe_GetDescriptors_Args);\
    static kern_return_t\
    GetDescriptors_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        GetDescriptors_Handler func);\
\
    typedef kern_return_t (*SetIdlePolicy_Handler)(OSMetaClassBase * target, IOUSBHostPipe_SetIdlePolicy_Args);\
    static kern_return_t\
    SetIdlePolicy_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        SetIdlePolicy_Handler func);\
\
    typedef kern_return_t (*GetIdlePolicy_Handler)(OSMetaClassBase * target, IOUSBHostPipe_GetIdlePolicy_Args);\
    static kern_return_t\
    GetIdlePolicy_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        GetIdlePolicy_Handler func);\
\
    typedef kern_return_t (*ClearStall_Handler)(OSMetaClassBase * target, IOUSBHostPipe_ClearStall_Args);\
    static kern_return_t\
    ClearStall_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        ClearStall_Handler func);\
\
    typedef void (*CompleteAsyncIO_Handler)(OSMetaClassBase * target, IOUSBHostPipe_CompleteAsyncIO_Args);\
    static kern_return_t\
    CompleteAsyncIO_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        CompleteAsyncIO_Handler func,\
        const OSMetaClass * targetActionClass);\
\
    static kern_return_t\
    CompleteAsyncIO_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        CompleteAsyncIO_Handler func);\
\
    typedef kern_return_t (*AsyncIO_Handler)(OSMetaClassBase * target, IOUSBHostPipe_AsyncIO_Args);\
    static kern_return_t\
    AsyncIO_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        AsyncIO_Handler func);\
\
    typedef kern_return_t (*IO_Handler)(OSMetaClassBase * target, IOUSBHostPipe_IO_Args);\
    static kern_return_t\
    IO_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        IO_Handler func);\
\
    typedef void (*CompleteAsyncIsochIO_Handler)(OSMetaClassBase * target, IOUSBHostPipe_CompleteAsyncIsochIO_Args);\
    static kern_return_t\
    CompleteAsyncIsochIO_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        CompleteAsyncIsochIO_Handler func,\
        const OSMetaClass * targetActionClass);\
\
    static kern_return_t\
    CompleteAsyncIsochIO_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        CompleteAsyncIsochIO_Handler func);\
\
    typedef kern_return_t (*IsochIO_Handler)(OSMetaClassBase * target, IOUSBHostPipe_IsochIO_Args);\
    static kern_return_t\
    IsochIO_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        IsochIO_Handler func);\
\
    typedef kern_return_t (*CreateMemoryDescriptorRing_Handler)(OSMetaClassBase * target, IOUSBHostPipe_CreateMemoryDescriptorRing_Args);\
    static kern_return_t\
    CreateMemoryDescriptorRing_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        CreateMemoryDescriptorRing_Handler func);\
\
    typedef kern_return_t (*SetMemoryDescriptor_Handler)(OSMetaClassBase * target, IOUSBHostPipe_SetMemoryDescriptor_Args);\
    static kern_return_t\
    SetMemoryDescriptor_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        SetMemoryDescriptor_Handler func);\
\
    typedef kern_return_t (*AsyncIOBundled_Handler)(OSMetaClassBase * target, IOUSBHostPipe_AsyncIOBundled_Args);\
    static kern_return_t\
    AsyncIOBundled_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        AsyncIOBundled_Handler func);\
\
    typedef void (*CompleteAsyncIOBundled_Handler)(OSMetaClassBase * target, IOUSBHostPipe_CompleteAsyncIOBundled_Args);\
    static kern_return_t\
    CompleteAsyncIOBundled_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        CompleteAsyncIOBundled_Handler func,\
        const OSMetaClass * targetActionClass);\
\
    static kern_return_t\
    CompleteAsyncIOBundled_Invoke(const IORPC rpc,\
        OSMetaClassBase * target,\
        CompleteAsyncIOBundled_Handler func);\
\


#define IOUSBHostPipe_KernelMethods \
\
protected:\
    /* _Impl methods */\
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
    IsochIO_Impl(IOUSBHostPipe_IsochIO_Args);\
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


#if !KERNEL

extern OSMetaClass          * gIOUSBHostPipeMetaClass;
extern const OSClassLoadInformation IOUSBHostPipe_Class;

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

class  IOUSBHostPipeInterface : public OSInterface
{
public:
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
#ifdef IOUSBHostPipe_DECLARE_IVARS
IOUSBHostPipe_DECLARE_IVARS
#else /* IOUSBHostPipe_DECLARE_IVARS */
    union
    {
        IOUSBHostPipe_IVars * ivars;
        IOUSBHostPipe_LocalIVars * lvars;
    };
#endif /* IOUSBHostPipe_DECLARE_IVARS */
#endif /* !KERNEL */

#if !KERNEL
    static OSMetaClass *
    sGetMetaClass() { return gIOUSBHostPipeMetaClass; };
#endif /* KERNEL */

    using super = OSObject;

#if !KERNEL
    IOUSBHostPipe_Methods
    IOUSBHostPipe_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


#endif /* !__DOCUMENTATION__ */

/* IOUSBHostPipe.iig:338- */

#endif /* ! _IOKIT_IOUSBHOSTPIPE_H */

