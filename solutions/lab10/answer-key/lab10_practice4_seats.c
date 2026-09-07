/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_practice4_seats.c
 * Description: Practice - recursively totals the seats in the first n rows
 *              of a stadium section, where each row has 2 more seats than
 *              the row before it and the first row has 1 seat.
 */
#include <stdio.h>

int total_seats(int n);

int main(void) {
    printf("total_seats(3) = %d\n", total_seats(3));
    printf("total_seats(5) = %d\n", total_seats(5));
    printf("total_seats(1) = %d\n", total_seats(1));

    return 0;
}

/*
 * total_seats: recursively totals the seats in the first n rows of a
 * stadium section. Row 1 has 1 seat, and each row after that has 2 more
 * seats than the previous row.
 * Parameters: n - number of rows (n >= 0)
 * Returns: the total number of seats in the first n rows, or 0 if n <= 0
 */
int total_seats(int n) {
    if (n <= 0) {
        return 0;
    }
    return (2 * n - 1) + total_seats(n - 1);
}
