
#include <machine/bcm2835_base.h>
#include <machine/gpio.h>

#define TOTAL_GPIO_PINS 54

#define IO_FSEL(x)  (volatile unsigned*)(GPIO_BASE + 0x00 + (x)*4)
#define IO_SET(x)   (volatile unsigned*)(GPIO_BASE + 0x1C + (x)*4)
#define IO_CLR(x)   (volatile unsigned*)(GPIO_BASE + 0x28 + (x)*4)
#define IO_LVL(x)   (volatile unsigned*)(GPIO_BASE + 0x28 + (x)*4)



void getGPIOPinBlock (unsigned* highGPIO, unsigned* lowGPIO)
{
    *highGPIO   = *(unsigned*)(IO_LVL(1));
    *lowGPIO    = *(unsigned*)(IO_LVL(0));
}


int getGPIOValue    (unsigned pin)
{
    if( pin >= TOTAL_GPIO_PINS ) return -1;
    
    volatile unsigned* addr = IO_LVL(pin/32);
    volatile unsigned mask = 0x1 << (pin%32);
    return ((*addr) & (~mask)) >> (pin%32);
}

int setGPIOValue    (unsigned pin, enum GPIO_LEVEL val)
{
    if( pin >= TOTAL_GPIO_PINS) return -1;

    volatile unsigned* addr = (val == 1) ? (IO_SET(pin/32)) : (IO_CLR(pin/32));
    *addr = (1 << (pin%32));
}


int setGPIOFunc     (unsigned pin, enum GPIO_FUNCTION func)
{
    if( pin >= TOTAL_GPIO_PINS) return -1;
    if( (unsigned)func >= 8 ) return -1;

    int x = pin % 10;
    int sel = pin / 10;
    char f = (char)(((unsigned)func) & 7);

    *(volatile unsigned*)(IO_FSEL(sel)) |= (f << (x*3));

    return 0;
}




