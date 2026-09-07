/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_practice5_discount.c
 * Description: Reads a price, a discount percentage, and a tax
 *              percentage, then applies both in a single expression to
 *              demonstrate operator precedence and parentheses (ungraded
 *              practice problem).
 */
#include <stdio.h>

int main(void) {
    double price;
    double discount_percent;
    double tax_percent;
    double final_price;

    printf("Enter the original price: ");
    scanf("%lf", &price);
    printf("Enter the discount percent (e.g., 20): ");
    scanf("%lf", &discount_percent);
    printf("Enter the tax percent (e.g., 10): ");
    scanf("%lf", &tax_percent);

    /* precedence: parentheses first, then * left to right */
    final_price = price * (1.0 - discount_percent / 100.0)
                        * (1.0 + tax_percent / 100.0);

    printf("Final price: %.2f\n", final_price);
    return 0;
}
