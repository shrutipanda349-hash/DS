#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Check if queue is empty
int isEmpty() {
    return front == NULL;
}

// 1. Enqueue - Insert at rear - From your CSLL logic
void enqueue(int item) {
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->info = item;
    
    if (front == NULL) { // First element
        front = rear = ptr;
        rear->next = front; // Circular: points to itself
    } else {
        rear->next = ptr;
        rear = ptr;
        rear->next = front; // Maintain circular link
    }
    printf("Enqueued %d\n", item);
}

// 2. Dequeue - Delete from front
void dequeue() {
    struct Node *ptr;
    if (isEmpty()) {
        printf("Circular Queue is EMPTY - Underflow\n");
        return;
    }
    
    if (front == rear) { // Single node
        ptr = front;
        printf("Dequeued %d\n", ptr->info);
        front = rear = NULL;
        free(ptr);
    } else {
        ptr = front;
        front = front->next;
        rear->next = front; // Update circular link
        printf("Dequeued %d\n", ptr->info);
        free(ptr);
    }
}

// 3. Peek - Front element
void peek() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Front element is %d\n", front->info);
}

// 4. Display - Traverse Circular Queue
void display() {
    struct Node *ptr;
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Circular Queue: front -> ");
    ptr = front;
    do {
        printf("%d -> ", ptr->info);
        ptr = ptr->next;
    } while (ptr != front);
    printf("(back to front %d)\n", front->info);
}

int main() {
    int choice, item;
    char ch;
    do {
        printf("\n--- MENU DRIVEN CIRCULAR QUEUE USING SLL ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front)\n");
        printf("4. Display / Traverse\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("Continue y/n: ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');
    
    return 0;
}
