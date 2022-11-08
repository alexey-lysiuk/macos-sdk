/*
 *  hv_base.h
 *  Hypervisor Framework
 *
 *  Copyright (c) 2019-2022 Apple Inc. All rights reserved.
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <os/availability.h>
#include <os/base.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#if defined(__arm64__)
#define HV_API_AVAILABLE_ARM64(...) API_AVAILABLE(__VA_ARGS__)
#define HV_API_AVAILABLE_X86_64(...)
#elif defined(__x86_64__)
#define HV_API_AVAILABLE_ARM64(...)
#define HV_API_AVAILABLE_X86_64(...) API_AVAILABLE(__VA_ARGS__)
#endif
