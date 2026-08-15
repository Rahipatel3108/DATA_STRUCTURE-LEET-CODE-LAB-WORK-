#include <stdio.h>

#define MAX 5  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// ─────────────────────────────────────────
// Check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// ─────────────────────────────────────────
// ENQUEUE: Insert element at rear
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }
    if (front == -1) front = 0; // first element
    queue[++rear] = value;
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
    front++;

    // Reset queue if all elements are dequeued
    if (front > rear) {
        front = rear = -1;
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
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear) printf(" -> ");
    }
    printf("\n");
}

// ─────────────────────────────────────────
// MAIN MENU
int main() {
    int choice, value;

    printf("=== Simple Queue using Array ===\n");
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
