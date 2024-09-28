#include <stdio.h>
#include <string.h>
#include "functions.h"

char *reverse_string(char *string);
{
    char tmp;
    int length, left, right;
    length = (int)strlen(string);
    left = 0;
    right = length -1 

    while (left <= right) {
        tmp = string[left];
        string[left] = string[right];
        string[right] = tmp;
        ++left;
        --right;
    }
}

