#include <stdio.h>

#include "027_struct_pointers.h"

car_t create_car(char *make, char *model, int year, float mileage) {
    car_t car = {make, model, year, mileage};
    car_t *new_car = &car;

    new_car->make = make;
    new_car->model = model;
    new_car->year = year;
    new_car->mileage = mileage;
    
    return *new_car;
}

void print_car_info(car_t *car) {
    printf("car make: %s\n", car->make);
    printf("car model: %s\n", car->model);
    printf("car year: %d\n", car->year);
    printf("car mileage: %.2f\n", car->mileage);
}

int main() {
    car_t my_car = create_car("toyota", "corolla", 2020, 15359.53f);
    print_car_info(&my_car);

    return 0;
}