/*
 * Copyright (C) 2025 Apple Inc. All rights reserved.
 *
 * This document is the property of Apple Inc.
 * It is considered confidential and proprietary.
 *
 * This document may not be reproduced or transmitted in any form,
 * in whole or in part, without the express written permission of
 * Apple Inc.
 */
#pragma once

#include <IOKit/IOReturn.h>
/**
 * List of external methods to be called from user land
 * @constant kAppleGPIOUserClientMethodSetDevice Sets the device associated with this UC
 *                Input: C-string; Output: None
 * @constant kAppleGPIOUserClientMethodGetGPIOData Get the GPIO value
 *                Input: None; Output: uint32_t
 * @constant kAppleGPIOUserClientMethodSetGPIOData Sets the GPIO value
 *                uint32_t data; Output: None
 * @constant kAppleGPIOUserClientMethodCount Enum length, not a method
 */
enum {
    kAppleGPIOUserClientMethodSetDevice,
    kAppleGPIOUserClientMethodGetGPIOData,
    kAppleGPIOUserClientMethodSetGPIOData,
    kAppleGPIOUserClientMethodCount
};

/** Maximum GPIO Device Name length */
#define kMaxDeviceNameLen 64
