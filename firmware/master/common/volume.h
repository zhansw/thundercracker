/*
 * Thundercracker Firmware -- Confidential, not for redistribution.
 * Copyright <c> 2012 Sifteo, Inc. All rights reserved.
 */

#ifndef _VOLUME_H
#define _VOLUME_H

#include "systime.h"
#include <stdint.h>

namespace Volume
{
    enum CalibrationState {
        CalibrationLow,
        CalibrationHigh
    };

    void init();
    int calibrate(CalibrationState state);

    /*
     * Current system volume.
     *
     * Unlike the individual mixer volumes, this is a 16-bit value
     * in order to give us enough dynamic range to be very very quiet
     * without dropping out completely.
     */
    int systemVolume();
    bool isActive();

    void task();

    static const int MAX_VOLUME = 0x10000;
    static const int MAX_VOLUME_LOG2 = 16;
}

#endif // _VOLUME_H
