#include <stdio.h>

#include "049_realloc.h"

int *reallocate_scalar_array(int initial_size, int new_size, int multiplier) {
    int *array = (int *)malloc(initial_size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    for (int i = 0; i < initial_size; i++) {
        array[i] = i * multiplier;
    }

    int *resized_array = (int *)realloc(array, new_size * sizeof(int));
    if (resized_array == NULL) {
        free(array);
        return NULL;
    }

    for (int i = initial_size; i < new_size; i++) {
        resized_array[i] = i * multiplier;
    }

    return resized_array;
}

int main() {
    int initial_size = 5;
    int new_size = 10;
    int multiplier = 3;
    int *array = reallocate_scalar_array(initial_size, new_size, multiplier);
    if (array == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < new_size; i++) {
        printf("%d\n", array[i]);
    }
    free(array);
    
    return 0;
}