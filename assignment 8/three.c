// WACP To insert a node at the end of doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertLast (struct Node **head, int data)
{

  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  newNode->data = data;
  newNode->next = NULL;

  //need this if there is no node present in linked list at all
  if (*head == NULL)
    {
      *head = newNode;
      newNode->prev = NULL;
      return;
    }

  struct Node *temp = *head;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
  newNode->prev = temp;
}

void insertStart (struct Node **head, int data)
{

  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  newNode->data = data;
  newNode->next = *head;
  newNode->prev = NULL;

  //If the linked list already had atleast 1 node
  if (*head != NULL)
    (*head)->prev = newNode;
  // *head->prev = newNode; would not work it has (*head) must be used

  //changing the new head to this freshly entered node
  *head = newNode;
}

// function to print the doubly linked list
void printList (struct Node *node)
{
  struct Node *end;

  while (node != NULL)
    {
      printf (" %d ", node->data);
      end = node;
      node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data;
    for (int i = 1; i <= 10; i++)
    {
        insertStart(&head, rand() % 99);
    }
    printf("The list before adding any nodes by you: ");
    printList(head);

    
    printf("\nIf you want to add a new node enter 0 or to exit enter any other number: ");
    scanf("%d", &choice);
    while (choice==0)
    {
        printf("Enter data that you want to add last: ");
        scanf("%d", &data);
        insertLast(&head, data);
        printf("The Linked List now: ");
        printList(head);
        printf("\nIf you want to add a new node enter 0 or to exit enter any other number: ");
        scanf("%d", &choice);
    }
    printf("The final Linked List after adding last: ");
    printList(head);
    
    return 0;
}
