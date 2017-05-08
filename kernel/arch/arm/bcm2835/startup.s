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

/* Constants */

    /* APSR bits */
    .equ    I_BIT,      0x80    /* For IRQ */
    .equ    F_BIT,      0x40    /* For FIQ */
    .equ    USR_MODE,   0x10
    .equ    FIQ_MODE,   0x11¬
    .equ    IRQ_MODE,   0x12¬
    .equ    SVC_MODE,   0x13¬
    .equ    ABT_MODE,   0x17¬
    .equ    UND_MODE,   0x1B¬
    .equ    SYS_MODE,   0x1F¬


/**
 * Startup code
 */
    .text
    .arm
    .global _start
    .func   _start

_start:
    /*
     * Vector table
     * NOTE: It will be remapped to RAM.
     */
    b   _reset          /* RESET */
    b   .               /* UNDEFINED INSTRUCTION */
    b   .               /* SOFTWARE INTERRUPT */
    b   .               /* PREFETCH ABORT */
    b   .               /* DATA ABORT */
    b   .               /* RESERVED */
    b   .               /* IRQ */
    b   .               /* FIQ */


/*
 * reset handler
 */
_reset:
    /*
     * Call platform dependent low level init
     */
    ldr     r0, =_reset
    ldr     r1, =_cstartup
    mov     lr, r1
    ldr     sp, =__stack_end__
    b       low_level_init      /* TODO: Rename this routine */

    /*
     * NOTE: After return from low level init code, ROM is remapped to its linked addresses in RAM.
     */
_cstartup:
    /* Relocate .fastcode section */
    ldr     r0, =__fastcode_load
    ldr     r1, =__fastcode_start
    ldr     r2, =__fastcode_end
1:
    cmp     r1, r2
    ldrlt   r3, [r0], #4
    strlt   r3, [r1], #4
    blt     1b

     /* Relocate .data section */
    ldr     r0, =__data_load
    ldr     r1, =__data_start
    ldr     r2, =_edata
1:
    cmp     r1, r2
    ldrlt   r3, [r0], #4
    strlt   r3, [r1], #4
    blt     1b

    /* Relocate .bss section and zero init */
    ldr     r1, =__bss_start__
    ldr     r2, =__bss_end__
    mov     r3, #0
1:
    cmp     r1, r2
    strlt   r3, [r1], #4
    blt     1b

   /* Relocate .stack section */
    ldr     r1, =__stack_start__
    ldr     r2, =__stack_end__
    ldr     r3, =STACK_FILL
1:
    cmp     r1, r2
    strlt   r3, [r1], #4
    blt     1b

    /* Initialize stack pointers for all modes
     *
     * 1. Change mode by setting CPSR.
     * 2. Change the stack pointer.
     * 3. Switch mode
     */

    msr     cpsr_c, #(IRQ_MODE | I_BIT | F_BIT)
    ldr     sp, =__irq_stack_top__

    msr     cpsr_c, #(FIQ_MODE | I_BIT | F_BIT)
    ldr     sp, =__fiq_stack_top__

    msr     cpsr_c, #(SVC_MODE | I_BIT | F_BIT)
    ldr     sp, =__svc_stack_top__

    msr     cpsr_c, #(ABT_MODE | I_BIT | F_BIT)
    ldr     sp, =__abt_stack_top__

    msr     cpsr_c, #(UND_MODE | I_BIT | F_BIT)
    ldr     sp, =__und_stack_top__

    msr     cpsr_c, #(SYS_MODE | I_BIT | F_BIT)
    ldr     sp, =__sys_stack_top__

    /* invoke static constructors */
    ldr     ip, =__libc_init_array
    mov     lr, pc      /* set return address */
    bx      ip          /* run function. bx takes care of switch from ARM to THUMB */

    ldr     ip, =main
    mov     lr, pc
    bx      ip

    swi     0xFFFFFF

    .size   _start, . - _start
    .endfunc

    .end

