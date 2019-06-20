//
//  VNDetectAnimalRectanglesRequest.h
//  Vision
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Vision/VNRequest.h>
#import <Vision/VNDefines.h>


NS_ASSUME_NONNULL_BEGIN


typedef NSString *VNAnimalDetector NS_STRING_ENUM;

VN_EXPORT VNAnimalDetector const VNAnimalDetectorDog API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0));
VN_EXPORT VNAnimalDetector const VNAnimalDetectorCat API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0));


/*!
	@brief A request that will detect various animals in an image. The list of animals supported by detection algorithm can be queried by +(NSArray *)knownAnimalDetectorsForRevision

	@details This request will generate VNRecognizedObjectObservation objects with defined a boundingBox, label and confidence level.
*/
API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0))
@interface VNDetectAnimalRectanglesRequest : VNImageBasedRequest

/*!
 @brief This class method returns a list of all animals supported by detection algorithm
 
 @details This request will generate a collection of names for supported animals by current detector.
 */
+ (NSArray<VNAnimalDetector> *)knownAnimalDetectorsForRevision:(NSUInteger)requestRevision;

@end


API_AVAILABLE(macos(10.15), ios(13.0), tvos(13.0))
static const NSUInteger VNDetectAnimalRectanglesRequestRevision1 = 1;


NS_ASSUME_NONNULL_END
