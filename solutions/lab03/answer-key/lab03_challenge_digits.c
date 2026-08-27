/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_challenge_digits.c
 * Description: Reads a four-digit integer and prints its thousands,
 *              hundreds, tens, and units digits using / and %.
 */
#include <stdio.h>

#define THOUSANDS_PLACE 1000
#define HUNDREDS_PLACE 100
#define TENS_PLACE 10
#define DIGIT_BASE 10

int main(void) {
    int number;
    int thousands;
    int hundreds;
    int tens;
    int units;

    printf("Enter a four-digit integer: ");
    scanf("%d", &number);

    /* peel off each digit with integer division and modulo */
    thousands = number / THOUSANDS_PLACE;
    hundreds = (number / HUNDREDS_PLACE) % DIGIT_BASE;
    tens = (number / TENS_PLACE) % DIGIT_BASE;
    units = number % DIGIT_BASE;

    printf("Thousands: %d\n", thousands);
    printf("Hundreds:  %d\n", hundreds);
    printf("Tens:      %d\n", tens);
    printf("Units:     %d\n", units);
    return 0;
}
