/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_practice6_longest_word.c
 * Description: Reads 5 words into an array of strings, finds the index
 *              of the longest word, and prints it with its length.
 */

#include <stdio.h>
#include <string.h>

#define NUM_WORDS 5
#define WORD_LEN 20

void read_words(char words[][WORD_LEN], int count);
int longest_word_index(const char words[][WORD_LEN], int count);

/*
 * main: reads NUM_WORDS words and prints the longest one along with its
 * length.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char words[NUM_WORDS][WORD_LEN];

    read_words(words, NUM_WORDS);

    int index = longest_word_index(words, NUM_WORDS);

    printf("Longest word: %s (%d letters)\n",
           words[index], (int)strlen(words[index]));

    return 0;
}

/*
 * read_words: reads count words (one per line of input) into words.
 * Parameters: words - destination array of strings, count - how many
 *             words to read
 * Returns: nothing
 */
void read_words(char words[][WORD_LEN], int count) {
    for (int i = 0; i < count; i++) {
        printf("Word %d: ", i + 1);
        scanf("%19s", words[i]);
    }
}

/*
 * longest_word_index: finds the index of the longest string in words.
 * On a tie, the first (lowest-index) longest word wins.
 * Parameters: words - array of strings, count - number of strings
 * Returns: the index of the longest word
 */
int longest_word_index(const char words[][WORD_LEN], int count) {
    int best_index = 0;
    for (int i = 1; i < count; i++) {
        if (strlen(words[i]) > strlen(words[best_index])) {
            best_index = i;
        }
    }
    return best_index;
}
