#include "stdlib.h"

#include "049_pointer_pointer.h"

void allocate_int(int **pointer_pointer, int value) {
    *pointer_pointer = (int *)malloc(sizeof(int));
    if (*pointer_pointer != NULL) {
        **pointer_pointer = value;
    }
}

int main() {
    int random = 5;
    int *my_pointer = &random;
    allocate_int(&my_pointer, 67);

    if (my_pointer != NULL) {
        printf("allocated integer value: %d\n", *my_pointer);
        free(my_pointer);
    } else {
        printf("memory allocation failed\n");
    }

    return 0;
}