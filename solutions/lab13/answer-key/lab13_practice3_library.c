/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_practice3_library.c
 * Description: Reads a small library catalog into an array of structs,
 *              then searches it by title using strcmp and reports the
 *              matching book's author and year.
 */

#include <stdio.h>
#include <string.h>

#define NUM_BOOKS 4
#define TITLE_LEN 40
#define AUTHOR_LEN 30

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

void read_books(Book books[], int count);
int find_book(const Book books[], int count, const char title[]);

/*
 * main: reads NUM_BOOKS books, then searches for a book by title and
 * prints its author and year, or reports that it was not found.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Book books[NUM_BOOKS];
    char search_title[TITLE_LEN];

    read_books(books, NUM_BOOKS);

    printf("Search for title: ");
    scanf("%39s", search_title);

    int index = find_book(books, NUM_BOOKS, search_title);
    if (index == -1) {
        printf("Not found\n");
    } else {
        printf("Found: %s (%d)\n", books[index].author, books[index].year);
    }

    return 0;
}

/*
 * read_books: reads a title, author, and year for each book.
 * Parameters: books - destination array of Book, count - how many books
 *             to read
 * Returns: nothing
 */
void read_books(Book books[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Book %d title: ", i + 1);
        scanf("%39s", books[i].title);
        printf("Author: ");
        scanf("%29s", books[i].author);
        printf("Year: ");
        scanf("%d", &books[i].year);
    }
}

/*
 * find_book: linearly searches books for an entry whose title matches
 * title exactly.
 * Parameters: books - array of Book, count - number of entries, title -
 *             title to search for
 * Returns: the index of the matching book, or -1 if none matches
 */
int find_book(const Book books[], int count, const char title[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}
