/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_practice3_digit_count.c
 * Description: Practice - reads a positive integer and counts its digits
 *              by repeatedly dividing by 10 in a while loop.
 */
#include <stdio.h>

int main(void) {
    int number, count;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    count = 0;
    if (number == 0) {
        count = 1;
    }
    while (number > 0) {
        count++;
        number /= 10;
    }
    printf("Number of digits: %d\n", count);

    return 0;
}
