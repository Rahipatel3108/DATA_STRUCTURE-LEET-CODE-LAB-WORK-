#include <stdio.h>

int main() {
    int arr[100];
    int size;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", (arr + i));
    }

    printf("\nOriginal Array: ");
    int *ptr = arr;
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }

    printf("\nArray in Reverse Order: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", *(ptr + i));
    }

    printf("\n");
    return 0;
}
