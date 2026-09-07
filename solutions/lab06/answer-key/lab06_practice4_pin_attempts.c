/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_practice4_pin_attempts.c
 * Description: Practice - uses a do-while loop to give the user up to
 *              three attempts to enter the correct PIN.
 */
#include <stdio.h>

#define CORRECT_PIN 1234
#define MAX_ATTEMPTS 3

int main(void) {
    int pin, attempts, granted;

    attempts = 0;
    granted = 0;
    do {
        printf("Enter PIN: ");
        scanf("%d", &pin);
        attempts++;
        if (pin == CORRECT_PIN) {
            granted = 1;
        } else if (attempts < MAX_ATTEMPTS) {
            printf("Incorrect PIN. Attempts left: %d\n", MAX_ATTEMPTS - attempts);
        }
    } while (pin != CORRECT_PIN && attempts < MAX_ATTEMPTS);

    if (granted == 1) {
        printf("Access granted.\n");
    } else {
        printf("Account locked.\n");
    }

    return 0;
}
