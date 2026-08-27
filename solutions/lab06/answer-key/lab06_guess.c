/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_guess.c
 * Description: Number-guessing game using a do-while loop; reports
 *              Too low/Too high hints and the number of attempts taken.
 */
#include <stdio.h>

#define SECRET_NUMBER 42

int main(void) {
    int guess, attempts;

    attempts = 0;
    printf("Guess my number (1-100)!\n");
    do {
        printf("Your guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess < SECRET_NUMBER) {
            printf("Too low.\n");
        } else if (guess > SECRET_NUMBER) {
            printf("Too high.\n");
        }
    } while (guess != SECRET_NUMBER);

    printf("Correct! It took you %d guesses.\n", attempts);

    return 0;
}
