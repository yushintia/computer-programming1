/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 02: Program Structure & Basic I/O
 * Filename : lab02_practice7_notice.c
 * Description: Prints a notice board message that must include a literal
 *              backslash, a literal double quote, and a tab, exercising
 *              several escape sequences at once (ungraded practice
 *              problem).
 */
#include <stdio.h>

int main(void) {
    printf("NOTICE BOARD\n");
    printf("Backup path: C:\\Lab02\\backup\n");
    printf("Today's quote: \"Practice makes progress.\"\n");
    printf("Office\thours\tare\t9-5.\n");
    return 0;
}
