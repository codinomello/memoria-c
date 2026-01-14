#include <stdio.h>

#include "021_initializers.h"

struct City new_city_information(char *name, int latitude, int longitude) {
    struct City city = {
        .name = name, {
            .latitude = latitude,
            .longitude = longitude
        }};
    
    return city;
}

int main() {
    struct City city = new_city_information("springfield", 39, -89);
    printf("city: %s, latitude: %d, longitude: %d\n", city.name, city.coordinate.latitude, city.coordinate.longitude);
    
    return 0;
}