#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

#define SIZE 10

Node* hashTable[SIZE];

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);
    
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Hash[%d]: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int choice, key;

    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    while (1) {
        printf("\nMenu:\n1. Insert\n2. Display\n3. Search\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(key))
                    printf("Key %d found in the hash table.\n", key);
                else
                    printf("Key %d not found in the hash table.\n", key);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
