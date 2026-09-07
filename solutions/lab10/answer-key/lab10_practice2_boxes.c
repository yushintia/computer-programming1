/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_practice2_boxes.c
 * Description: Practice problem - recursively multiplies two integers using
 *              repeated addition (how many items in b boxes of a items).
 */
#include <stdio.h>

int recursive_multiply(int a, int b);

int main(void) {
    printf("recursive_multiply(6, 4) = %d\n", recursive_multiply(6, 4));
    printf("recursive_multiply(7, 0) = %d\n", recursive_multiply(7, 0));
    printf("recursive_multiply(5, 3) = %d\n", recursive_multiply(5, 3));

    return 0;
}

/*
 * recursive_multiply: computes a * b using recursive repeated addition.
 * Parameters: a - value to add repeatedly, b - number of times to add it
 * (b >= 0)
 * Returns: the product a * b
 */
int recursive_multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + recursive_multiply(a, b - 1);
}
