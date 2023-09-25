#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


void addLast(struct node **head, int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL)
         *head = newNode;
    else
    {
        struct node *lastNode = *head;

        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

}

void printList(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
     struct node *head = NULL;
     int data;

     addLast(&head,10);
     addLast(&head,20);
     addLast(&head,30);
     printf("The existing list: ");
     printList(head);
     printf("Enter data to add last: ");
     scanf("%d", &data);
     addLast(&head,data);
     printf("The new list: ");
     printList(head);

     return 0;
}