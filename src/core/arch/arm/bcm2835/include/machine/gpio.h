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

#ifndef __BCM2835_GPIO_H__
#define __BCM2835_GPIO_H__

/*
* GPIO_INPUT  0x0
* GPIO_OUTPUT 0x1
* GPIO_FUNC0  0x4
* GPIO_FUNC1  0x5
* GPIO_FUNC2  0x6
* GPIO_FUNC3  0x7
* GPIO_FUNC4  0x3
* GPIO_FUNC5  0x2
*/


enum GPIO_LEVEL {
    PIN_LOW, PIN_HIGH
};

enum GPIO_FUNCTION {
    GPIO_INPUT,
    GPIO_OUTPUT,
    GPIO_FUNC5,
    GPIO_FUNC4,
    GPIO_FUNC0,
    GPIO_FUNC1,
    GPIO_FUNC2,
    GPIO_FUNC3
};

void getGPIOPinBlock(unsigned* highGPIO, unsigned* lowGPIO); 
int getGPIOValue    (unsigned pin);
int setGPIOValue    (unsigned pin, enum GPIO_LEVEL val);
int setGPIOFunc     (unsigned pin, enum GPIO_FUNCTION func);

// TODO: Event detection
#endif
