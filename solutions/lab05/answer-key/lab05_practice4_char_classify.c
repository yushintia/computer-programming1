/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_practice4_char_classify.c
 * Description: Practice - reads one character and classifies it as a
 *              vowel, digit, consonant, or other symbol.
 */
#include <stdio.h>

int main(void) {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        printf("Vowel\n");
    } else if (ch >= '0' && ch <= '9') {
        printf("Digit\n");
    } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        printf("Consonant\n");
    } else {
        printf("Other\n");
    }

    return 0;
}
