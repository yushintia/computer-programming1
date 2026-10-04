/* buggy.c: summarize five test scores */
#include <stdio.h>

#define COUNT 5

int main(void) {
    int scores[COUNT] = {72, 85, 90, 64, 88}
    int total = 0;
    int highest = scores[0];

    for (int i = 0; i <= COUNT; i++) {
        total += scores[i];
        if (scores[i] < highest) {
            highest = scores[i];
        }
    }

    printf("Total: %d\n", total);
    printf("Average: %.2f\n", (double)total / COUNT);
    printf("Highest: %d\n", highest);
    return 0;
}
