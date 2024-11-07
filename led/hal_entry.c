/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-10     Sherman       first version
 */

#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>

#define LED_USER1    BSP_IO_PORT_02_PIN_09 /* Onboard LED pins */
#define LED_USER2    BSP_IO_PORT_02_PIN_10 /* Onboard LED pins */

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");

    while (1)
    {
        rt_pin_write(LED_USER1, PIN_HIGH);
        rt_pin_write(LED_USER2, PIN_LOW);
        rt_thread_mdelay(500);
        rt_pin_write(LED_USER1, PIN_LOW);
        rt_pin_write(LED_USER2, PIN_HIGH);
        rt_thread_mdelay(500);
    }
}
