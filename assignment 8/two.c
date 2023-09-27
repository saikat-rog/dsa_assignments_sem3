// WACP To insert a node at any position of doubly linked list
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a given position in the doubly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        return;
    }
    
    if (position <= 1) {
        // Insert at the beginning
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    int currentPosition = 1;
    
    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }
    
    if (current->next == NULL) {
        // Insert at the end
        current->next = newNode;
        newNode->prev = current;
    } else {
        // Insert in the middle
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, pos, data;
    for (int i = 1; i <= 10; i++)
    {
        insertAtPosition(&head, rand() % 99, i);
    }
    printf("The list before adding any nodes by you: ");
    printList(head);

    
    printf("If you want to add a new node enter 0 or to exit enter any other number: ");
    scanf("%d", &choice);
    while (choice==0)
    {
        printf("Enter data that you want to add: ");
        scanf("%d", &data);
        printf("Enter the position: ");
        scanf("%d", &pos);
        insertAtPosition(&head, data, pos);
        printf("The Linked List now: ");
        printList(head);
        printf("If you want to add a new node enter 0 or to exit enter any other number: ");
        scanf("%d", &choice);
    }
    printf("The final Linked List: ");
    printList(head);
    
    return 0;
}
