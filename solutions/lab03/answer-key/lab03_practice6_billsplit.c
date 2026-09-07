/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_practice6_billsplit.c
 * Description: Reads a total bill in won and a number of friends, then
 *              splits it evenly using integer division and modulo, and
 *              reports the leftover coins that cannot be split evenly
 *              (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    int total_won;
    int num_friends;
    int share_each;
    int leftover;

    printf("Enter the total bill in won: ");
    scanf("%d", &total_won);
    printf("Enter the number of friends splitting it: ");
    scanf("%d", &num_friends);

    share_each = total_won / num_friends;
    leftover = total_won % num_friends;

    printf("Each friend pays: %d won\n", share_each);
    printf("Leftover (cannot be split evenly): %d won\n", leftover);
    return 0;
}
