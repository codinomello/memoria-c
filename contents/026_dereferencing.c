#include <stdio.h>

#include "026_dereferencing.h"

codefile_t change_file(codefile_t *file, int new_lines, char* new_filetype){
    codefile_t new_file = *file;
    new_file.lines = new_lines;
    new_file.filetype = new_filetype;

    return new_file;
}

int main() {
    codefile_t my_file = {150, ".jpg"};
    printf("original lines: %d, original filetype: %s\n", my_file.lines, my_file.filetype);

    codefile_t updated_file = change_file(&my_file, 210, ".jpeg");
    printf("original lines: %d, updated filetype: %s\n", updated_file.lines, updated_file.filetype);

    return 0;
}