//
//  BELayerHierarchyHostingTransactionCoordinator.h
//  BrowserEngineKit
//
//  Copyright © 2023 Apple Inc. All rights reserved.
//

#import <BrowserEngineKit/BELayerHierarchy.h>
#import <BrowserEngineKit/BELayerHierarchyHostingView.h>
#import <BrowserEngineKit/BEMacros.h>
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


API_AVAILABLE(ios(17.4))
API_UNAVAILABLE(macos, watchos, tvos, visionos)
BROWSERENGINE_EXPORT
BROWSERENGINE_FINAL
NS_SWIFT_SENDABLE
NS_SWIFT_NAME(LayerHierarchyHostingTransactionCoordinator)
@interface BELayerHierarchyHostingTransactionCoordinator : NSObject <NSSecureCoding>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// may fail if a connection to the render server cannot be established
+ (nullable BELayerHierarchyHostingTransactionCoordinator *)coordinatorWithError:(NSError **)error NS_SWIFT_NAME(init());

#if BROWSERENGINEKIT_HAS_LIBXPC
+ (nullable BELayerHierarchyHostingTransactionCoordinator *)coordinatorWithXPCRepresentation:(nullable xpc_object_t)xpcRepresentation error:(NSError **)error NS_SWIFT_NAME(init(xpcRepresentation:));
- (xpc_object_t)createXPCRepresentation NS_SWIFT_NAME(createXPCRepresentation());
#endif

/// a signal to coordinate transactions involving `layerHierarchy` from now until `commit` is called
- (void)addLayerHierarchy:(BELayerHierarchy *)layerHierarchy NS_SWIFT_UI_ACTOR NS_SWIFT_NAME(add(_:));
#if BROWSERENGINEKIT_HAS_UIVIEW
/// a signal to coordinate transactions involving `hostingView` from now until `commit` is called
- (void)addLayerHierarchyHostingView:(BELayerHierarchyHostingView *)hostingView NS_SWIFT_UI_ACTOR NS_SWIFT_NAME(add(_:));
#endif

/// `commit` must be called on _every_ instance and it must be the last call to each instance.
/// note that it does not commit `CATransaction`s but rather commits the coordination of transactions in the render server.
/// note that coordinators should have as constrained a lifespan as possible and will timeout if held open too long.
- (void)commit NS_SWIFT_UI_ACTOR NS_SWIFT_NAME(commit());

@end


NS_ASSUME_NONNULL_END
