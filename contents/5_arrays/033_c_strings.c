#include <stdio.h>

#include "033_c_strings.h"

void concat_strings(char *str1, const char *str2) {
    while (1) {
        if (*str1 == '\0') {
            break;
        }
        str1++;
    }

    while (1) {
        *str1 = *str2;
        if (*str2 == '\0') {
            break;
        }
        str1++;
        str2++;
    }
}

int main() {
    char str1[50] = "hello, ";
    const char *str2 = "world!";
    concat_strings(str1, str2);
    printf("%s\n", str1);

    return 0;
}