/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_challenge_won.c
 * Description: Reads a price in Korean won and breaks it down into 50,000,
 *              10,000, 5,000, and 1,000-won notes plus remaining coins.
 */
#include <stdio.h>

#define NOTE_50000 50000
#define NOTE_10000 10000
#define NOTE_5000 5000
#define NOTE_1000 1000

int main(void) {
    int amount;
    int remaining;
    int num_50000;
    int num_10000;
    int num_5000;
    int num_1000;
    int coins;

    printf("Enter the price in won: ");
    scanf("%d", &amount);

    /* take out the largest notes first; % keeps what is left over */
    remaining = amount;
    num_50000 = remaining / NOTE_50000;
    remaining = remaining % NOTE_50000;
    num_10000 = remaining / NOTE_10000;
    remaining = remaining % NOTE_10000;
    num_5000 = remaining / NOTE_5000;
    remaining = remaining % NOTE_5000;
    num_1000 = remaining / NOTE_1000;
    coins = remaining % NOTE_1000;

    printf("Breakdown of %d won:\n", amount);
    printf("50,000-won notes : %d\n", num_50000);
    printf("10,000-won notes : %d\n", num_10000);
    printf(" 5,000-won notes : %d\n", num_5000);
    printf(" 1,000-won notes : %d\n", num_1000);
    printf("Coins (< 1000)   : %d won\n", coins);
    return 0;
}
