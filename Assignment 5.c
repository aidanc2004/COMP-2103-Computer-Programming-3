/*
Author Name: Aidan Carey
Student ID: 0302409c
Date: 13 March 2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *array; // array to hold elements of stack
    int top;    // index of top element
    int size;   // size of the stack
} stack;

stack *st;

// create a stack on the heap and return it
stack *create_stack() {
    stack *st = malloc(sizeof(st)); // allocate memory for the stack
    st->array = malloc(sizeof(int)*5); // allocate array
    st->top = -1; // set the index of the top element to be -1
    st->size = 5;
    return st;
}

// print the stack to stdout
void print_stack() {
    printf("Stack: ");   
    for (int i = 0; i <= st->top; i++) {
        printf("%d ", st->array[i]);
    }
    putchar('\n');
}

// free the stack
void free_stack(stack *st) {
    free(st->array); // free the array
    free(st);        // free the stuct
}

// push an element onto the stack, returns 0 on success, -1 on failure
int push(int element) {
    // if at the top of the stack, allocate new stack
    if (st->top + 1 == st->size) {
        printf("Increased size from %d to %d\n", st->size, st->size * 2);
        stack *newst = malloc(sizeof(st));
        newst->array = malloc(sizeof(int)*(st->size*2));
        // move all elements of stack to new stack
        for (int i = 0; i <= st->size; i++) {
            newst->array[i] = st->array[i];
        }
        newst->top = st->top;
        newst->size = st->size * 2;
        free_stack(st); // free old stack
        st = newst;
    }

    st->top++; // go to the next space on the stack
    st->array[st->top] = element; // set new top to new element

    return 0;
}

// pop the top element off of the stack, returns the popped element
int pop() {
    // if the stack is empty return -1 for error
    if (st->top == -1) {
        return -1;
    }

    // get the top element from the stack
    int element = st->array[st->top];

    // decrement top, top is now the previous element
    st->top--;

    // if there are less then 25% of elements in stack, half size of the stack
    if (st->top <= st->size / 4 && st->size > 5) {
        printf("Decreased size from %d to %d\n", st->size, st->size / 2);
        stack *newst = malloc(sizeof(st));
        newst->array = malloc(sizeof(int)*(st->size/2));
        newst->size = st->size / 2;
        // move all elements of stack to new stack
        for (int i = 0; i < newst->size; i++) {
            newst->array[i] = st->array[i];
        }
        newst->top = st->top;
        free_stack(st); // free old stack
        st = newst;
    }

    return element;
}

// test the stack data structure
int main() {
    // create a new stack with size 5
    st = create_stack();

    int quit = 0;

    while (!quit) {
        printf("Choose:\n1. Push\n2. Pop\n3. Quit.\n");

        char c;
        scanf(" %c", &c);

        switch (c)
        {
        case '1':
            printf("Enter an integer: ");
            int x;
            scanf(" %d", &x);
            getchar(); // get rid of extra characters
            push(x);
            break;
        case '2':
            printf("Popped %d\n", pop());
            break;
        case '3':
            quit = 1;
            break;
        default:
            break;
        }

        print_stack();
    }    

    // free the stack when done
    free_stack(st);

    return 0;
}
