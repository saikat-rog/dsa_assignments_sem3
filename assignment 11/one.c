#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Queue structure
struct Queue {
    int front, rear;
    int items[MAX_SIZE];
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to insert an element into the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->items[queue->rear] = item;
        printf("%d enqueued to the queue.\n", item);
    }
}

// Function to delete an element from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        int removedItem = queue->items[queue->front];
        if (queue->front == queue->rear) {
            initializeQueue(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("%d dequeued from the queue.\n", removedItem);
    }
}

// Function to display the elements in the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = queue->front;
        do {
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, item;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
