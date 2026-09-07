/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_practice3_fuel.c
 * Description: Reads the liters of fuel pumped and the price per liter,
 *              then prints an aligned fuel purchase summary using printf
 *              width and precision (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    double liters;
    double price_per_liter;
    double total_cost;

    printf("Enter liters pumped: ");
    scanf("%lf", &liters);
    printf("Enter price per liter: ");
    scanf("%lf", &price_per_liter);

    total_cost = liters * price_per_liter;

    printf("%-10s %10.2f\n", "Liters", liters);
    printf("%-10s %10.2f\n", "Price/L", price_per_liter);
    printf("----------------------\n");
    printf("%-10s %10.2f\n", "Total", total_cost);
    return 0;
}
