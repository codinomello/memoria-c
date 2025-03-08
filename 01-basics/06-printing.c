#include <stdio.h>

int main() {
    int sneklang_default_max_threads = 8;
    char sneklang_default_perms = 'r';
    float sneklang_default_pi = 3.141592;
    char *sneklang_title = "Sneklang";

    printf("sneklang default max threads: %d\n", sneklang_default_max_threads);
    printf("sneklang default perms: %c\n", sneklang_default_perms);
    printf("sneklang default pi: %f\n", sneklang_default_pi);
    printf("sneklang title: %s\n", sneklang_title);

    return 0;
}