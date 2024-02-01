/*
Aidan Carey
COMP 2103 Assignment 2
question1_carey.c
*/

#include <stdio.h>

int main() {
    char c;
    int num;

    printf("Enter a character then a number:\n");
    scanf("%c\n%d", &c, &num);

    // loop backwards from num to 0
    for (int i = num; i != 0; i--) {
        // print `i` characters
        for (int j = 0; j < i; j++) {
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}