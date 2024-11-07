#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;

// Browser structure
typedef struct {
    char *current;
    Stack *back;
    Stack *forward;
} Browser;

// Method declarations
Browser *createBrowser();
void visitPage(Browser *browser, const char *page);
void backward(Browser *browser);
void forward(Browser *browser);
void displayCurrentPage(Browser *browser);
void printStack(Stack *stack);
Stack *createStack();
void deleteStack(Stack *stack);
bool isEmpty(Stack *stack);
bool push(Stack *stack, const char *item);
char *pop(Stack *stack);
char *peek(Stack *stack);

// Main method
int main(void) {
    Browser *browser = createBrowser();
    if (browser == NULL) {
        printf("Error creating browser\n");
        return 1;
    } else {
        printf("Browser created successfully\n");
    }

    visitPage(browser, "google.com");
    visitPage(browser, "facebook.com");
    

    printf("\n");
    backward(browser);
    printf("\n");

    forward(browser);
    printf("\n");

    visitPage(browser, "youtube.com");
    printf("\n");
    forward(browser);
    return 0;
}

// Creating a stack
Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Destroying a stack
void deleteStack(Stack *stack) {
    Node *current = stack->top;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(stack);
}

// Checking if a stack is empty
bool isEmpty(Stack *stack) {
    return stack->size == 0;
}

// Pushing an item onto a stack
bool push(Stack *stack, const char *item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return false;
    }
    newNode->data = strdup(item);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    return true;
}

// Popping an item from the stack
char *pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, pop failed\n");
        return NULL;
    }
    Node *topNode = stack->top;
    char *item = topNode->data;
    stack->top = topNode->next;
    free(topNode);
    stack->size--;
    return item;
}

// Peeking the top item of the stack
char *peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("You can't peek from an empty stack\n");
        return NULL;
    }
    return stack->top->data;
}

// Create browser
Browser *createBrowser() {
    Browser *browser = (Browser *)malloc(sizeof(Browser));
    if (browser == NULL) {
        return NULL;
    }
    browser->back = createStack();
    browser->forward = createStack();
    browser->current = NULL;
    return browser;
}

// Visit page
void visitPage(Browser *browser, const char *page) {
    if (browser->current != NULL) {
        push(browser->back, browser->current);
    }
    browser->current = strdup(page);
    displayCurrentPage(browser);

    // Empty forward stack
    while (!isEmpty(browser->forward)) {
        free(pop(browser->forward));
    }
}

// Backward functionality
void backward(Browser *browser) {
    if (isEmpty(browser->back)) {
        printf("No more pages to go back to\n");
        return;
    }
    push(browser->forward, browser->current);
    browser->current = pop(browser->back);
    displayCurrentPage(browser);
}

// Forward functionality
void forward(Browser *browser) {
    if (isEmpty(browser->forward)) {
        printf("No more pages to go forward to\n");
        return;
    }
    push(browser->back, browser->current);
    browser->current = pop(browser->forward);
    displayCurrentPage(browser);
}

// Display current page
void displayCurrentPage(Browser *browser) {
    printf("Current page: %s\n", browser->current);

    printf("Back stack:\n");
    printStack(browser->back);
    printf("Forward stack:\n");
    printStack(browser->forward);
}

// Print everything on a stack
void printStack(Stack *stack) {
    Node *current = stack->top;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}