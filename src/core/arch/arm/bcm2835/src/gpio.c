
#include <machine/bcm2835_base.h>
#include <machine/gpio.h>
#include <stdint.h>


#define TOTAL_GPIO_PINS 54

#define GPFSEL0 (volatile unsigned*)(GPIO_BASE + 0x00)
#define GPFSEL1 (volatile unsigned*)(GPIO_BASE + 0x04)
#define GPFSEL2 (volatile unsigned*)(GPIO_BASE + 0x08)
#define GPFSEL3 (volatile unsigned*)(GPIO_BASE + 0x0C)
#define GPFSEL4 (volatile unsigned*)(GPIO_BASE + 0x10)
#define GPFSEL5 (volatile unsigned*)(GPIO_BASE + 0x14)

#define GPFSEL(x)   (volatile unsigned*)(GPIO_BASE + 0x00 + (x)*4)

#define GPSET0  (volatile unsigned*)(GPIO_BASE + 0x1C)
#define GPSET1  (volatile unsigned*)(GPIO_BASE + 0x20)

#define GPCLR0  (volatile unsigned*)(GPIO_BASE + 0x28)
#define GPCLR1  (volatile unsigned*)(GPIO_BASE + 0x2C)

#define GPLEV0  (volatile unsigned*)(GPIO_BASE + 0x34)
#define GPLEV1  (volatile unsigned*)(GPIO_BASE + 0x38)



void getGPIOPinBlock (unsigned* highGPIO, unsigned* lowGPIO)
{
    *highGPIO   = *(unsigned*)(GPLEV1);
    *lowGPIO    = *(unsigned*)(GPLEV0);
}


int getGPIOValue    (unsigned pin)
{
    if( pin >= TOTAL_GPIO_PINS ) return -1;

    uint32_t port = (pin >= 32) ? 1 : 0;
    unsigned mask = 1 << (pin - (32*port));

    volatile unsigned* addr = (port == 0) ? GPLEV0 : GPLEV1;
    return ((*addr) & (~mask)) >> (pin - (32*port));
}

int setGPIOValue    (unsigned pin, enum GPIO_LEVEL val)
{

    if( pin >= TOTAL_GPIO_PINS ) return -1;
    unsigned port = (pin >= 32) ? 1 : 0;
    unsigned mask = 1 << (pin - (32*port));
    volatile unsigned* addr = (val == 1) ? ((port == 0) ? GPSET0 : GPSET1) : ((port == 0) ? GPCLR0 : GPCLR1);
    *addr = mask;
}


int setGPIOFunc     (unsigned pin, enum GPIO_FUNCTION func)
{
    if( pin >= TOTAL_GPIO_PINS ) return -1;
    if( (unsigned)func >= 8 ) return -1;

    int x = pin % 10;
    int sel = pin / 10;
    char f = (char)(((unsigned)func) & 7);

    *(volatile unsigned*)(GPFSEL(sel)) |= (f << (x*3));

    return 0;
}




