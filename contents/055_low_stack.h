#include <stddef.h>

typedef struct Stack {
    size_t count;
    size_t capacity;
    void **data;
} stack_t;

stack_t *stack_new(size_t capacity);

void scary_double_push(stack_t *s);

void stack_push_multiple_types(stack_t *s);