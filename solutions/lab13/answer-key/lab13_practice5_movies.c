/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_practice5_movies.c
 * Description: Reads 5 movies (title and rating) into an array of
 *              structs, then counts and lists how many movies meet or
 *              exceed a rating threshold entered by the user.
 */

#include <stdio.h>

#define NUM_MOVIES 5
#define TITLE_LEN 30

typedef struct {
    char title[TITLE_LEN];
    double rating;
} Movie;

void read_movies(Movie movies[], int count);
int print_movies_at_or_above(const Movie movies[], int count, double threshold);

/*
 * main: reads NUM_MOVIES movies, reads a rating threshold, then prints
 * and counts the movies rated at or above that threshold.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Movie movies[NUM_MOVIES];
    double threshold;

    read_movies(movies, NUM_MOVIES);

    printf("Rating threshold: ");
    scanf("%lf", &threshold);

    printf("Movies rated >= %.1f:\n", threshold);
    int matches = print_movies_at_or_above(movies, NUM_MOVIES, threshold);

    printf("Total: %d movie(s)\n", matches);

    return 0;
}

/*
 * read_movies: reads a title and rating for each movie.
 * Parameters: movies - destination array of Movie, count - how many
 *             movies to read
 * Returns: nothing
 */
void read_movies(Movie movies[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Movie %d title: ", i + 1);
        scanf("%29s", movies[i].title);
        printf("Rating: ");
        scanf("%lf", &movies[i].rating);
    }
}

/*
 * print_movies_at_or_above: prints the title of every movie whose
 * rating is >= threshold and counts how many there are.
 * Parameters: movies - array of Movie, count - number of movies,
 *             threshold - minimum rating to include
 * Returns: the number of movies printed
 */
int print_movies_at_or_above(const Movie movies[], int count, double threshold) {
    int matches = 0;
    for (int i = 0; i < count; i++) {
        if (movies[i].rating >= threshold) {
            printf("  %s (%.1f)\n", movies[i].title, movies[i].rating);
            matches++;
        }
    }
    return matches;
}
