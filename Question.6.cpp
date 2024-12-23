#include <stdio.h>
#define SIZE 100

struct queue {
    int queue[SIZE];
    int front, rear;
} q;

void init() {
    q.front = q.rear = -1;
}

int full() {
    if (q.rear >= SIZE - 1)
        return 1;
    else
        return 0;
}

int empty() {
    if (q.front == -1 || q.front > q.rear)
        return 1;
    else
        return 0;
}

void insert(int element) {
    if (full()) {
        printf("Queue is full. Cannot insert %d\n", element);
    } else {
        if (q.front == -1)
            q.front = 0;
        q.rear++;
        q.queue[q.rear] = element;
        printf("Inserted %d into the queue.\n", element);
    }
}

void deleteData() {
    if (empty()) {
        printf("Queue is empty. Cannot delete.\n");
    } else {
        printf("Deleted %d from the queue.\n", q.queue[q.front]);
        q.front++;
    }
}

void display() {
    if (empty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    init();

    do {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            deleteData();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
