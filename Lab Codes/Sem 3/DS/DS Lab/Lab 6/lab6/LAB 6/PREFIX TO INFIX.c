#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[100][100];
int top=-1;

int isEmpty() {
    return top == -1;
}

void push(char item[]) {
    if (top >= 99) {
        printf("Stack Overflow\n");
        exit(1);
    }
    strcpy(data[++top], item);
}

void pop(char item[]) {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    strcpy(item, data[top--]);
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int IsOperand(char c)
{
    if(c>='A'&&c<='Z' || c>='a'&&c<='z' || c>='0'&&c<='9')
    return 1;
    return 0;
}

void prefixToInfix(char prefix[], char infix[]) {
    int len = strlen(prefix);
    char temp[100];

    for (int i = len - 1; i >= 0; i--) {
        if (IsOperand(prefix[i])) {
            // Operand: Push onto the stack
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        } else if (isOperator(prefix[i])) {
            // Operator: Pop the top two operands, construct the infix expression, and push back
            char operand1[100], operand2[100];
            pop(operand1);
            pop(operand2);

            sprintf(temp, "(%s%c%s)", operand1, prefix[i], operand2);
            push(temp);
        }
    }

    if (top == 0) {
        strcpy(infix, data[0]);
    } else {
        printf("Invalid prefix expression.\n");
        exit(1);
    }
}

int main() {
    char prefix[100];//*-a/bc+/def
    char infix[100];
    printf("Enter prefix expression:- ");
    gets(prefix);
    prefixToInfix(prefix, infix);

    printf("Prefix expression: %s\n", prefix);
    printf("Infix expression: %s\n", infix);

    return 0;
}

