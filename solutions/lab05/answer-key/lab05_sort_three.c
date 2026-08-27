/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_sort_three.c
 * Description: Reads three integers and prints them in ascending order
 *              using only if-else comparisons (no arrays or library sorts).
 */
#include <stdio.h>

int main(void) {
    int a, b, c, smallest, middle, largest;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a <= b && a <= c) {
        smallest = a;
        if (b <= c) {
            middle = b;
            largest = c;
        } else {
            middle = c;
            largest = b;
        }
    } else if (b <= a && b <= c) {
        smallest = b;
        if (a <= c) {
            middle = a;
            largest = c;
        } else {
            middle = c;
            largest = a;
        }
    } else {
        smallest = c;
        if (a <= b) {
            middle = a;
            largest = b;
        } else {
            middle = b;
            largest = a;
        }
    }

    printf("Ascending order: %d %d %d\n", smallest, middle, largest);

    return 0;
}
