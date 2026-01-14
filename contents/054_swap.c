#include <stdio.h>

#include "052_swap.h"

void swap_ints(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_strings(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void swap(void *vp1, void *vp2, size_t size) {
    unsigned char *p1 = (unsigned char *)vp1;
    unsigned char *p2 = (unsigned char *)vp2;
    for (size_t i = 0; i < size; i++) {
        unsigned char temp = p1[i];
        p1[i] = p2[i];
        p2[i] = temp;
    }
}

int main() {
    int x = 10, y = 20;
    printf("before swap_ints: x = %d, y = %d\n", x, y);
    swap_ints(&x, &y);
    printf("after swap_ints: x = %d, y = %d\n", x, y);

    char *str1 = "crab";
    char *str2 = "gopher";
    printf("before swap_strings: str1 = %s, str2 = %s\n", str1, str2);
    swap_strings(&str1, &str2);
    printf("after swap_strings: str1 = %s, str2 = %s\n", str1, str2);

    double a = 1.5, b = 2.5;
    printf("before swap (generic): a = %.2f, b = %.2f\n", a, b);
    swap(&a, &b, sizeof(double));
    printf("after swap (generic): a = %.2f, b = %.2f\n", a, b);

    return 0;
}