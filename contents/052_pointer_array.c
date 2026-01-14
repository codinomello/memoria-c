#include <stdlib.h>

#include "050_pointer_array.h"

token_t **create_token_pointer_array(token_t *tokens, size_t count) {
    token_t **token_pointers = malloc(count * sizeof(token_t *));
    if (token_pointers == NULL) {
      exit(1);
    }
    for (size_t i = 0; i < count; ++i) {
      token_pointers[i] = &tokens[i];
    }

    return token_pointers;
}

int main() {
    token_t tokens[] = {
        {"1¹ token", 1, 1},
        {"2² token", 2, 5},
        {"3³ token", 3, 10}
    };
    size_t count = sizeof(tokens) / sizeof(tokens[0]);

    token_t **token_pointers = create_token_pointer_array(tokens, count);

    for (size_t i = 0; i < count; ++i) {
        printf("token %zu: literal = '%s', line = %d, column = %d\n",
               i + 1,
               token_pointers[i]->literal,
               token_pointers[i]->line,
               token_pointers[i]->column);
    }

    free(token_pointers);

    return 0;
}