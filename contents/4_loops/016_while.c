#include <stdio.h>

#include "016_while.h"

void print_numbers_reverse(int start, int end) {
    while (start >= end) {
        printf("%d\n", start);
        start--;
    }
}

int main() {
    print_numbers_reverse(10, 1);
    
    return 0;
}