/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_practice1_rectangle.c
 * Description: Reads a rectangle's length and width and prints its area
 *              and perimeter with two decimal places (ungraded practice
 *              problem).
 */
#include <stdio.h>

int main(void) {
    double length;
    double width;
    double area;
    double perimeter;

    printf("Enter the rectangle length: ");
    scanf("%lf", &length);
    printf("Enter the rectangle width: ");
    scanf("%lf", &width);

    area = length * width;
    perimeter = 2.0 * (length + width);

    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
    return 0;
}
