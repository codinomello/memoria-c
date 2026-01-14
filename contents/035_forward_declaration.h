typedef struct ProgramObject program_object_t;

typedef struct ProgramObject {
    char *name;
    program_object_t *child;
} program_object_t;

program_object_t new_node(char *name);