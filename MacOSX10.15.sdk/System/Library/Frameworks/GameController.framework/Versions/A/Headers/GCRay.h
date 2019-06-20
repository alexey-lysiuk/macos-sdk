//
//  GCRay.h
//  CoreController
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <simd/simd.h>

NS_ASSUME_NONNULL_BEGIN

GAMECONTROLLER_EXPORT
@interface GCRay : NSObject

- (id)initWithOrigin:(simd_float3)origin direction:(simd_float3)direction;

@property (nonatomic, assign) simd_float3 origin;
@property (nonatomic, assign) simd_float3 direction; // normalized direction vector

@end

NS_ASSUME_NONNULL_END
