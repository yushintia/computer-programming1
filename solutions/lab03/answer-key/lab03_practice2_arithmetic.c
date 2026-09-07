/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_practice2_arithmetic.c
 * Description: Reads two integers and prints their sum, difference, and
 *              product (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    int a;
    int b;
    int sum;
    int diff;
    int product;

    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);

    sum = a + b;
    diff = a - b;
    product = a * b;

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", product);
    return 0;
}
