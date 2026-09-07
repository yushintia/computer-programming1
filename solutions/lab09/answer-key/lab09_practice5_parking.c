/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 09: Functions I: Basics
 * Filename : lab09_practice5_parking.c
 * Description: Practice - parking garage fee calculator function with a
 *              flat first-hour rate, an hourly rate after that, and a daily
 *              maximum, tested with several durations.
 */
#include <stdio.h>

#define BASE_FEE 5.0
#define HOURLY_RATE 2.0
#define MAX_FEE 20.0

double parking_fee(int hours);

int main(void) {
    printf("parking_fee(1) = %.2f\n", parking_fee(1));
    printf("parking_fee(4) = %.2f\n", parking_fee(4));
    printf("parking_fee(10) = %.2f\n", parking_fee(10));

    return 0;
}

/*
 * parking_fee: computes a parking fee: a flat rate for the first hour, an
 * hourly rate for each additional hour, capped at a daily maximum.
 * Parameters: hours - number of hours parked (hours >= 1)
 * Returns: the fee in currency units
 */
double parking_fee(int hours) {
    double fee;

    if (hours <= 1) {
        fee = BASE_FEE;
    } else {
        fee = BASE_FEE + (hours - 1) * HOURLY_RATE;
    }

    if (fee > MAX_FEE) {
        fee = MAX_FEE;
    }

    return fee;
}
