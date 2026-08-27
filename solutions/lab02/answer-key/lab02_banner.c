/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 02: Program Structure & Basic I/O
 * Filename : lab02_banner.c
 * Description: Prints an ASCII-art banner of the initials "CP" (Computer
 *              Programming) using printf, tabs, and escaped quotes.
 */
#include <stdio.h>

int main(void) {
    /* \t aligns the two letters into columns; \" prints literal quotes */
    printf("\t*****\t*****\n");
    printf("\t*    \t*   *\n");
    printf("\t*    \t*****\n");
    printf("\t*    \t*\n");
    printf("\t*****\t*\n");
    printf("\n");
    printf("\t\"Computer Programming I\"\n");
    return 0;
}
