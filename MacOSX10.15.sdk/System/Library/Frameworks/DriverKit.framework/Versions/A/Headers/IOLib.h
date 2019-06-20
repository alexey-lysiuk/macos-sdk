#include <DriverKit/IOReturn.h>
#include <sys/cdefs.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <os/overflow.h>
#include <TargetConditionals.h>

#ifndef DRIVERKIT_IOLIB_H
#define DRIVERKIT_IOLIB_H

__BEGIN_DECLS

void 
IOLogBuffer(const char * title, const void * buffer, size_t size,
                          void (*output)(const char *format, ...));
uint32_t
crc32(uint32_t crc, const void *buf, size_t size);

void IOLog(const char *format, ...)
__attribute__((format(printf, 1, 2)));

void *
IOMalloc(size_t length)
__attribute__((alloc_size(1)));

void * 
IOMallocZero(size_t length)
__attribute__((alloc_size(1)));

void
IOFree(void * address, size_t length);

void
IOSleep(uint64_t ms);

void
IODelay(uint64_t us);

#if TARGET_OS_DRIVERKIT && !DRIVERKIT_PRIVATE

/*!
 * @functiongroup Raw Mach Time API
 * In general prefer to use the <time.h> API clock_gettime_nsec_np(3), which
 * deals in the same clocks (and more) in ns units.
 * Conversion of ns to (resp. from) tick units as returned by the mach time APIs
 * is performed by division (resp. multiplication) with the fraction returned by
 * mach_timebase_info().
 */

struct mach_timebase_info {
	uint32_t numer;
	uint32_t denom;
};

typedef struct mach_timebase_info *mach_timebase_info_t;
typedef struct mach_timebase_info  mach_timebase_info_data_t;

/*!
 * @function mach_timebase_info
 * Returns fraction to multiply a value in mach tick units with to convert it
 * to nanoseconds.
 *
 * @param info	Timebase fraction out parameter.
 * @result		KERN_SUCCESS if `info` was filled in.
 */
kern_return_t
mach_timebase_info(mach_timebase_info_t info);

/*!
 * @function mach_absolute_time
 * Returns current value of a clock that increments monotonically in tick units
 * (starting at an arbitrary point), this clock does not increment while the
 * system is asleep.
 *
 * Prefer to use the equivalent clock_gettime_nsec_np(CLOCK_UPTIME_RAW) in
 * nanoseconds.
 *
 * @result		Value of mach absolute time clock.
 */
uint64_t
mach_absolute_time(void);

/*!
 * @function mach_continuous_time
 * Returns current value of a clock that increments monotonically in tick units
 * (starting at an arbitrary point), including while the system is asleep.
 *
 * Prefer to use the equivalent clock_gettime_nsec_np(CLOCK_MONOTONIC_RAW) in
 * nanoseconds.
 *
 * @result		Value of mach continous time clock.
 */
uint64_t
mach_continuous_time(void);

#endif // TARGET_OS_DRIVERKIT && !DRIVERKIT_PRIVATE

void
OSSynchronizeIO(void);

bool
IOParseBootArgNumber(
	const char      *arg_string,
	void            *arg_ptr,
	int                     max_len);

bool
IOParseBootArgString(
	const char      *arg_string,
	char            *arg_ptr,
	int                     strlen);

void __attribute__((noinline, not_tail_called))
OSReportWithBacktrace(const char *str, ...);


enum {
	kIODKEnable            = 0x00000001ULL,
	kIODKLogSetup          = 0x00000002ULL,
	kIODKLogIPC            = 0x00000004ULL,
	kIODKLogPM             = 0x00000008ULL,
	kIODKLogMessages       = 0x00000010ULL,
	kIODKLogConsole        = 0x00000800ULL,
	kIODKDisableDextLaunch = 0x00001000ULL,
	kIODKDisableDextTag    = 0x00002000ULL,
};

extern int64_t gIODKDebug;

#define OSSafeReleaseNULL(o) { if (o) { (o)->release(); (o) = NULL; } }

#define IONew(type, count)                              \
({                                                      \
    size_t __size;                                      \
    (os_mul_overflow(sizeof(type), (count), &__size)    \
    ? ((type *) NULL)                                   \
    : ((type *) IOMalloc(__size)));                     \
})

#define IONewZero(type, count)                          \
({                                                      \
    size_t __size;                                      \
    (os_mul_overflow(sizeof(type), (count), &__size)    \
    ? ((type *) NULL)                                   \
    : ((type *) IOMallocZero(__size)));                 \
})

#define IODelete(ptr, type, count)                          \
({                                                          \
    size_t __size;                                          \
    if (!os_mul_overflow(sizeof(type), (count), &__size)) { \
        IOFree(ptr, __size);                                \
    }                                                       \
})

#define IOSafeDeleteNULL(ptr, type, count)              \
    do {                                                \
        if (NULL != (ptr)) {                            \
            IODelete((ptr), type, count);               \
            (ptr) = NULL;                               \
        }                                               \
    } while (0)                                         \

#if TARGET_OS_DRIVERKIT && !DRIVERKIT_PRIVATE

/*!
 * @functiongroup OSByteOrder Macros
 * Subset of historical OSByteOrder macros that may still be in use by driver
 * projects. Should be considered as deprecated.
 */

#if defined(__BIG_ENDIAN__)

#define OSSwapLittleToHostInt16(x) __builtin_bswap16((uint16_t)(x))
#define OSSwapHostToLittleInt16(x) __builtin_bswap16((uint16_t)(x))
#define OSSwapLittleToHostInt32(x) __builtin_bswap32((uint32_t)(x))
#define OSSwapHostToLittleInt32(x) __builtin_bswap32((uint32_t)(x))
#define OSSwapLittleToHostInt64(x) __builtin_bswap64((uint64_t)(x))
#define OSSwapHostToLittleInt64(x) __builtin_bswap64((uint64_t)(x))

#define OSSwapBigToHostInt16(x) ((uint16_t)(x))
#define OSSwapHostToBigInt16(x) ((uint16_t)(x))
#define OSSwapBigToHostInt32(x) ((uint32_t)(x))
#define OSSwapHostToBigInt32(x) ((uint32_t)(x))
#define OSSwapBigToHostInt64(x) ((uint64_t)(x))
#define OSSwapHostToBigInt64(x) ((uint64_t)(x))

#elif defined(__LITTLE_ENDIAN__)

#define OSSwapLittleToHostInt16(x) ((uint16_t)(x))
#define OSSwapHostToLittleInt16(x) ((uint16_t)(x))
#define OSSwapLittleToHostInt32(x) ((uint32_t)(x))
#define OSSwapHostToLittleInt32(x) ((uint32_t)(x))
#define OSSwapLittleToHostInt64(x) ((uint64_t)(x))
#define OSSwapHostToLittleInt64(x) ((uint64_t)(x))

#define OSSwapBigToHostInt16(x) __builtin_bswap16((uint16_t)(x))
#define OSSwapHostToBigInt16(x) __builtin_bswap16((uint16_t)(x))
#define OSSwapBigToHostInt32(x) __builtin_bswap32((uint32_t)(x))
#define OSSwapHostToBigInt32(x) __builtin_bswap32((uint32_t)(x))
#define OSSwapBigToHostInt64(x) __builtin_bswap64((uint64_t)(x))
#define OSSwapHostToBigInt64(x) __builtin_bswap64((uint64_t)(x))

#else
#error Unknown endianess.
#endif

#endif // TARGET_OS_DRIVERKIT && !DRIVERKIT_PRIVATE

#if !TARGET_OS_DRIVERKIT
extern kern_return_t
IOUserServerMain(const char * serverName, const char * serverTagStr, uint32_t bundleCount, const char * bundles[]);

extern int
DriverExecutableMain(int argc, char * argv[]);
#endif // TARGET_OS_DRIVERKIT

extern uint64_t IOVMPageSize;

kern_return_t
_ZN18IOMemoryDescriptor3MapEyyyyPyS0_PFiP15OSMetaClassBase5IORPCE(
		void * md,
		uint64_t options,
		uint64_t address,
		uint64_t length,
		uint64_t alignment,
		uint64_t * returnAddress,
		uint64_t * returnLength,
		void * supermethod);

__END_DECLS

#endif /* DRIVERKIT_IOLIB_H */
