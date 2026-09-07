/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_practice7_armstrong_finder.c
 * Description: Practice - reads a 3-digit range and uses a for loop to
 *              find all 3-digit Armstrong numbers within it.
 */
#include <stdio.h>

int main(void) {
    int low, high, num, d1, d2, d3, cube_sum;

    printf("Enter range start: ");
    scanf("%d", &low);
    printf("Enter range end: ");
    scanf("%d", &high);

    printf("Armstrong numbers:");
    for (num = low; num <= high; num++) {
        if (num < 100 || num > 999) {
            continue;
        }
        d1 = num / 100;
        d2 = (num / 10) % 10;
        d3 = num % 10;
        cube_sum = d1 * d1 * d1 + d2 * d2 * d2 + d3 * d3 * d3;
        if (cube_sum == num) {
            printf(" %d", num);
        }
    }
    printf("\n");

    return 0;
}
