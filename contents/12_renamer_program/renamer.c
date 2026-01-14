#include <stdio.h>
#include <string.h>
#include <dirent.h>

void replace_chars(char *str) {
    for (; *str; ++str) {
        if (*str == '-') *str = '_';
    }
}

int main() {
    struct dirent *de;
    DIR *dr = opendir("."); // Open current directory

    if (dr == NULL) {
        perror("Could not open directory");
        return 1;
    }

    while ((de = readdir(dr)) != NULL) {
        // Skip current and parent directory pointers
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
            continue;

        if (strchr(de->d_name, '-')) {
            char new_name[256];
            strcpy(new_name, de->d_name);
            replace_chars(new_name);

            if (rename(de->d_name, new_name) == 0) {
                printf("Renamed: %s -> %s\n", de->d_name, new_name);
            } else {
                perror("Error renaming file");
            }
        }
    }

    closedir(dr);
    return 0;
}
