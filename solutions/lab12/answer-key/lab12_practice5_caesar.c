/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_practice5_caesar.c
 * Description: Reads a lowercase word and a shift amount, then prints
 *              the word encoded with a Caesar cipher that wraps from
 *              'z' back to 'a'.
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 50
#define ALPHABET_SIZE 26

void encode_caesar(char word[], int shift);

/*
 * main: reads a lowercase word and a shift amount, then prints the
 * Caesar-cipher-encoded word.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char word[MAX_LEN];
    int shift;

    printf("Enter a lowercase word: ");
    scanf("%49s", word);

    printf("Enter shift amount: ");
    scanf("%d", &shift);

    encode_caesar(word, shift);

    printf("Encoded: %s\n", word);

    return 0;
}

/*
 * encode_caesar: shifts every letter in word forward by shift places in
 * the alphabet, wrapping around from 'z' back to 'a', in place.
 * Parameters: word - lowercase letters only, modified in place
 *             shift - number of positions to shift forward (may be
 *             larger than 26; wrapping is handled with modulo)
 * Returns: nothing
 */
void encode_caesar(char word[], int shift) {
    int len = strlen(word);
    int wrapped_shift = shift % ALPHABET_SIZE;

    for (int i = 0; i < len; i++) {
        int offset = word[i] - 'a';
        word[i] = 'a' + (offset + wrapped_shift) % ALPHABET_SIZE;
    }
}
