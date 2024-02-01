/*
Author Name: Aidan Carey
Student ID: 0302409c
Date: 05 March 2023
*/

/*
notes:

 you are able to assign to an index value outside of the memory specificed,
this works, but this is very unsafe as you could accidently override something
very important, and can allow hackers to run unsafe code on your computer. i made
sure to include a test to check that the input is in the range of the memory, but
if this check was not included, then this example test case input would do this:
1       (allocate)
15      (size)
2       (set)
500     (index)
123     (number)
3       (get)
500     (index)
in my testing, this gave back the value i put in, 500.

 because calloc automatically assigns the value 0 to all values in memory, trying to
get a value that you havent assigned anything to returns a 0. however, if you try to
get a value from outside the allocated memory, it may return any garbage values or give
a segmentation fault. i made sure to include a test to check that the input is in the
range of the memory, but if this check was not included, then this example test case
input would do this:
1       (allocate)
15      (size)
3       (get)
3       (index)     // this gives back the value 0
3       (get)
99900   (index)
this gave me a segmentation fault, i believe this is because i was accessing data that i
should not have been
*/

#include <stdio.h>
#include <stdlib.h>

int size; // size must be a global so we can check if the index is out of bounds

int *allocate(int n) {
    // allocate a block of memory of size n and return it
    int *block = calloc(n, sizeof(int));
    
    // if the block is null, something has gone wrong
    if (block == NULL) {
        printf("Error allocating memory.\n");
    }

    return block;
}

void set(int *b, int index, int number) {
    // if out of range
    if (index > size) {
        printf("Error: index out of range\n");
        return;
    }

    b[index] = number; // set address at index to number
}

int get(int *b, int index) {
    // if out of range
    if (index > size) {
        printf("Error: index out of range\n");
        return;
    }

    return b[index]; // return number at index
}



int main() {
    int *b;
    int index, number;
    int quit = 0;

    while (!quit) {
        printf("Choose a function to call:\n1 - allocate()\n2 - set()\n3 - get()\nq - Quit\n");

        char c;
        scanf(" %c", &c);

        switch (c)
        {
        case '1':
            printf("Size: ");
            scanf(" %d", &size);
            getchar(); // get rid of extra characters
            b = allocate(size);
            break;
        case '2':
            printf("Index: ");
            scanf(" %d", &index);
            printf("Number: ");
            scanf(" %d", &number);
            getchar(); // get rid of extra characters
            set(b, index, number);
            break;
        case '3':
            printf("Index: ");
            scanf(" %d", &index);
            printf("The number at index %d is %d\n", index, get(b, index));
            break;
        case 'q':
            quit = 1;
            break;
        }
    }

    free(b);

    return 0;
}
