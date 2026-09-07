/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_practice7_clock.c
 * Description: Practice - 12-hour clock hour advancer function that wraps
 *              around from 12 back to 1 (or 1 back to 12 for negative
 *              shifts), tested with several starting hours and shifts.
 */
#include <stdio.h>

#define HOURS_ON_CLOCK 12

int advance_hour(int start_hour, int hours_to_add);

int main(void) {
    printf("advance_hour(10, 5) = %d\n", advance_hour(10, 5));
    printf("advance_hour(11, 3) = %d\n", advance_hour(11, 3));
    printf("advance_hour(5, -7) = %d\n", advance_hour(5, -7));

    return 0;
}

/*
 * advance_hour: advances (or rewinds) an hour on a 12-hour clock, wrapping
 * around so the result always stays between 1 and 12.
 * Parameters: start_hour - starting hour, 1 to 12, hours_to_add - hours to
 * move forward (may be negative to move backward)
 * Returns: the resulting hour, 1 to 12
 */
int advance_hour(int start_hour, int hours_to_add) {
    int result = (start_hour - 1 + hours_to_add) % HOURS_ON_CLOCK;

    if (result < 0) {
        result += HOURS_ON_CLOCK;
    }

    return result + 1;
}
