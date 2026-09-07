/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_practice6_bar_chart.c
 * Description: Practice - reads a count for each category and uses
 *              nested for loops to print an ASCII bar chart.
 */
#include <stdio.h>

int main(void) {
    int num_categories, cat, count, star;

    printf("Enter number of categories: ");
    scanf("%d", &num_categories);

    for (cat = 1; cat <= num_categories; cat++) {
        printf("Category %d count: ", cat);
        scanf("%d", &count);
        for (star = 1; star <= count; star++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
