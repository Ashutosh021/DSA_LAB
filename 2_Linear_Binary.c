#include<stdio.h>
#define mx 100

void linearSearch(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Linear Search Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found\n");
}

void BinarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            printf("Binary Search Element found at index %d\n", mid);
            return;
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Element not found\n");
}

int main() {
    int arr[mx];
    int size, target, choice;
    printf("\nEnter array size: ");
    scanf("%d", &size);
    printf("\nEnter %d elements of array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter target element: ");
    scanf("%d", &target);

    // printf("\nEnter Choice: ");
    // printf("\n1. Linear Search ");
    // printf("\n2. Binary Search ");
    // scanf("%d", &choice);
    // if (choice == 1) {
        linearSearch(arr, size, target);
    // }
    // else if (choice == 2) {
        BinarySearch(arr, size, target);
    // }
    // else {
        // printf("\nInvalid Choice ");
    // }
    return 0;
}
