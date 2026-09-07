/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 05: Conditional Statements
 * Filename : lab05_practice6_quadrant.c
 * Description: Practice - reads x and y coordinates and reports the
 *              quadrant, axis, or origin the point lies on.
 */
#include <stdio.h>

int main(void) {
    double x, y;

    printf("Enter x and y: ");
    scanf("%lf %lf", &x, &y);

    if (x == 0 && y == 0) {
        printf("Origin\n");
    } else if (x == 0) {
        printf("On y-axis\n");
    } else if (y == 0) {
        printf("On x-axis\n");
    } else if (x > 0 && y > 0) {
        printf("Quadrant I\n");
    } else if (x < 0 && y > 0) {
        printf("Quadrant II\n");
    } else if (x < 0 && y < 0) {
        printf("Quadrant III\n");
    } else {
        printf("Quadrant IV\n");
    }

    return 0;
}
