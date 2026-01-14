#include <stdio.h>

#include "020_structs.h"

void print_coordinate(struct Coordinate coord) {
    printf("coordinate: x = %d, y = %d, z = %d\n", coord.x, coord.y, coord.z);
}

int main() {
    struct Coordinate point = {10, 20, 30};
    print_coordinate(point);
    
    return 0;
}