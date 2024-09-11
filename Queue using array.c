#include <stdio.h>
#define max 10

int a[max];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == max - 1) {
        printf("The Queue overflows...\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        a[rear] = data;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("The Queue underflows...\n");
    } else {
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
}

void main() {
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
                printf("The data is dequeued...\n");
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
}