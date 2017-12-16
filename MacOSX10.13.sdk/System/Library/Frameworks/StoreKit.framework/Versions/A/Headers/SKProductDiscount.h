//
//  SKProductDiscount.h
//  StoreKit
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKitDefines.h>

@class SKProductSubscriptionPeriod;

typedef NS_ENUM(NSUInteger, SKProductDiscountPaymentMode) {
    SKProductDiscountPaymentModePayAsYouGo,
    SKProductDiscountPaymentModePayUpFront,
    SKProductDiscountPaymentModeFreeTrial
} NS_SWIFT_NAME(SKProductDiscount.PaymentMode);

NS_ASSUME_NONNULL_BEGIN

SK_EXTERN_CLASS_AVAILABLE(10_13_2) @interface SKProductDiscount : NSObject
{
@private
    id _internal;
}

@property(nonatomic, readonly) NSDecimalNumber *price;

@property(nonatomic, readonly) NSLocale *priceLocale;

@property(nonatomic, readonly) SKProductSubscriptionPeriod *subscriptionPeriod;

@property(nonatomic, readonly) NSUInteger numberOfPeriods;

@property(nonatomic, readonly) SKProductDiscountPaymentMode paymentMode;

@end

NS_ASSUME_NONNULL_END
