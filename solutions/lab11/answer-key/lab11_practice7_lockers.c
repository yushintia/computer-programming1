/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_practice7_lockers.c
 * Description: Practice problem - binary search over a sorted array of
 *              locker numbers, printing each step of the search.
 */
#include <stdio.h>

#define NUM_LOCKERS 8

int binary_search_verbose(int a[], int n, int target);

int main(void) {
    int lockers[NUM_LOCKERS] = {101, 105, 110, 118, 124, 130, 142, 150};

    printf("Searching for locker 124:\n");
    int index1 = binary_search_verbose(lockers, NUM_LOCKERS, 124);
    if (index1 != -1) {
        printf("Locker 124 found at index %d.\n", index1);
    } else {
        printf("Locker 124 not found.\n");
    }

    printf("\nSearching for locker 115:\n");
    int index2 = binary_search_verbose(lockers, NUM_LOCKERS, 115);
    if (index2 != -1) {
        printf("Locker 115 found at index %d.\n", index2);
    } else {
        printf("Locker 115 not found.\n");
    }

    return 0;
}

/*
 * binary_search_verbose: performs binary search for target in a sorted
 * array, printing the index and value it checks at each step.
 * Parameters: a - sorted array to search, n - number of elements, target -
 * value to find
 * Returns: the index of target if found, -1 otherwise
 */
int binary_search_verbose(int a[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int step = 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        printf("Step %d: checking index %d (value %d)\n", step, mid, a[mid]);

        if (a[mid] == target) {
            return mid;
        }
        if (a[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        step++;
    }

    return -1;
}
