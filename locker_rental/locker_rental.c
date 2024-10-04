#include <stdio.h>
#include <string.h>

#define MAX_LOCKERS 100        // Define maximum number of lockers
#define MAX_ITEM_LENGTH 50     // Define maximum length of item stored in a locker

// Function to display the main menu options
void displayMenu() {
    printf("\nLocker Rental Menu\n");
    printf("=============================\n");
    printf("1. View a locker\n");
    printf("2. Rent a locker\n");
    printf("3. End a locker rental\n");
    printf("4. List all locker contents\n");
    printf("5. Quit\n");
    printf("Enter your choice (1-5): ");
}

// Function to view the contents of a specific locker
void viewLocker(char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH]) {
    int lockerNumber;
    printf("Enter locker number (1-100): ");
    scanf("%d", &lockerNumber); // Get locker number from user

    // Validate locker number range
    if (lockerNumber < 1 || lockerNumber > MAX_LOCKERS) {
        printf("Invalid locker number. Please enter a number between 1 and 100.\n");
        return;
    }

    // Check if locker is empty or occupied
    if (strlen(lockers[lockerNumber - 1]) == 0) {
        printf("Locker %d is EMPTY.\n", lockerNumber);
    } else {
        printf("Locker %d contains: %s\n", lockerNumber, lockers[lockerNumber - 1]);
    }
}

// Function to rent a locker and store an item
void rentLocker(char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH]) {
    int lockerNumber;
    char item[MAX_ITEM_LENGTH];

    printf("Enter locker number (1-100): ");
    scanf("%d", &lockerNumber); // Get locker number from user

    // Validate locker number range
    if (lockerNumber < 1 || lockerNumber > MAX_LOCKERS) {
        printf("Invalid locker number. Please enter a number between 1 and 100.\n");
        return;
    }

    // Check if locker is already rented
    if (strlen(lockers[lockerNumber - 1]) != 0) {
        printf("Sorry, but locker %d has already been rented!\n", lockerNumber);
        return;
    }

    // Get item to store in locker
    printf("Enter the item you want to store in the locker: ");
    scanf(" %[^\n]", item); // Reads a string with spaces

    // Store the item in the selected locker
    strcpy(lockers[lockerNumber - 1], item);
    printf("Locker %d has been rented for %s storage.\n", lockerNumber, item);
}

// Function to end a rental and free up the locker
void endRental(char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH]) {
    int lockerNumber;
    printf("Enter locker number (1-100): ");
    scanf("%d", &lockerNumber); // Get locker number from user

    // Validate locker number range
    if (lockerNumber < 1 || lockerNumber > MAX_LOCKERS) {
        printf("Invalid locker number. Please enter a number between 1 and 100.\n");
        return;
    }

    // Check if locker is currently rented
    if (strlen(lockers[lockerNumber - 1]) == 0) {
        printf("Locker %d is not rented.\n", lockerNumber);
    } else {
        // End rental by clearing the locker
        printf("Locker %d rental has ended, please take your %s.\n", lockerNumber, lockers[lockerNumber - 1]);
        lockers[lockerNumber - 1][0] = '\0'; // Clear locker contents
    }
}

// Function to list the contents of all rented lockers
void listAllLockers(char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH]) {
    int rentedLockers = 0; // Counter to track if any lockers are rented

    // Iterate through all lockers to find rented ones
    for (int i = 0; i < MAX_LOCKERS; i++) {
        if (strlen(lockers[i]) != 0) { // If locker is not empty
            printf("Locker %d: %s\n", i + 1, lockers[i]);
            rentedLockers++;
        }
    }

    // If no lockers are rented, display message
    if (rentedLockers == 0) {
        printf("No lockers are currently rented.\n");
    }
}

int main() {
    char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH] = {0}; // Initialize lockers as empty
    char input;
    int choice;

    // Loop to keep displaying menu until the user chooses to quit
    while (1) {
        displayMenu();         // Show the menu
        scanf("%s", &input);  // Get user input for menu choice
        if (sscanf(&input, "%d", &choice) !=1)
        {
            printf("Invaild input, Please enter a valid menu choice.\n");
            printf("Invaild menu_choice. Please try again\n");
            while(getchar() != '\n');
            continue;
        }
        // Switch case to handle different menu options
        switch (choice) {
            case 1:
                viewLocker(lockers);  // View specific locker
                break;
            case 2:
                rentLocker(lockers);  // Rent a locker
                break;
            case 3:
                endRental(lockers);   // End rental for a locker
                break;
            case 4:
                listAllLockers(lockers);  // List all rented lockers
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }

    return 0;  // Program ends when user chooses to quit
}
