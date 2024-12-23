#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

struct Stack {
    char arr[SIZE];
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

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void push(struct Stack* stack, char ch) {
    if (stack->top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = ch;
}

char pop(struct Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

char peek(struct Stack* stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top];
    }
    return -1;
}

void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infix_to_prefix(char* infix) {
    reverse(infix);
    struct Stack* stack = create_stack();
    char prefix[SIZE];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            prefix[j++] = ch;
        } else if (ch == ')') {
            push(stack, ch);
        } else if (ch == '(') {
            while (!is_empty(stack) && peek(stack) != ')') {
                prefix[j++] = pop(stack);
            }
            pop(stack);
        } else {
            while (!is_empty(stack) && precedence(ch) < precedence(peek(stack))) {
                prefix[j++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    while (!is_empty(stack)) {
        prefix[j++] = pop(stack);
    }

    prefix[j] = '\0';
    reverse(prefix);

    printf("Prefix Expression: %s\n", prefix);
}

int main() {
    char infix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infix_to_prefix(infix);

    return 0;
}
