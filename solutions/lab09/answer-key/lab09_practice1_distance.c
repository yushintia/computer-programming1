/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_practice1_distance.c
 * Description: Practice - road trip distance converter with functions to
 *              convert kilometers to miles and back.
 */
#include <stdio.h>

double km_to_miles(double km);
double miles_to_km(double miles);

int main(void) {
    printf("%.1f km = %.2f miles\n", 10.0, km_to_miles(10.0));
    printf("%.1f km = %.2f miles\n", 100.0, km_to_miles(100.0));

    printf("%.1f miles = %.2f km\n", 50.0, miles_to_km(50.0));
    printf("%.1f miles = %.2f km\n", 26.2, miles_to_km(26.2));

    return 0;
}

/*
 * km_to_miles: converts a distance in kilometers to miles.
 * Parameters: km - distance in kilometers
 * Returns: the equivalent distance in miles
 */
double km_to_miles(double km) {
    return km * 0.621371;
}

/*
 * miles_to_km: converts a distance in miles to kilometers.
 * Parameters: miles - distance in miles
 * Returns: the equivalent distance in kilometers
 */
double miles_to_km(double miles) {
    return miles * 1.60934;
}
