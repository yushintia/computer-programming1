/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_practice5_pos_neg_count.c
 * Description: Practice - reads integers until a sentinel 0 and counts
 *              how many were positive and how many were negative.
 */
#include <stdio.h>

int main(void) {
    int value, positive_count, negative_count;

    positive_count = 0;
    negative_count = 0;

    printf("Enter integers (0 to stop): ");
    scanf("%d", &value);
    while (value != 0) {
        if (value > 0) {
            positive_count++;
        } else {
            negative_count++;
        }
        scanf("%d", &value);
    }

    printf("Positive count: %d\n", positive_count);
    printf("Negative count: %d\n", negative_count);

    return 0;
}
