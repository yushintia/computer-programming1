/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_practice5_runnerup.c
 * Description: Practice problem - finds the highest and runner-up (second
 *              distinct highest) score in an array that may contain ties.
 */
#include <stdio.h>

#define NUM_SCORES 6

int find_highest(int a[], int n);
int find_runner_up(int a[], int n, int highest);

int main(void) {
    int scores[NUM_SCORES] = {88, 95, 72, 95, 60, 91};

    int highest = find_highest(scores, NUM_SCORES);
    int runner_up = find_runner_up(scores, NUM_SCORES, highest);

    printf("Highest score: %d\n", highest);
    printf("Runner-up score: %d\n", runner_up);

    return 0;
}

/*
 * find_highest: finds the largest value in an array.
 * Parameters: a - array of scores, n - number of elements (n > 0)
 * Returns: the largest value in a
 */
int find_highest(int a[], int n) {
    int max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

/*
 * find_runner_up: finds the largest value in an array that is strictly less
 * than a known highest value, so duplicates of the highest value are
 * skipped.
 * Parameters: a - array of scores, n - number of elements, highest - the
 * array's highest value (from find_highest)
 * Returns: the largest value strictly less than highest
 */
int find_runner_up(int a[], int n, int highest) {
    int second = a[0];
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < highest && (!found || a[i] > second)) {
            second = a[i];
            found = 1;
        }
    }

    return second;
}
