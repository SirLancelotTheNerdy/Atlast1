#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

// Define a struct to store contact information
typedef struct {
    char name[MAX_CONTACT_NAME_LENGTH];
    char phone[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_ADDRESS_LENGTH];
} Contact;

// Function declarations
int load_contacts(Contact contacts[], const char *filename);
void list_contacts(Contact contacts[], int num_contacts);
void select_contact(Contact contacts[], int num_contacts);
void perform_contact_action(Contact contact);

// Main menu function
void display_menu();

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;

    // Load contacts from the CSV file
    num_contacts = load_contacts(contacts, "phone_contacts.csv");
    printf("%d", num_contacts);
    // If file could not be opened or loaded, show an error message
    if (num_contacts == 0) {
        printf("Error opening phone contacts file.\n");
        return 1;
    }

    // Main loop for menu
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_contacts(contacts, num_contacts);
                break;
            case 2:
                select_contact(contacts, num_contacts);
                break;
            case 3:
                printf("Exiting the Smartphone Contact Hub.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to load contacts from a CSV file
int load_contacts(Contact contacts[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1; // Error opening file
    }

    char line[200];
    int i = 0;

    // Read the file line by line and store contact information
    while (fgets(line, sizeof(line), file) && i < MAX_CONTACTS) {
        // Remove any trailing newline character
        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, ",");
        printf("THIS IS A LINE");
        printf("%c", line);
        if (token != NULL) {
            strncpy(contacts[i].name, token, MAX_CONTACT_NAME_LENGTH);
            contacts[i].name[MAX_CONTACT_NAME_LENGTH - 1] = '\0';  // Ensure null-terminated
        }
        printf("%d",contacts[i].name);

        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(contacts[i].phone, token, MAX_PHONE_NUMBER_LENGTH);
            contacts[i].phone[MAX_PHONE_NUMBER_LENGTH - 1] = '\0';  // Ensure null-terminated
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(contacts[i].email, token, MAX_EMAIL_ADDRESS_LENGTH);
            contacts[i].email[MAX_EMAIL_ADDRESS_LENGTH - 1] = '\0';  // Ensure null-terminated
        }

        i++;
    }

    fclose(file);
    return i; // Return the number of contacts loaded
}

// Function to display the main menu
void display_menu() {
    printf("\nSmartphone Contact Hub\n");
    printf("1. List Contacts\n");
    printf("2. Select Contact\n");
    printf("3. Exit\n");
}

// Function to list all contacts
void list_contacts(Contact contacts[], int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\nPhone Contacts:\n");
    printf("%d", num_contacts);
    for (int i = 0; i < num_contacts; i++) {
        printf("%d , %d", num_contacts, i);
        printf("%d. Name: %s\n   Phone: %s\n   Email: %s\n",
               i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to select a contact
void select_contact(Contact contacts[], int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts available to select.\n");
        return;
    }

    int index;
    printf("Enter the contact index: ");
    scanf("%d", &index);

    if (index < 1 || index > num_contacts) {
        printf("Invalid contact index. Please try again.\n");
        return;
    }

    Contact selected_contact = contacts[index - 1];
    printf("\nSelected Contact:\n");
    printf("Name: %s\nPhone: %s\nEmail: %s\n", 
           selected_contact.name, selected_contact.phone, selected_contact.email);

    perform_contact_action(selected_contact);
}

// Function to perform an action (call or email) on the selected contact
void perform_contact_action(Contact contact) {
    int action_choice;
    printf("What would you like to do?\n");
    printf("1. Call\n");
    printf("2. Send Email\n");
    printf("Enter your choice: ");
    scanf("%d", &action_choice);

    if (action_choice == 1) {
        printf("Calling %s...\n", contact.name);
    } else if (action_choice == 2) {
        printf("Sending email to %s...\n", contact.email);
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}
