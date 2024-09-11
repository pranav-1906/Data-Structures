#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue overflow...\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("The queue underflows...\n");
    } else {
        struct Node* temp = front;
        front = front->next;
        if (front == NULL) {  // If the queue becomes empty
            rear = NULL;
        }
        free(temp);
        printf("The data is dequeued...\n");
    }
}

void display() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("The queue is empty.\n");
    } else {
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int data, ch, e = 0;
    while (e != 4) {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Display\n");
                display();
                break;
            case 4:
                printf("Exiting....\n");
                e = 4;
                break;
            default:
                printf("Invalid choice...\n");
        }
    }
    return 0;
}