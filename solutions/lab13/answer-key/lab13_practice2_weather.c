/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_practice2_weather.c
 * Description: Reads 5 daily temperature readings into an array of
 *              structs and reports the hottest and coldest day.
 */

#include <stdio.h>

#define NUM_READINGS 5
#define DAY_LEN 10

typedef struct {
    char day[DAY_LEN];
    double celsius;
} Reading;

void read_readings(Reading readings[], int count);
Reading hottest_day(const Reading readings[], int count);
Reading coldest_day(const Reading readings[], int count);

/*
 * main: reads NUM_READINGS daily temperatures and prints the hottest
 * and coldest day.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Reading readings[NUM_READINGS];

    read_readings(readings, NUM_READINGS);

    Reading hottest = hottest_day(readings, NUM_READINGS);
    Reading coldest = coldest_day(readings, NUM_READINGS);

    printf("Hottest day: %s (%.1f C)\n", hottest.day, hottest.celsius);
    printf("Coldest day: %s (%.1f C)\n", coldest.day, coldest.celsius);

    return 0;
}

/*
 * read_readings: reads a day name and a Celsius temperature for each
 * reading.
 * Parameters: readings - destination array of Reading, count - how many
 *             readings to read
 * Returns: nothing
 */
void read_readings(Reading readings[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Day %d name: ", i + 1);
        scanf("%9s", readings[i].day);
        printf("Temperature (C): ");
        scanf("%lf", &readings[i].celsius);
    }
}

/*
 * hottest_day: returns a copy of the Reading with the highest celsius.
 * Parameters: readings - array of Reading, count - number of readings
 *             (count > 0)
 * Returns: the Reading with the highest temperature
 */
Reading hottest_day(const Reading readings[], int count) {
    Reading best = readings[0];
    for (int i = 1; i < count; i++) {
        if (readings[i].celsius > best.celsius) {
            best = readings[i];
        }
    }
    return best;
}

/*
 * coldest_day: returns a copy of the Reading with the lowest celsius.
 * Parameters: readings - array of Reading, count - number of readings
 *             (count > 0)
 * Returns: the Reading with the lowest temperature
 */
Reading coldest_day(const Reading readings[], int count) {
    Reading best = readings[0];
    for (int i = 1; i < count; i++) {
        if (readings[i].celsius < best.celsius) {
            best = readings[i];
        }
    }
    return best;
}
