#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct ProgramObject program_object_t;

int program_length(program_object_t *obj);
program_object_t *program_add(program_object_t *a, program_object_t *b);

typedef struct {
    size_t size;
    program_object_t **elements;
} program_array_t;

typedef struct {
    program_object_t *x;
    program_object_t *y;
    program_object_t *z;
} program_vector_t;

typedef enum ProgramObjectKind {
    INTEGER,
    FLOAT,
    STRING,
    VECTOR3,
    ARRAY
} program_object_kind_t;

typedef union ProgramObjectData {
    int v_int;
    float v_float;
    char *v_string;
    program_vector_t v_vector3;
    program_array_t v_array;
} program_object_data_t;

typedef struct ProgramObject {
    program_object_kind_t kind;
    program_object_data_t data;
} program_object_t;

program_object_t *new_program_integer(int value);
program_object_t *new_program_float(float value);
program_object_t *new_program_string(char *value);
program_object_t *new_program_vector3(
    program_object_t *x, program_object_t *y, program_object_t *z
);

program_object_t *new_program_array(size_t size);

bool program_array_set(program_object_t *array, size_t index, program_object_t *value);

program_object_t *program_array_get(program_object_t *array, size_t index);