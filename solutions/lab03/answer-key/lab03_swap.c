/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_swap.c
 * Description: Reads two integers, swaps them using a temporary variable,
 *              and prints the values after the swap.
 */
#include <stdio.h>

int main(void) {
    int first_value;
    int second_value;
    int temp;

    printf("Enter the first integer: ");
    scanf("%d", &first_value);
    printf("Enter the second integer: ");
    scanf("%d", &second_value);

    /* classic three-step swap: hold one value in temp while rearranging */
    temp = first_value;
    first_value = second_value;
    second_value = temp;

    printf("After swap: first = %d, second = %d\n", first_value, second_value);
    return 0;
}
