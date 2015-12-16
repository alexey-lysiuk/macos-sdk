/*
     File:       CFNetwork/CFProxySupport.h
 
     Contains:   Support for computing which proxy applies when
 
     Version:    CFNetwork-219~1
 
     Copyright:  © 2006 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFPROXYSUPPORT__
#define __CFPROXYSUPPORT__

#ifndef __CFNETWORKDEFS__
#include <CFNetwork/CFNetworkDefs.h>
#endif

#ifndef __CFARRAY__
#include <CoreFoundation/CFArray.h>
#endif

#ifndef __CFSTRING__
#include <CoreFoundation/CFString.h>
#endif

#ifndef __CFURL__
#include <CoreFoundation/CFURL.h>
#endif

#ifndef __CFERROR__
#include <CoreFoundation/CFError.h>
#endif

#ifndef __CFRUNLOOP__
#include <CoreFoundation/CFRunLoop.h>
#endif

#ifndef __CFSTREAM__
#include <CoreFoundation/CFStream.h>
#endif


/* 
    These APIs return arrays of dictionaries, where each dictionary describes a single proxy. 
    The arrays represent the order in which the proxies should be tried - try to download the URL
    using the first entry in the array, and if that fails, try using the second entry, and so on.

    The keys to the proxy dictionaries follow the function declarations; every proxy dictionary 
    will have an entry for kCFProxyTypeKey.  If the type is anything except 
    kCFProxyTypeAutoConfigurationURL, the dictionary will also have entries for the proxy's host
    and port (under kCFProxyHostNameKey and kCFProxyPortNumberKey respectively).  If the type is
    kCFProxyTypeAutoConfigurationURL, it will have an entry for kCFProxyAutoConfigurationURLKey.  
    
    The keys for username and password are optional and will only be present if the username 
    or password could be extracted from the information passed in (i.e. either the URL itself
    or the proxy dictionary supplied).  These APIs do not consult any external credential stores
    (such as the Keychain).
*/

#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  CFNetworkCopyProxiesForURL()
 *  
 *  Discussion:
 *    Given a URL and a proxy dictionary, determines the ordered list
 *    of proxies that should be used to download the given URL.
 *  
 *  Parameters:
 *    
 *    url:
 *      The URL to be accessed
 *    
 *    proxySettings:
 *      A dictionary describing the available proxy settings; the
 *      dictionary's format should match that described in and returned
 *      by SystemConfiguration.framework
 *  
 *  Result:
 *    An array of dictionaries; each dictionary describes a single
 *    proxy.  See the comment at the top of this file for how to
 *    interpret the returned dictionaries.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern CFArrayRef 
CFNetworkCopyProxiesForURL(
  CFURLRef          url,
  CFDictionaryRef   proxySettings)                            AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;




/*
 *  CFProxyAutoConfigurationResultCallback
 *  
 *  Discussion:
 *    Callback function to be called when a PAC file computation
 *    (initiated by either CFNetworkExecuteProxyAutoConfigurationScript
 *    or CFNetworkExecuteProxyAutoConfigurationURL) has completed.
 *  
 *  Parameters:
 *    
 *    client:
 *      The client reference passed in to
 *      CFNetworkExecuteProxyAutoConfigurationScript or
 *      CFNetworkExecuteProxyAutoConfigurationURL
 *    
 *    proxyList:
 *      Upon success, the list of proxies returned by the
 *      autoconfiguration script.  The list has the same format as
 *      returned by CFProxyCopyProxiesForURL, above, except that no
 *      entry may be of type kCFProxyTypeAutoConfigurationURL.  Note
 *      that if the client wishes to keep this list, they must retain
 *      it when they receive this callback.
 *    
 *    error:
 *      Upon failure, an error object explaining the failure.
 */
typedef CALLBACK_API_C( void , CFProxyAutoConfigurationResultCallback )(void *client, CFArrayRef proxyList, CFErrorRef error);
/*
 *  CFNetworkCopyProxiesForAutoConfigurationScript()
 *  
 *  Discussion:
 *    Begins the process of executing proxyAutoConfigurationScript to
 *    determine the correct proxy to use to retrieve targetURL.  The
 *    caller should schedule the returned run loop source; when the
 *    results are found, the caller's callback will be called via the
 *    run loop, passing a valid proxyList and NULL error upon success,
 *    or a NULL proxyList and valid error on failure.  The caller
 *    should invalidate the returned run loop source if it wishes to
 *    terminate the request before completion.
 *  
 *  Parameters:
 *    
 *    proxyAutoConfigurationScript:
 *      A CFString containing the code of the script to be executed.
 *    
 *    targetURL:
 *      The URL that should be input in to the autoconfiguration script
 *  
 *  Result:
 *    An array of dictionaries describing the proxies returned by the
 *    script.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern CFArrayRef 
CFNetworkCopyProxiesForAutoConfigurationScript(
  CFStringRef   proxyAutoConfigurationScript,
  CFURLRef      targetURL)                                    AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;


/*
 *  CFNetworkExecuteProxyAutoConfigurationURL()
 *  
 *  Discussion:
 *    As CFNetworkExecuteProxyAutoConfigurationScript(), above, except
 *    that CFNetworkExecuteProxyAutoConfigurationURL will additionally
 *    download the contents of proxyAutoConfigURL, convert it to a
 *    JavaScript string, and then execute that script.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern CFRunLoopSourceRef 
CFNetworkExecuteProxyAutoConfigurationURL(
  CFURLRef                                 proxyAutoConfigURL,
  CFURLRef                                 targetURL,
  CFProxyAutoConfigurationResultCallback   cb,
  CFStreamClientContext *                  clientContext)     AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;




/*
 *  kCFProxyTypeKey
 *  
 *  Discussion:
 *    Key for the type of proxy being represented; value will be one of
 *    the kCFProxyType constants listed below.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyTypeKey                             AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFProxyHostNameKey
 *  
 *  Discussion:
 *    Key for the proxy's hostname; value is a CFString.  Note that
 *    this may be an IPv4 or IPv6 dotted-IP string.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyHostNameKey                         AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFProxyPortNumberKey
 *  
 *  Discussion:
 *    Key for the proxy's port number; value is a CFNumber specifying
 *    the port on which to contact the proxy
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyPortNumberKey                       AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFProxyAutoConfigurationURLKey
 *  
 *  Discussion:
 *    Key for the proxy's PAC file location; this key is only present
 *    if the proxy's type is kCFProxyTypeAutoConfigurationURL.  Value
 *    is a CFURL specifying the location of a proxy auto-configuration
 *    file
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyAutoConfigurationURLKey             AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFProxyUsernameKey
 *  
 *  Discussion:
 *    Key for the username to be used with the proxy; value is a
 *    CFString. Note that this key will only be present if the username
 *    could be extracted from the information passed in.  No external
 *    credential stores (like the Keychain) are consulted.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyUsernameKey                         AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/*
 *  kCFProxyPasswordKey
 *  
 *  Discussion:
 *    Key for the password to be used with the proxy; value is a
 *    CFString. Note that this key will only be present if the username
 *    could be extracted from the information passed in.  No external
 *    credential stores (like the Keychain) are consulted.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyPasswordKey                         AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

/* 
    Possible values for kCFProxyTypeKey:
    kCFProxyTypeNone - no proxy should be used; contact the origin server directly
    kCFProxyTypeHTTP - the proxy is an HTTP proxy
    kCFProxyTypeHTTPS - the proxy is a tunneling proxy as used for HTTPS
    kCFProxyTypeSOCKS - the proxy is a SOCKS proxy
    kCFProxyTypeFTP - the proxy is an FTP proxy
    kCFProxyTypeAutoConfigurationURL - the proxy is specified by a proxy autoconfiguration (PAC) file
*/
/*
 *  kCFProxyTypeNone
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyTypeNone                            AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
/*
 *  kCFProxyTypeHTTP
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyTypeHTTP                            AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
/*
 *  kCFProxyTypeHTTPS
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyTypeHTTPS                           AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
/*
 *  kCFProxyTypeSOCKS
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyTypeSOCKS                           AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
/*
 *  kCFProxyTypeFTP
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyTypeFTP                             AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
/*
 *  kCFProxyTypeAutoConfigurationURL
 *  
 *  Availability:
 *    Mac OS X:         in version 10.5 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFProxyTypeAutoConfigurationURL            AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

#ifdef __cplusplus
}
#endif

#endif /* __CFPROXYSUPPORT__ */

