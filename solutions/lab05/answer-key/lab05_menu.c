/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_menu.c
 * Description: Presents a shape-area menu and computes the chosen area
 *              using a switch-case statement.
 */
#include <stdio.h>

#define PI 3.14159265358979
#define CHOICE_CIRCLE 1
#define CHOICE_SQUARE 2
#define CHOICE_TRIANGLE 3
#define CHOICE_QUIT 4

int main(void) {
    int choice;
    double radius, side, base, height, area;

    printf("1. Circle area\n");
    printf("2. Square area\n");
    printf("3. Triangle area\n");
    printf("4. Quit\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case CHOICE_CIRCLE:
            printf("Enter radius: ");
            scanf("%lf", &radius);
            area = PI * radius * radius;
            printf("Circle area: %.2f\n", area);
            break;
        case CHOICE_SQUARE:
            printf("Enter side length: ");
            scanf("%lf", &side);
            area = side * side;
            printf("Square area: %.2f\n", area);
            break;
        case CHOICE_TRIANGLE:
            printf("Enter base: ");
            scanf("%lf", &base);
            printf("Enter height: ");
            scanf("%lf", &height);
            area = 0.5 * base * height;
            printf("Triangle area: %.2f\n", area);
            break;
        case CHOICE_QUIT:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
