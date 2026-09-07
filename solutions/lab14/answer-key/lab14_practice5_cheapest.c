/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_practice5_cheapest.c
 * Description: Corrected version of the buggy cheapest-item finder from
 *              Practice Problem 5. Reads a small list of items (name,
 *              price) and reports the cheapest one.
 */

#include <stdio.h>

#define NUM_ITEMS 4
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    double price;
} Item;

void read_items(Item items[], int count);
int find_cheapest(const Item items[], int count);

/*
 * main: reads NUM_ITEMS items and prints the cheapest one.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Item items[NUM_ITEMS];

    read_items(items, NUM_ITEMS);

    int index = find_cheapest(items, NUM_ITEMS);
    printf("Cheapest item: %s ($%.2f)\n", items[index].name, items[index].price);

    return 0;
}

/*
 * read_items: reads a name and price for each item.
 * Parameters: items - destination array of Item, count - how many items
 *             to read
 * Returns: nothing
 */
void read_items(Item items[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Item %d name: ", i + 1);
        scanf("%19s", items[i].name);
        printf("Price: ");
        scanf("%lf", &items[i].price);
    }
}

/*
 * find_cheapest: finds the index of the item with the lowest price.
 * Parameters: items - array of Item, count - number of items (count > 0)
 * Returns: the index of the cheapest item
 */
int find_cheapest(const Item items[], int count) {
    int cheapest_index = 0;
    /* BUG FIX: the original started best_price at 0.0, so the
     * "items[i].price < best_price" test was never true for any real
     * (positive) price, and the function always returned index 0
     * regardless of the actual cheapest item. Starting from the first
     * item's own price fixes the comparison. */
    double best_price = items[0].price;

    for (int i = 1; i < count; i++) {
        if (items[i].price < best_price) {
            cheapest_index = i;
            best_price = items[i].price;
        }
    }
    return cheapest_index;
}
