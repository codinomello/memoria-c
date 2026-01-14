#include <stdio.h>
#include <string.h>

#include "034_string_library.h"

int smart_append(text_buffer_t *dest, const char *src) {
    if (!dest || !src) {
        return 1;
    }

    const int MAX_BUFFER_SIZE = sizeof(dest->buffer);
    int src_length = strlen(src);
    int remaining_space = sizeof(dest->buffer) - dest->length - 1; // -1 for null terminator

    if (src_length > remaining_space) {
        strncat(dest->buffer, src, remaining_space);
        dest->length = sizeof(dest->buffer) - 1; // ensure null termination
        return 1;
    } else {
        strcat(dest->buffer, src);
        dest->length += src_length;
        return 0;
    }
}

int main() {
    text_buffer_t my_buffer = {0, ""};
    smart_append(&my_buffer, "hello, ");
    smart_append(&my_buffer, "world!");

    printf("%s\n", my_buffer.buffer);
    
    return 0;
}