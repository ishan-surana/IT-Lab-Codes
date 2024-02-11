#include <stdio.h>
#include <stdlib.h>

struct Person {
    int number;
    struct Person* next;
};

struct Person* newPerson(int number) {
    struct Person* newPerson = (struct Person*)malloc(sizeof(struct Person));
    newPerson->number = number;
    newPerson->next = NULL;
    return newPerson;
}

// Function to reverse the line while maintaining hand-holding
struct Person* reverseLine(struct Person* head) {
    struct Person* prev = NULL;
    struct Person* current = head;
    struct Person* next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next person
        current->next = prev; // Reverse the direction of the chain
        prev = current;       // Move to the next person
        current = next;
    }

    return prev; // The last person becomes the new "Head"
}

// Function to print the line
void printLine(struct Person* head) {
    struct Person* current = head;
    printf("Head");
    while (current != NULL) {
        printf(" -> Person %d", current->number);
        current = current->next;
    }
    printf(" -> End of Line!");
}

int main() {
    int num; // Number of people in the line
    printf("Enter num:- ");
    scanf("%d",&num);
    // Create the initial line of people
    struct Person* head = newPerson(1);
    struct Person* current = head;
    for (int i = 2; i <= num; i++) {
        current->next = newPerson(i);
        current = current->next;
    }

    printf("Original Line:\n");
    printLine(head);

    // Reverse the line
    struct Person* revHead = reverseLine(head);

    printf("\nReversed Line:\n");
    printLine(revHead);

    return 0;
}
