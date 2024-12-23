#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {
    int arr[50];
    int top;
};

struct Stack* create_stack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

int evaluate_prefix(char* prefix) {
    struct Stack* stack = create_stack();
    int i = strlen(prefix) - 1;

    while (i >= 0) {
        char ch = prefix[i];
        
        if (isdigit(ch)) {
            push(stack, ch - '0');
        } else {
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            
            switch (ch) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
            }
        }
        i--;
    }
    return pop(stack);
}

int main() {
    char prefix[50];
    
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    
    int result = evaluate_prefix(prefix);
    printf("Result: %d\n", result);
    
    return 0;
}
