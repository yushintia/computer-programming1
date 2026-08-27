/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_temp.c
 * Description: Reads a temperature in Celsius and prints the Fahrenheit
 *              equivalent with two decimal places.
 */
#include <stdio.h>

int main(void) {
    double celsius;
    double fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    /* F = C x 9/5 + 32; use 9.0/5.0 so the division is not truncated */
    fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    return 0;
}
