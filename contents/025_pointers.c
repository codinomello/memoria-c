#include <stdio.h>

int main() {
    int var = 37;
    int *pointer_to_var = &var;

    printf("age: %d\n", var);
    printf("address of age variable: %p\n", (void*)&var);
    printf("pointer to age variable: %p\n", (void*)pointer_to_var);
    printf("value pointed to by pointer_to_age: %d\n", *pointer_to_var);

    return 0;
}