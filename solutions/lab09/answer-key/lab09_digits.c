/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_digits.c
 * Description: Challenge problem - count_digits counts the digits of an
 *              integer and reverse_num reverses its digits, both handling
 *              zero and negative numbers.
 */
#include <stdio.h>

int count_digits(int n);
int reverse_num(int n);

int main(void) {
    int test_values[] = {0, 12345, -407, 7, -9};
    int num_tests = 5;

    for (int i = 0; i < num_tests; i++) {
        int n = test_values[i];
        printf("count_digits(%d) = %d, reverse_num(%d) = %d\n",
               n, count_digits(n), n, reverse_num(n));
    }

    return 0;
}

/*
 * count_digits: counts how many decimal digits the integer n has.
 * Parameters: n - any integer (sign is ignored when counting)
 * Returns: the number of digits (count_digits(0) is 1)
 */
int count_digits(int n) {
    if (n == 0) {
        return 1;
    }

    int count = 0;
    int magnitude = (n < 0) ? -n : n;

    while (magnitude > 0) {
        count++;
        magnitude /= 10;
    }

    return count;
}

/*
 * reverse_num: reverses the decimal digits of n, preserving its sign.
 * Parameters: n - any integer
 * Returns: n with its digits reversed (reverse_num(0) is 0)
 */
int reverse_num(int n) {
    int is_negative = (n < 0);
    int magnitude = is_negative ? -n : n;
    int reversed = 0;

    while (magnitude > 0) {
        reversed = reversed * 10 + magnitude % 10;
        magnitude /= 10;
    }

    return is_negative ? -reversed : reversed;
}
