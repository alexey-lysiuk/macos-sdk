/*
 * Copyright (c) 2008-2009 Apple Inc. All rights reserved.
 */

#ifndef __DISPATCH_PUBLIC__
#define __DISPATCH_PUBLIC__

#include <Availability.h>
#include <sys/cdefs.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#define DISPATCH_API_VERSION 20090501

#ifndef __DISPATCH_BUILDING_DISPATCH__

#ifndef __DISPATCH_INDIRECT__
#define __DISPATCH_INDIRECT__
#endif

#include <dispatch/base.h>
#include <dispatch/object.h>
#include <dispatch/time.h>
#include <dispatch/queue.h>
#include <dispatch/source.h>
#include <dispatch/group.h>
#include <dispatch/semaphore.h>
#include <dispatch/once.h>

#undef __DISPATCH_INDIRECT__

#endif /* !__DISPATCH_BUILDING_DISPATCH__ */

#endif
