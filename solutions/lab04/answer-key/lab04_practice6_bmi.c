/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 04: Input/Output & Operators
 * Filename : lab04_practice6_bmi.c
 * Description: Reads weight and height, computes body mass index, and
 *              prints the 0/1 result of relational and logical checks
 *              for each BMI category band (ungraded practice problem).
 */
#include <stdio.h>

int main(void) {
    double weight_kg;
    double height_m;
    double bmi;

    printf("Enter weight in kg: ");
    scanf("%lf", &weight_kg);
    printf("Enter height in meters: ");
    scanf("%lf", &height_m);

    bmi = weight_kg / (height_m * height_m);

    printf("BMI: %6.2f\n", bmi);
    printf("Underweight (< 18.5)      : %d\n", bmi < 18.5);
    printf("Normal (18.5 to < 25)     : %d\n", bmi >= 18.5 && bmi < 25.0);
    printf("Overweight (>= 25)        : %d\n", bmi >= 25.0);
    return 0;
}
