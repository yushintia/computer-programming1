/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_validate.c
 * Description: Re-prompts with a do-while loop until a valid 0-100 grade
 *              percentage is entered, then prints the corresponding letter grade.
 */
#include <stdio.h>

#define MIN_GRADE 0
#define MAX_GRADE 100
#define GRADE_A_CUTOFF 90
#define GRADE_B_CUTOFF 80
#define GRADE_C_CUTOFF 70
#define GRADE_D_CUTOFF 60

int main(void) {
    int score;

    do {
        printf("Enter grade percentage (0-100): ");
        scanf("%d", &score);
        if (score < MIN_GRADE || score > MAX_GRADE) {
            printf("Invalid value. Please try again.\n");
        }
    } while (score < MIN_GRADE || score > MAX_GRADE);

    if (score >= GRADE_A_CUTOFF) {
        printf("Grade: A\n");
    } else if (score >= GRADE_B_CUTOFF) {
        printf("Grade: B\n");
    } else if (score >= GRADE_C_CUTOFF) {
        printf("Grade: C\n");
    } else if (score >= GRADE_D_CUTOFF) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F (Fail)\n");
    }

    return 0;
}
