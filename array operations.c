#include <stdio.h>

#define SIZE 6

int main() {
    int arr[SIZE];
    int num_elements = 5;
    int insert_pos, insert_value, delete_pos, search_value;

    printf("Enter 5 elements:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the value to insert: ");
    scanf("%d", &insert_value);
    printf("Enter the position (0 to %d) to insert the value: ", num_elements);
    scanf("%d", &insert_pos);

    if (insert_pos < 0 || insert_pos > num_elements) {
        printf("Invalid position!\n");
    } else {
        for (int i = num_elements; i > insert_pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[insert_pos] = insert_value;
        num_elements++;

        printf("Array elements after insertion:\n");
        for (int i = 0; i < num_elements; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("Enter the position (0 to %d) to delete the element: ", num_elements - 1);
    scanf("%d", &delete_pos);

    if (delete_pos < 0 || delete_pos >= num_elements) {
        printf("Invalid position!\n");
    } else {
        for (int i = delete_pos; i < num_elements - 1; i++) {
            arr[i] = arr[i + 1];
        }
        num_elements--;

        printf("Array elements after deletion:\n");
        for (int i = 0; i < num_elements; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("Enter the value to search: ");
    scanf("%d", &search_value);

    int found = 0;
    for (int i = 0; i < num_elements; i++) {
        if (arr[i] == search_value) {
            printf("Element %d found at index %d\n", search_value, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array\n", search_value);
    }

    printf("Array before sorting:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < num_elements - 1; i++) {
        for (int j = i + 1; j < num_elements; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array after sorting:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
