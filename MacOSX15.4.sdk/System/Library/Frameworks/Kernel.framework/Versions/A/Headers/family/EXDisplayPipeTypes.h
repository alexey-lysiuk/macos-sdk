//
//  EXDisplayPipeTypes.h
//  EXDisplayPipeDriver
//
//  Created by Clement Moussu on 2/14/23.
//

#include <stdint.h>
#include <stdbool.h>

#pragma once

#define ENABLE_EXCLAVE_REG_INTERRUPTS 1
#define EXDISPLAY_PIPE_TIMER_PERIOD_MS 8

#define EXDISP_COMPANION_TELEMETRY_TIMER_PERIOD_MS (24 * 60 * 60 * 1000)

#define EXDISP_USE_COMPANION_KEXT_TIMER 0

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
    INDICATOR_CAM = 0,
    INDICATOR_MIC = 1,
    INDICATOR_MIC_ALT_ACCESSIBILITY = 2,
    INDICATOR_COUNT
} EXDisplayPipeIndicator;

#define EXDISP_SCL_REGION_COUNT 4

#define CANCELLED_QUEUE_MAX_LENGTH 10
#define DROPPED_QUEUE_MAX_LENGTH 10
#define SECURE_TE_INFO_MAX_LENGTH 10

typedef struct
{
    uint16_t x;
    uint16_t y;
    float alpha;
} EXDisplayPipeIndicatorParams;

typedef struct
{
    uint64_t timestamp;
    bool health;
} EXDisplayPipeHealthRecord;

typedef struct
{
    EXDisplayPipeHealthRecord sca_driver_health;
    EXDisplayPipeHealthRecord sca_algorithm_health;
    EXDisplayPipeHealthRecord scl_health;
    EXDisplayPipeHealthRecord pipe_health;
    EXDisplayPipeHealthRecord link_health;
    bool health;
} EXDisplayPipeHealthReport;

typedef struct
{
    uint64_t displayedSwapID;
    bool validDisplayedID;
    bool poweredOn;
    struct
    {
        EXDisplayPipeIndicator indicator;
        uint16_t x;
        uint16_t y;
        uint16_t w;
        uint16_t h;
        float alpha;
        bool enabled;
        bool populated;
    } indicators[EXDISP_SCL_REGION_COUNT];
    EXDisplayPipeHealthReport health_report;
    uint64_t cancelledQueue[CANCELLED_QUEUE_MAX_LENGTH];
    uint64_t droppedQueue[DROPPED_QUEUE_MAX_LENGTH];
    uint8_t cancelledCount;
    uint8_t droppedCount;
} EXDisplayPipeStatus;

typedef struct
{
    EXDisplayPipeHealthRecord healthRecord;
    uint64_t errorCount;
    uint64_t lastErrorTimestamp;
    uint64_t maxConsecutiveErrors;
    uint64_t lastErrorVal;
    bool enabled;
    struct {
        uint64_t prevTimebase;
        uint64_t prevTimestamp;
        uint64_t currTimebase;
        uint64_t currTimestamp;
        uint64_t timeDiff;
        uint64_t timebaseDiff;
    } errorInfo[SECURE_TE_INFO_MAX_LENGTH];
    int errorInfoCount;
} EXDisplayPipeSecureTEStatus;

// kEXBrightMessageFunction API
// callPlatformFunction( kEXBrightMessageFunction, false,
//                       param1 = msgSize (size_t *),
//                       param2 = msg (EXBrightMessage *),
//                       nullptr, nullptr )
#define kEXBrightMessageFunction "EXBrightMessageFunction"

typedef enum
{
    kLoadALSSCalibration = 0
} EXBrightMessageType;


typedef struct
{
    EXBrightMessageType type;
    uint32_t arg0;
    uint32_t arg1;
} EXBrightMessage;

#ifdef __cplusplus
}
#endif
