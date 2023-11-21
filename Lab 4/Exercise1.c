/*Write a program that simulates a simple address book. Define a structure to store contact
information (name, email, phone number). Allow the user to add new contacts to the
address book dynamically. Use dynamic memory allocation for storing the contacts using
malloc and update the memory allocation using realloc when adding new contacts.
Implement an option to delete a contact and free the memory. Ensure that memory is
properly managed throughout the program's execution.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact information
struct Contact {
    char name[50];
    char email[50];
    char phone[15];
};

// Function to add a new contact to the address book
void addContact(struct Contact **addressBook, int *numContacts) {
    // Increment the number of contacts
    (*numContacts)++;

    // Dynamically allocate memory for the new contact
    *addressBook = realloc(*addressBook, (*numContacts) * sizeof(struct Contact));

    // Check if memory allocation is successful
    if (*addressBook == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Get user input for the new contact
    printf("Enter contact details:\n");
    printf("Name: ");
    scanf("%s", (*addressBook + (*numContacts - 1))->name);
    printf("Email: ");
    scanf("%s", (*addressBook + (*numContacts - 1))->email);
    printf("Phone: ");
    scanf("%s", (*addressBook + (*numContacts - 1))->phone);

    printf("Contact added successfully.\n");
}

// Function to delete a contact from the address book
void deleteContact(struct Contact **addressBook, int *numContacts, char *name) {
    int found = 0;

    // Search for the contact by name
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp((*addressBook + i)->name, name) == 0) {
            // Contact found, shift remaining contacts to fill the gap
            found = 1;
            for (int j = i; j < *numContacts - 1; j++) {
                strcpy((*addressBook + j)->name, (*addressBook + j + 1)->name);
                strcpy((*addressBook + j)->email, (*addressBook + j + 1)->email);
                strcpy((*addressBook + j)->phone, (*addressBook + j + 1)->phone);
            }

            // Decrement the number of contacts
            (*numContacts)--;

            // Reallocate memory to adjust the size
            *addressBook = realloc(*addressBook, (*numContacts) * sizeof(struct Contact));

            // Check if memory reallocation is successful
            // if (*addressBook == NULL) {
            //     fprintf(stderr, "Memory reallocation error.\n");
            //     exit(EXIT_FAILURE);
            // }

            printf("Contact deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to display all contacts in the address book
void displayContacts(const struct Contact *addressBook, int numContacts) {
    if (numContacts == 0) {
        printf("Address book is empty.\n");
        return;
    }

    printf("Address Book:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", (addressBook + i)->name);
        printf("Email: %s\n", (addressBook + i)->email);
        printf("Phone: %s\n", (addressBook + i)->phone);
        printf("------------------------\n");
    }
}

// Function to free the allocated memory for the address book
void freeAddressBook(struct Contact *addressBook) {
    free(addressBook);
}

int main() {
    struct Contact *addressBook = NULL;
    int numContacts = 0;
    int choice;
    char nameToDelete[50];

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Add a contact\n");
        printf("2. Delete a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&addressBook, &numContacts);
                break;
            case 2:
                if (numContacts > 0) {
                    printf("Enter the name to delete: ");
                    scanf("%s", nameToDelete);
                    deleteContact(&addressBook, &numContacts, nameToDelete);
                } else {
                    printf("Address book is empty. Cannot delete.\n");
                }
                break;
            case 3:
                displayContacts(addressBook, numContacts);
                break;
            case 4:
                // Free the allocated memory before exiting
                freeAddressBook(addressBook);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
