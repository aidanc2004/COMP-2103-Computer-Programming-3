/*
Aidan Carey
COMP 2103 Assignment 2
question2_carey.c
*/

#include <stdio.h>

int main() {
    // loop from 0 to 100 (including 100)
    for (int i = 0; i <= 100; i++) {
        // if i is even, print i
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}