/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_practice6_recipe.c
 * Description: Practice - recipe ingredient scaler with functions to scale
 *              a liquid ingredient (as a double) and a whole-item ingredient
 *              (rounded to the nearest whole number) to a new serving size.
 */
#include <stdio.h>

double scaled_liquid(double base_amount, int base_servings, int target_servings);
int scaled_whole_items(int base_amount, int base_servings, int target_servings);

int main(void) {
    printf("Scaling recipe from 4 to 6 servings:\n");
    printf("Milk: %.2f cups\n", scaled_liquid(2.0, 4, 6));
    printf("Eggs: %d\n", scaled_whole_items(3, 4, 6));

    printf("\nScaling recipe from 4 to 10 servings:\n");
    printf("Milk: %.2f cups\n", scaled_liquid(2.0, 4, 10));
    printf("Eggs: %d\n", scaled_whole_items(3, 4, 10));

    return 0;
}

/*
 * scaled_liquid: scales a liquid ingredient amount from a base recipe to a
 * new number of servings.
 * Parameters: base_amount - amount in the base recipe, base_servings -
 * servings the base recipe makes, target_servings - desired servings
 * Returns: the scaled amount as a double
 */
double scaled_liquid(double base_amount, int base_servings, int target_servings) {
    return base_amount * target_servings / (double)base_servings;
}

/*
 * scaled_whole_items: scales a whole-count ingredient (such as eggs) from a
 * base recipe to a new number of servings, rounding to the nearest whole
 * number.
 * Parameters: base_amount - count in the base recipe, base_servings -
 * servings the base recipe makes, target_servings - desired servings
 * Returns: the scaled count, rounded to the nearest integer
 */
int scaled_whole_items(int base_amount, int base_servings, int target_servings) {
    double exact = (double)base_amount * target_servings / base_servings;
    return (int)(exact + 0.5);
}
