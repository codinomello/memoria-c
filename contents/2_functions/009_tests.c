#include <stdio.h>

#include "009_tests.h"

float get_average(int x, int y, int z) {
    return (float)(x + y + z) / 3.0;
}

int main() {
    float average = get_average(1, 2, 3);
    printf("average: %.1f\n", average);
   
    return 0;
}