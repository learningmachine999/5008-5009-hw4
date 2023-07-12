#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

int isEmpty(struct Node* head) {
    return (head == NULL);
}

int isFull(struct Node* head) {
    return 0; // Linked list implementation, always returns false
}

void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (isEmpty(*head) || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued: %d (Priority: %d)\n", data, priority);
}

void dequeue(struct Node** head) {
    if (isEmpty(*head)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Dequeued: %d (Priority: %d)\n", temp->data, temp->priority);
    free(temp);
}

void display(struct Node* head) {
    if (isEmpty(head)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d (Priority: %d) -> ", current->data, current->priority);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, priority;

    do {
        printf("Priority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(head)) {
                    printf("Priority Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter the data to enqueue: ");
                    scanf("%d", &data);
                    printf("Enter the priority of the data: ");
                    scanf("%d", &priority);
                    enqueue(&head, data, priority);
                }
                break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    while (!isEmpty(head)) {
        dequeue(&head);
    }

    return 0;
}