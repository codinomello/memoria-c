#include <stdio.h>

int main() {
    int c_default_max_threads = 8;
    char c_default_perms = 'r';
    float c_default_pi = 3.141592;
    char *c_title = "c";

    printf("c default max threads: %d\n", c_default_max_threads);
    printf("c default perms: %c\n", c_default_perms);
    printf("c default pi: %f\n", c_default_pi);
    printf("c title: %s\n", c_title);

    return 0;
}