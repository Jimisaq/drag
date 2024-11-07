#include <stdio.h>
#include <ctype.h>  // For checking digits
#include <math.h>   // For pow function

#define MAX 100  // Maximum size of the stack

typedef struct {

    int data[MAX];
    int top;

} Stack;

void init(Stack *S) {            // Initialize the stack
    S->top = -1;
}

int isEmpty(Stack *S) {         // Check if the stack is empty
    return S->top == -1;
}

void push(Stack *S, int value) {    // Push an element onto the stack
    S->data[++(S->top)] = value;
}

int pop(Stack *S) {                 // Pop an element from the stack
    return S->data[(S->top)--];
}

int evaluatePostfix(char* expression) {        // Method to evaluate postfix expression

    Stack S;
    init(&S);                                  // Initialize the stack

    for (int i = 0; expression[i] != '\0'; i++) {     // Loop through each character in the expression
        char c = expression[i];

        if (isdigit(c)) {                        // If the character is a digit, push it onto the stack
            push(&S, c - '0');                  // Convert character to integer and push
        }
                                                
        else {                                  // If the character is an operator, pop two elements from stack and apply the operation
            int v1 = pop(&S);
            int v2 = pop(&S);

            switch (c) {
                case '+':
                    push(&S, v2 + v1);  // Perform addition
                    break;
                case '-':
                    push(&S, v2 - v1);  // Perform subtraction
                    break;
                case '*':
                    push(&S, v2 * v1);  // Perform multiplication
                    break;
                case '/':
                    push(&S, v2 / v1);  // Perform division
                    break;
                case '^':
                    push(&S, (int) pow(v2, v1));  // Perform exponentiation
                    break;
            }
        }
    }

    return pop(&S);                          // Return the final result (the only value left in the stack)
}

int main() {
    char expression[] = "23+5*";            // Example postfix expression: (2 + 3) * 5
    printf("Postfix Evaluation Result: %d\n", evaluatePostfix(expression));  // Output: 25

    return 0;
}
