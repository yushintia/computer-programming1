/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_practice2_vowel_count.c
 * Description: Corrected version of the buggy vowel counter from
 *              Practice Problem 2. Reads a word and counts its vowels.
 */

#include <stdio.h>

int count_vowels(const char word[]);

/*
 * main: reads a word and prints how many vowels it contains.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char word[50];

    printf("Enter a word: ");
    scanf("%49s", word);

    printf("Vowel count: %d\n", count_vowels(word));

    return 0;
}

/*
 * count_vowels: counts how many characters in word are a, e, i, o, or u.
 * Parameters: word - null-terminated lowercase string
 * Returns: the number of vowels found
 */
int count_vowels(const char word[]) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];
        /* BUG FIX: the original used && between every comparison, which
         * requires c to equal five different characters at once: an
         * impossible condition, so no vowel was ever counted. Chaining
         * with || (any one of the letters matches) is correct. */
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}
