/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_practice1_reverse.c
 * Description: Reads a single word and prints it reversed by swapping
 *              characters in place from both ends toward the middle.
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

void reverse_word(char word[]);

/*
 * main: reads one word and prints its reversed form.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char word[MAX_LEN];

    printf("Enter a word: ");
    scanf("%49s", word);

    reverse_word(word);

    printf("Reversed: %s\n", word);

    return 0;
}

/*
 * reverse_word: reverses the characters of word in place by swapping
 * the character at each end and working inward.
 * Parameters: word - null-terminated string to reverse
 * Returns: nothing
 */
void reverse_word(char word[]) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        char temp = word[i];
        word[i] = word[len - 1 - i];
        word[len - 1 - i] = temp;
    }
}
