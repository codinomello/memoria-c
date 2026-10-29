#include <stdio.h>
#include <stdlib.h>

#include "035_forward_declaration.h"

program_object_t new_node(char *name) {
    return (program_object_t) {
        .name = name,
        .child = NULL
    };
}

int main() {
    program_object_t root = new_node("root");
    program_object_t child = new_node("child");
    root.child = &child;

    printf("root name: %s\n", root.name);
    printf("child name: %s\n", root.child->name);

    return 0;
}