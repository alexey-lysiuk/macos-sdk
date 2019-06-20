#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/NSLayoutAnchor.h>)
/*	NSLayoutAnchor.h
	Copyright (c) 2015-2018, Apple Inc. All rights reserved.
*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@class NSLayoutConstraint;

/* An NSLayoutAnchor represents an edge or dimension of a layout item.  Its concrete 
 subclasses allow concise creation of constraints.  
    Instead of invoking 
 
 +[NSLayoutConstraint constraintWithItem:attribute:relatedBy:toItem:attribute:multiplier:constant:] 
 
 directly, you can instead do something like this:
 
 [myView.topAnchor constraintEqualToAnchor:otherView.topAnchor constant:10];
 
 The -constraint* methods are available in multiple flavors to support use of different
 relations and omission of unused options.
 */
UIKIT_EXTERN API_AVAILABLE(ios(9.0))
@interface NSLayoutAnchor<AnchorType> : NSObject

/* These methods return an inactive constraint of the form thisAnchor = otherAnchor.
 */
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor __attribute((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor __attribute__((warn_unused_result));

/* These methods return an inactive constraint of the form thisAnchor = otherAnchor + constant.
 */
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutAnchor<AnchorType> *)anchor constant:(CGFloat)c __attribute__((warn_unused_result));
@end


/* Axis-specific subclasses for location anchors: top/bottom, leading/trailing, baseline, etc.
 */
@class NSLayoutXAxisAnchor, NSLayoutYAxisAnchor, NSLayoutDimension;
UIKIT_EXTERN API_AVAILABLE(ios(9.0))
@interface NSLayoutXAxisAnchor : NSLayoutAnchor<NSLayoutXAxisAnchor *>
// A composite anchor for creating constraints relating horizontal distances between locations.
- (NSLayoutDimension *)anchorWithOffsetToAnchor:(NSLayoutXAxisAnchor *)otherAnchor API_AVAILABLE(ios(10.0),tvos(10.0));

@end

@interface NSLayoutXAxisAnchor (UIViewDynamicSystemSpacingSupport)
/* Constraints of the form,
        receiver [= | ≥ | ≤] 'anchor' + 'multiplier' * system space, 
 where the value of the system space is determined from information available from the anchors.
    The constraint affects how far the receiver will be positioned trailing 'anchor', per the effective user interface layout direction.
 */
- (NSLayoutConstraint *)constraintEqualToSystemSpacingAfterAnchor:(NSLayoutXAxisAnchor *)anchor multiplier:(CGFloat)multiplier __attribute__((warn_unused_result)) API_AVAILABLE(ios(11.0),tvos(11.0));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToSystemSpacingAfterAnchor:(NSLayoutXAxisAnchor *)anchor multiplier:(CGFloat)multiplier __attribute__((warn_unused_result)) API_AVAILABLE(ios(11.0),tvos(11.0));
- (NSLayoutConstraint *)constraintLessThanOrEqualToSystemSpacingAfterAnchor:(NSLayoutXAxisAnchor *)anchor multiplier:(CGFloat)multiplier __attribute__((warn_unused_result)) API_AVAILABLE(ios(11.0),tvos(11.0));

@end
UIKIT_EXTERN API_AVAILABLE(ios(9.0))
@interface NSLayoutYAxisAnchor : NSLayoutAnchor<NSLayoutYAxisAnchor *>
// A composite anchor for creating constraints relating vertical distances between locations.
- (NSLayoutDimension *)anchorWithOffsetToAnchor:(NSLayoutYAxisAnchor *)otherAnchor API_AVAILABLE(ios(10.0),tvos(10.0));

@end

@interface NSLayoutYAxisAnchor (UIViewDynamicSystemSpacingSupport)
/* Constraints of the form,
        receiver [= | ≥ | ≤] 'anchor' + 'multiplier' * system space, 
 where the value of the system space is determined from information available from the anchors.
    The constraint affects how far the receiver will be positioned below 'anchor'. 
    If either the receiver or 'anchor' is the firstBaselineAnchor or lastBaselineAnchor of a view with text content
 then the spacing will depend on the fonts involved and will change when those do.
 */
- (NSLayoutConstraint *)constraintEqualToSystemSpacingBelowAnchor:(NSLayoutYAxisAnchor *)anchor multiplier:(CGFloat)multiplier __attribute__((warn_unused_result)) API_AVAILABLE(ios(11.0),tvos(11.0));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToSystemSpacingBelowAnchor:(NSLayoutYAxisAnchor *)anchor multiplier:(CGFloat)multiplier __attribute__((warn_unused_result)) API_AVAILABLE(ios(11.0),tvos(11.0));
- (NSLayoutConstraint *)constraintLessThanOrEqualToSystemSpacingBelowAnchor:(NSLayoutYAxisAnchor *)anchor multiplier:(CGFloat)multiplier __attribute__((warn_unused_result)) API_AVAILABLE(ios(11.0),tvos(11.0));
@end


/* This layout anchor subclass is used for sizes (width & height).
 */
UIKIT_EXTERN API_AVAILABLE(ios(9.0))
@interface NSLayoutDimension : NSLayoutAnchor<NSLayoutDimension *>

/* These methods return an inactive constraint of the form 
    thisVariable = constant.
*/
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToConstant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToConstant:(CGFloat)c __attribute__((warn_unused_result));

/* These methods return an inactive constraint of the form 
    thisAnchor = otherAnchor * multiplier.
*/
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m __attribute__((warn_unused_result));

/* These methods return an inactive constraint of the form 
    thisAnchor = otherAnchor * multiplier + constant.
*/
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m constant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m constant:(CGFloat)c __attribute__((warn_unused_result));
- (NSLayoutConstraint *)constraintLessThanOrEqualToAnchor:(NSLayoutDimension *)anchor multiplier:(CGFloat)m constant:(CGFloat)c __attribute__((warn_unused_result));
@end
NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/NSLayoutAnchor.h>
#endif
