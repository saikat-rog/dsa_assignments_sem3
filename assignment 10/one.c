// Write a program to show the operations of a circular linked list

// HEHEHE : ) | THIS CODE HAS INCORRECT OUTPUT, i can't fix it, Do it your own byee!!!

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

// Insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;
    }
}

// Delete a node by value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* current = (*head)->next;
    struct Node* prev = *head;

    if (prev->data == data) {
        if (prev->next == prev) {
            free(prev);
            *head = NULL;
        } else {
            (*head)->next = prev->next;
            free(prev);
        }
        return;
    }

    while (current != *head) {
        if (current->data == data) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Data not found in the list.\n");
}

// Display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("%d -> ... (loop)\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting elements at the beginning
    int num1, node_data1;
    printf("Enter num of elements to add: " );
    scanf("%d", &num1);
    for (int i = 0; i < num1; i++){
        printf("Enter node %d: ", i + 1 );
        scanf("%d", &node_data1);
        insertAtBeginning(&head, node_data1);
    }
    // Display the list
    printf("List after adding: ");
    displayList(head);

    // Inserting elements at the end
    int num, node_data;
    printf("Enter num of elements to add: " );
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        printf("Enter node %d: ", i + 1 );
        scanf("%d", &node_data);
        insertAtEnd(&head, node_data);
    }
    // Display the list
    printf("List after adding: ");
    displayList(head);

    //Delition
    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);
    deleteNode(&head, 3);
    // Display the list after deletion
    displayList(head);

    return 0;
}

