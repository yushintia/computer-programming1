/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_practice5_ticket_price.c
 * Description: Practice - presents a movie-ticket category menu, looks up
 *              the base price with switch-case, and applies a weekend
 *              surcharge using a nested if.
 */
#include <stdio.h>

#define CHILD_PRICE 6.00
#define ADULT_PRICE 12.00
#define SENIOR_PRICE 9.00
#define WEEKEND_SURCHARGE 1.50
#define CATEGORY_CHILD 1
#define CATEGORY_ADULT 2
#define CATEGORY_SENIOR 3

int main(void) {
    int category, weekend;
    double price;

    printf("1. Child\n");
    printf("2. Adult\n");
    printf("3. Senior\n");
    printf("Enter category (1-3): ");
    scanf("%d", &category);
    printf("Weekend? (1=yes, 0=no): ");
    scanf("%d", &weekend);

    if (category < CATEGORY_CHILD || category > CATEGORY_SENIOR) {
        printf("Invalid category.\n");
    } else {
        switch (category) {
            case CATEGORY_CHILD:
                price = CHILD_PRICE;
                break;
            case CATEGORY_ADULT:
                price = ADULT_PRICE;
                break;
            case CATEGORY_SENIOR:
                price = SENIOR_PRICE;
                break;
            default:
                price = 0.0;
                break;
        }

        if (weekend == 1) {
            price += WEEKEND_SURCHARGE;
        }
        printf("Ticket price: $%.2f\n", price);
    }

    return 0;
}
