#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
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
        new_node->prev = NULL;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            new_node->prev = temp;
            temp = new_node;
        }
    }

    display();
    insert();
    delete_node();
    search();
}

void display() {
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert() {
    int pos, i;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &new_node->data);
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if (pos == 1) {
        new_node->next = head;
        new_node->prev = NULL;
        if (head != NULL)
            head->prev = new_node;
        head = new_node;
    } else {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of range.\n");
        } else {
            new_node->next = temp->next;
            new_node->prev = temp;

            if (temp->next != NULL) {
                temp->next->prev = new_node;
            }

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
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    } else {
        temp = head;
        for (i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of range.\n");
        } else {
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
    }
    display();
}

void search() {
    int val, found = 0;
    printf("Enter element to be searched: ");
    scanf("%d", &val);
    temp = head;

    while (temp != NULL) {
        if (temp->data == val) {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        printf("%d is found.\n", val);
    } else {
        printf("%d is not found.\n", val);
    }
}