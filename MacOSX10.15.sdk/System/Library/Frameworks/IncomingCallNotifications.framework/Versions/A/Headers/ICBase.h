//
//  ICBase.h
//  IncomingCallNotifications
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
#define IC_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define IC_EXTERN extern __attribute__((visibility("default")))
#endif

#define IC_CLASS_AVAILABLE(...) IC_EXTERN API_AVAILABLE(__VA_ARGS__)

NS_ASSUME_NONNULL_END
