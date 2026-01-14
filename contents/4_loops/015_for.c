#include <stdio.h>

#include "015_for.h"

void print_numbers(int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d\n", i);
    }
}

int main() {
    print_numbers(1, 10);
    
    return 0;
}