/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_text.c
 * Description: Reads a word and prints its length, whether it is a
 *              palindrome, its vowel count, and its uppercase form.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

int is_palindrome(const char s[]);
int count_vowels(const char s[]);
void to_uppercase(const char src[], char dst[]);

/*
 * main: reads a single word and prints its length, palindrome status,
 * vowel count, and uppercase form.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char word[MAX_WORD_LEN];
    char upper[MAX_WORD_LEN];

    printf("Enter a word (no spaces): ");
    scanf("%99s", word);

    int length = (int)strlen(word);
    int vowels = count_vowels(word);
    to_uppercase(word, upper);

    printf("Length: %d\n", length);
    printf("Palindrome: %s\n", is_palindrome(word) ? "yes" : "no");
    printf("Vowel count: %d\n", vowels);
    printf("Uppercase: %s\n", upper);

    return 0;
}

/*
 * is_palindrome: returns 1 if s reads the same forwards and backwards
 * (case-sensitive), 0 otherwise.
 * Parameters: s - null-terminated string to check
 * Returns: 1 if palindrome, 0 if not
 */
int is_palindrome(const char s[]) {
    int len = (int)strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

/*
 * count_vowels: counts how many characters of s are vowels (a, e, i, o, u),
 * case-insensitive.
 * Parameters: s - null-terminated string to scan
 * Returns: number of vowel characters found
 */
int count_vowels(const char s[]) {
    int count = 0;
    int len = (int)strlen(s);
    for (int i = 0; i < len; i++) {
        char c = (char)tolower((unsigned char)s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

/*
 * to_uppercase: copies src into dst with every letter converted to
 * uppercase using toupper.
 * Parameters: src - source string, dst - destination buffer (must be
 *             at least as large as src, including the terminator)
 * Returns: nothing
 */
void to_uppercase(const char src[], char dst[]) {
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dst[i] = (char)toupper((unsigned char)src[i]);
    }
    dst[i] = '\0';
}
