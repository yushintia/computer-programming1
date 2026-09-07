/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_practice3_discount.c
 * Description: Practice problem - demonstrates pass-by-value scope by
 *              showing that a shopping cart price is unchanged by a function
 *              call unless the caller explicitly reassigns it.
 */
#include <stdio.h>

int apply_discount(int price);

int main(void) {
    int original_price1 = 100;
    int discounted1 = apply_discount(original_price1);

    printf("Original price: %d\n", original_price1);
    printf("Price is unchanged after calling apply_discount: %d\n", original_price1);
    printf("Discounted price returned by the function: %d\n", discounted1);
    original_price1 = discounted1;
    printf("After reassigning, original price is now: %d\n", original_price1);

    int original_price2 = 250;
    int discounted2 = apply_discount(original_price2);

    printf("Original price: %d\n", original_price2);
    printf("Price is unchanged after calling apply_discount: %d\n", original_price2);
    printf("Discounted price returned by the function: %d\n", discounted2);
    original_price2 = discounted2;
    printf("After reassigning, original price is now: %d\n", original_price2);

    return 0;
}

/*
 * apply_discount: computes a price after a 20% discount. Because C passes
 * arguments by value, this function cannot change the caller's variable;
 * it only returns the new value.
 * Parameters: price - the original price in whole currency units
 * Returns: the price after a 20% discount
 */
int apply_discount(int price) {
    price = price - price / 5;
    return price;
}
