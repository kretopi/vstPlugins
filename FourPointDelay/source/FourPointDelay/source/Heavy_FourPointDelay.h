/**
 * Copyright (c) 2018 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_FOURPOINTDELAY_H_
#define _HEAVY_FOURPOINTDELAY_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif

typedef enum {
  HV_FOURPOINTDELAY_PARAM_IN__1FEED = 0xA43D8EBB, // 1feed
  HV_FOURPOINTDELAY_PARAM_IN__1POINT = 0xAE922D5E, // 1point
  HV_FOURPOINTDELAY_PARAM_IN__1TIME = 0x6A401883, // 1time
  HV_FOURPOINTDELAY_PARAM_IN__1VOL = 0x8D622449, // 1vol
  HV_FOURPOINTDELAY_PARAM_IN__2FEED = 0x529E72F3, // 2feed
  HV_FOURPOINTDELAY_PARAM_IN__2POINT = 0xCBD550B1, // 2point
  HV_FOURPOINTDELAY_PARAM_IN__2TIME = 0x686A73A8, // 2time
  HV_FOURPOINTDELAY_PARAM_IN__2VOL = 0xBD7BB228, // 2vol
  HV_FOURPOINTDELAY_PARAM_IN__3FEED = 0x803EB744, // 3feed
  HV_FOURPOINTDELAY_PARAM_IN__3POINT = 0x244F5F9E, // 3point
  HV_FOURPOINTDELAY_PARAM_IN__3TIME = 0x52ECA77D, // 3time
  HV_FOURPOINTDELAY_PARAM_IN__3VOL = 0xBE49A30F, // 3vol
  HV_FOURPOINTDELAY_PARAM_IN__4FEED = 0xF294C022, // 4feed
  HV_FOURPOINTDELAY_PARAM_IN__4POINT = 0xB7BCDFBB, // 4point
  HV_FOURPOINTDELAY_PARAM_IN__4TIME = 0xB2A79489, // 4time
  HV_FOURPOINTDELAY_PARAM_IN__4VOL = 0xF2256234, // 4vol
  HV_FOURPOINTDELAY_PARAM_IN_DRY = 0xBA8CED4E, // dry
  HV_FOURPOINTDELAY_PARAM_IN_WET = 0x1B53CD5A, // wet
} Hv_FourPointDelay_ParameterIn;


/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_FourPointDelay_new(double sampleRate);

/**
 * Creates a new patch instance.
 * @param sampleRate  Sample rate should be positive (> 0) and in Hertz, e.g. 48000.0.
 * @param poolKb  Pool size is in kilobytes, and determines the maximum amount of memory
 *   allocated to messages at any time. By default this is 10 KB.
 * @param inQueueKb  The size of the input message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages between calls to
 *   process(). Default is 2 KB.
 * @param outQueueKb  The size of the output message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages to the default sendHook.
 *   See getNextSentMessage() for info on accessing these messages. Default is 0 KB.
 */
HeavyContextInterface *hv_FourPointDelay_new_with_options(double sampleRate, int poolKb, int inQueueKb, int outQueueKb);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_FOURPOINTDELAY_H_
