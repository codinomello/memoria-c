#include <stdio.h>

#include "031_array_casting.h"

void dump_graphics(graphics_t gsettings[10]) {
    int *ptr = (int *)gsettings;
    for (int i = 0; i < 60; i++) {
        printf("settings[%d] = %d\n", i, ptr[i]);
    }
}

int main() {
    graphics_t gsettings[10] = {
        {800, 600, 32},
        {1024, 768, 24},
        {1280, 720, 16},
        {1920, 1080, 32},
        {2560, 1440, 24},
        {3840, 2160, 32},
        {640, 480, 16},
        {320, 240, 8},
        {1600, 900, 24},
        {1366, 768, 32}
    };

    dump_graphics(gsettings);

    printf("sizeof graphics_t: %zu\n", sizeof(graphics_t));
    
    return 0;
}