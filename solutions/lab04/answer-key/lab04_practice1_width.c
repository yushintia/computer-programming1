/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_practice1_width.c
 * Description: Reads an integer and prints it with three different field
 *              widths (right-aligned, left-aligned, zero-padded) to
 *              explore printf width specifiers (ungraded practice
 *              problem).
 */
#include <stdio.h>

int main(void) {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("Right-aligned width 6: [%6d]\n", number);
    printf("Left-aligned width 6 : [%-6d]\n", number);
    printf("Zero-padded width 6  : [%06d]\n", number);
    return 0;
}
