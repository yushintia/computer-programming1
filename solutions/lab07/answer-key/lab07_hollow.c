/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_hollow.c
 * Description: Prints a hollow rectangle of stars given a width and
 *              height, with '*' on the border and blanks inside.
 */
#include <stdio.h>

int main(void) {
    int width, height, row, col;

    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);

    for (row = 1; row <= height; row++) {
        for (col = 1; col <= width; col++) {
            if (row == 1 || row == height || col == 1 || col == width) {
                printf("*");
            } else {
                printf(" ");
            }
            if (col < width) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
