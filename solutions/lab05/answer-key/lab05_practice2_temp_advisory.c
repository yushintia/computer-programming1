/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_practice2_temp_advisory.c
 * Description: Practice - reads a Celsius temperature and prints a
 *              weather advisory band using an if-else if chain.
 */
#include <stdio.h>

#define COLD_MIN 0
#define MILD_MIN 15
#define HOT_MIN 25

int main(void) {
    double temp_c;

    printf("Enter temperature (C): ");
    scanf("%lf", &temp_c);

    if (temp_c < COLD_MIN) {
        printf("Freezing\n");
    } else if (temp_c < MILD_MIN) {
        printf("Cold\n");
    } else if (temp_c < HOT_MIN) {
        printf("Mild\n");
    } else {
        printf("Hot\n");
    }

    return 0;
}
