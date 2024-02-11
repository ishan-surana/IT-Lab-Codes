#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of a linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to split the linked list into two lists
void split(struct Node* original, struct Node** list1, struct Node** list2) {
    int toggle = 1; // Flag to alternate between lists
    struct Node* current = original;

    while (current != NULL) {
        if (toggle) {
            insertNode(list1, current->data);
        } else {
            insertNode(list2, current->data);
        }

        current = current->next;
        toggle = !toggle; // Toggle the flag to alternate lists
    }
}

// Function to print a linked list
void printList(struct Node* head) {
    for(struct Node* current = head;current!=NULL;current=current->next)
        printf("%d -> ", current->data);
    printf("NULL\n");
}

void symdiff(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    int flag;
    for (struct Node* tracker = list1; tracker != NULL; tracker = tracker->next) {
        flag = 0;
        for (struct Node* temp = list2; temp != NULL; temp = temp->next)
            if (temp->data == tracker->data) {
                flag = 1;
                break;
            }
        if (!flag) {
            insertNode(&result, tracker->data);
        }
    }
    for (struct Node* tracker = list2; tracker != NULL; tracker = tracker->next) {
        flag = 0;
        for (struct Node* temp = list1; temp != NULL; temp = temp->next)
            if (temp->data == tracker->data) {
                flag = 1;
                break;
            }

        if (!flag) {
            insertNode(&result, tracker->data);
        }
    }
    printf("Symmetric difference: ");
    printList(result);
}


int main() {
    struct Node* original = NULL;
    int key=1;
    /*while(key)
    {
        printf("Enter node data:- ");
        int data;
        scanf("%d",&data);
        insertNode(&original,data);
        printf("Do you want to enter more nodes? (1/0):- ");
        scanf("%d",&key);
    }*/
    insertNode(&original,6);
    insertNode(&original,1);
    insertNode(&original,2);
    insertNode(&original,3);
    insertNode(&original,3);
    insertNode(&original,5);
    insertNode(&original,4);
    insertNode(&original,6);
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    split(original, &list1, &list2);

    printf("\nOriginal List: ");
    printList(original);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    printf("\n\n");
    symdiff(list1,list2);
    return 0;
}
