/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_sort_challenge.c
 * Description: Challenge problem - sorts an array of Student structs in
 *              descending order of score using bubble sort, then prints
 *              the sorted roster.
 */

#include <stdio.h>

#define MAX 5

typedef struct {
    int id;
    char name[30];
    double score;
} Student;

void sort_by_score(Student r[], int n);
void print_roster(Student r[], int n);

/*
 * main: builds a hardcoded unsorted roster, sorts it by score in
 * descending order, and prints the result so the ordering can be
 * verified directly.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Student roster[MAX] = {
        {2025001, "Alice", 72.50},
        {2025002, "Bob",   91.00},
        {2025003, "Carol", 65.25},
        {2025004, "Dave",  88.75},
        {2025005, "Eve",   99.00}
    };

    printf("Before sort:\n");
    print_roster(roster, MAX);

    sort_by_score(roster, MAX);

    printf("\nAfter sort (descending by score):\n");
    print_roster(roster, MAX);

    return 0;
}

/*
 * sort_by_score: sorts the roster in descending order of score using a
 * bubble sort.
 * Parameters: r - array of Student to sort in place, n - number of
 *             students
 * Returns: nothing
 */
void sort_by_score(Student r[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (r[j].score < r[j + 1].score) {
                Student temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }
}

/*
 * print_roster: prints the roster as a formatted table.
 * Parameters: r - array of Student, n - number of students
 * Returns: nothing
 */
void print_roster(Student r[], int n) {
    printf("%-8s %-12s %6s\n", "ID", "Name", "Score");
    for (int i = 0; i < n; i++) {
        printf("%-8d %-12s %6.2f\n", r[i].id, r[i].name, r[i].score);
    }
}
