/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_practice7_clock.c
 * Description: Reads the total minutes since midnight, formats it as a
 *              zero-padded HH:MM clock, and prints 0/1 flags for whether
 *              it is afternoon and whether it is an exact hour (ungraded
 *              practice problem).
 */
#include <stdio.h>

int main(void) {
    int total_minutes;
    int hours;
    int minutes;

    printf("Enter total minutes since midnight: ");
    scanf("%d", &total_minutes);

    hours = total_minutes / 60;
    minutes = total_minutes % 60;

    printf("Time: %02d:%02d\n", hours, minutes);
    printf("Is afternoon (hours >= 12): %d\n", hours >= 12);
    printf("Is exact hour (minutes == 0): %d\n", minutes == 0);
    return 0;
}
