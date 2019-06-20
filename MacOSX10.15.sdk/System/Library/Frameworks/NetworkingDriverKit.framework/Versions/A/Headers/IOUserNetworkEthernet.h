/* iig(DriverKit-54.0.0.111.1) generated from IOUserNetworkEthernet.iig */

/* IOUserNetworkEthernet.iig:1-24 */
#ifndef _IOUSERNETWORKETHERNET_IIG
#define _IOUSERNETWORKETHERNET_IIG

#include <DriverKit/IOService.h>  /* .iig include */ 
#include <DriverKit/OSAction.h>  /* .iig include */ 
#include <DriverKit/IODispatchQueue.h>  /* .iig include */ 
#include <DriverKit/IODataQueueDispatchSource.h>  /* .iig include */ 

#include <NetworkingDriverKit/IOUserNetworkTypes.h>
#include <NetworkingDriverKit/IOUserNetworkPacketQueue.h>  /* .iig include */ 
#include <NetworkingDriverKit/IOUserNetworkPacketBufferPool.h>  /* .iig include */ 

struct _IOUserNetworkEthernetInterfaceDescriptor;

/*!
@iig implementation
#if KERNEL
#include <NetworkingDriverKit/IOUserNetworkPacketBufferPool_kext.h>
#include <NetworkingDriverKit/IOUserNetworkPacketQueue_kext.h>
#include <NetworkingDriverKit/IOUserNetworkEthernet_kext.h>
#endif
@iig end
*/

/* class IOUserNetworkEthernet IOUserNetworkEthernet.iig:25-84 */

#define IOUserNetworkEthernet__DataAvailable_ID            0xf1fe93bc0f089f02ULL
#define IOUserNetworkEthernet__ReportAvailableMediaTypes_ID            0xb48b4ba3f53fbc2aULL
#define IOUserNetworkEthernet__SetMulticastAddresses_ID            0xfce8a9ef10e7e262ULL
#define IOUserNetworkEthernet__RegisterEthernetInterface_ID            0xd3a4f5774bc98335ULL
#define IOUserNetworkEthernet_ReportLinkStatus_ID            0xbfd68fa3f5c86c4dULL
#define IOUserNetworkEthernet_ReportLinkQuality_ID            0xb0a7fe8ebb582f72ULL
#define IOUserNetworkEthernet_SetInterfaceEnable_ID            0xf421a9d80f9a1fdaULL
#define IOUserNetworkEthernet_SetPromiscuousModeEnable_ID            0xe072fcc26cf639acULL
#define IOUserNetworkEthernet_SetMulticastAddresses_ID            0xa1b551fe3b8a09c1ULL
#define IOUserNetworkEthernet_SetAllMulticastModeEnable_ID            0xe042a87972611225ULL
#define IOUserNetworkEthernet_SelectMediaType_ID            0xc3e63ac546ebd1feULL
#define IOUserNetworkEthernet_SetWakeOnMagicPacketEnable_ID            0xb23ee0228705fb95ULL

#define IOUserNetworkEthernet__DataAvailable_Args \
        OSAction * action

#define IOUserNetworkEthernet__ReportAvailableMediaTypes_Args \
        const unsigned int * mediaTypes, \
        uint32_t mediaTypesCount

#define IOUserNetworkEthernet__SetMulticastAddresses_Args \
        IOMemoryDescriptor * md

#define IOUserNetworkEthernet__RegisterEthernetInterface_Args \
        _IOUserNetworkEthernetInterfaceDescriptor descriptor, \
        IOUserNetworkPacketBufferPool * pool, \
        IOUserNetworkPacketQueue * queue1, \
        IOUserNetworkPacketQueue * queue2, \
        IOUserNetworkPacketQueue * queue3, \
        IOUserNetworkPacketQueue * queue4

#define IOUserNetworkEthernet_ReportLinkStatus_Args \
        IOUserNetworkLinkStatus linkStatus, \
        IOUserNetworkMediaType activeMediaType

#define IOUserNetworkEthernet_ReportLinkQuality_Args \
        IOUserNetworkLinkQuality linkQuality

#define IOUserNetworkEthernet_SetInterfaceEnable_Args \
        bool isEnable

#define IOUserNetworkEthernet_SetPromiscuousModeEnable_Args \
        bool enable

#define IOUserNetworkEthernet_SetMulticastAddresses_Args \
        const IOUserNetworkMACAddress * addresses, \
        uint32_t count

#define IOUserNetworkEthernet_SetAllMulticastModeEnable_Args \
        bool enable

#define IOUserNetworkEthernet_SelectMediaType_Args \
        IOUserNetworkMediaType mediaType

#define IOUserNetworkEthernet_SetWakeOnMagicPacketEnable_Args \
        bool enable

#define IOUserNetworkEthernet_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUserNetworkEthernet * self, const IORPC rpc);\
\
    void\
    _DataAvailable(\
        OSAction * action,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    _ReportAvailableMediaTypes(\
        const unsigned int * mediaTypes,\
        uint32_t mediaTypesCount,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    _SetMulticastAddresses(\
        IOMemoryDescriptor * md,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    _RegisterEthernetInterface(\
        _IOUserNetworkEthernetInterfaceDescriptor descriptor,\
        IOUserNetworkPacketBufferPool * pool,\
        IOUserNetworkPacketQueue * queue1,\
        IOUserNetworkPacketQueue * queue2,\
        IOUserNetworkPacketQueue * queue3,\
        IOUserNetworkPacketQueue * queue4,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetInterfaceSubFamily(\
        uint32_t subFamily);\
\
    kern_return_t\
    SetTxPacketHeadroom(\
        uint16_t numBytes);\
\
    kern_return_t\
    SetTxPacketTailroom(\
        uint16_t numBytes);\
\
    kern_return_t\
    SetWakeOnMagicPacketSupport(\
        bool isSupported);\
\
    kern_return_t\
    ReportLinkStatus(\
        IOUserNetworkLinkStatus linkStatus,\
        IOUserNetworkMediaType activeMediaType,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    ReportLinkQuality(\
        IOUserNetworkLinkQuality linkQuality,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetInterfaceEnable(\
        bool isEnable,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetPromiscuousModeEnable(\
        bool enable,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetMulticastAddresses(\
        const IOUserNetworkMACAddress * addresses,\
        uint32_t count,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetAllMulticastModeEnable(\
        bool enable,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SelectMediaType(\
        IOUserNetworkMediaType mediaType,\
        OSDispatchMethod supermethod = NULL);\
\
    kern_return_t\
    SetWakeOnMagicPacketEnable(\
        bool enable,\
        OSDispatchMethod supermethod = NULL);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    _SetMulticastAddresses_Impl(IOUserNetworkEthernet__SetMulticastAddresses_Args);\
\
\
protected:\
    /* _Invoke methods */\
\
    kern_return_t\
    _DataAvailable_Invoke(const IORPC rpc,\
        void (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet__DataAvailable_Args));\
\
    kern_return_t\
    _ReportAvailableMediaTypes_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet__ReportAvailableMediaTypes_Args));\
\
    kern_return_t\
    _SetMulticastAddresses_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet__SetMulticastAddresses_Args));\
\
    kern_return_t\
    _RegisterEthernetInterface_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet__RegisterEthernetInterface_Args));\
\
    kern_return_t\
    ReportLinkStatus_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet_ReportLinkStatus_Args));\
\
    kern_return_t\
    ReportLinkQuality_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet_ReportLinkQuality_Args));\
\
    kern_return_t\
    SetInterfaceEnable_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet_SetInterfaceEnable_Args));\
\
    kern_return_t\
    SetPromiscuousModeEnable_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet_SetPromiscuousModeEnable_Args));\
\
    kern_return_t\
    SetMulticastAddresses_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet_SetMulticastAddresses_Args));\
\
    kern_return_t\
    SetAllMulticastModeEnable_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet_SetAllMulticastModeEnable_Args));\
\
    kern_return_t\
    SelectMediaType_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet_SelectMediaType_Args));\
\
    kern_return_t\
    SetWakeOnMagicPacketEnable_Invoke(const IORPC rpc,\
        kern_return_t (IOUserNetworkEthernet::*func)(IOUserNetworkEthernet_SetWakeOnMagicPacketEnable_Args));\
\


#define IOUserNetworkEthernet_KernelMethods \
\
protected:\
    /* _Impl methods */\
\
    void\
    _DataAvailable_Impl(IOUserNetworkEthernet__DataAvailable_Args);\
\
    kern_return_t\
    _ReportAvailableMediaTypes_Impl(IOUserNetworkEthernet__ReportAvailableMediaTypes_Args);\
\
    kern_return_t\
    _RegisterEthernetInterface_Impl(IOUserNetworkEthernet__RegisterEthernetInterface_Args);\
\
    kern_return_t\
    ReportLinkStatus_Impl(IOUserNetworkEthernet_ReportLinkStatus_Args);\
\
    kern_return_t\
    ReportLinkQuality_Impl(IOUserNetworkEthernet_ReportLinkQuality_Args);\
\


#define IOUserNetworkEthernet_VirtualMethods \
\
public:\
\
    virtual bool\
    init(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual kern_return_t\
    RegisterEthernetInterface(\
        IOUserNetworkMACAddress macAddress,\
        IOUserNetworkPacketBufferPool * pool,\
        IOUserNetworkPacketQueue ** queues,\
        uint32_t queueCount) APPLE_KEXT_OVERRIDE;\
\
    virtual kern_return_t\
    ReportAvailableMediaTypes(\
        const IOUserNetworkMediaType * mediaTypes,\
        uint32_t count) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOUserNetworkEthernetMetaClass;
extern OSClassLoadInformation IOUserNetworkEthernet_Class;

class IOUserNetworkEthernetMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUserNetworkEthernetInterface : public OSInterface
{
public:
    virtual kern_return_t
    RegisterEthernetInterface(IOUserNetworkMACAddress macAddress,
        IOUserNetworkPacketBufferPool * pool,
        IOUserNetworkPacketQueue ** queues,
        uint32_t queueCount) = 0;

    virtual kern_return_t
    ReportAvailableMediaTypes(const IOUserNetworkMediaType * mediaTypes,
        uint32_t count) = 0;

};

struct IOUserNetworkEthernet_IVars;
struct IOUserNetworkEthernet_LocalIVars;

class IOUserNetworkEthernet : public IOService, public IOUserNetworkEthernetInterface
{
#if !KERNEL
    friend class IOUserNetworkEthernetMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUserNetworkEthernet_IVars * ivars;
        IOUserNetworkEthernet_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOService;

#if !KERNEL
    IOUserNetworkEthernet_Methods
    IOUserNetworkEthernet_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


/* IOUserNetworkEthernet.iig:109- */
enum {
    kIOUserNetworkFeatureFlagWOMP = 0x01
};

struct _IOUserNetworkEthernetInterfaceDescriptor {
    IOUserNetworkMACAddress     macAddress;
    uint8_t                 featureFlags;
    uint8_t                 _reserved;
    uint32_t                interfaceSubFamily;
    uint16_t                txPacketHeadroomBytes;
    uint16_t                txPacketTailroomBytes;
} __attribute__((packed));

#endif /* ! _IOUSERNETWORKETHERNET_H */
