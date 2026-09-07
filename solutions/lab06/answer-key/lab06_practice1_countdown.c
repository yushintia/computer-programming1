/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_practice1_countdown.c
 * Description: Practice - reads a starting number and counts down to 1
 *              with a while loop, then prints "Liftoff!".
 */
#include <stdio.h>

int main(void) {
    int n;

    printf("Enter start number: ");
    scanf("%d", &n);

    while (n >= 1) {
        printf("%d ", n);
        n--;
    }
    printf("Liftoff!\n");

    return 0;
}
