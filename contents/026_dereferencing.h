#pragma once

typedef struct CodeFile {
    int lines;
    char *filetype;
} codefile_t;

codefile_t change_file(codefile_t *file, int new_lines, char *new_filetype);