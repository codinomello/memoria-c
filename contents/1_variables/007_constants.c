#include <stdio.h>

int main() {
    const int x = 5;
    // x = 10; // error: assignment of read-only variable ‘x’
   
    printf("x: %d\n", x);
}