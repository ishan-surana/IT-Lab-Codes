#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList
{
    struct DoublyLinkedList* prev;
    int data;
    struct DoublyLinkedList* next;
} node;
node* head1=NULL;
node* head2=NULL;

void insert(int l,int val)
{
    node** head;
    if(l==1) head=&head1;
    else head=&head2;
    node* temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->prev=NULL;
    temp->next=NULL;
    if(*head==NULL) *head=temp;
    else
    {
        node* tracker=*head;
        while(tracker->next!=NULL) tracker=tracker->next;
        tracker->next=temp;
        temp->prev=tracker;
    }
}

void traverse(int l)
{
    node* head;
    if(l==1) head=head1;
    else head=head2;
    if(head==NULL) printf("Empty List!\n");
    else{
    node* newnode;
    printf("%d",head->data);
    for(newnode=head->next;newnode!=NULL;newnode=newnode->next)
        printf(" <-> %d", newnode->data);
    printf("\n");}
}

void concat()
{
    node* temp;
    for(temp=head1;temp->next!=NULL;temp=temp->next);
    temp->next=head2;
}

int main()
{
    insert(1,1);
    traverse(1);
    insert(1,3);
    traverse(1);
    insert(1,5);
    traverse(1);
    insert(2,2);
    traverse(2);
    insert(2,4);
    traverse(2);
    insert(2,6);
    traverse(2);
    concat();
    traverse(1);
    return 0;
}