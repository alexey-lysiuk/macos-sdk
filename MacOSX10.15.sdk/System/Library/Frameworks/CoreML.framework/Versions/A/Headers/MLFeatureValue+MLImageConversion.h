//
//  MLFeatureValue+MLImageConversion.h
//  CoreML_framework
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <CoreML/MLFeatureValue.h>
#import <CoreML/MLImageConstraint.h>
#import <CoreGraphics/CGImage.h>
#import <Foundation/NSURL.h>

NS_ASSUME_NONNULL_BEGIN

/// Options keys passed into the MLFeatureValue construction for image types
typedef NSString * MLFeatureValueImageOption NS_SWIFT_NAME(MLFeatureValue.ImageOption) NS_TYPED_EXTENSIBLE_ENUM;


/// Key for CGRect describing a crop region of interest of image source in normalized coordinates
ML_EXPORT MLFeatureValueImageOption const MLFeatureValueImageOptionCropRect API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0));

/// Key for VNImageCropAndScaleOption describing how to crop and scale the image (or region of interest) to the desired size
ML_EXPORT MLFeatureValueImageOption const MLFeatureValueImageOptionCropAndScale API_AVAILABLE(macos(10.15), ios(13.0),tvos(13.0));


API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0))
ML_EXPORT
@interface MLFeatureValue (MLImageConversion)


/// Construct image feature value from an image on disk
+ (nullable instancetype)featureValueWithImageAtURL:(NSURL *)url
                                         pixelsWide:(NSInteger)pixelsWide
                                         pixelsHigh:(NSInteger)pixelsHigh
                                    pixelFormatType:(OSType)pixelFormatType
                                            options:(nullable NSDictionary<MLFeatureValueImageOption, id> *)options
                                              error:(NSError * _Nullable __autoreleasing *)error;

/// Construct image feature value from an image on disk, using a model specified image constraint
+ (nullable instancetype)featureValueWithImageAtURL:(NSURL *)url
                                         constraint:(MLImageConstraint *)constraint
                                            options:(nullable NSDictionary<MLFeatureValueImageOption, id> *)options
                                              error:(NSError * _Nullable __autoreleasing *)error;


/// Construct image feature value from CGImage
+ (nullable instancetype)featureValueWithCGImage:(CGImageRef)cgImage
                                      pixelsWide:(NSInteger)pixelsWide
                                      pixelsHigh:(NSInteger)pixelsHigh
                                 pixelFormatType:(OSType)pixelFormatType
                                         options:(nullable NSDictionary<MLFeatureValueImageOption, id> *)options
                                           error:(NSError * _Nullable __autoreleasing *)error;

/// Construct image feature value from CGImage, using the size and type information required by feature description
+ (nullable instancetype)featureValueWithCGImage:(CGImageRef)cgImage
                                      constraint:(MLImageConstraint *)constraint
                                         options:(nullable NSDictionary<MLFeatureValueImageOption, id> *)options
                                           error:(NSError * _Nullable __autoreleasing *)error;


@end

NS_ASSUME_NONNULL_END
