/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_practice3_triangle.c
 * Description: Practice - triangular garden plot calculator with functions
 *              for triangle area (base and height) and perimeter (three
 *              sides), tested on two plots.
 */
#include <stdio.h>

double triangle_area(double base, double height);
double triangle_perimeter(double side_a, double side_b, double side_c);

int main(void) {
    printf("Plot 1: area = %.2f (base %.1f, height %.1f)\n",
           triangle_area(6.0, 8.0), 6.0, 8.0);
    printf("Plot 1: perimeter = %.2f (sides %.1f, %.1f, %.1f)\n",
           triangle_perimeter(6.0, 8.0, 10.0), 6.0, 8.0, 10.0);

    printf("Plot 2: area = %.2f (base %.1f, height %.1f)\n",
           triangle_area(9.0, 12.0), 9.0, 12.0);
    printf("Plot 2: perimeter = %.2f (sides %.1f, %.1f, %.1f)\n",
           triangle_perimeter(9.0, 12.0, 15.0), 9.0, 12.0, 15.0);

    return 0;
}

/*
 * triangle_area: computes the area of a triangle from its base and height.
 * Parameters: base, height - the triangle's base and height
 * Returns: 0.5 * base * height
 */
double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

/*
 * triangle_perimeter: computes the perimeter of a triangle from its three
 * side lengths.
 * Parameters: side_a, side_b, side_c - the three side lengths
 * Returns: the sum of the three sides
 */
double triangle_perimeter(double side_a, double side_b, double side_c) {
    return side_a + side_b + side_c;
}
