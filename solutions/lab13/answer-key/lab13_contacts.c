/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 13: Basic Data Structures
 * Filename : lab13_contacts.c
 * Description: Reads 3 contacts (name, phone, email) into an array of
 *              structs and prints them as a formatted table.
 */

#include <stdio.h>

#define NUM_CONTACTS 3
#define NAME_LEN 30
#define PHONE_LEN 20
#define EMAIL_LEN 40

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} ContactEntry;

void read_contacts(ContactEntry contacts[], int count);
void print_contacts(const ContactEntry contacts[], int count);

/*
 * main: reads NUM_CONTACTS contacts and prints them as a table.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    ContactEntry contacts[NUM_CONTACTS];

    read_contacts(contacts, NUM_CONTACTS);

    printf("\n");
    print_contacts(contacts, NUM_CONTACTS);

    return 0;
}

/*
 * read_contacts: reads name, phone, and email for each contact.
 * Parameters: contacts - destination array of ContactEntry, count - how
 *             many contacts to read
 * Returns: nothing
 */
void read_contacts(ContactEntry contacts[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Contact %d name: ", i + 1);
        scanf("%29s", contacts[i].name);
        printf("Contact %d phone: ", i + 1);
        scanf("%19s", contacts[i].phone);
        printf("Contact %d email: ", i + 1);
        scanf("%39s", contacts[i].email);
    }
}

/*
 * print_contacts: prints the contacts array as a formatted table with
 * name, phone, and email columns.
 * Parameters: contacts - array of ContactEntry, count - number of entries
 * Returns: nothing
 */
void print_contacts(const ContactEntry contacts[], int count) {
    printf("%-15s %-15s %-25s\n", "Name", "Phone", "Email");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-15s %-25s\n",
               contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}
