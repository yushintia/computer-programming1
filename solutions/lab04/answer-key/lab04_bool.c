/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_bool.c
 * Description: Reads two integers and prints the 0/1 results of four
 *              relational and logical expressions.
 */
#include <stdio.h>

int main(void) {
    int a;
    int b;

    printf("Enter integer a: ");
    scanf("%d", &a);
    printf("Enter integer b: ");
    scanf("%d", &b);

    /* relational and logical operators evaluate to 1 (true) or 0 (false) */
    printf("a > b            : %d\n", a > b);
    printf("a == b           : %d\n", a == b);
    printf("a > 0 && b > 0   : %d\n", a > 0 && b > 0);
    printf("!(a == b)        : %d\n", !(a == b));
    return 0;
}
