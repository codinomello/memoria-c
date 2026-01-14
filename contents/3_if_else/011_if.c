#include <stdio.h>

#include "011_if.h"

char *get_temperature_status(int temp) {
    if (temp < 70) {
        return "too cold";
    } else if (temp > 90) {
        return "too hot";
    } else {
        return "just right";
    }
}

int main() {
    int temp = 75;
    printf("temperature is %d, which is %s\n", temp, get_temperature_status(temp));
   
    return 0;
}