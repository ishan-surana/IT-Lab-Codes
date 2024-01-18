#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for the stack
struct Stack {
    double data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a double onto the stack
void push(struct Stack* stack, double item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = item;
}

// Function to pop a double from the stack
double pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to evaluate a prefix expression
double evaluatePrefix(char prefix[]) {
    struct Stack stack;
    initialize(&stack);

    int len = strlen(prefix);

    for (int j = len - 1; j >= 0; j--) {
        if (isdigit(prefix[j])) {
            // Operand: Push onto the stack
            push(&stack, (double)(prefix[j] - '0'));
        } else if (isOperator(prefix[j])) {
            // Operator encountered
            // Pop two elements from Stack
            double o1 = pop(&stack);
            double o2 = pop(&stack);

            // Use switch case to operate on o1
            // and o2 and perform o1 Or o2.
            switch (prefix[j]) {
                case '+':
                    push(&stack, o1 + o2);
                    break;
                case '-':
                    push(&stack, o1 - o2);
                    break;
                case '*':
                    push(&stack, o1 * o2);
                    break;
                case '/':
                    push(&stack, o1 / o2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char prefix[] = "+9*26";
    double result = evaluatePrefix(prefix);

    printf("Result: %lf\n", result);

    return 0;
}

