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

int evaluate_postfix(char* postfix) {
    struct Stack* stack = create_stack();

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(stack, ch - '0');
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            
            switch (ch) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
            }
        }
    }
    return pop(stack);
}

int main() {
    char postfix[50];
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    int result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);
    
    return 0;
}
