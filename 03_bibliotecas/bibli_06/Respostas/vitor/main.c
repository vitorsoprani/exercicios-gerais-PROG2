#include <stdio.h>
#include <stdlib.h>
#include "temperature_conversor.h"

int main() {
    float temp;
    char atualScale, newScale;

    scanf("%f %c %c", &temp, &atualScale, &newScale);

    printf("Temperature: ");
    if (atualScale == 'c'){
        if (newScale == 'f') {
            printf("%.2fFº", convert_temperature(temp, convert_celsius_to_fahrenheit));
        } else if (newScale == 'k') {
            printf("%.2fK", convert_temperature(temp, convert_celsius_to_kelvin));
        } else {
            printf("[ERRO] Invalid new scale\n");
            exit(1);
        }
    } else if (atualScale == 'f') {
        if (newScale == 'c') {
            printf("%.2fCº", convert_temperature(temp, convert_fahrenheit_to_celsius));
        } else if (newScale == 'k') {
            printf("%.2fK", convert_temperature(temp, convert_fahrenheit_to_kelvin));
        } else {
            printf("[ERRO] Invalid new scale\n");
            exit(1);
        }
    } else if (atualScale == 'k') {
        if (newScale == 'c') {
            printf("%.2fCº", convert_temperature(temp, convert_kelvin_to_celsius));
        } else if (newScale == 'f') {
            printf("%.2fFº", convert_temperature(temp, convert_kelvin_to_fahrenheit));
        } else {
            printf("[ERRO] Invalid initial scale\n");
            exit(1);
        }
    } else{
        printf("[ERRO] Invalid scale\n");
        exit(1);
    }

    return 0;
}   