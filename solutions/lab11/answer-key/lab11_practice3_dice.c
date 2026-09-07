/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_practice3_dice.c
 * Description: Practice problem - counts how many times a chosen value
 *              appears in a fixed array of dice rolls.
 */
#include <stdio.h>

#define NUM_ROLLS 12

int count_occurrences(int a[], int n, int target);

int main(void) {
    int rolls[NUM_ROLLS] = {3, 5, 1, 5, 6, 2, 5, 4, 3, 5, 2, 5};
    int target;

    printf("Enter the value to count (1-6): ");
    scanf("%d", &target);

    int count = count_occurrences(rolls, NUM_ROLLS, target);
    printf("The value %d appears %d times.\n", target, count);

    return 0;
}

/*
 * count_occurrences: counts how many elements of an array equal a target
 * value.
 * Parameters: a - array to search, n - number of elements, target - value
 * to count
 * Returns: the number of elements equal to target
 */
int count_occurrences(int a[], int n, int target) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            count++;
        }
    }

    return count;
}
