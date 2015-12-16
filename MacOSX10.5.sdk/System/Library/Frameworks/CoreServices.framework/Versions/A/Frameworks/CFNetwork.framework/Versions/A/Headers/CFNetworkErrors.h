/*
     File:       CFNetwork/CFNetworkErrors.h
 
     Contains:   CFNetwork error header
 
     Version:    CFNetwork-219~1
 
     Copyright:  © 2006 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFNETWORKERRORS__
#define __CFNETWORKERRORS__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __CFSTRING__
#include <CoreFoundation/CFString.h>
#endif



#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_ENUM_ALWAYSINT
    #pragma enumsalwaysint on
#endif

/*
 *  kCFErrorDomainCFNetwork
 *  
 *  Discussion:
 *    Error domain for all errors originating in CFNetwork. Error codes
 *    may be interpreted using the list below.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFErrorDomainCFNetwork                     AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFErrorDomainWinSock
 *  
 *  Discussion:
 *    On Windows, errors originating from WinSock are represented using
 *    this domain.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFErrorDomainWinSock                       AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;


/*
 *  CFNetworkErrors
 *  
 *  Discussion:
 *    The list of all error codes returned under the error domain
 *    kCFErrorDomainCFNetwork
 */
enum CFNetworkErrors {
  kCFHostErrorHostNotFound      = 1,
  kCFHostErrorUnknown           = 2,    /* Query the kCFGetAddrInfoFailureKey to get the value returned from getaddrinfo; lookup in netdb.h*/
                                        /* SOCKS errors; in all cases you may query kCFSOCKSStatusCodeKey to recover the status code returned by the server*/
  kCFSOCKSErrorUnknownClientVersion = 100,
  kCFSOCKSErrorUnsupportedServerVersion = 101, /* Query the kCFSOCKSVersionKey to find the version requested by the server*/
                                        /* SOCKS4-specific errors*/
  kCFSOCKS4ErrorRequestFailed   = 110,  /* request rejected or failed by the server*/
  kCFSOCKS4ErrorIdentdFailed    = 111,  /* request rejected because SOCKS server cannot connect to identd on the client*/
  kCFSOCKS4ErrorIdConflict      = 112,  /* request rejected because the client program and identd report different user-ids*/
  kCFSOCKS4ErrorUnknownStatusCode = 113, /* SOCKS5-specific errors*/
  kCFSOCKS5ErrorBadState        = 120,
  kCFSOCKS5ErrorBadResponseAddr = 121,
  kCFSOCKS5ErrorBadCredentials  = 122,
  kCFSOCKS5ErrorUnsupportedNegotiationMethod = 123, /* query kCFSOCKSNegotiationMethodKey to find the method requested*/
  kCFSOCKS5ErrorNoAcceptableMethod = 124, /* Errors originating from CFNetServices*/
  kCFNetServiceErrorUnknown     = -72000L,
  kCFNetServiceErrorCollision   = -72001L,
  kCFNetServiceErrorNotFound    = -72002L,
  kCFNetServiceErrorInProgress  = -72003L,
  kCFNetServiceErrorBadArgument = -72004L,
  kCFNetServiceErrorCancel      = -72005L,
  kCFNetServiceErrorInvalid     = -72006L,
  kCFNetServiceErrorTimeout     = -72007L,
  kCFNetServiceErrorDNSServiceFailure = -73000L, /* An error from DNS discovery; look at kCFDNSServiceFailureKey to get the error number and interpret using dns_sd.h*/
                                        /* FTP errors; query the kCFFTPStatusCodeKey to get the status code returned by the server*/
  kCFFTPErrorUnexpectedStatusCode = 200, /* HTTP errors*/
  kCFErrorHTTPAuthenticationTypeUnsupported = 300,
  kCFErrorHTTPBadCredentials    = 301,
  kCFErrorHTTPConnectionLost    = 302,
  kCFErrorHTTPParseFailure      = 303,
  kCFErrorHTTPRedirectionLoopDetected = 304,
  kCFErrorHTTPBadURL            = 305,
  kCFErrorHTTPProxyConnectionFailure = 306,
  kCFErrorHTTPBadProxyCredentials = 307
};
typedef enum CFNetworkErrors CFNetworkErrors;


/* Keys used by CFNetwork to pass additional error information back to the user within CFError's userInfo dictionary */
/*
 *  kCFGetAddrInfoFailureKey
 *  
 *  Discussion:
 *    When an error of kCFHostErrorUnknown is returned, this key's
 *    value is set to a CFNumber containing the raw error value
 *    returned by getaddrinfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFGetAddrInfoFailureKey                    AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFSOCKSStatusCodeKey
 *  
 *  Discussion:
 *    When a SOCKS failure has occurred, this key's value is set to a
 *    CFString containing the status value returned by the SOCKS server.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFSOCKSStatusCodeKey                       AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFSOCKSVersionKey
 *  
 *  Discussion:
 *    When an error of kCFSOCKSErrorUnsupportedServerVersion is
 *    returned, this key's value is set to a CFString containing the
 *    version number requested by the server.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFSOCKSVersionKey                          AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFSOCKSNegotiationMethodKey
 *  
 *  Discussion:
 *    When an error of kCFSOCKS5ErrorUnsupportedNegotiationMethod is
 *    returned, this key's value is set to a CFString containing the
 *    negotiation method requested by the server.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFSOCKSNegotiationMethodKey                AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFDNSServiceFailureKey
 *  
 *  Discussion:
 *    When an error of kCFNetServicesErrorDNSServiceFailure is
 *    returned, this key's value is set to a CFNumber containing the
 *    value returned from DNS; interret it using the values dns_sd.h
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFDNSServiceFailureKey                     AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFFTPStatusCodeKey
 *  
 *  Discussion:
 *    When an error of kCFFTPErrorUnexpectedStatusCode is returned,
 *    this key's value is set to a CFString containing the status code
 *    returned by the server
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPStatusCodeKey                         AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

#if PRAGMA_ENUM_ALWAYSINT
    #pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFNETWORKERRORS__ */

