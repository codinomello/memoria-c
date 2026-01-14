typedef enum ProgramObjectKind {
    INTEGER,
    STRING
} program_object_kind_t;

typedef union ProgramObjectData {
    int v_int;
    char *v_string;
} program_object_data_t;

typedef struct ProgramObject {
    program_object_kind_t kind;
    program_object_data_t data;
} program_object_t;

program_object_t new_integer(int);
program_object_t new_string(char *str);

void format_object(program_object_t obj, char *buffer);
