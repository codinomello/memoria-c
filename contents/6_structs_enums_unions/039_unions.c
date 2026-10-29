#include <stdio.h>

#include "039_unions.h"

void format_object(program_object_t obj, char *buffer) {
    switch (obj.kind) {
        case INTEGER:
            sprintf(buffer, "integer: %d", obj.data.v_int);
            break;
        case STRING:
            sprintf(buffer, "string: %s", obj.data.v_string);
            break;
        default:
            sprintf(buffer, "unknown object kind");
            break;
    }
}

program_object_t new_integer(int i) {
    return (program_object_t) {
      .kind = INTEGER,
      .data = {.v_int = i}
    };
}

program_object_t new_string(char *str) {
    return (program_object_t) {
      .kind = STRING,
      .data = {.v_string = str}
    };
}

int main() {
    char buffer[100];

    program_object_t int_obj = new_integer(42);
    format_object(int_obj, buffer);
    printf("%s\n", buffer);

    program_object_t str_obj = new_string("hello, world!");
    format_object(str_obj, buffer);
    printf("%s\n", buffer);

    return 0;
}