
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

int setGPIOValue    (unsigned pin, unsigned val)
{
}


#define GPIO_INPUT  0x0
#define GPIO_OUTPUT 0x1
#define GPIO_FUNC0  0x4
#define GPIO_FUNC1  0x5
#define GPIO_FUNC2  0x6
#define GPIO_FUNC3  0x7
#define GPIO_FUNC4  0x3
#define GPIO_FUNC5  0x2

int setGPIOFunc     (unsigned pin, unsigned func)
{
    if( pin >= TOTAL_GPIO_PINS) return 1;
    if( func >= 8 ) return 1;

    *((uint32_t) IO_FSEL
    
}




