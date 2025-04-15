#ifndef TIM.H
#define TIM.H

#include "stm32f407xx.h"

void tim_init();
void tim2_start();
void tim3_start();
void tim2_stop();
void tim3_stop();
void tim4_start();
void tim4_stop();
uint32_t  random_number() ;

#endif
