struct Coordinate {
	int latitude;
	int longitude;
};

struct City {
    char* name;
    struct Coordinate coordinate;
};

struct City new_city_information(char *name, int latitude, int longitude);