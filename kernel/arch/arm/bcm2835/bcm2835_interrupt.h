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

#ifndef __BCM2835_INTERRUPTS_H__
#define __BCM2835_INTERRUPTS_H__

/*
 * Interrupt assignments
 */

#define INTERRUPT_TIMER0                (0)
#define INTERRUPT_TIMER1                (1)
#define INTERRUPT_TIMER2                (2)
#define INTERRUPT_TIMER3                (3)
#define INTERRUPT_CODEC0                (4)
#define INTERRUPT_CODEC1                (5)
#define INTERRUPT_CODEC2                (6)
#define INTERRUPT_VC_JPEG               (7)
#define INTERRUPT_ISP                   (8)
#define INTERRUPT_VC_USB                (9)
#define INTERRUPT_VC_3D                 (10)
#define INTERRUPT_TRANSPOSER            (11)
#define INTERRUPT_MULTICORESYNC0        (12)
#define INTERRUPT_MULTICORESYNC1        (13)
#define INTERRUPT_MULTICORESYNC2        (14)
#define INTERRUPT_MULTICORESYNC3        (15)
#define INTERRUPT_DMA0                  (16)
#define INTERRUPT_DMA1                  (17)
#define INTERRUPT_VC_DMA2               (18)
#define INTERRUPT_VC_DMA3               (19)
#define INTERRUPT_DMA4                  (20)
#define INTERRUPT_DMA5                  (21)
#define INTERRUPT_DMA6                  (22)
#define INTERRUPT_DMA7                  (23)
#define INTERRUPT_DMA8                  (24)
#define INTERRUPT_DMA9                  (25)
#define INTERRUPT_DMA10                 (26)
#define INTERRUPT_DMA11                 (27)
#define INTERRUPT_DMA12                 (28)
#define INTERRUPT_AUX                   (29)
#define INTERRUPT_ARM                   (30)
#define INTERRUPT_VPUDMA                (31)

#define INTERRUPT_HOSTPORT              (32 + 0)
#define INTERRUPT_VIDEOSCALER           (32 + 1)
#define INTERRUPT_CCP2TX                (32 + 2)
#define INTERRUPT_SDC                   (32 + 3)
#define INTERRUPT_DSI0                  (32 + 4)
#define INTERRUPT_AVE                   (32 + 5)
#define INTERRUPT_CAM0                  (32 + 6)
#define INTERRUPT_CAM1                  (32 + 7)
#define INTERRUPT_HDMI0                 (32 + 8)
#define INTERRUPT_HDMI1                 (32 + 9)
#define INTERRUPT_PIXELVALVE1           (32 + 10)
#define INTERRUPT_I2CSPISLV             (32 + 11)
#define INTERRUPT_DSI1                  (32 + 12)
#define INTERRUPT_PWA0                  (32 + 13)
#define INTERRUPT_PWA1                  (32 + 14)
#define INTERRUPT_CPR                   (32 + 15)
#define INTERRUPT_SMI                   (32 + 16)
#define INTERRUPT_GPIO0                 (32 + 17)
#define INTERRUPT_GPIO1                 (32 + 18)
#define INTERRUPT_GPIO2                 (32 + 19)
#define INTERRUPT_GPIO3                 (32 + 20)
#define INTERRUPT_VC_I2C                (32 + 21)
#define INTERRUPT_VC_SPI                (32 + 22)
#define INTERRUPT_VC_I2SPCM             (32 + 23)
#define INTERRUPT_VC_SDIO               (32 + 24)
#define INTERRUPT_VC_UART               (32 + 25)
#define INTERRUPT_SLIMBUS               (32 + 26)
#define INTERRUPT_VEC                   (32 + 27)
#define INTERRUPT_CPG                   (32 + 28)
#define INTERRUPT_RNG                   (32 + 29)
#define INTERRUPT_VC_ARASANSDIO         (32 + 30)
#define INTERRUPT_AVSPMON               (32 + 31)

#define ARM_IRQ_BASE                  64
#define INTERRUPT_ARM_TIMER            (ARM_IRQ_BASE + 0)
#define INTERRUPT_ARM_MAILBOX          (ARM_IRQ_BASE + 1)
#define INTERRUPT_ARM_DOORBELL_0       (ARM_IRQ_BASE + 2)
#define INTERRUPT_ARM_DOORBELL_1       (ARM_IRQ_BASE + 3)
#define INTERRUPT_VPU0_HALTED          (ARM_IRQ_BASE + 4)
#define INTERRUPT_VPU1_HALTED          (ARM_IRQ_BASE + 5)
#define INTERRUPT_ILLEGAL_TYPE0        (ARM_IRQ_BASE + 6)
#define INTERRUPT_ILLEGAL_TYPE1        (ARM_IRQ_BASE + 7)
#define INTERRUPT_PENDING1             (ARM_IRQ_BASE + 8)
#define INTERRUPT_PENDING2             (ARM_IRQ_BASE + 9)
#define INTERRUPT_JPEG                 (ARM_IRQ_BASE + 10)
#define INTERRUPT_USB                  (ARM_IRQ_BASE + 11)
#define INTERRUPT_3D                   (ARM_IRQ_BASE + 12)
#define INTERRUPT_DMA2                 (ARM_IRQ_BASE + 13)
#define INTERRUPT_DMA3                 (ARM_IRQ_BASE + 14)
#define INTERRUPT_I2C                  (ARM_IRQ_BASE + 15)
#define INTERRUPT_SPI                  (ARM_IRQ_BASE + 16)
#define INTERRUPT_I2SPCM               (ARM_IRQ_BASE + 17)
#define INTERRUPT_SDIO                 (ARM_IRQ_BASE + 18)
#define INTERRUPT_UART                 (ARM_IRQ_BASE + 19)
#define INTERRUPT_ARASANSDIO           (ARM_IRQ_BASE + 20)



#endif
