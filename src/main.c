#include <stdbool.h>
#include "gpio.h"

#define LED_PORT 1
#define LED_PIN 6
#define TECLA_PORT 1
#define TECLA_PIN 7

int main(void){

    gpio_t led_rojo = gpioCreate(LED_PORT, LED_PIN, true, true);
    gpio_t tecla_1 = gpioCreate(TECLA_PORT, TECLA_PIN, false, true);

    while(true){
        if(gpioGetValue(tecla_1) == 0) {
            gpioSetOuput(led_rojo, true);
        } else {
            gpioSetOuput(led_rojo, false);
        }
    }

    return 0;
}