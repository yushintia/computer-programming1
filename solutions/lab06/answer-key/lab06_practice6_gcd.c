/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_practice6_gcd.c
 * Description: Practice - computes the greatest common divisor of two
 *              positive integers using the Euclidean algorithm in a
 *              while loop.
 */
#include <stdio.h>

int main(void) {
    int a, b, temp;

    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD: %d\n", a);

    return 0;
}
