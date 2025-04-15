#include "exti.h"

void exti4_init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;    
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;   

    GPIOA->MODER &= ~(3 << 8);              
    SYSCFG->EXTICR[1] &= ~(0xF << 0);       
    EXTI->IMR |= (1 << 4);                  
    EXTI->RTSR |= (1 << 4);                 
    EXTI->FTSR &= ~(1 << 4);                
    GPIOA->PUPDR &= ~(3 << 8);              
    GPIOA->PUPDR |= (2 << 8);               
    NVIC_EnableIRQ(EXTI4_IRQn);             
}
void exti1_init() {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;     
    GPIOA->MODER &= ~(3 << (2 * 1));        

    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;    
    SYSCFG->EXTICR[0] &= ~(0xF << 4);      
    GPIOA->PUPDR &= ~(3 << (2 * 1));  
    GPIOA->PUPDR |= (2 << (2 * 1));   
    EXTI->IMR |= (1 << 1);    
    EXTI->RTSR |= (1 << 1);   
    NVIC_EnableIRQ(EXTI1_IRQn);  
}