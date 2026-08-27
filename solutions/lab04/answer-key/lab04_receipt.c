/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_receipt.c
 * Description: Reads a unit price and quantity, then prints an aligned
 *              receipt with subtotal, 10% tax, and total.
 */
#include <stdio.h>

int main(void) {
    const double TAX_RATE = 0.10;
    double item_price;
    int quantity;
    double subtotal;
    double tax;
    double total;

    printf("Enter the item price: ");
    scanf("%lf", &item_price);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    subtotal = item_price * quantity;
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    /* width 9 with 2 decimals keeps every number right-aligned */
    printf("Item price :%9.2f\n", item_price);
    printf("Quantity   :%9d\n", quantity);
    printf("-----------------------\n");
    printf("Subtotal   :%9.2f\n", subtotal);
    printf("Tax (10%%)  :%9.2f\n", tax);
    printf("Total      :%9.2f\n", total);
    return 0;
}
