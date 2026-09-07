/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_practice2_letter_count.c
 * Description: Reads a sentence and a target letter, then counts how
 *              many times that letter appears in the sentence, ignoring
 *              case.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int count_letter(const char sentence[], char target);

/*
 * main: reads a sentence and a target letter, then prints how many
 * times the letter occurs in the sentence (case-insensitive).
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char sentence[MAX_LEN];
    char target;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LEN, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    printf("Enter a letter to count: ");
    scanf(" %c", &target);

    int count = count_letter(sentence, target);
    printf("'%c' appears %d time(s)\n", target, count);

    return 0;
}

/*
 * count_letter: counts occurrences of target in sentence, ignoring case.
 * Parameters: sentence - text to search, target - letter to count
 * Returns: the number of case-insensitive matches
 */
int count_letter(const char sentence[], char target) {
    int count = 0;
    char lower_target = (char)tolower((unsigned char)target);

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (tolower((unsigned char)sentence[i]) == lower_target) {
            count++;
        }
    }
    return count;
}
