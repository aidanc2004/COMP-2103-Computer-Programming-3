/*
Aidan Carey 0302409c
COMP-2103 Assignment 3
main.c
*/

#include <stdio.h>
#include <stdlib.h>

// array to represent seats in flight
int *seats;


// put a passenger in economy (6-24)
void economy() {
    int seated = 0;

    // loop through seats until we find an empty one
    for (int i = 5; i < 24; i++) {
        // if seat is empty
        if (seats[i] == 0) {
            seats[i] = i;
            printf("Class: Ecnonomy, Seat number: %d\n", i+1);
            // index of array starts at 0 so we add 1 before printing i to show correct seat number
            seated = 1;
            break;
        }
    }

    // if a seat hasnt been assigned
    if (!seated) {
        printf("All economy seats full.\n");
    }
}

// put a passenger into a first class seat (1-5)
void first_class() {
    int seated = 0;

    // loop through seats until we find an empty one
    for (int i = 0; i < 5; i++) {
        // if seat is empty
        if (seats[i] == 0) {
            seats[i] = 1;
            // index of array starts at 0 so we add 1 before printing i to show correct seat number
            printf("Class: First Class, Seat number: %d\n", i+1);
            seated = 1;
            break;
        }
    }

    // if a seat hasnt been assigned
    if (!seated) {
        printf("First class is full, is it acceptable to be placed in economy? (1 for yes, 2 for no)\n");

        int option;
        scanf("%d", &option);

        printf("option: %d\n", option);

        if (option == 1) {
            economy();
        } else if (option == 2) {
            printf("Next flight leaves in 3 hours.\n");
        }
    }
}

int main() {
    // initalize all elements to 0 in array
    seats = malloc(24 * sizeof(int));

    // main program loop
    while (1) {
        printf("Please type 1 for \"First Class\" and Please type 2 for \"Economy\"\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            // first class
            case 1:
                first_class();
                break;
            // economy
            case 2:
                economy();
                break;
            // not a valid selection
            default:
                printf("Please select one or two.\n");
                break;
        }
    }

    return 0;
}
