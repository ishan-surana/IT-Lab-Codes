#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for the stack
struct Stack {
    char data[MAX_SIZE][MAX_SIZE];
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

// Function to push a string onto the stack
void push(struct Stack* stack, char item[]) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    strcpy(stack->data[++stack->top], item);
}

// Function to pop a string from the stack
void pop(struct Stack* stack, char item[]) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    strcpy(item, stack->data[stack->top--]);
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert a prefix expression to an infix expression
void prefixToInfix(char prefix[], char infix[]) {
    struct Stack stack;
    initialize(&stack);

    int len = strlen(prefix);
    char temp[MAX_SIZE];

    for (int i = len - 1; i >= 0; i--) {
        if (isalpha(prefix[i])) {
            // Operand: Push onto the stack
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(&stack, temp);
        } else if (isOperator(prefix[i])) {
            // Operator: Pop the top two operands, construct the infix expression, and push back
            char operand1[MAX_SIZE], operand2[MAX_SIZE];
            pop(&stack, operand1);
            pop(&stack, operand2);

            snprintf(temp, sizeof(temp), "(%s%c%s)", operand1, prefix[i], operand2);
            push(&stack, temp);
        }
    }

    if (stack.top == 0) {
        strcpy(infix, stack.data[0]);
    } else {
        printf("Invalid prefix expression.\n");
        exit(1);
    }
}

int main() {
    char prefix[] = "*-a/bc-/ade";
    char infix[MAX_SIZE];

    prefixToInfix(prefix, infix);

    printf("Prefix expression: %s\n", prefix);
    printf("Infix expression: %s\n", infix);

    return 0;
}

