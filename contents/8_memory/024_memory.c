#include <stdio.h>

#include "024_memory.h"

unsigned long size_of_address(long long i){
    unsigned long sizeof_program_version = sizeof(&i);

    return sizeof_program_version;
}

int main() {
    long long i = 9876543210LL;
    printf("address in hexadecimal: %p\n", (void *)&i);
    printf("size of memory address in bytes: %lu\n", size_of_address(i));

    return 0;
}