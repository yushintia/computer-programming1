/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_practice2_hottemp.c
 * Description: Practice problem - prints a week of daily temperatures and
 *              finds the index of the highest temperature.
 */
#include <stdio.h>

#define NUM_DAYS 7

int index_of_max(double a[], int n);

int main(void) {
    double temps[NUM_DAYS] = {68.5, 72.0, 75.3, 90.1, 81.4, 77.7, 74.2};

    for (int i = 0; i < NUM_DAYS; i++) {
        printf("Day %d: %.1f\n", i + 1, temps[i]);
    }

    int hottest = index_of_max(temps, NUM_DAYS);
    printf("Highest temperature: %.1f on Day %d\n", temps[hottest], hottest + 1);

    return 0;
}

/*
 * index_of_max: finds the index of the largest value in an array.
 * Parameters: a - array of temperatures, n - number of elements (n > 0)
 * Returns: the index of the largest element
 */
int index_of_max(double a[], int n) {
    int max_index = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[max_index]) {
            max_index = i;
        }
    }

    return max_index;
}
