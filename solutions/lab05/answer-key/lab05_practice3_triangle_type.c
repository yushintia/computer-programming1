/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_practice3_triangle_type.c
 * Description: Practice - reads three side lengths, checks whether they
 *              form a valid triangle, and classifies it as equilateral,
 *              isosceles, or scalene.
 */
#include <stdio.h>

int main(void) {
    double a, b, c;

    printf("Enter three side lengths: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        printf("Not a valid triangle\n");
    } else if (a == b && b == c) {
        printf("Valid triangle: Equilateral\n");
    } else if (a == b || b == c || a == c) {
        printf("Valid triangle: Isosceles\n");
    } else {
        printf("Valid triangle: Scalene\n");
    }

    return 0;
}
