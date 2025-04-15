#include "tim.h"

void tim_init()
{

    //TIM2  9adeh random delay bsh tabda game

    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; 
    TIM2->PSC = 16000;                  
    TIM2->ARR = 10000;                  
    TIM2->SR = 0;                     
    TIM2->DIER |= TIM_DIER_UIE;       
    NVIC_EnableIRQ(TIM2_IRQn);          
    
                      
   //TIM3 bch tchouf reaction time

    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    TIM3->PSC = 16000;
    TIM3->ARR = 100000;
    TIM3->DIER |=(1<<0);
    NVIC_EnableIRQ(TIM3_IRQn);
    
    
    

    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    TIM4->PSC = 16000;
    TIM4->ARR = 0xFFFF;
  
    TIM4->SR = 0; 

}
void tim2_start() {
    
    TIM2->CR1 |= (1<<0);  
}

void tim3_start()
{
    TIM3->CR1 |=(1<<0);
}
void tim2_stop()
{
    TIM2->CR1 &=~(1<<0);
    
}
void tim3_stop()
{
    TIM3->CR1 &=~(1<<0);
}
void tim4_start()
{
    TIM4->CR1 |=(1<<0);
}
void tim4_stop()
{
    TIM4->CR1 &=~(1<<0);
}

uint32_t  random_number()
{
    uint32_t seed = TIM4->CNT & 0x0FFF;  
    return 1500 + (seed % 3501);  //  valeur entre 5000 - 1500
} 
