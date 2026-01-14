#pragma once

#include <stdio.h>

typedef struct Human {
    char first_initial;
    int age;
    double height;
} human_t;

size_t sum_all_bytes(char first_initial_size, int age_size, double height_size);

human_t create_human(char first_initial, int age, double height) {
    human_t human = {
        .first_initial = first_initial,
        .age = age,
        .height = height,
    };

    return human;
}