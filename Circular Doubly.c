#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *temp = NULL, *new_node;

void display();
void insert();
void delete_node();
void search();

void main() {
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i + 1);
        scanf("%d", &new_node->data);
        new_node->next = new_node->prev = NULL;

        if (head == NULL) {
            head = new_node;
            head->next = head;
            head->prev = head;
        } else {
            temp = head->prev;
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next = head;
            head->prev = new_node;
        }
    }

    display();
    insert();
    delete_node();
    search();
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

void insert() {
    int pos, i;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &new_node->data);
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    if (pos == 1) {
        if (head == NULL) {
            head = new_node;
            head->next = head;
            head->prev = head;
        } else {
            temp = head->prev;
            new_node->next = head;
            new_node->prev = temp;
            temp->next = new_node;
            head->prev = new_node;
            head = new_node;
        }
    } else {
        temp = head;
        for (i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head && pos > i + 1) {
            printf("Position out of range.\n");
        } else {
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next->prev = new_node;
            temp->next = new_node;
        }
    }
    display();
}

void delete_node() {
    int pos, i;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos == 1) {
        temp = head;
        if (head->next == head) {
            head = NULL;
            free(temp);
        } else {
            struct node *last = head->prev;
            head = head->next;
            head->prev = last;
            last->next = head;
            free(temp);
        }
    } else {
        temp = head;
        for (i = 1; i < pos && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp == head || temp->next == NULL) {
            printf("Position out of range.\n");
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
    display();
}

void search() {
    int val, found = 0;
    printf("Enter element to be searched: ");
    scanf("%d", &val);
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    do {
        if (temp->data == val) {
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);
    if (found) {
        printf("%d is found.\n", val);
    } else {
        printf("%d is not found.\n", val);
    }
}