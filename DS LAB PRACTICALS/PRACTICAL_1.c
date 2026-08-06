#include <stdio.h>

#define MAX 100

void traversal(int arr[], int size) {
    printf("\nArray Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int insertion(int arr[], int size, int element, int position) {
    if (size >= MAX || position < 0 || position > size) {
        return size;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    return size + 1;
}

int deletion(int arr[], int size, int position) {
    if (size == 0 || position < 0 || position >= size) {
        return size;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int main() {
    int arr[MAX];
    int size, choice, element, position, key, index;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n1. Traversal\n2. Search\n3. Insertion\n4. Deletion\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traversal(arr, size);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);
                index = search(arr, size, key);
                if (index != -1) {
                    printf("Element found at index %d\n", index);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                size = insertion(arr, size, element, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                size = deletion(arr, size, position);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

