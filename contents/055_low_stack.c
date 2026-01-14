#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "053_low_stack.h"

void stack_free(stack_t *stack) {
    if (stack == NULL) {
        return;
    }

    if (stack->data != NULL) {
        free(stack->data);
    }

    free(stack);
}

void *stack_pop(stack_t *stack) {
    if (stack->count == 0) {
        return NULL;
    }

    stack->count--;

    return stack->data[stack->count];
}

void stack_push(stack_t *stack, void *obj) {
    if (stack->count == stack->capacity) {
        stack->capacity *= 2;
        void **temp = realloc(stack->data, stack->capacity * sizeof(void *));
        if (temp == NULL) {
        stack->capacity /= 2;
        exit(1);
        }
        stack->data = temp;
    }
    stack->data[stack->count] = obj;
    stack->count++;

    return;
}

stack_t *stack_new(size_t capacity) {
    stack_t *stack = malloc(sizeof(stack_t));
    if (stack == NULL) {
        return NULL;
    }

    stack->count = 0;
    stack->capacity = capacity;
    stack->data = malloc(stack->capacity * sizeof(void *));
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }

    return stack;
}

void scary_double_push(stack_t *stack) {
    stack_push(stack, (void *)1337);

    int *ptr = malloc(sizeof(int));
    *ptr = 1024;
    stack_push(stack, (void *)ptr);
}

void stack_push_multiple_types(stack_t *stack) {
    float *fptr = malloc(sizeof(float));
    *fptr = 3.14f;
    stack_push(stack, (void *)fptr);

    char *value = "naclstack";
    size_t length = strlen(value) + 1;

    char *string = malloc(length * sizeof(char));
    strncpy(string, value, length);
    stack_push(stack, string);
}

int main() {
    stack_t *stack = stack_new(2);
    assert(stack != NULL);
    assert(stack->count == 0);
    assert(stack->capacity == 2);

    scary_double_push(stack);
    assert(stack->count == 2);

    void *first = stack_pop(stack);
    assert(first != NULL);
    assert(*(int *)first == 1024);
    free(first);

    void *second = stack_pop(stack);
    assert(second != NULL);
    assert((size_t)second == 1337);

    assert(stack->count == 0);

    stack_push_multiple_types(stack);
    assert(stack->count == 2);

    void *str_ptr = stack_pop(stack);
    assert(str_ptr != NULL);
    assert(strcmp((char *)str_ptr, "naclstack") == 0);
    free(str_ptr);

    void *float_ptr = stack_pop(stack);
    assert(float_ptr != NULL);
    assert(*(float *)float_ptr == 3.14f);
    free(float_ptr);

    assert(stack->count == 0);

    stack_free(stack);

    return 0;
}