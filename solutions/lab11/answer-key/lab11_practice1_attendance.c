/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_practice1_attendance.c
 * Description: Practice problem - prints a 10-day class attendance report
 *              from an array of 0/1 flags and counts total present days.
 */
#include <stdio.h>

#define NUM_DAYS 10

int count_present(int attendance[], int n);

int main(void) {
    int attendance[NUM_DAYS] = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1};

    for (int i = 0; i < NUM_DAYS; i++) {
        printf("Day %d: %s\n", i + 1, attendance[i] == 1 ? "Present" : "Absent");
    }

    printf("Total present days: %d\n", count_present(attendance, NUM_DAYS));

    return 0;
}

/*
 * count_present: counts how many entries in an attendance array equal 1.
 * Parameters: attendance - array of 0 (absent) / 1 (present) flags, n -
 * number of elements
 * Returns: the number of present days
 */
int count_present(int attendance[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (attendance[i] == 1) {
            total++;
        }
    }

    return total;
}
