#include <stdio.h>
#define SIZE 30

int stack[SIZE], top = -1;

void push(int value);
int pop();
int peek();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push operation");
        printf("\n2. Pop operation");
        printf("\n3. Peek operation");
        printf("\n4. Display operation");
        printf("\n5. Exit");
       // printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("\nPopped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("\nTop value: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

void push(int value) {
    if (top == SIZE - 1) {
        printf("\nStack is full. Cannot push %d.\n", value);
    } else {
        stack[++top] = value;
        printf("\nValue pushed: %d\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("\nStack is empty. Cannot pop.\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
