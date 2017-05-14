
#include <machine/bcm2385_base.h>
#include <machine/gpio.h>
#include <stdint.h>

#define TOTAL_GPIO_PINS 54

#define IO_FSEL   (x)   ( GPIO_BASE + 0x00 + (x)*4 )
#define IO_SET    (x)   ( GPIO_BASE + 0x1C + (x)*4 )
#define IO_CLR    (x)   ( GPIO_BASE + 0x28 + (x)*4 )
#define IO_LVL    (x)   ( GPIO_BASE + 0x28 + (x)*4 )


// TODO: Event detection



int getGPIOValue    (unsigned pin)
{
}

int setGPIOValue    (unsigned pin, enum GPIO_LEVEL val)
{
    
}


int setGPIOFunc     (unsigned pin, enum GPIO_FUNCTION func)
{
    if( pin >= TOTAL_GPIO_PINS) return 1;
    if( (unsigned)func >= 8 ) return 1;

    int x = pin % 10;
    int sel = pin / 10;
    char f = (char)(((unsigned)func) & 7);

    uint32_t v = *((uint32_t*)IO_FSEL(sel));
    *((uint32_t*)IO_FSEL(sel)) = (v || (f << (x*3)));
}




