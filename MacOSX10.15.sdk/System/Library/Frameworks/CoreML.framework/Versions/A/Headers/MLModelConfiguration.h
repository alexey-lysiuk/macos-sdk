//
//  MLModelConfiguration.h
//  CoreML_framework
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreML/MLExport.h>

NS_ASSUME_NONNULL_BEGIN

@class MLParameterKey;
@protocol MTLDevice;

typedef NS_ENUM(NSInteger, MLComputeUnits) {
    MLComputeUnitsCPUOnly = 0,
    MLComputeUnitsCPUAndGPU = 1,
    MLComputeUnitsAll = 2
} API_AVAILABLE(macos(10.14), ios(12.0), watchos(5.0), tvos(12.0));

/*!
 * An object to hold options for loading a model.
 */
API_AVAILABLE(macos(10.14), ios(12.0), watchos(5.0), tvos(12.0))
ML_EXPORT
@interface MLModelConfiguration : NSObject <NSCopying, NSSecureCoding>

@property (readwrite) MLComputeUnits computeUnits;

@end

/*!
 * Allows app to specify  GPU configuration options
 */
API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0))
ML_EXPORT
@interface MLModelConfiguration (MLGPUConfigurationOptions)

/// Set to YES to allow low precision accumulation on GPU when available. Defaults to NO
@property (readwrite) BOOL allowLowPrecisionAccumulationOnGPU ;

/// Set to specify a preferred Metal device. Defaults to nil which indicates automatic selection
@property (readwrite, nonatomic, nullable) id<MTLDevice> preferredMetalDevice;

@end

/*!
 * Allows app to set updateParameters as a dictionary.
 */
API_AVAILABLE(macos(10.15), ios(13.0))
ML_EXPORT
@interface MLModelConfiguration (MLUpdateAdditions)

// Allows application to override update parameters provided in the model before starting the update process.
@property (readwrite, nonatomic, nullable) NSDictionary<MLParameterKey *, id> *updateParameters;

@end

/*!
 * Allows app to set modelParameters as a dictionary.
 */
API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0))
ML_EXPORT
@interface MLModelConfiguration (MLModelParameterAdditions)

// Allows application to override model parameters on loading of a model
@property (readwrite, nonatomic, nullable) NSDictionary<MLParameterKey *, id> *modelParameters;

@end

NS_ASSUME_NONNULL_END
