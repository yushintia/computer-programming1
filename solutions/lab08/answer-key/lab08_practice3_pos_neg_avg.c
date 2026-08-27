/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 08: Midterm Sample Practice
 * Filename : lab08_practice3_pos_neg_avg.c
 * Description: Practice 3 - reads numbers until a 0 sentinel, then prints
 *              the count of positive numbers, count of negative numbers,
 *              and the average of all entered values.
 */
#include <stdio.h>

#define SENTINEL 0

int main(void) {
    int value, pos_count, neg_count, total_count;
    double sum;

    pos_count = 0;
    neg_count = 0;
    total_count = 0;
    sum = 0.0;

    printf("Enter numbers (0 to stop): ");
    scanf("%d", &value);
    while (value != SENTINEL) {
        if (value > 0) {
            pos_count++;
        } else if (value < 0) {
            neg_count++;
        }
        sum += value;
        total_count++;
        scanf("%d", &value);
    }

    printf("Positive count: %d\n", pos_count);
    printf("Negative count: %d\n", neg_count);
    if (total_count > 0) {
        printf("Average: %.2f\n", sum / total_count);
    } else {
        printf("Average: no values entered.\n");
    }

    return 0;
}
