/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_practice7_time.c
 * Description: Reads a duration in total seconds and prints it broken
 *              down into hours, minutes, and seconds using integer
 *              division and modulo (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    int total_seconds;
    int hours;
    int minutes;
    int seconds;
    int remainder;

    printf("Enter a duration in total seconds: ");
    scanf("%d", &total_seconds);

    hours = total_seconds / 3600;
    remainder = total_seconds % 3600;
    minutes = remainder / 60;
    seconds = remainder % 60;

    printf("Hours:   %d\n", hours);
    printf("Minutes: %d\n", minutes);
    printf("Seconds: %d\n", seconds);
    return 0;
}
