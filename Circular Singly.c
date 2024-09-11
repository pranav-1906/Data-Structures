#include <stdio.h>
#include <stdlib.h>

struct node {
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
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            head->next = head;
            temp = head;
        } else {
            temp->next = new_node;
            new_node->next = head;
            temp = new_node;
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
        printf("%d -> ", temp->data);
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
        } else {
            new_node->next = head;
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
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
            while (temp->next != head) {
                temp = temp->next;
            }
            struct node *to_delete = head;
            temp->next = head->next; // Last node points to the second node
            head = head->next;       // Update head
            free(to_delete);
        }
    } else {
        temp = head;
        for (i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head || temp->next == NULL) {
            printf("Position out of range.\n");
        } else {
            struct node *to_delete = temp->next;
            temp->next = to_delete->next;
            free(to_delete);
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