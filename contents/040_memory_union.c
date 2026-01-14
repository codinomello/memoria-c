#include <stdio.h>

#include "040_memory_union.h"

typedef union {
    int value;
    unsigned int err;
} val_or_err_t;

int main() {
    const int UINT_MAX = 2891;
    val_or_err_t person_one_score = {
        .value = -420
    };
    printf("value (set): %d\n", person_one_score.value);
    printf("err (unset): %u\n", person_one_score.err);

    val_or_err_t person_two_score = {
        .err = UINT_MAX
    };
    printf("value (unset): %d\n", person_two_score.value);
    printf("err (set): %u\n", person_two_score.err);
}