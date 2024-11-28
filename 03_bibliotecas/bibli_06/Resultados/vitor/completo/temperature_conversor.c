#include "temperature_conversor.h"

float convert_celsius_to_kelvin(float temperature) {
    return temperature + 273.15;
}

float convert_celsius_to_fahrenheit(float temperature) {
    return ((9.0 / 5.0) * temperature) + 32;
}

float convert_kelvin_to_celsius(float temperature) {
    return temperature - 273.15;
}

float convert_kelvin_to_fahrenheit(float temperature) {
    temperature = convert_kelvin_to_celsius(temperature);
    return convert_celsius_to_fahrenheit(temperature);
}

float convert_fahrenheit_to_celsius(float temperature) {
    return (5.0 / 9.0) * (temperature - 32);
}

float convert_fahrenheit_to_kelvin(float temperature) {
    temperature = convert_fahrenheit_to_celsius(temperature);
    return convert_celsius_to_kelvin(temperature);
}

float convert_temperature(float temperature, float convert_func(float temperature)) {
    return convert_func(temperature);
}
