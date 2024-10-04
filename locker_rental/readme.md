Notes:
Constants:

MAX_LOCKERS defines the total number of lockers.
MAX_ITEM_LENGTH defines the maximum length of the item name stored in a locker.
Menu Handling:

displayMenu() prints the available options.
User choices are processed in a loop, continuing until the user selects "Quit."
View a Locker:

viewLocker() checks if the locker is empty or occupied and shows the appropriate message.
Rent a Locker:

rentLocker() stores the specified item in the chosen locker if it's available.
It checks if the locker is already rented and provides feedback accordingly.
End Rental:

endRental() frees up a locker and displays a message about the previously stored item.
List All Lockers:

listAllLockers() iterates over all lockers and lists those that are currently rented.
Input Validation:

The program checks if locker numbers are within the valid range (1-100) and provides feedback for invalid input.
a. Would you like to handle user inputs in a more robust way (e.g., handling non-numeric inputs)? b. Would you like to enhance the program with locker persistency to save and load locker states from a file?