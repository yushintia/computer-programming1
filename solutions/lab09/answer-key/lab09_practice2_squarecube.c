/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_practice2_squarecube.c
 * Description: Practice - square and cube reporter functions, tested with
 *              positive and negative integers.
 */
#include <stdio.h>

int square(int n);
int cube(int n);

int main(void) {
    printf("square(3) = %d, cube(3) = %d\n", square(3), cube(3));
    printf("square(5) = %d, cube(5) = %d\n", square(5), cube(5));
    printf("square(-2) = %d, cube(-2) = %d\n", square(-2), cube(-2));

    return 0;
}

/*
 * square: computes the square of an integer.
 * Parameters: n - the integer to square
 * Returns: n * n
 */
int square(int n) {
    return n * n;
}

/*
 * cube: computes the cube of an integer.
 * Parameters: n - the integer to cube
 * Returns: n * n * n
 */
int cube(int n) {
    return n * n * n;
}
