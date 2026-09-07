/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_practice1_rectangles.c
 * Description: Reads a catalog of rectangles (label, width, height) into
 *              an array of structs and prints a table with each
 *              rectangle's computed area.
 */

#include <stdio.h>

#define NUM_RECTANGLES 3
#define LABEL_LEN 10

typedef struct {
    char label[LABEL_LEN];
    double width;
    double height;
} Rectangle;

void read_rectangles(Rectangle rects[], int count);
void print_catalog(const Rectangle rects[], int count);

/*
 * main: reads NUM_RECTANGLES rectangles and prints a table of their
 * dimensions and areas.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Rectangle rects[NUM_RECTANGLES];

    read_rectangles(rects, NUM_RECTANGLES);

    printf("\n");
    print_catalog(rects, NUM_RECTANGLES);

    return 0;
}

/*
 * read_rectangles: reads a label, width, and height for each rectangle.
 * Parameters: rects - destination array of Rectangle, count - how many
 *             rectangles to read
 * Returns: nothing
 */
void read_rectangles(Rectangle rects[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Rectangle %d label: ", i + 1);
        scanf("%9s", rects[i].label);
        printf("Width: ");
        scanf("%lf", &rects[i].width);
        printf("Height: ");
        scanf("%lf", &rects[i].height);
    }
}

/*
 * print_catalog: prints rects as a formatted table with label, width,
 * height, and computed area columns.
 * Parameters: rects - array of Rectangle, count - number of entries
 * Returns: nothing
 */
void print_catalog(const Rectangle rects[], int count) {
    printf("%-10s %8s %8s %8s\n", "Label", "Width", "Height", "Area");
    for (int i = 0; i < count; i++) {
        double area = rects[i].width * rects[i].height;
        printf("%-10s %8.2f %8.2f %8.2f\n",
               rects[i].label, rects[i].width, rects[i].height, area);
    }
}
