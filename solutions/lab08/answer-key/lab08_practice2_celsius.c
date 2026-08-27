/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 08: Midterm Sample Practice
 * Filename : lab08_practice2_celsius.c
 * Description: Practice 2 - reads a Celsius temperature and classifies
 *              it as Freezing, Cold, Comfortable, or Hot.
 */
#include <stdio.h>

#define COLD_MAX 15
#define COMFORTABLE_MAX 30

int main(void) {
    double temperature;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &temperature);

    if (temperature < 0) {
        printf("Freezing\n");
    } else if (temperature <= COLD_MAX) {
        printf("Cold\n");
    } else if (temperature <= COMFORTABLE_MAX) {
        printf("Comfortable\n");
    } else {
        printf("Hot\n");
    }

    return 0;
}
