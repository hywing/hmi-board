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

#define USER_KEY0      BSP_IO_PORT_00_PIN_05 /* Onboard TN0 pins */
#define USER_KEY1      BSP_IO_PORT_00_PIN_06 /* Onboard TN1 pins */

void led0_callback(void *args)
{
    int val = rt_pin_read(USER_KEY0);
    if(val == 1) {
        rt_pin_write(LED_USER1, PIN_HIGH);
    }
    else {
        rt_pin_write(LED_USER1, PIN_LOW);
    }
}

void led1_callback(void *args)
{
    int val = rt_pin_read(USER_KEY1);
    if(val == 1) {
        rt_pin_write(LED_USER2, PIN_HIGH);
    }
    else {
        rt_pin_write(LED_USER2, PIN_LOW);
    }
}

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");

    rt_pin_mode(USER_KEY0, PIN_MODE_INPUT_PULLUP);
    rt_pin_attach_irq(USER_KEY0, PIN_IRQ_MODE_RISING_FALLING, led0_callback, RT_NULL);
    rt_pin_irq_enable(USER_KEY0, PIN_IRQ_ENABLE);

    rt_pin_mode(USER_KEY1, PIN_MODE_INPUT_PULLUP);
    rt_pin_attach_irq(USER_KEY1, PIN_IRQ_MODE_RISING_FALLING, led1_callback, RT_NULL);
    rt_pin_irq_enable(USER_KEY1, PIN_IRQ_ENABLE);

    while (1)
    {
        rt_thread_mdelay(500);
    }
}
