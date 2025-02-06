#include "temperature_conversor.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temperature;
    char esc1, esc2;

    scanf("%f %c %c", &temperature, &esc1, &esc2);

    if (esc1 == 'c')
    {
        if (esc2 == 'f')
            printf("Temperature: %.2fFº", convert_temperature(temperature, convert_celsius_to_fahrenheit));

        if (esc2 == 'k')
            printf("Temperature: %.2fK", convert_temperature(temperature, convert_celsius_to_kelvin));
    }

    if (esc1 == 'f')
    {
        if (esc2 == 'c')
            printf("Temperature: %.2fCº", convert_temperature(temperature, convert_fahrenheit_to_celsius));

        if (esc2 == 'k')
            printf("Temperature: %.2fK", convert_temperature(temperature, convert_fahrenheit_to_kelvin));
    }

    if (esc1 == 'k')
    {
        if (esc2 == 'c')
            printf("Temperature: %.2fCº", convert_temperature(temperature, convert_kelvin_to_celsius));

        if (esc2 == 'f')
            printf("Temperature: %.2fFº", convert_temperature(temperature, convert_kelvin_to_fahrenheit));
    }
}