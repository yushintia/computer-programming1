/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_power.c
 * Description: Recursive power function that raises a base to a
 *              non-negative integer exponent.
 */
#include <stdio.h>

double power(double base, int exp);

int main(void) {
    printf("power(2,10) = %.0f\n", power(2, 10));
    printf("power(1.5,3) = %.3f\n", power(1.5, 3));
    printf("power(5,0) = %.0f\n", power(5, 0));

    return 0;
}

/*
 * power: recursively raises base to the integer exponent exp.
 * Parameters: base - the base value, exp - non-negative integer exponent
 * Returns: base^exp as a double
 */
double power(double base, int exp) {
    if (exp == 0) {
        return 1.0;
    }
    return base * power(base, exp - 1);
}
