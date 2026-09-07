/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_practice4_inventory.c
 * Description: Reads a product inventory into an array of structs,
 *              computes the total inventory value, and reports which
 *              product contributes the highest total value.
 */

#include <stdio.h>

#define NUM_PRODUCTS 4
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    int quantity;
    double unit_price;
} Product;

void read_products(Product products[], int count);
double total_inventory_value(const Product products[], int count);
int highest_value_index(const Product products[], int count);

/*
 * main: reads NUM_PRODUCTS products, prints the total inventory value,
 * and reports the product with the highest total value.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    Product products[NUM_PRODUCTS];

    read_products(products, NUM_PRODUCTS);

    double total = total_inventory_value(products, NUM_PRODUCTS);
    printf("Total inventory value: %.2f\n", total);

    int index = highest_value_index(products, NUM_PRODUCTS);
    double best_value = products[index].quantity * products[index].unit_price;
    printf("Highest value product: %s (%.2f)\n",
           products[index].name, best_value);

    return 0;
}

/*
 * read_products: reads a name, quantity, and unit price for each
 * product.
 * Parameters: products - destination array of Product, count - how
 *             many products to read
 * Returns: nothing
 */
void read_products(Product products[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Product %d name: ", i + 1);
        scanf("%19s", products[i].name);
        printf("Quantity: ");
        scanf("%d", &products[i].quantity);
        printf("Unit price: ");
        scanf("%lf", &products[i].unit_price);
    }
}

/*
 * total_inventory_value: sums quantity * unit_price over all products.
 * Parameters: products - array of Product, count - number of products
 * Returns: the total inventory value as a double
 */
double total_inventory_value(const Product products[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += products[i].quantity * products[i].unit_price;
    }
    return total;
}

/*
 * highest_value_index: finds the index of the product with the highest
 * total value (quantity * unit_price).
 * Parameters: products - array of Product, count - number of products
 *             (count > 0)
 * Returns: the index of the highest-value product
 */
int highest_value_index(const Product products[], int count) {
    int best_index = 0;
    double best_value = products[0].quantity * products[0].unit_price;

    for (int i = 1; i < count; i++) {
        double value = products[i].quantity * products[i].unit_price;
        if (value > best_value) {
            best_value = value;
            best_index = i;
        }
    }
    return best_index;
}
