#include <stdint.h>
#include "swervolf_nexys.h"

volatile uint32_t* const port_led     = (uint32_t*) GPIO_BASE;
volatile uint32_t* const port_sw      = (uint32_t*) SWITCH_BASE;

void delay();

void main()
{

    while(1){
        *port_led |= (1);   // led-on
        delay();
        *port_led &= ~(1);  // led-off
        delay();
    }
}

void delay()
{
    uint32_t i=0;
    for(i=0;i<100000;i++);
    return;
}