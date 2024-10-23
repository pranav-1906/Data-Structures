#include <stdio.h>

int main() {
    int size, target, flag = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            flag = 1;  // Element found
            break;
        }
    }

    if (!flag) {
        printf("Element not found\n");
    }

    return 0;
}