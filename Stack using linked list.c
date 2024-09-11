#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Stack overflow...\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("The stack underflows...\n");
    } else {
        struct Node* temp = top;
        top = top->next;
        free(temp);
        printf("The data is popped...\n");
    }
}

void display() {
    struct Node* temp = top;
    if (temp == NULL) {
        printf("The stack is empty.\n");
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
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
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