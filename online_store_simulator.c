#include <stdio.h>
#include <string.h>
#include <ctype.h> /* for handling character case conversion*/

/* Define constants for clothing item prices*/
#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

/*Define constants for shipping costs*/
#define USA_STANDARD_SHIPPING 5.99
#define USA_EXPEDITED_SHIPPING 9.99
#define MEXICO_STANDARD_SHIPPING 7.99
#define MEXICO_EXPEDITED_SHIPPING 12.99
#define CANADA_STANDARD_SHIPPING 6.99
#define CANADA_EXPEDITED_SHIPPING 11.99

/* Define constants for tax rates*/
#define USA_TAX_RATE 0.08
#define MEXICO_TAX_RATE 0.16
#define CANADA_TAX_RATE 0.12

int main(void) {
    char itemInput[20];
    char countryInput[20];
    char shippingInput[20];
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0;
    float totalCost = 0.0, shippingCost = 0.0, taxRate = 0.0, taxAmount = 0.0;
    
    /* Item selection and quantity input*/
    do {
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and proceed to shipping details.\n");
        scanf("%s", itemInput);

        /*Convert user input to lowercase for case-insensitive comparison*/
        for(int i = 0; itemInput[i]; i++) itemInput[i] = tolower(itemInput[i]);

        if (strcmp(itemInput, "exit") == 0) {
            break;
        }

           int quantity = 0;

        /*Use switch statement to handle different item types*/
        // printf("item input: %s", itemInput);
        switch (itemInput[0]) {
            case 's':
                if (strcmp(itemInput, "shirt") == 0) {
                    printf("Enter the quantity of %ss needed: ", itemInput);
                    scanf("%d", &quantity);
                    shirtQuantity += quantity;

                    printf("Clothing item '%s' successfully added to your cart.\n", itemInput);
                
                } else if (strcmp(itemInput, "shoes") == 0) {
                    printf("Enter the quantity of %s needed: Clothing item '%s' successfully added to your cart.\n", itemInput, itemInput);
                    scanf("%d", &quantity);
                    shoeQuantity += quantity;
                
                } else {
                    printf("Invalid item. Please enter 'shirt', 'shoes', or 'pants'.\n");
                }
                break;
            case 'p':
                if (strcmp(itemInput, "pants") == 0) {
                printf("Enter the quantity of %s needed: Clothing item '%s' successfully added to your cart.\n", itemInput, itemInput);
                scanf("%d", &quantity);
                    pantsQuantity += quantity;
            
                } else {
                    printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
                }
                break;
            default:
                printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
        }
    
    
    
        
    }
     while (1); 
       
    /*Calculate total item cost*/
    totalCost = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);

    /*Shipping selection*/
    printf("\nEnter the shipping destination (USA, Mexico, Canada):");
    scanf("%s", countryInput);
    for(int i = 0; countryInput[i]; i++) countryInput[i] = tolower(countryInput[i]);  // Convert to lowercase

    /*Determine tax rate based on country*/
    switch (countryInput[0]) {
        case 'u':
            if (strcmp(countryInput, "usa") == 0) {
                taxRate = USA_TAX_RATE;
            } else {
                printf("Invalid country. Defaulting to USA standard shipping.\n");
                taxRate = USA_TAX_RATE;
            }
            break;
        case 'm':
            if (strcmp(countryInput, "mexico") == 0) {
                taxRate = MEXICO_TAX_RATE;
            } else {
                printf("Invalid country. Defaulting to USA standard shipping.\n");
                taxRate = USA_TAX_RATE;
            }
            break;
        case 'c':
            if (strcmp(countryInput, "canada") == 0) {
                taxRate = CANADA_TAX_RATE;
            } else {
                printf("Invalid country. Defaulting to USA standard shipping.\n");
                taxRate = USA_TAX_RATE;
            }
            break;
        default:
            printf("Invalid country. Defaulting to USA standard shipping.\n");
            taxRate = USA_TAX_RATE;
    }

    /*Shipping method selection*/
    printf(" Enter the shipping method (standard, expedited):\n");
    scanf("%s", shippingInput);
    for(int i = 0; shippingInput[i]; i++) shippingInput[i] = tolower(shippingInput[i]);

    /* Calculate shipping cost based on country and shipping method*/
    switch (countryInput[0]) {
        case 'u':
            if (strcmp(shippingInput, "standard") == 0) {
                shippingCost = USA_STANDARD_SHIPPING;
            } else if (strcmp(shippingInput, "expedited") == 0) {
                shippingCost = USA_EXPEDITED_SHIPPING;
            }
            break;
        case 'm':
            if (strcmp(shippingInput, "standard") == 0) {
                shippingCost = MEXICO_STANDARD_SHIPPING;
            } else if (strcmp(shippingInput, "expedited") == 0) {
                shippingCost = MEXICO_EXPEDITED_SHIPPING;
            }
            break;
        case 'c':
            if (strcmp(shippingInput, "standard") == 0) {
                shippingCost = CANADA_STANDARD_SHIPPING;
            } else if (strcmp(shippingInput, "expedited") == 0) {
                shippingCost = CANADA_EXPEDITED_SHIPPING;
            }
            break;
        default:
            printf("Invalid shipping method. Defaulting to standard.\n");
            shippingCost = USA_STANDARD_SHIPPING;
    }
       

    /*Calculate tax amount*/
    taxAmount = totalCost * taxRate;

    /*Display the formatted bill*/
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Total Cost:\t\t\t\t\t$%.2f\n", totalCost);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shippingCost);
    printf("Tax Amount:\t\t\t\t\t$%.2f\n", taxAmount);
    printf("-------------------------------------------------------\n");
    printf("Grand Total:\t\t\t\t\t$%.2f\n", totalCost + shippingCost + taxAmount);

    return 0;
}
