// Q2. Write a C program to delete an element from the last position of a linked list

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

    if (*head == NULL)
        *head = newNode;
    else
    {
        struct node *lastNode = *head;

        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void removeLast(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else{
        struct node *temp = head;
        struct node *temp2 = head;
        while (temp2->next != NULL)
        {
            temp = temp2;
            temp2 = temp2->next;
        }
        temp->next = NULL;
        free(temp2);
        temp2=NULL;
    }
}

void printList(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    addLast(&head, 10);
    addLast(&head, 20);
    addLast(&head, 30);
    printf("The existing list: ");
    printList(head);

    printf("The new list: ");
    removeLast(head);
    printList(head);

    return 0;
}
