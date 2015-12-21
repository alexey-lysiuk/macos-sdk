//
//  PROAPIAccessing.h
//  ProPlug
//
//  Copyright (c) 2006 Apple Computer All rights reserved.
//

#import <Foundation/Foundation.h>

//-----------------------------------------------------------------------------
// Protocols to support requesting API from the Plug-In Manager.
//-----------------------------------------------------------------------------

@protocol PROAPIAccessing <NSObject>
- (id)apiForProtocol:(Protocol *)apiProtocol;
@end

@protocol PROAPIObject <NSObject>
- (BOOL)conformsToProtocol:(Protocol *)aProtocol version:(unsigned int)versionNumber;
@end

@interface NSObject (PROPlugIn)
- (id)initWithAPIManager:(id<PROAPIAccessing>)apiManager;
@end
