#include <stdio.h>

#include "038_sizeof_enum.h"

int main() {
    printf("the size of big number enum is %zu bytes\n", sizeof(big_number_t));
    printf("the size of http status enum is %zu bytes\n", sizeof(http_status_t));
   
    return 0;
}