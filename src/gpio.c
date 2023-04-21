#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "gpio.h"
//#include "config.h"

#ifndef GPIO_COUNT
#define GPIO_COUNT 6
#endif

struct gpio_s {
    uint8_t port;
    uint8_t pin;
    bool output;
    bool alocated;
    bool inverted;
};

gpio_t gpioAlocate(void){
    static struct gpio_s instances[GPIO_COUNT] = {0};
    gpio_t result = NULL;

    for (int indice = 0; indice < GPIO_COUNT; indice++)
    {
        if (instances[indice].alocated == false)
        {
            result = &instances[indice];
            result->alocated = true;
            break;
        }
    }
    return result;
}

gpio_t gpioCreate(uint8_t port, uint8_t pin, bool output, bool inverted){
    #ifdef STATIC
        gpio_t result = maloc(sizeof(struct gpio_s));
    #else
        gpio_t result = gpioAlocate();
    #endif
    
    if(result){
        result->port = port;
        result->pin = pin;
        result->output = output;
        result->inverted = inverted;
        /* Lo configuro como entrada*/
    }
    return result;
}

bool gpioGetValue(gpio_t output){
    if (output->inverted)
    {
        //...
    } else {
        //...
    }
}

void gpioSetValue(gpio_t output, bool value){
    if(output->output){
        //...
    }
}