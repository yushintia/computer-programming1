/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_stats.c
 * Description: Reads up to MAX_VALUES integers into an array, prints their
 *              sum, average, minimum, and maximum, and counts how many
 *              values are above the average.
 */
#include <stdio.h>

#define MAX_VALUES 20

int read_count(void);

int main(void) {
    int values[MAX_VALUES];
    int count = read_count();

    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int sum = 0;
    int min = values[0];
    int max = values[0];

    for (int i = 0; i < count; i++) {
        sum += values[i];
        if (values[i] < min) {
            min = values[i];
        }
        if (values[i] > max) {
            max = values[i];
        }
    }

    double average = (double)sum / count;
    int above_average = 0;

    for (int i = 0; i < count; i++) {
        if (values[i] > average) {
            above_average++;
        }
    }

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Count above average: %d\n", above_average);

    return 0;
}

/*
 * read_count: prompts for and reads how many values will be entered,
 * re-prompting until the value is between 1 and MAX_VALUES inclusive.
 * Parameters: none
 * Returns: a validated count between 1 and MAX_VALUES
 */
int read_count(void) {
    int n;

    while (1) {
        printf("How many values (1-%d)? ", MAX_VALUES);
        scanf("%d", &n);
        if (n >= 1 && n <= MAX_VALUES) {
            return n;
        }
        printf("Invalid, try again.\n");
    }
}
