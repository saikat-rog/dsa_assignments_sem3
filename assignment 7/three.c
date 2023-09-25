// Q3. Write a C program to delete an element from the any particularly specified position of a linked list
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

void removeN(struct node *head, int pos)
{
    int pos2 = 0;
    if (head == NULL)
    {
        printf("List is empty, nothing can be deleted.\n");
    }
    else if(head->next==NULL && pos==1)
    {
        free(head);
        head=NULL;
    }
    else if(head->next==NULL && pos > 1)
    {
        printf("Position is out of bounds.\n");
    }
    else{
        struct node *temp = head;
        struct node *temp2 = head;
        pos2++;
        while (temp2->next != NULL)
        {
            pos2++;
            temp = temp2;
            temp2 = temp2->next;
            if(pos2 == pos){
                break;
            }
            
        }
        temp->next = temp2->next;
        free(temp2);
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
    addLast(&head, 40);
    addLast(&head, 50);
    printf("The existing list: ");
    printList(head);

    printf("The new list: ");
    removeN(head, 3);
    printList(head);

    return 0;
}
