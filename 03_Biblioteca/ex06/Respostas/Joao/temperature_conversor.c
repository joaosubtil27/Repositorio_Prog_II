#include "temperature_conversor.h"

float convert_celsius_to_kelvin(float temperature)
{

    return temperature + 273.15;
}

float convert_celsius_to_fahrenheit(float temperature)
{
    return (temperature * 1.8) + 32;
}

float convert_kelvin_to_celsius(float temperature)
{

    return temperature - 273.15;
}

float convert_kelvin_to_fahrenheit(float temperature)
{

    return (9 * (temperature - 273.15) / 5) + 32;
}

float convert_fahrenheit_to_celsius(float temperature)
{

    return 5 * (temperature - 32) / 9;
}

float convert_fahrenheit_to_kelvin(float temperature)
{

    return (5 * (temperature - 32) / 9) + 273.15;
}

float convert_temperature(float temperature, float convert_func(float temperature))
{

    return convert_func(temperature);
}
