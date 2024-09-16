#include <stdio.h>

#define SIZE 100

void display(int arr[], int n) {
    printf("Array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *n, int value, int pos) {
    if (pos < 0 || pos > *n || *n >= SIZE) {
        printf("Invalid position or array is full!\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void search(int arr[], int n, int value) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Element %d found at index %d\n", value, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array\n", value);
    }
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void main() {
    int arr[SIZE], n = 0, choice, value, pos,e=0;

    while (e!=4) {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Sort\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                insert(arr, &n, value, pos);
                break;
            case 2:
                printf("Enter the position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(arr, n, value);
                break;
            case 4:
                sort(arr, n);
                printf("Array sorted.\n");
                break;
            case 5:
                display(arr, n);
                break;
            case 6:
                e=4;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}
