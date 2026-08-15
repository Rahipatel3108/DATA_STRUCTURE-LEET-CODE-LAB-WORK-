#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeg(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Insert after a given node
void insertAfter(int key, int val) {
    if (head == NULL) return;

    struct Node *temp = head;
    do {
        if (temp->data == key) {
            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node not found.\n");
}

// Delete first node
void deleteBeg() {
    if (head == NULL) return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    struct Node *del = head;
    temp->next = head->next;
    head = head->next;
    free(del);
}

// Delete last node
void deleteEnd() {
    if (head == NULL) return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    free(temp->next);
    temp->next = head;
}

// Delete node after a given node
void deleteAfter(int key) {
    if (head == NULL) return;

    struct Node *temp = head;
    do {
        if (temp->data == key) {
            struct Node *del = temp->next;

            if (del == head)
                head = head->next;

            if (del == temp) {
                free(del);
                head = NULL;
                return;
            }

            temp->next = del->next;
            free(del);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Deletion not possible.\n");
}

// Display nodes
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, val, key;

    while (1) {
        printf("\n--- Singly Circular Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert after a Given Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node after a Given Node\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeg(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter node value after which to insert: ");
                scanf("%d", &key);
                printf("Enter new value: ");
                scanf("%d", &val);
                insertAfter(key, val);
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter node value after which to delete: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
