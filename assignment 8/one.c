// WACP To insert a node at the beginning of doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertStart (struct Node **head, int data)
{

  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  newNode->data = data;
  newNode->next = *head;
  newNode->prev = NULL;

  if (*head != NULL)
    (*head)->prev = newNode;

  *head = newNode;
}

void display (struct Node *node)
{
  struct Node *end;
  printf ("The list after adding all the nodes at the start sequentialy: ");

  while (node != NULL)
    {
      printf (" %d ", node->data);
      end = node;
      node = node->next;
    }
}

int main ()
{
  struct Node *head = NULL;

    int data, choice;
    printf("If you want to add a new node enter 0 or to exit enter any other number: ");
    scanf("%d", &choice);
    while (choice==0)
    {
        printf("Enter data that you want to add at the beginning: ");
        scanf("%d", &data);
        insertStart(&head, data);
        printf("If you want to add a new node enter 0 or to exit enter any other number: ");
        scanf("%d", &choice);
    }
    
  display (head);

  return 0;
}
