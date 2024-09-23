// Include necessary header files
#include <stdio.h>   // Provides input/output functions
#include <string.h>  // Provides string manipulation functions
#include <stdlib.h>
#include <ctype.h>

// Define constants for clothing item prices using macros
#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99
#define MEXICO_std 7.99
#define MEXICO_ex 12.99
#define USA_std 5.99
#define USA_ex 9.99
#define CANADA_std 6.99
#define CANADA_ex 11.99
#define CTAX .12
#define MTAX .16
#define UTAX .08
int main(void) {
    // Declare variables
    char userInput[20];
    char shpInput[20];
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0;  // Variables to store quantities of each clothing item
    double shipping = 0;
    do {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and proceed to shipping details.\n");

        // Read user input for clothing type
        scanf("%s", userInput);



        // Check user input and prompt for quantity based on clothing type

        switch (userInput[0])
        {
        case 's':
            if (strcmp(userInput, "shirt") == 0) {
               
                printf("Enter the quantity of shirts needed: ");
                scanf("%d", &shirtQuantity);
                printf("Clothing item '%s' successfully added to your cart.\n", userInput);
            }
            else if (strcmp(userInput, "shoes") == 0) {
            

                printf("Enter the quantity of shoes needed: ");
                scanf("%d", &shoeQuantity);
                printf("Clothing item '%s' successfully added to your cart.\n", userInput);

            }
                break;
        
        case 'p':
            if (strcmp(userInput, "pants") == 0) {

                
                printf("Enter the quantity of pants needed: ");
                scanf("%d", &pantsQuantity);
                printf("Clothing item '%s' successfully added to your cart.\n", userInput);

            }
            break;
        case 'e':
           // printf("Clothing item '%s' successfully added to your cart.\n", userInput);
            break;
        default:
            //f user input is not a valid clothing type or 'exit', display an error message and continue the loop
            printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
        }
        // If user input is not 'exit', display a success message for adding the clothing item

    } while (strcmp(userInput, "exit") != 0);  // Repeat the loop until user enters 'exit'

    double taxperc = UTAX;
    char* userInput1 = "Standard";
    char* shpInput1 = "USA";
    do
    {
        // Display menu options to uaer fo ahipping
        printf("\nEnter the shipping destination (USA, Mexico, Canada): ");
        scanf("%s", shpInput);
        printf("Enter the shipping method (standard, expedited): ");
        scanf("%s", userInput);
        // Check user input and prompt for quantity based on clothing type

        for (int i = 0; shpInput[i]; i++) shpInput[i] = tolower(shpInput[i]);
        switch (shpInput[0])
        { 
    case 'u':
        if (strcmp(shpInput, "usa") == 0) {
            
            if (strcmp(userInput, "standard") == 0)
            {
                shipping = USA_std;
                userInput1 = "Standard";
            }
            else if (strcmp(userInput, "expedited") == 0)
            {
                shipping = USA_ex;
                userInput1 = "Expedited";
            }
            shpInput1 = "USA";
            taxperc = UTAX;
        }
        break;
    case 'm':
        if (strcmp(shpInput, "mexico") == 0) {
            //printf("Enter the shipping method (standard, expedited): ");
            //scanf("%s", shpInput);
            if (strcmp(userInput, "standard") == 0)
            {
                shipping = MEXICO_std;
                userInput1 = "Standard";

            }
            else if (strcmp(userInput, "expedited") == 0)
            {
                shipping = MEXICO_ex;
                userInput1 = "Expedited";
            }
            shpInput1 = "Mexico";
            taxperc = MTAX;
        }
        break;
    case 'c':
        if (strcmp(shpInput, "canada") == 0) {
            // printf("Enter the shipping method (standard, expedited): ");
             //scanf("%s", shpInput);
            if (strcmp(userInput, "standard") == 0)
            {
                shipping = CANADA_std;
                userInput1 = "Standard";
            }
            else if (strcmp(userInput, "expedited") == 0)
            {
                shipping = CANADA_ex;
                userInput1 = "Expedited";

            }
            shpInput1 = "Canada";
            taxperc = CTAX;
        }
        break;
        default:
        
            printf("Invalid shipping destination. Defaulting to USA standard shipping.\n");
            shipping = USA_std;
            taxperc = UTAX;
            shpInput1 = "USA";
            userInput1 = "Standard";
        }

    } while (shpInput[0] == 0);
    // Calculate the total cost based on quantities and prices of each clothing item
    float SubtotalCost = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);
    float tax = SubtotalCost * taxperc;
    float totalCost = SubtotalCost + tax + shipping;
    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", SubtotalCost);
    printf("Shipping Destination: %s\n", shpInput1);
    printf("Shipping Method: %s to %s\n", userInput1, shpInput1);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shipping);
    printf("Tax (%.2f%%):\t\t\t\t\t$%.2f\n", taxperc * 100, tax);
    printf("-------------------------------------------------------\n");
    printf("Total Cost (including tax and shipping):\t$%.2f\n", totalCost);

    return 0;  
}