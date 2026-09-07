/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_practice3_seating.c
 * Description: Reads a classroom seating chart as a 2-D char array
 *              ('X' occupied, '.' empty), prints it back, and reports
 *              how many empty seats are in each row.
 */

#include <stdio.h>

#define NUM_ROWS 3
#define NUM_COLS 4

void read_chart(char chart[][NUM_COLS + 1], int rows);
void print_chart(const char chart[][NUM_COLS + 1], int rows);
int count_empty(const char row[]);

/*
 * main: reads a NUM_ROWS x NUM_COLS seating chart, prints it back, then
 * prints the number of empty seats in each row.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char chart[NUM_ROWS][NUM_COLS + 1];

    read_chart(chart, NUM_ROWS);

    printf("\n");
    print_chart(chart, NUM_ROWS);

    for (int r = 0; r < NUM_ROWS; r++) {
        printf("Row %d empty seats: %d\n", r + 1, count_empty(chart[r]));
    }

    return 0;
}

/*
 * read_chart: reads rows seat strings (each NUM_COLS characters of 'X'
 * or '.') into chart.
 * Parameters: chart - destination array of row strings, rows - row count
 * Returns: nothing
 */
void read_chart(char chart[][NUM_COLS + 1], int rows) {
    for (int r = 0; r < rows; r++) {
        printf("Row %d: ", r + 1);
        scanf("%4s", chart[r]);
    }
}

/*
 * print_chart: prints each row string of chart, one per line.
 * Parameters: chart - array of row strings, rows - row count
 * Returns: nothing
 */
void print_chart(const char chart[][NUM_COLS + 1], int rows) {
    for (int r = 0; r < rows; r++) {
        printf("%s\n", chart[r]);
    }
}

/*
 * count_empty: counts how many '.' characters appear in row.
 * Parameters: row - a null-terminated seat string
 * Returns: the number of empty ('.') seats
 */
int count_empty(const char row[]) {
    int empty = 0;
    for (int c = 0; row[c] != '\0'; c++) {
        if (row[c] == '.') {
            empty++;
        }
    }
    return empty;
}
