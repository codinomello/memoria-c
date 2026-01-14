#include <stdio.h>

#include "023_sizeof_types.h"

size_t sum_all_bytes(char first_initial_size, int age_size, double height_size) {
    size_t total_size = sizeof(first_initial_size) + sizeof(age_size) + sizeof(height_size);
    return total_size;
}

int main() {
    printf("size of char: %zu byte(s)\n", sizeof(char)); // padding for alignment (3 bytes)
    printf("size of int: %zu byte(s)\n", sizeof(int));
    printf("size of double: %zu byte(s)\n", sizeof(double));

    human_t person = create_human('A', 30, 5.9);
    printf("size of the sum of human_t fields: %zu byte(s)\n", sum_all_bytes(
        person.first_initial, person.age, person.height
    ));
    
    printf("size of human_t: %zu byte(s)\n", sizeof(human_t));

    return 0;
}