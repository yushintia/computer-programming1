/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_practice4_height.c
 * Description: Reads a height in feet and inches and converts it to
 *              centimeters using a typed constant (ungraded practice
 *              problem).
 */
#include <stdio.h>

int main(void) {
    const double CM_PER_INCH = 2.54;
    int feet;
    int inches;
    double total_inches;
    double centimeters;

    printf("Enter feet: ");
    scanf("%d", &feet);
    printf("Enter inches: ");
    scanf("%d", &inches);

    total_inches = feet * 12 + inches;
    centimeters = total_inches * CM_PER_INCH;

    printf("Height: %.2f cm\n", centimeters);
    return 0;
}
