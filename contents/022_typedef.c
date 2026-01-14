#include <stdio.h>

#include "022_typedef.h"

pastry_t new_pastry_recipe(float flour_amount, float sugar_amount, float yeast_amount, int eggs) {
    pastry_t pastry = {
        .flour_amount = flour_amount, 
        .sugar_amount = sugar_amount,
        .yeast_amount = yeast_amount,
        .eggs = eggs
    };

    return pastry;
}

pastry_t scale_pastry_recipe(pastry_t pastry, int factor) {
    pastry_t scaled = pastry;
    scaled.flour_amount *= factor;
    scaled.sugar_amount *= factor;
    scaled.yeast_amount *= factor;
    scaled.eggs *= factor;

    return scaled;
}

int main() {
    pastry_t pastry = new_pastry_recipe(1.1, 2.2, 3.3, 4);
    printf("pastry: flour = %.1f, sugar = %.1f, yeast = %.1f & eggs = %d\n",
        pastry.flour_amount, pastry.sugar_amount, pastry.yeast_amount, pastry.eggs
    );

    pastry_t scaled = scale_pastry_recipe(pastry, 10);
    printf("scaled pastry recipe: flour = %.1f, sugar = %.1f, yeast = %.1f & eggs = %d\n", 
        scaled.flour_amount, scaled.sugar_amount, scaled.yeast_amount, scaled.eggs
    );

    return 0;
}