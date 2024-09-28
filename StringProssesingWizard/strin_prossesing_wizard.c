#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_STRING_SIZE 100
#define PALINDROME_FOUND 1
#define PALINDROME_NOT_FOUND 0

void count_characters(char *str);
void reverse_string(char *str);
void convert_to_uppercase(char *str);
int check_palindrome(char *str);
int count_occurrences_of_char(char *str, char ch);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char input[MAX_INPUT_STRING_SIZE];
    strncpy(input, argv[1], MAX_INPUT_STRING_SIZE - 1);
    input[MAX_INPUT_STRING_SIZE - 1] = '\0'; // Ensure null termination

    int choice;
    char char_to_count;
    do {
        printf("\nString Processing Tool\n");
        printf("1. Count characters\n");
        printf("2. Reverse string\n");
        printf("3. Convert to uppercase\n");
        printf("4. Check palindrome\n");
        printf("5. Count occurrences of a character\n");
        printf("6. Exit\n");
        printf("Enter your input_selection: ");
        
        char selection[10];
        fgets(selection, 10, stdin);
        choice = atoi(selection);

        switch (choice) {
            case 1:
                count_characters(input);
                break;
            case 2:
                reverse_string(input);
                break;
            case 3:
                convert_to_uppercase(input);
                break;
            case 4:
                if (check_palindrome(input) == PALINDROME_FOUND)
                    printf("%s is a palindrome\n", input);
                else
                    printf("%s is not a palindrome\n", input);
                break;
            case 5:
                printf("Enter a character to count: ");
                char_to_count = getchar();
                getchar(); // To consume the newline character
                printf("Occurrences of '%c': %d\n", char_to_count, count_occurrences_of_char(input, char_to_count));
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid selection, please try again.\n");
        }

        if (choice != 6) {
            printf("Press Enter to continue...");
            getchar();
        }
    } while (choice != 6);

    return 0;
}

void count_characters(char *str) {
    int count = 0;
    while (*str++) count++;
    printf("Number of characters: %d\n", count);
}

void reverse_string(char *str) {
    int len = strlen(str);
    printf("Reversed string: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void convert_to_uppercase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
    printf("Uppercase string: %s\n", str);
}

int check_palindrome(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        if (*start != *end) {
            return PALINDROME_NOT_FOUND;
        }
        start++;
        end--;
    }
    return PALINDROME_FOUND;
}

int count_occurrences_of_char(char *str, char ch) {
    int count = 0;
    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}
