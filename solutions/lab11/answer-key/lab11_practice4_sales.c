/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_practice4_sales.c
 * Description: Practice problem - sums daily sales while excluding refunds
 *              (negative entries) and counts how many refunds occurred.
 */
#include <stdio.h>

#define NUM_ENTRIES 8

double net_sales(double a[], int n);
int count_refunds(double a[], int n);

int main(void) {
    double sales[NUM_ENTRIES] = {120.50, -15.00, 89.25, 42.00, -8.75, 60.10, 15.00, -30.00};

    printf("Net sales (excluding refunds): %.2f\n", net_sales(sales, NUM_ENTRIES));
    printf("Number of refunds: %d\n", count_refunds(sales, NUM_ENTRIES));

    return 0;
}

/*
 * net_sales: sums only the non-negative entries of a sales array, treating
 * negative entries as refunds to be excluded.
 * Parameters: a - array of sales amounts (refunds are negative), n - number
 * of elements
 * Returns: the total of the non-negative entries
 */
double net_sales(double a[], int n) {
    double total = 0.0;

    for (int i = 0; i < n; i++) {
        if (a[i] >= 0.0) {
            total += a[i];
        }
    }

    return total;
}

/*
 * count_refunds: counts how many entries in a sales array are negative.
 * Parameters: a - array of sales amounts, n - number of elements
 * Returns: the number of negative (refund) entries
 */
int count_refunds(double a[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0.0) {
            count++;
        }
    }

    return count;
}
