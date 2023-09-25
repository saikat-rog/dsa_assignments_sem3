#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position
void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position. Node can't be inserted.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int data, position,choice = 0;
    struct Node* head = NULL;
    for (int i = 1; i <= 10; i++)
    {
        insertNode(&head, rand(), i);
    }
    printf("The already created linked List: ");
    displayList(head);
    printf("If you want to add a new node enter 0 or to exit enter any other number: ");
    scanf("%d", &choice);

    
    while (choice==0)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        printf("Enter position: ");
        scanf("%d", &position);
        insertNode(&head, data, position);
        printf("If you want to add a new node enter 0 or to exit enter any other number: ");
        scanf("%d", &choice);
    }
    
    printf("New linked List: ");
    displayList(head);

    return 0;
}
