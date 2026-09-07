/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_practice5_interest.c
 * Description: Reads a loan principal, an annual interest rate, and a
 *              number of years, then prints the simple interest and the
 *              total amount owed (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    double principal;
    double rate;
    int years;
    double interest;
    double total;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate (e.g., 0.05 for 5%%): ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    interest = principal * rate * years;
    total = principal + interest;

    printf("Interest: %.2f\n", interest);
    printf("Total owed: %.2f\n", total);
    return 0;
}
