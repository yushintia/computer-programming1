/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_practice4_password.c
 * Description: Reads a password length and a flag for whether it
 *              contains a digit, then prints the 0/1 result of several
 *              relational and logical checks (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    int length;
    int has_digit;

    printf("Enter the password length: ");
    scanf("%d", &length);
    printf("Does it contain a digit? (1 = yes, 0 = no): ");
    scanf("%d", &has_digit);

    printf("length >= 8            : %d\n", length >= 8);
    printf("has_digit == 1          : %d\n", has_digit == 1);
    printf("length >= 8 && has_digit: %d\n", length >= 8 && has_digit == 1);
    printf("!(has_digit == 1)       : %d\n", !(has_digit == 1));
    return 0;
}
