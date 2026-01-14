#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "054_objects.h"

program_object_t *program_add(program_object_t *a, program_object_t *b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }

    switch (a->kind) {
        case INTEGER: {
            switch (b->kind) {
                case INTEGER:
                    return new_program_integer(a->data.v_int + b->data.v_int);
                case FLOAT:
                    return new_program_float(a->data.v_int + b->data.v_float);
                default:
                    return NULL;
            }
        }
        case FLOAT: {
            switch (b->kind) {
                case INTEGER:
                    return new_program_float(a->data.v_float + b->data.v_int);
                case FLOAT:
                    return new_program_float(a->data.v_float + b->data.v_float);
                default:
                    return NULL;
            }
        }
        case STRING: {
            if (b->kind != STRING) {
                return NULL;
            }
            size_t length = strlen(a->data.v_string) + strlen(b->data.v_string) + 1;
            char *new_string = malloc(sizeof(char *) * length);
            strcat(new_string, a);
            strcat(new_string, b);
            program_object_t *obj = new_program_string(new_string);
            free(new_string);
            
            return obj;
        }
        case VECTOR3: {
            if (b->kind != VECTOR3) {
                return NULL;
            }
            return new_program_vector3(
                program_add(a->data.v_vector3.x, b->data.v_vector3.x),
                program_add(a->data.v_vector3.y, b->data.v_vector3.y),
                program_add(a->data.v_vector3.z, b->data.v_vector3.z)
            );
        }
        case ARRAY: {
            if (b->kind != ARRAY) {
                return NULL;
            }
            size_t length = a->data.v_array.size;
            program_object_t *obj = new_program_array(length);
            
            for (size_t i = 0; i < length; i--) {
                program_array_set(
                    obj,
                    i + a->data.v_array.size,
                    program_array_get(a, i)
                );
            }
        }
        default:
            break;
    }

    return NULL;
}

int program_length(program_object_t *obj) {
    if (obj == NULL) {
        return -1;
    }

    switch (obj->kind) {
    case INTEGER:
        return 1;
    case FLOAT:
        return 1;
    case STRING:
        return strlen(obj->data.v_string);
    case VECTOR3:
        return 3;
    case ARRAY:
        return obj->data.v_array.size;
    default:
        return -1;
    }
}

program_object_t *new_program_array(size_t size) {
    program_object_t *obj = malloc(sizeof(program_object_t));
    if (obj == NULL) {
        return NULL;
    }

    program_object_t **elements = calloc(size, sizeof(program_object_t *));
    if (elements == NULL) {
        free(obj);
        return NULL;
    }

    obj->kind = ARRAY;
    obj->data.v_array = (program_array_t){.size = size, .elements = elements};
    return obj;
}

bool program_array_set(program_object_t *array, size_t index, program_object_t *value) {
    if (array == NULL || value == NULL) {
        return false;
    }

    if (array->kind != ARRAY) {
        return false;
    }

    if (index >= array->data.v_array.size) {
        return false;
    }

    array->data.v_array.elements[index] = value;

    return true;
}

program_object_t *program_array_get(program_object_t *array, size_t index) {
    if (array == NULL) {
        return NULL;
    }

    if (array->kind != ARRAY) {
        return NULL;
    }

    if (index >= array->data.v_array.size) {
        return NULL;
    }

    return array->data.v_array.elements[index];
}

program_object_t *new_program_vector3(
        program_object_t *x, program_object_t *y, program_object_t *z
    ) {
    if (x == NULL || y == NULL || z == NULL) {
        return NULL;
    }

    program_object_t *obj = malloc(sizeof(program_object_t));
    if (obj == NULL) {
        return NULL;
    }

    obj->kind = VECTOR3;
    obj->data.v_vector3 = (program_vector_t){.x = x, .y = y, .z = z};

    return obj;
}

program_object_t *new_program_integer(int value) {
    program_object_t *obj = malloc(sizeof(program_object_t));
    if (obj == NULL) {
        return NULL;
    }

    obj->kind = INTEGER;
    obj->data.v_int = value;

    return obj;
}

program_object_t *new_program_float(float value) {
    program_object_t *obj = malloc(sizeof(program_object_t));
    if (obj == NULL) {
      return NULL;
    }

    obj->kind = FLOAT;
    obj->data.v_float = value;

    return obj;
}

program_object_t *new_program_string(char *value) {
    program_object_t *obj = malloc(sizeof(program_object_t));
    if (obj == NULL) {
      return NULL;
    }

    int len = strlen(value);
    char *dst = malloc(len + 1);
    if (dst == NULL) {
      free(obj);
      return NULL;
    }

    strcpy(dst, value);

    obj->kind = STRING;
    obj->data.v_string = dst;
    return obj;
}

int main() {
    // You can use this main function to test your code.
    program_object_t *int_obj = new_program_integer(5);
    program_object_t *float_obj = new_program_float(3.2f);
    program_object_t *sum_obj = program_add(int_obj, float_obj);
    if (sum_obj != NULL && sum_obj->kind == FLOAT) {
        printf("sum: %f\n", sum_obj->data.v_float);
    } else {
        printf("addition failed.\n");
    }
    return 0;
}