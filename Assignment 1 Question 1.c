/*
Aidan Carey
January 17, 2023
Assignment 1, Question 1
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;

    scanf("%d", &num);

    // if number is not positive
    if (num < 0) {
        printf("Error, number must be a positive number.\n");
        return -1;
    }

    // print first number (prevents first 0 from not being printed)
    printf("%d", num % 10);
    
    while (num != 0) {
        num /= 10; // divide number by 10
        printf("%d", num % 10); // print remainder of num divided by 10
    }

    putchar('\n');

    return 0;
}
