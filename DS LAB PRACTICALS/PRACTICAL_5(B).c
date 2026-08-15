#include <stdio.h>

#define MAX 5  // Maximum size of the circular queue

int queue[MAX];
int front = -1, rear = -1;

// ─────────────────────────────────────────
// Check if queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Check if queue is empty
int isEmpty() {
    return front == -1;
}

// ─────────────────────────────────────────
// ENQUEUE: Insert element at rear
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }
    if (front == -1) {
        // First element being inserted
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX; // wrap around
    }
    queue[rear] = value;
    printf("%d enqueued successfully.\n", value);
}

// ─────────────────────────────────────────
// DEQUEUE: Remove element from front
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    printf("%d dequeued successfully.\n", queue[front]);

    if (front == rear) {
        // Last element was removed, reset queue
        front = rear = -1;
    } else {
        front = (front + 1) % MAX; // wrap around
    }
}

// ─────────────────────────────────────────
// DISPLAY: Show all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (front to rear): ");
    int i = front;
    while (1) {
        printf("%d", queue[i]);
        if (i == rear) break;
        printf(" -> ");
        i = (i + 1) % MAX; // wrap around
    }
    printf("\n");
    printf("Front = %d, Rear = %d\n", front, rear);
}

// ─────────────────────────────────────────
// MAIN MENU
int main() {
    int choice, value;

    printf("=== Circular Queue using Array ===\n");
    printf("Queue capacity: %d\n\n", MAX);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
