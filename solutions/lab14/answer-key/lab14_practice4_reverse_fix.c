/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_practice4_reverse_fix.c
 * Description: Corrected version of the buggy in-place string reverser
 *              from Practice Problem 4. Reads a word and prints it
 *              reversed.
 */

#include <stdio.h>
#include <string.h>

void reverse_string(char s[]);

/*
 * main: reads a word and prints it reversed.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char word[50];

    printf("Enter a word: ");
    scanf("%49s", word);

    reverse_string(word);

    printf("Reversed: %s\n", word);

    return 0;
}

/*
 * reverse_string: reverses s in place by swapping characters from each
 * end toward the middle.
 * Parameters: s - null-terminated string to reverse
 * Returns: nothing
 */
void reverse_string(char s[]) {
    int len = strlen(s);
    /* BUG FIX: the original looped i from 0 to len - 1, which swaps
     * every pair once going in and then swaps each pair BACK on the
     * second half of the loop, leaving the string unchanged. Stopping
     * at len / 2 swaps each pair exactly once. */
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
