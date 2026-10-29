#pragma once

#include <string.h>

typedef struct {
    size_t length;
    char buffer[64];
} text_buffer_t;

int smart_append(text_buffer_t *dest, const char *src);
