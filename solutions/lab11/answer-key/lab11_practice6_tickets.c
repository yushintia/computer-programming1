/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_practice6_tickets.c
 * Description: Practice problem - sorts an array of concert ticket prices
 *              into ascending order using bubble sort.
 */
#include <stdio.h>

#define NUM_TICKETS 6

void bubble_sort_prices(double a[], int n);
void print_prices(double a[], int n);

int main(void) {
    double prices[NUM_TICKETS] = {49.99, 12.50, 75.00, 8.25, 33.10, 60.00};

    printf("Before sorting: ");
    print_prices(prices, NUM_TICKETS);

    bubble_sort_prices(prices, NUM_TICKETS);

    printf("After sorting: ");
    print_prices(prices, NUM_TICKETS);

    return 0;
}

/*
 * bubble_sort_prices: sorts an array of prices into ascending order using
 * bubble sort.
 * Parameters: a - array of prices to sort in place, n - number of elements
 * Returns: nothing (modifies a in place)
 */
void bubble_sort_prices(double a[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - 1 - pass; i++) {
            if (a[i] > a[i + 1]) {
                double tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }
    }
}

/*
 * print_prices: prints all n prices separated by spaces, then a newline.
 * Parameters: a - array of prices, n - number of elements
 * Returns: nothing
 */
void print_prices(double a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}
