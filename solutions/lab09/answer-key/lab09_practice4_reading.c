/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_practice4_reading.c
 * Description: Practice - book reading pace estimator with functions for
 *              pages read per day and days needed to finish a book.
 */
#include <stdio.h>

double pages_per_day(int total_pages, int days);
int days_to_finish(int total_pages, double pace);

int main(void) {
    double pace1 = pages_per_day(300, 10);
    printf("pages_per_day(300, 10) = %.1f pages/day\n", pace1);
    printf("days_to_finish(300, %.1f) = %d days\n", pace1, days_to_finish(300, pace1));

    int finish_days = days_to_finish(250, 40.0);
    printf("days_to_finish(250, 40.0) = %d days\n", finish_days);

    return 0;
}

/*
 * pages_per_day: computes the average number of pages read per day.
 * Parameters: total_pages - pages read so far, days - number of days spent
 * reading (days > 0)
 * Returns: total_pages / days as a double
 */
double pages_per_day(int total_pages, int days) {
    return (double)total_pages / days;
}

/*
 * days_to_finish: computes how many whole days are needed to read a book at
 * a given pace, rounding up any partial day.
 * Parameters: total_pages - total pages in the book, pace - pages read per
 * day (pace > 0)
 * Returns: the number of days needed, rounded up
 */
int days_to_finish(int total_pages, double pace) {
    int whole_days = (int)(total_pages / pace);

    if (whole_days * pace < total_pages) {
        whole_days++;
    }

    return whole_days;
}
