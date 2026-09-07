/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_practice7_attendance.c
 * Description: Corrected version of the buggy attendance tracker from
 *              Practice Problem 7. Reads a roster of students with a
 *              days-present count, then reports total attendance, how
 *              many students had perfect attendance, and who had the
 *              lowest attendance. All 3 deliberate bugs from the
 *              problem statement are fixed and marked.
 */

#include <stdio.h>

#define NUM_STUDENTS 4
#define TOTAL_DAYS 10
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    int days_present;
} Student;

/*
 * main: reads NUM_STUDENTS attendance records, then prints total
 * attendance, the count of students with perfect attendance, and the
 * student with the lowest attendance.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Student roster[NUM_STUDENTS];
    int total_present = 0;  /* BUG FIX: added missing semicolon (compile-time bug) */
    int perfect_count = 0;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%19s", roster[i].name);
        printf("Days present: ");
        scanf("%d", &roster[i].days_present);

        total_present += roster[i].days_present;

        /* BUG FIX: the original used = (assignment) instead of ==
         * (comparison). That both overwrote every student's
         * days_present with TOTAL_DAYS and made the condition always
         * true, so perfect_count always ended up equal to
         * NUM_STUDENTS. Using == only checks the value. */
        if (roster[i].days_present == TOTAL_DAYS) {
            perfect_count++;
        }
    }

    int lowest_index = 0;
    /* BUG FIX: the original looped with i <= NUM_STUDENTS, reading one
     * element past the end of the roster array. Looping with
     * i < NUM_STUDENTS keeps every access in bounds. */
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (roster[i].days_present < roster[lowest_index].days_present) {
            lowest_index = i;
        }
    }

    printf("Total attendance: %d\n", total_present);
    printf("Perfect attendance: %d\n", perfect_count);
    printf("Lowest attendance: %s (%d days)\n",
           roster[lowest_index].name, roster[lowest_index].days_present);

    return 0;
}
