/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_validator.c
 * Description: Reads two positive integers using a validating input
 *              function and prints their sum.
 */
#include <stdio.h>

int read_positive(void);

int main(void) {
    int first_value = read_positive();
    int second_value = read_positive();
    int sum = first_value + second_value;

    printf("Sum = %d\n", sum);

    return 0;
}

/*
 * read_positive: prompts the user for a positive integer, re-prompting on
 * invalid input (zero, negative, or non-numeric).
 * Parameters: none
 * Returns: the first valid positive integer entered
 */
int read_positive(void) {
    int value;

    while (1) {
        printf("Enter a positive integer: ");
        if (scanf("%d", &value) != 1) {
            printf("Invalid, try again.\n");
            while (getchar() != '\n') {
                /* discard the rest of the invalid line */
            }
            continue;
        }
        if (value <= 0) {
            printf("Invalid, try again.\n");
            continue;
        }
        return value;
    }
}
