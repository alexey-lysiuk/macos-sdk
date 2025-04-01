/* CoreAnimation - CARemoteLayerClient.h

   Copyright (c) 2010-2022, Apple Inc.
   All rights reserved. */

#ifdef __OBJC__

#import <QuartzCore/CABase.h>
#import <Foundation/NSObject.h>
#import <mach/mach.h>

@class CALayer;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(macos(10.7))
@interface CARemoteLayerClient : NSObject
{
@private
  id _impl;
}

/* The designated initializer. The port must have been obtained from
 * -[CARemoteLayerServer serverPort]. */

- (instancetype)initWithServerPort:(mach_port_t)port;

/* Invalidate the object, i.e. delete all state from the server. This
 * is called implicitly when the object is finalized. */

- (void)invalidate;

/* An integer used by the server to identify the client. The value
 * should be passed back to the server so it can display the client's
 * root layer. */

@property(readonly) uint32_t clientId;

/* The root layer. Defaults to nil. */

@property(nullable, strong) CALayer *layer;

@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif
