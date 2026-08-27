/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 08: Midterm Sample Practice
 * Filename : lab08_practice4_fizzbuzz.c
 * Description: Practice 4 - prints 1 to 50, replacing multiples of 3
 *              with "Fizz", multiples of 5 with "Buzz", and multiples
 *              of both with "FizzBuzz".
 */
#include <stdio.h>

#define FIZZBUZZ_MAX 50
#define DIVISOR_FIZZ 3
#define DIVISOR_BUZZ 5

int main(void) {
    int i;

    for (i = 1; i <= FIZZBUZZ_MAX; i++) {
        if (i % DIVISOR_FIZZ == 0 && i % DIVISOR_BUZZ == 0) {
            printf("FizzBuzz\n");
        } else if (i % DIVISOR_FIZZ == 0) {
            printf("Fizz\n");
        } else if (i % DIVISOR_BUZZ == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}
