#include "uart.h"
#include <stdio.h>
#include <string.h>
#include "stm32f407xx.h"

void uart_init() {
    
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // PA2 = TX 
    GPIOA->MODER &= ~(3 << (2 * 2));
    GPIOA->MODER |= (2 << (2 * 2)); 
    GPIOA->AFR[0] |= (7 << (4 * 2)); 

    
    USART2->BRR = 16000000 / 9600; //BAUD rate 9600 lel HC06
    USART2->CR1 |= USART_CR1_TE;   // 
    USART2->CR1 |= USART_CR1_UE;   //
}

void uart_transmit_string(const char* str) {
    
    for (int i = 0; str[i] != '\0'; i++) {
        while (!(USART2->SR & USART_SR_TXE));
        USART2->DR = str[i];
    }
}

void transmit_tim_cnt() {
    char buf[50]; 
    uint32_t cnt = TIM3->CNT; //  TICK NUMBER
    sprintf(buf, "Your reaction time is: %lu ms\n", cnt);
    uart_transmit_string(buf); 
}


