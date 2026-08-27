/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_precedence.c
 * Description: Verifies the precedence-puzzle predictions by printing the
 *              value of each expression next to its predicted result.
 */
#include <stdio.h>

/*
 * Predictions (made before running):
 *   x = 2 + 3 * 4 - 1     -> * first: 2 + 12 - 1        -> predicted 13
 *   y = (2 + 3) * (4 - 1) -> parentheses first: 5 * 3   -> predicted 15
 *   z = 10 / 3 + 10 % 3   -> 3 + 1 (int division, mod)  -> predicted 4
 * Predicted output line: "13 15 4"
 */
int main(void) {
    int x = 2 + 3 * 4 - 1;     /* predicted 13: * binds tighter than + and - */
    int y = (2 + 3) * (4 - 1); /* predicted 15: parentheses evaluate first */
    int z = 10 / 3 + 10 % 3;   /* predicted 4: 10/3 truncates to 3, 10%3 is 1 */

    printf("%d %d %d\n", x, y, z);
    return 0;
}
