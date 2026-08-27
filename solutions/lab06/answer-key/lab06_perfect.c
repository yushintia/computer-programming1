/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_perfect.c
 * Description: Finds and prints all perfect numbers up to 1000 (numbers
 *              equal to the sum of their proper divisors).
 */
#include <stdio.h>

#define LIMIT 1000

/*
 * sum_of_divisors: computes the sum of the proper divisors of num.
 * Parameters: num - the positive integer to check (num > 0)
 * Returns: the sum of all divisors of num strictly less than num
 */
int sum_of_divisors(int num) {
    int divisor_sum, divisor;

    divisor_sum = 0;
    for (divisor = 1; divisor < num; divisor++) {
        if (num % divisor == 0) {
            divisor_sum += divisor;
        }
    }

    return divisor_sum;
}

int main(void) {
    int candidate;

    printf("Perfect numbers up to %d:\n", LIMIT);
    for (candidate = 2; candidate <= LIMIT; candidate++) {
        if (sum_of_divisors(candidate) == candidate) {
            printf("%d\n", candidate);
        }
    }

    return 0;
}
