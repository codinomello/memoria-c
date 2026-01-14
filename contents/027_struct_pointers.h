#pragma once

typedef struct Car {
    char *make;
    char *model;
    int year;
    float mileage;
} car_t;

car_t create_car(char *make, char *model, int year, float mileage);

void print_car_info(car_t* car);