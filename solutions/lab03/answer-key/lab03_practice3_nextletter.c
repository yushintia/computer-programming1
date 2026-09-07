/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_practice3_nextletter.c
 * Description: Reads a single character and prints the next letter in the
 *              alphabet using char arithmetic, plus both characters' ASCII
 *              codes (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    char letter;
    char next_letter;

    printf("Enter a lowercase letter: ");
    scanf(" %c", &letter);

    /* chars are small integers, so adding 1 moves to the next ASCII code */
    next_letter = letter + 1;

    printf("You entered '%c' (ASCII %d)\n", letter, letter);
    printf("The next letter is '%c' (ASCII %d)\n", next_letter, next_letter);
    return 0;
}
