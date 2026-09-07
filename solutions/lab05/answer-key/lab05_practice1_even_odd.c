/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_practice1_even_odd.c
 * Description: Practice - reads an integer and reports whether it is
 *              even or odd using the modulo operator.
 */
#include <stdio.h>

int main(void) {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }

    return 0;
}
