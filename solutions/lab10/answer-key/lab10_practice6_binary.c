/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_practice6_binary.c
 * Description: Practice problem - recursively prints the binary
 *              representation of a non-negative integer, one bit at a time.
 */
#include <stdio.h>

void print_binary(int n);

int main(void) {
    printf("print_binary(13) = ");
    print_binary(13);
    printf("\n");

    printf("print_binary(2) = ");
    print_binary(2);
    printf("\n");

    printf("print_binary(0) = ");
    print_binary(0);
    printf("\n");

    return 0;
}

/*
 * print_binary: recursively prints the binary digits of a non-negative
 * integer, most significant bit first, with no trailing newline.
 * Parameters: n - a non-negative integer
 * Returns: nothing
 */
void print_binary(int n) {
    if (n > 1) {
        print_binary(n / 2);
    }
    printf("%d", n % 2);
}
