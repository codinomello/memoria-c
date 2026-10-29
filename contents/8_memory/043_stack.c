#include <stdio.h>

#include "043_stack.h"

int main() {
    print_message_one();
    print_message_two();
    print_message_three();
    
    return 0;
}

void print_message_one() {
    const char *message = "dark mode?\n";
    print_stack_pointer_diff();
    printf("%s\n", message);
}

void print_message_two() {
    const char *message = "more like...\n";
    print_stack_pointer_diff();
    printf("%s\n", message);
}

void print_message_three() {
    const char *message = "dark roast.\n";
    print_stack_pointer_diff();
    printf("%s\n", message);
}

void print_stack_pointer_diff() {
    static void *last_sp = NULL;
    void *current_sp;
    current_sp = __builtin_frame_address(0);
    long diff = (char*)last_sp - (char*)current_sp;
    if (last_sp == NULL){
        last_sp = current_sp;
        diff = 0;
    }
    printf("stack pointer offset: %ld bytes\n", diff);
}