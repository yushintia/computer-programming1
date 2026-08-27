/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_names.c
 * Description: Reads 5 names, sorts them alphabetically with a bubble
 *              sort using strcmp, and prints the sorted list.
 */

#include <stdio.h>
#include <string.h>

#define NUM_NAMES 5
#define NAME_LEN 30

void read_names(char names[][NAME_LEN], int count);
void sort_names(char names[][NAME_LEN], int count);
void print_names(const char names[][NAME_LEN], int count);

/*
 * main: reads NUM_NAMES names, sorts them alphabetically, and prints
 * the sorted list.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char names[NUM_NAMES][NAME_LEN];

    printf("Enter %d names:\n", NUM_NAMES);
    read_names(names, NUM_NAMES);

    sort_names(names, NUM_NAMES);

    printf("\nSorted names:\n");
    print_names(names, NUM_NAMES);

    return 0;
}

/*
 * read_names: reads count names (one word each) into the names array.
 * Parameters: names - destination array of strings, count - how many to read
 * Returns: nothing
 */
void read_names(char names[][NAME_LEN], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name %d: ", i + 1);
        scanf("%29s", names[i]);
    }
}

/*
 * sort_names: sorts the names array alphabetically in ascending order
 * using a bubble sort with strcmp for comparison.
 * Parameters: names - array of strings to sort in place, count - length
 * Returns: nothing
 */
void sort_names(char names[][NAME_LEN], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char temp[NAME_LEN];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

/*
 * print_names: prints each name in the array, one per line.
 * Parameters: names - array of strings, count - length
 * Returns: nothing
 */
void print_names(const char names[][NAME_LEN], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", names[i]);
    }
}
