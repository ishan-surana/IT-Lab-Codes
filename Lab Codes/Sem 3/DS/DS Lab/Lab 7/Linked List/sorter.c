#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* head = NULL;

void printList() {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortlist() {
    node** root=&head;
    node* current;
    node* temp;
    int swapped;

    if (root==NULL) {
        return;
    }

    do {
        swapped = 0;
        current = *root;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                // Swap the data
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

void appendNode(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

int main() {
    appendNode(3);
    appendNode(1);
    appendNode(4);
    appendNode(2);

    printf("Original linked list: ");
    printList();

    sortlist();

    printf("Sorted linked list: ");
    printList();

    return 0;
}
