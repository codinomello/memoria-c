typedef struct Pastry {
    float flour_amount;
    float sugar_amount;
    float yeast_amount;
    int eggs;
} pastry_t;

pastry_t new_pastry_recipe(float flour_amount, float sugar_amount, float yeast_amount, int eggs);
pastry_t scale_pastry_recipe(pastry_t pastry, int factor);