/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_records.c
 * Description: Reads a roster of student records (id, name, score) into
 *              an array of structs, prints the roster, finds the top
 *              student, and computes the class average score.
 */

#include <stdio.h>

#define MAX 5

typedef struct {
    int id;
    char name[30];
    double score;
} Student;

void read_roster(Student r[], int n);
void print_roster(Student r[], int n);
Student find_top(Student r[], int n);
double class_average(Student r[], int n);

/*
 * main: reads a roster of MAX students, prints it, then reports the top
 * student and the class average score.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Student roster[MAX];

    read_roster(roster, MAX);
    print_roster(roster, MAX);

    Student top = find_top(roster, MAX);
    printf("Top student: %s (%.2f)\n", top.name, top.score);

    double average = class_average(roster, MAX);
    printf("Class average: %.2f\n", average);

    return 0;
}

/*
 * read_roster: reads id, name, and score for each student in r.
 * Parameters: r - destination array of Student, n - number of students
 * Returns: nothing
 */
void read_roster(Student r[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d ID: ", i + 1);
        scanf("%d", &r[i].id);
        printf("Name: ");
        scanf("%29s", r[i].name);
        printf("Score: ");
        scanf("%lf", &r[i].score);
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

/*
 * find_top: returns a copy of the Student record with the highest score.
 * Parameters: r - array of Student, n - number of students (n > 0)
 * Returns: the Student record with the highest score
 */
Student find_top(Student r[], int n) {
    Student best = r[0];
    for (int i = 1; i < n; i++) {
        if (r[i].score > best.score) {
            best = r[i];
        }
    }
    return best;
}

/*
 * class_average: returns the average score across all students in r.
 * Parameters: r - array of Student, n - number of students (n > 0)
 * Returns: the average score as a double
 */
double class_average(Student r[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += r[i].score;
    }
    return total / n;
}
