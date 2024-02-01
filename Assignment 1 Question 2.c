/*
Aidan Carey
January 18, 2023
Assignment 1, Question 2
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char input, c;

    // get input from user
    scanf("%c", &input);

    // if the input is not a valid letter
    if ((int)input < 65 || (int)input > 122) {
        printf("Error, not a letter.\n");
        return 1;
    }

    // if uppercase, convert to lowercase to make switch case easier
    if ((int)input <= 90) {
        c = (char)(input + 32);
    } else {
        c = input;
    }

    switch (c) {
        // check if character is a vowel
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%c is a vowel.\n", input);
            break;
        // if character is not a vowel
        default:
            printf("%c is not a vowel.\n", input);
            break;
    }

    return 0;
}