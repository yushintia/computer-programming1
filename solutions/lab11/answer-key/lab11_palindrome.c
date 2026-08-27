/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 11: Arrays I: One-Dimensional Arrays
 * Filename : lab11_palindrome.c
 * Description: Challenge problem - checks whether an array of integers
 *              reads the same forwards and backwards.
 */
#include <stdio.h>

int is_palindrome(int a[], int n);

int main(void) {
    int odd_palindrome[] = {1, 2, 3, 2, 1};
    int even_palindrome[] = {4, 7, 7, 4};
    int not_palindrome[] = {1, 2, 3, 4, 5};
    int single_element[] = {9};

    printf("{1,2,3,2,1} is palindrome: %d\n", is_palindrome(odd_palindrome, 5));
    printf("{4,7,7,4} is palindrome: %d\n", is_palindrome(even_palindrome, 4));
    printf("{1,2,3,4,5} is palindrome: %d\n", is_palindrome(not_palindrome, 5));
    printf("{9} is palindrome: %d\n", is_palindrome(single_element, 1));

    return 0;
}

/*
 * is_palindrome: checks whether array a of size n reads the same forwards
 * and backwards.
 * Parameters: a - array to check, n - number of elements
 * Returns: 1 if a is a palindrome, 0 otherwise
 */
int is_palindrome(int a[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (a[left] != a[right]) {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}
