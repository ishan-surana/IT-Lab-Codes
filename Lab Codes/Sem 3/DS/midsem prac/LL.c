#include<Stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void insertNodeBegin(int value)
{
    struct node *temp;
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(newNode==NULL)
    {
        printf("Memory Overflow");
    }
    else if(head==NULL)
    {
        head=newNode;
        newNode->next=NULL;
    }
    else
    {
        temp=head;
        head=newNode;
        newNode->next=temp;
    }
}

void insertNodeEnd(int value)
{
    struct node *temp, *temp1;
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(newNode==NULL)
    {
        printf("Memory Overflow");
    }
    else if(head==NULL)
    {
        head=newNode;
        newNode->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newNode;
        newNode->next=NULL;
    }
}

void deleteBegin()
{
    if(head==NULL) printf("UNDERFLOW!\n");
    else
    {
        struct node *temp;
        temp=head;
        head=temp->next;
        free(temp);
    }
}

void deleteEnd()
{
    if(head==NULL) printf("UNDERFLOW!\n");
    else
    {
        struct node *temp, *temp1;
        struct node *newNode;
        temp=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
    }
}

void printList()
{
    struct node *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
}

// void push(int val)
// {
//     struct node *newNode;
//     newNode=(struct node *)malloc(sizeof(struct node));
//     newNode->data=val;
//     if(newNode==NULL) printf("Memory Overflow!\n");
//     else if(head==NULL)
//     {
//         head=newNode;
//         newNode->next=NULL;
//     }
//     else
//     {
//         newNode->next=head;
//         head=newNode;
//     }
// }

int main()
{
    insertNodeBegin(1);
    printList();
    insertNodeBegin(2);
    printList();
    insertNodeBegin(3);
    printList();
    insertNodeEnd(4);
    printList();
    insertNodeEnd(5);
    printList();
    deleteEnd();
    printList();
    deleteBegin();
    printList();
    insertNodeEnd(6);
    printList();
}