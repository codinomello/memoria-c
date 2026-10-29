#include <stdio.h>

#include "048_calloc.h"

int *calloc_scalar_array(int size, int multiplier) {
    int *array = (int *)calloc(size, sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        array[i] = i * multiplier;
    }

    return array;
}

int main() {
    int size = 10;
    int multiplier = 5;
    int *array = calloc_scalar_array(size, multiplier);
    if (array == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
    free(array);
    
    return 0;
}