#include <stdio.h>

#include "030_multibyte_arrays.h"

pixel_t pixels[3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int main() {
    for (int i = 0; i < 3; i++) {
        printf("pixel %d: x=%d, y=%d, z=%d\n", i, pixels[i].x, pixels[i].y, pixels[i].z);
    }
    
    return 0;
}