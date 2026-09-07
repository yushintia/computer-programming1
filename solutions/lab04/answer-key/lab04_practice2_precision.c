/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_practice2_precision.c
 * Description: Reads a price and prints it with several different
 *              decimal-place precisions to explore printf precision
 *              specifiers (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    double price;

    printf("Enter a price: ");
    scanf("%lf", &price);

    printf("0 decimals: %.0f\n", price);
    printf("1 decimal : %.1f\n", price);
    printf("3 decimals: %.3f\n", price);
    return 0;
}
