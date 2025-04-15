#include "stm32f407xx.h"
#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "exti.h"
#include "uart.h"
#include <stdio.h>
#include "rng.h"

uint8_t game_on = 0;



void EXTI1_IRQHandler()
{
    if ((EXTI->PR & (1 << 1)) && game_on==0)   
    {
        
        
        GPIOD->ODR &= ~(1 << 0);  // RED OFF - GREEN ON
        int rng = random_number();
        TIM2->ARR =rng ; 
        tim2_start();
        TIM4->CNT = 0;
        EXTI->PR = (1 << 1);
    }
}

void EXTI4_IRQHandler()
{
    if (EXTI->PR & (1 << 4))   
    {
       
       if (game_on==1)
       {
           tim3_stop();
           game_on=0; 
           transmit_tim_cnt();
           GPIOD->ODR |=(1<<1);
           GPIOD->ODR |=(1<<0);
           TIM3->CNT=0;
              
       }
       else 
       {
        tim3_stop();
        tim2_stop();
        uart_transmit_string("TOO EARLY ! \n");
        GPIOD->ODR |=(1<<1);
        GPIOD->ODR |=(1<<0);
        
        TIM3->CNT=0;
        game_on=0;
       }

       EXTI->PR =(1<<4);
    }
}

int main()
{

    
    
    exti4_init();
    exti1_init();
    gpio_init();
    tim_init();
    uart_init();
    tim4_start();
    
    
    GPIOD->ODR |= (1<<0);   // GREEN - RED   ON melowel
    GPIOD->ODR |=(1<<1);

    
    while(1)
    {
    }
    
}

void TIM2_IRQHandler()
{
    
    TIM2->SR = 0;  
    GPIOD->ODR &= ~(1 << 1); // GREEN OFF
    GPIOD->ODR |= (1 << 0);  // RED ON 
        
    tim2_stop();
    tim3_start();
    game_on = 1;
}
    

void TIM3_IRQHandler()
{
    if (TIM3->SR & (1<<0))
    {
       
    }
}