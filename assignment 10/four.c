#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the expression
#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to initialize a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '$'; // '$' is used as an empty character
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i, j;
    for (i = 0, j = -1; infix[i]; ++i) {
        if (isOperand(infix[i])) {
            postfix[++j] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(') {
                postfix[++j] = pop(stack);
            }
            if (!isEmpty(stack) && stack->array[stack->top] != '(') {
                printf("Invalid expression\n");
                return;
            } else {
                pop(stack); // Pop '('
            }
        } else {
            while (!isEmpty(stack) && getPrecedence(infix[i]) <= getPrecedence(stack->array[stack->top])) {
                postfix[++j] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(stack)) {
        postfix[++j] = pop(stack);
    }

    postfix[++j] = '\0'; // Null-terminate the postfix expression
}

// Driver program to test the functions
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Input infix expression
    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character from fgets input

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
