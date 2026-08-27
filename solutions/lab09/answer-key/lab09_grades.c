/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_grades.c
 * Description: Modular grade printer that reads three scores, converts
 *              each to a letter grade, and prints a report with the
 *              average.
 */
#include <stdio.h>

#define GRADE_A_MIN 90.0
#define GRADE_B_MIN 80.0
#define GRADE_C_MIN 70.0
#define GRADE_D_MIN 60.0
#define SCORE_MIN 0.0
#define SCORE_MAX 100.0
#define NUM_SCORES 3

double read_score(const char *label);
char grade_letter(double score);
void print_report(double s1, double s2, double s3);

int main(void) {
    double score1 = read_score("Score 1");
    double score2 = read_score("Score 2");
    double score3 = read_score("Score 3");

    print_report(score1, score2, score3);

    return 0;
}

/*
 * read_score: prints label as a prompt and reads a score, re-prompting
 * until the value is within the valid range 0 to 100 inclusive.
 * Parameters: label - text describing which score is being entered
 * Returns: a validated double score between 0 and 100
 */
double read_score(const char *label) {
    double score;

    while (1) {
        printf("%s (0-100): ", label);
        if (scanf("%lf", &score) != 1) {
            printf("Invalid, try again.\n");
            while (getchar() != '\n') {
                /* discard the rest of the invalid line */
            }
            continue;
        }
        if (score < SCORE_MIN || score > SCORE_MAX) {
            printf("Invalid, try again.\n");
            continue;
        }
        return score;
    }
}

/*
 * grade_letter: converts a numeric score into a letter grade.
 * Parameters: score - a value between 0 and 100
 * Returns: 'A', 'B', 'C', 'D', or 'F'
 */
char grade_letter(double score) {
    if (score >= GRADE_A_MIN) {
        return 'A';
    } else if (score >= GRADE_B_MIN) {
        return 'B';
    } else if (score >= GRADE_C_MIN) {
        return 'C';
    } else if (score >= GRADE_D_MIN) {
        return 'D';
    } else {
        return 'F';
    }
}

/*
 * print_report: prints each of the three scores with its letter grade and
 * the average of the three scores.
 * Parameters: s1, s2, s3 - the three scores to report
 * Returns: nothing
 */
void print_report(double s1, double s2, double s3) {
    double average = (s1 + s2 + s3) / NUM_SCORES;

    printf("Score 1: %.2f (%c)\n", s1, grade_letter(s1));
    printf("Score 2: %.2f (%c)\n", s2, grade_letter(s2));
    printf("Score 3: %.2f (%c)\n", s3, grade_letter(s3));
    printf("Average: %.2f\n", average);
}
