/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_practice3_checkerboard.c
 * Description: Practice - uses nested for loops to print an n by n
 *              checkerboard grid alternating X and O.
 */
#include <stdio.h>

int main(void) {
    int size, row, col;

    printf("Enter board size: ");
    scanf("%d", &size);

    for (row = 1; row <= size; row++) {
        for (col = 1; col <= size; col++) {
            if ((row + col) % 2 == 0) {
                printf("X");
            } else {
                printf("O");
            }
            if (col < size) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
