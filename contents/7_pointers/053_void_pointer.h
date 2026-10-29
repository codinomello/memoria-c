typedef enum ProgramObjectKind {
    INTEGER,
    FLOAT,
    BOOL,
} program_object_kind_t;

typedef struct ProgramInt {
    char *name;
    int value;
} program_int_t;

typedef struct ProgramFloat {
    char *name;
    float value;
} program_float_t;

typedef struct ProgramBool {
    char *name;
    unsigned int value;
} program_bool_t;

void program_zero_out(void *ptr, program_object_kind_t kind);