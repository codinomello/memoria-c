#include <stdio.h>
#include <stdlib.h>
#include "046_heap.h"

char *get_full_greeting(char *greeting, char *name, int size) {
    char *full_greeting = malloc(size * sizeof(char));
    snprintf(full_greeting, size, "%s %s", greeting, name);

    return full_greeting;
}

int main() {
    char *greeting = "hi,";
    char *name = "john";
    char *full_greeting = get_full_greeting(greeting, name, 100);
    printf("%s\n", full_greeting);
    return 0;
}