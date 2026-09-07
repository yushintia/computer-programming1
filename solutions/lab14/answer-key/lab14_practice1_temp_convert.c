/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_practice1_temp_convert.c
 * Description: Corrected version of the buggy Fahrenheit-to-Celsius
 *              converter from Practice Problem 1. Reads a Fahrenheit
 *              temperature and prints the Celsius equivalent.
 */

#include <stdio.h>

/*
 * main: reads a Fahrenheit temperature and prints its Celsius
 * equivalent.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    int fahrenheit;

    printf("Enter Fahrenheit temperature: ");
    scanf("%d", &fahrenheit);

    /* BUG FIX: the original computed (fahrenheit - 32) / 9 * 5 using
     * integer division, which divides before multiplying and truncates
     * the fractional part. Multiplying by 5.0 first and dividing by
     * 9.0 with double arithmetic gives the correct result. */
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;

    printf("%d F = %.1f C\n", fahrenheit, celsius);

    return 0;
}
