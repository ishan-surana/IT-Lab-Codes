#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack {
    int top;
    int capacity;
    char* array;
};

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to count missing or invalid tags
int countMissingTags(char* input) {
    int count = 0, len = strlen(input), i=0;
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = 1000;
    stack->top = -1;
    stack->array = (char*)malloc(1000 * sizeof(char));
    while (i < len) {
        if (input[i] == '<') {
            if (input[i + 1] == '/') {
                char c = pop(stack);
                if (c != input[i + 2])
                    count++;
                i += 3; // Skip the closing tag
            } else {
                push(stack, input[i + 1]);
                i += 2;
            }
        } else i++;
    }

    while (!isEmpty(stack)) {
        pop(stack);
        count++;
    }

    return count;
}

int main() {
    char input[1000];
    printf("Enter string to check: ");
    scanf("%999[^#]", input);
   printf("Output = %d",countMissingTags(input));
    return 0;
}
