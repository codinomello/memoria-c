#include <stdio.h>

#include "051_void_pointer.h"

void program_zero_out(void *ptr, program_object_kind_t kind) {
    switch (kind) {
        case INTEGER: {
            int *int_ptr = (int *)ptr;
            *int_ptr = 0;
            printf("int zeroed to: %d\n", *int_ptr);
            break;
        }
        case FLOAT: {
            float *float_ptr = (float *)ptr;
            *float_ptr = 0.0f;
            printf("float zeroed to: %.1f\n", *float_ptr);
            break;
        }
        case BOOL: {
            _Bool *bool_ptr = (_Bool *)ptr;
            *bool_ptr = 0;
            printf("bool zeroed to: %d\n", *bool_ptr);
            break;
        }
        default:
            break;
    }
}

int main() {
    int i = 42;
    float f = 3.14f;
    _Bool b = 1;

    program_zero_out(&i, INTEGER);
    program_zero_out(&f, FLOAT);
    program_zero_out(&b, BOOL);

    return 0;
}