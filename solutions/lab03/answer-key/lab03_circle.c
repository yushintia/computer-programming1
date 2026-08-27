/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 03: Variables, Data Types & Expressions
 * Filename : lab03_circle.c
 * Description: Reads a circle's radius and prints its area and
 *              circumference with four decimal places.
 */
#include <stdio.h>

int main(void) {
    const double PI = 3.14159265;
    double radius;
    double area;
    double circumference;

    printf("Enter the radius: ");
    scanf("%lf", &radius);

    area = PI * radius * radius;
    circumference = 2.0 * PI * radius;

    printf("Area          : %.4f\n", area);
    printf("Circumference : %.4f\n", circumference);
    return 0;
}
