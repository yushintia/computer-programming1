/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_rotate.c
 * Description: Rotates the elements of an array one position to the left,
 *              wrapping the first element to the end, and demonstrates it
 *              on a sample array.
 */
#include <stdio.h>

#define ARRAY_SIZE 5

void rotate_left(int a[], int n);
void print_array(int a[], int n);

int main(void) {
    int values[ARRAY_SIZE] = {1, 2, 3, 4, 5};

    printf("Original: ");
    print_array(values, ARRAY_SIZE);

    rotate_left(values, ARRAY_SIZE);
    printf("After 1 rotation: ");
    print_array(values, ARRAY_SIZE);

    rotate_left(values, ARRAY_SIZE);
    printf("After 2 rotations: ");
    print_array(values, ARRAY_SIZE);

    return 0;
}

/*
 * rotate_left: shifts every element of a one position to the left,
 * wrapping the original first element around to the last position.
 * Parameters: a - array to rotate, n - number of elements
 * Returns: nothing (modifies a in place)
 */
void rotate_left(int a[], int n) {
    if (n <= 1) {
        return;
    }

    int first = a[0];

    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    a[n - 1] = first;
}

/*
 * print_array: prints all n elements of a separated by spaces, then a
 * newline.
 * Parameters: a - array to print, n - number of elements
 * Returns: nothing
 */
void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
