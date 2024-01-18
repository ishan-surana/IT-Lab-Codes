#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if character is operator or not
int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

// Function to convert prefix to postfix expression
void preToPost(char pre_exp[]) {
    char stack[MAX_SIZE][MAX_SIZE];
    int top = -1;

    // Length of expression
    int length = strlen(pre_exp);

    // Reading from right to left
    for (int i = length - 1; i >= 0; i--) {
        // Check if the symbol is an operator
        if (isOperator(pre_exp[i])) {
            // Pop two operands from the stack
            char op1[MAX_SIZE], op2[MAX_SIZE];
            strcpy(op1, stack[top]);
            top--;
            strcpy(op2, stack[top]);
            top--;

            // Concatenate the operands and operator
            char temp[MAX_SIZE];
            sprintf(temp, "%s%s%c", op1, op2, pre_exp[i]);

            // Push the result back to the stack
            top++;
            strcpy(stack[top], temp);
        } else {
            // Push the operand to the stack
            top++;
            stack[top][0] = pre_exp[i];
            stack[top][1] = '\0';
        }
    }

    // The stack now contains only the postfix expression
    printf("Postfix: %s", stack[top]);
}

int main() {
    char pre_exp[] = "*-A/BC-/AKL";
    preToPost(pre_exp);
    return 0;
}

