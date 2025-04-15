#include "gpio.h"
#include "stm32f407xx.h"


void gpio_init()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER &= ~(3<<2*0);
    GPIOD->MODER |=  (1<<2*0); 
    
    GPIOD->MODER &= ~(3<<2*1);
    GPIOD->MODER |=  (1<<2*1); 
    // PD1-PD2 outputs
}
