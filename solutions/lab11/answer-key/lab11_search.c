/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_search.c
 * Description: Reads an array of ARRAY_SIZE integers, then repeatedly
 *              prompts for a target value and reports its index via
 *              linear search until the user enters the stop sentinel.
 */
#include <stdio.h>

#define ARRAY_SIZE 10
#define STOP_SENTINEL -1

int search(int a[], int n, int target);

int main(void) {
    int values[ARRAY_SIZE];

    printf("Enter %d integers:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int target;

    printf("Search for: ");
    scanf("%d", &target);

    while (target != STOP_SENTINEL) {
        int index = search(values, ARRAY_SIZE, target);

        if (index != -1) {
            printf("Found %d at index %d\n", target, index);
        } else {
            printf("Not found\n");
        }

        printf("Search for: ");
        scanf("%d", &target);
    }

    return 0;
}

/*
 * search: performs a linear search for target in array a of size n.
 * Parameters: a - array to search, n - number of elements, target - value
 * sought
 * Returns: the index of target if found, or -1 if not found
 */
int search(int a[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}
