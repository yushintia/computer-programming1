/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_buggy.c
 * Description: Corrected version of lab14_buggy_original.c. Reads a
 *              fixed set of scores, computes their sum and average, and
 *              counts how many scores are above average. All 3
 *              deliberate bugs from the original are fixed and marked.
 */

#include <stdio.h>

#define NUM_SCORES 5

/*
 * main: computes the sum and average of a fixed set of scores and
 * counts how many scores are above the average.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    int scores[NUM_SCORES] = {82, 70, 91, 60, 100};
    int sum = 0;  /* BUG FIX: added missing semicolon (compile-time bug) */
    int i;

    /* BUG FIX: loop bound changed from i <= NUM_SCORES to i < NUM_SCORES
     * to avoid reading one element past the end of the scores array */
    for (i = 0; i < NUM_SCORES; i++) {
        sum += scores[i];
    }

    /* BUG FIX: average must be a double and use floating-point division;
     * the original used integer division which truncated the result */
    double average = (double)sum / NUM_SCORES;

    int above_average_count = 0;
    for (i = 0; i < NUM_SCORES; i++) {
        if (scores[i] > average) {
            above_average_count++;
        }
    }

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Scores above average: %d\n", above_average_count);

    return 0;
}
