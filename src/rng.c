#include "rng.h"

void rng_init() {
    RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN;    
    RNG->CR &= ~RNG_CR_RNGEN;             
    RNG->SR = 0;                          
    RNG->CR |= RNG_CR_RNGEN;              
    RNG->CR |= RNG_CR_IE; 
    uint32_t timeout = 10000;             
    while (!(RNG->SR & RNG_SR_DRDY) && timeout--);
}
uint32_t rng_get_random(void) {
    uint32_t timeout = 10000;
    while (!(RNG->SR & RNG_SR_DRDY) && timeout--); 
    return timeout ? RNG->DR : 0; 
}

uint32_t generate_random(void) {
    uint32_t random_value = rng_get_random();
    if (random_value == 0) return 5000; 
    else return (3000 + (random_value % 3000)); 
    
}