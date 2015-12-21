//
//  PROPlugInBundleRegistration.h
//  ProPlug
//
//  Copyright (c) 2006 Apple Computer, Inc. All rights reserved.
//

@class NSArray, NSError;

//-----------------------------------------------------------------------------
// Protocol for a plug-in type that dynamically registers the plug-in(s)
// contained in a loadable bundle.  The plug-in class that implements this
// protocol must be registered as the principal class in the bundle.
//-----------------------------------------------------------------------------

@protocol PROPlugInRegistering <NSObject>

+ (id)sharedInstance;

// Accept or refuse to be loaded.
- (BOOL)shouldLoadFirstInstanceOfPlugInWithError:(NSError **)error;

// Dynamically register any plug-in groups.
// Return an array of NSDictionaries mirroring the structure found in property lists.
// This return value will override any plug-ins found in the Info.plist.
// If returning nil, error should be filled with an appropriately illuminating error object.
// This method should not return a list with zero elements.
- (NSArray *)registeredPlugInGroupsWithError:(NSError **)error;

// DEPRECATED: request host API protocols. You don't need to call this any more, as of PluginManager 1.7.
- (NSArray *)requestedProtocolsWithError:(NSError **)error;

// Dynamically register any plug-ins.
// Return an array of NSDictionaries mirroring the structure found in property lists.
// This return value will override any plug-ins found in the Info.plist.
// If returning nil, error should be filled with an appropriately illuminating error object.
// This method should not return a list with zero elements.
- (NSArray *)registeredPlugInsWithError:(NSError **)error;

@end

