#include <stdio.h>
#include <stdlib.h>

#include "048_free.h"

int *allocate_scalar_list(int size, int multiplier) {
    int *list = (int *)malloc(size * sizeof(int));
    if (list == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        list[i] = i * multiplier;
    }

    return list;
}

int main() {
    const int num_lists = 500;
    for (int i = 0; i < num_lists; i++) {
        int *list = allocate_scalar_list(50000, 2);
        free(list);
        if (list == NULL) {
            printf("failed to allocate list\n");
            return 1;
        } else {
            printf("%dº allocated list\n", i);
        }
    }

    return 0;
}
