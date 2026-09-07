/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_practice7_leaderboard.c
 * Description: Reads 5 players (name, score, level) into an array of
 *              structs, reports the top scorer, the average score, and
 *              how many players reached at least a given level.
 */

#include <stdio.h>

#define NUM_PLAYERS 5
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    int score;
    int level;
} Player;

void read_players(Player players[], int count);
Player top_scorer(const Player players[], int count);
double average_score(const Player players[], int count);
int count_at_or_above_level(const Player players[], int count, int min_level);

/*
 * main: reads NUM_PLAYERS players, prints the top scorer and average
 * score, then reports how many players reached at least a given level.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Player players[NUM_PLAYERS];
    int min_level;

    read_players(players, NUM_PLAYERS);

    Player best = top_scorer(players, NUM_PLAYERS);
    printf("Top scorer: %s (%d)\n", best.name, best.score);

    double average = average_score(players, NUM_PLAYERS);
    printf("Average score: %.2f\n", average);

    printf("Minimum level to check: ");
    scanf("%d", &min_level);

    int reached = count_at_or_above_level(players, NUM_PLAYERS, min_level);
    printf("Players at level %d or above: %d\n", min_level, reached);

    return 0;
}

/*
 * read_players: reads a name, score, and level for each player.
 * Parameters: players - destination array of Player, count - how many
 *             players to read
 * Returns: nothing
 */
void read_players(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Player %d name: ", i + 1);
        scanf("%19s", players[i].name);
        printf("Score: ");
        scanf("%d", &players[i].score);
        printf("Level: ");
        scanf("%d", &players[i].level);
    }
}

/*
 * top_scorer: returns a copy of the Player with the highest score.
 * Parameters: players - array of Player, count - number of players
 *             (count > 0)
 * Returns: the Player with the highest score
 */
Player top_scorer(const Player players[], int count) {
    Player best = players[0];
    for (int i = 1; i < count; i++) {
        if (players[i].score > best.score) {
            best = players[i];
        }
    }
    return best;
}

/*
 * average_score: returns the average score across all players.
 * Parameters: players - array of Player, count - number of players
 *             (count > 0)
 * Returns: the average score as a double
 */
double average_score(const Player players[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += players[i].score;
    }
    return (double)total / count;
}

/*
 * count_at_or_above_level: counts players whose level is >= min_level.
 * Parameters: players - array of Player, count - number of players,
 *             min_level - the minimum level to count
 * Returns: the number of matching players
 */
int count_at_or_above_level(const Player players[], int count, int min_level) {
    int matches = 0;
    for (int i = 0; i < count; i++) {
        if (players[i].level >= min_level) {
            matches++;
        }
    }
    return matches;
}
