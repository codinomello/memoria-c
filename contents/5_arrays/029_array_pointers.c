#include <stdio.h>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};

    printf("numbers[2] = %d\n", numbers[2]);
    printf("*(numbers + 2) = %d\n", *(numbers + 2));

    int *array_ptr = numbers;
    printf("array pointer points to numbers[0]: %d\n", *array_ptr);
    array_ptr += 2;
    printf("array pointer points to numbers[2]: %d\n", *array_ptr);

    return 0;
}