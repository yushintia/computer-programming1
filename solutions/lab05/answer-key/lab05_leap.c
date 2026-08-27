/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_leap.c
 * Description: Reads a year and reports whether it is a leap year using
 *              the divisible-by-4-except-100-unless-400 rule.
 */
#include <stdio.h>

#define CENTURY 100
#define QUADRENNIAL 400

/*
 * is_leap_year: determines whether a given year is a leap year.
 * Parameters: year - the calendar year to test
 * Returns: 1 if year is a leap year, 0 otherwise
 */
int is_leap_year(int year) {
    if (year % 4 == 0 && (year % CENTURY != 0 || year % QUADRENNIAL == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (is_leap_year(year)) {
        printf("Leap year\n");
    } else {
        printf("Not a leap year\n");
    }

    return 0;
}
