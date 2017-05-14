/*
 * Copyright (c) 2017 <name of copyright holder>
 * Author: Balakrishnan, Anand <anandbala1597@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */



#ifndef __BCM2385_PLATFORM_H__
#define __BCM2385_PLATFORM_H__


#define P_BASE          0x20000000

#define SYSTIMER_BASE   (P_BASE + 0x3000)
#define DMA_BASE        (P_BASE + 0x7000)
#define ARM_BASE    (P_BASE + 0xB000)

#define PM_BASE         (P_BASE + 0x100000)
#define RNG_BASE        (P_BASE + 0x104000)

#define GPIO_BASE       (P_BASE + 0x200000)

#define UART0_BASE      (P_BASE + 0x201000)
#define UART1_BASE      (P_BASE + 0x215000)

#define MMCI0_BASE      (P_BASE + 0x202000)
#define EMMC_BASE       (P_BASE + 0x300000)

#define SPI0_BASE       (P_BASE + 0x204000)


#define ARM_IC_BASE     (ARM_BASE + 0x200)
#define ARM_TIMER_BASE  (ARM_BASE + 0x400)
#define ARM_SBM_BASE    (ARM_BASE + 0x800)


#endif

