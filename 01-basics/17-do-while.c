#include <stdio.h>
#include "17-do-while.h"

void print_numbers_reverse(int start, int end) {
    do {
      printf("%d\n", start);
      start--;
    } while (start >= end);
}

int main() {
    print_numbers_reverse(10, 1);
    return 0;
}