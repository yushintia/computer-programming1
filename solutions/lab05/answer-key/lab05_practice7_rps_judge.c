/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_practice7_rps_judge.c
 * Description: Practice - reads two players' rock-paper-scissors choices
 *              and determines the winner of a single round using nested
 *              logical conditions.
 */
#include <stdio.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main(void) {
    int p1, p2;

    printf("Player 1 (1=Rock, 2=Paper, 3=Scissors): ");
    scanf("%d", &p1);
    printf("Player 2 (1=Rock, 2=Paper, 3=Scissors): ");
    scanf("%d", &p2);

    if (p1 < ROCK || p1 > SCISSORS || p2 < ROCK || p2 > SCISSORS) {
        printf("Invalid choice.\n");
    } else if (p1 == p2) {
        printf("It's a tie!\n");
    } else if ((p1 == ROCK && p2 == SCISSORS) ||
               (p1 == PAPER && p2 == ROCK) ||
               (p1 == SCISSORS && p2 == PAPER)) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}
