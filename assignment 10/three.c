#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push a value onto the stack
void push(struct Node** stack, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *stack;
    *stack = newNode;
    printf("%d pushed to the stack.\n", value);
}

// Function to pop a value from the stack
int pop(struct Node** stack) {
    if (*stack == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *stack;
    int poppedValue = temp->data;
    *stack = temp->next;
    free(temp);
    printf("%d popped from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to display the elements of the stack
void display(struct Node* stack) {
    printf("Stack: ");
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* stack = NULL;
    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                display(stack);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
