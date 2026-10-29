#include <stdio.h>

int main() {
    const int pool_size = 1024 * 10;
    char program_pool[pool_size];
    program_pool[0] = 's';
    program_pool[1] = 'n';
    program_pool[2] = 'e';
    program_pool[3] = 'k';
    program_pool[4] = '\0';

    printf("size of pool: %d\n", pool_size);
    printf("initial string: %s\n", program_pool);

    return 0;
}
