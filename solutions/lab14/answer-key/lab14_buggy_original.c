/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_buggy_original.c
 * Description: INTENTIONALLY BROKEN instructor handout for the Exercise 1
 *              bug hunt. Contains exactly 3 deliberate bugs (one
 *              compile-time, two logic). Do NOT use this file as a
 *              reference for correct output -- see lab14_buggy.c for the
 *              corrected version. This file is expected to fail to
 *              compile as-is.
 */

#include <stdio.h>

#define NUM_SCORES 5

int main(void) {
    int scores[NUM_SCORES] = {82, 70, 91, 60, 100};
    int sum = 0
    int i;

    for (i = 0; i <= NUM_SCORES; i++) {
        sum += scores[i];
    }

    int average = sum / NUM_SCORES;

    int above_average_count = 0;
    for (i = 0; i < NUM_SCORES; i++) {
        if (scores[i] > average) {
            above_average_count++;
        }
    }

    printf("Sum: %d\n", sum);
    printf("Average: %d\n", average);
    printf("Scores above average: %d\n", above_average_count);

    return 0;
}
