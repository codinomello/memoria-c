#include <stdio.h>

#include "028_arrays.h"

void update_file(int message_data[5], int new_filetype, int new_num_lines){
    message_data[0] = new_filetype;
    message_data[1] = new_num_lines;
}

int main() {
    int message_data[5] = {0};

    update_file(message_data, 3, 150);

    printf("file type: %d\n", message_data[0]);
    printf("number of lines: %d\n", message_data[1]);

    message_data[2] = 42;
    message_data[3] = message_data[2] * 2;
    message_data[4] = message_data[3] + 10;
    message_data[5] = message_data[3] / 3;

    for (int i = 2; i <= 5; i++) {
        printf("message_data[%d]: %d\n", i, message_data[i]);
    }

    return 0;
}