// Q. write a C program to delete the first node from a double link list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
    printf("Deleting the first node.\n");
}

void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int value;

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
    }
    printf("List before deletion: ");
    displayList(head);

    deleteFirstNode(&head);
    printf("List after deletion: ");
    displayList(head);
}
