/*
*
* Copyright (c) 2015, The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above
*       copyright notice, this list of conditions and the following
*       disclaimer in the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of The Linux Foundation nor the names of its
*       contributors may be used to endorse or promote products derived
*       from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
* ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#ifndef ANDROID_PIEZOSOUND_INTERFACE_H
#define ANDROID_PIEZOSOUND_INTERFACE_H

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <hardware/hardware.h>

__BEGIN_DECLS

/**
 * The id of this module
 */
#define PIEZO_HARDWARE_MODULE_ID "piezosound"

typedef void (* piezo_cmd_done_callback)(void *data);

typedef struct {
    size_t size;
    piezo_cmd_done_callback cmd_done_cb;
}piezo_callbacks;

struct piezo_params_t {

    /**
       * The following is the params need to be set to sysfs control files
       *
       * frequency - in Hz
       *                   The optimum frequency range supported is from 1 kHz to 6 kHz
       * duration -   in ms
       * duty_cycle - in percentage i.e, 1 ~ 100%
       * command - 0 : off 1: on
       * Returns: 0 on succes, error code on failure.
       */
    uint32_t frequency;
    uint32_t duration;
    uint32_t duty_cycle;
};

struct piezo_device_t {
    struct hw_device_t common;

    int (*register_callbacks)(piezo_callbacks *callbacks);

    /*
        * Set kernel control files with the provided values.
        *
        * Returns: 0 on succes, error code on failure.
        */
    int (*run_piezo)(struct piezo_params_t const *params);

    int (*cancel_piezo)(void);
};

__END_DECLS

#endif  // ANDROID_PIEZOSOUND_INTERFACE_H
