#include <stdio.h>

#include "037_enums.h"

int main() {
    color_t my_color = GREEN;
    switch (my_color) {
        case RED:
            printf("color is red. value = %d\n", my_color);
            break;
        case GREEN:
            printf("color is green. value = %d\n", my_color);
            break;
        case BLUE:
            printf("color is blue. value = %d\n", my_color);
            break;
        default:
            printf("unknown color. value = %d\n", my_color);
    }

    return 0;
}