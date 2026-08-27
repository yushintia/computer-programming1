/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_mathlib.c
 * Description: Mini math library with max, min, is_prime, gcd (Euclid's
 *              algorithm), and power (no math.h), each tested with at
 *              least two inputs.
 */
#include <stdio.h>

int max(int a, int b);
int min(int a, int b);
int is_prime(int n);
int gcd(int a, int b);
double power(double base, int exp);

int main(void) {
    printf("max(7,12) = %d\n", max(7, 12));
    printf("min(7,12) = %d\n", min(7, 12));
    printf("is_prime(17) = %d\n", is_prime(17));
    printf("is_prime(15) = %d\n", is_prime(15));

    printf("gcd(48,18) = %d\n", gcd(48, 18));
    printf("gcd(20,8) = %d\n", gcd(20, 8));

    printf("power(2,10) = %.0f\n", power(2, 10));
    printf("power(3,4) = %.0f\n", power(3, 4));
    printf("power(5,0) = %.0f\n", power(5, 0));

    return 0;
}

/*
 * max: returns the larger of two integers.
 * Parameters: a, b - the two integers to compare
 * Returns: a if a > b, otherwise b
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/*
 * min: returns the smaller of two integers.
 * Parameters: a, b - the two integers to compare
 * Returns: b if a > b, otherwise a
 */
int min(int a, int b) {
    return (a < b) ? a : b;
}

/*
 * is_prime: checks whether n is a prime number.
 * Parameters: n - the integer to test
 * Returns: 1 if n is prime, 0 otherwise
 */
int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

/*
 * gcd: returns the greatest common divisor of a and b using Euclid's
 * algorithm.
 * Parameters: a, b - integers (tested with non-negative values)
 * Returns: the greatest common divisor as an int
 */
int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

/*
 * power: returns base raised to the integer exponent exp, without
 * <math.h>.
 * Parameters: base - the base value, exp - non-negative integer exponent
 * Returns: base^exp as a double
 */
double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
