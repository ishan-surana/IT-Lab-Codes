#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList
{
    struct DoublyLinkedList* prev;
    int data;
    struct DoublyLinkedList* next;
} node;
node* head=NULL;

void endinsert(int val)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        temp->prev=head;
    }
    else
    {
        node* tracker=head;
        while(tracker->next!=NULL) tracker=tracker->next;
        tracker->next=temp;
        temp->prev=tracker;
    }
}

void midinsert(int pos, int val)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        temp->prev=head;
    }
    else
    {
        int index=pos-1;
        node* tracker=head;
        for(int i=0;i<index;i++) tracker=tracker->next;
        node* prevnode=tracker->prev;
        prevnode->next=temp;
        temp->prev=prevnode;
        temp->next=tracker;
        tracker->prev=temp;
    }
}

void endelete()
{
    if(head==NULL)
    {
        printf("List Empty! Cannot delete further.\n");
        return;
    }
    else if(head->next==NULL)
    {
        free(head->next);
        head=NULL;
    }
    else
    {
        node* tracker=head;
        node* temp;
        while(tracker->next!=NULL)
        {
            temp=tracker;
            tracker=tracker->next;
        }
        temp->next=NULL;
        free(tracker);
    }
}

void midelete(int pos)
{
    if(pos==1)
    {
        node* temp=head;
        head=temp->next;
        free(temp);
    }
    else {
    int index=pos-1;
    if(head==NULL)
    {
        printf("List Empty! Cannot delete further.\n");
        return;
    }
    else
    {
        node* tracker=head;
        node* temp;
        int flag=0;
        for(int i=0;i<index;i++)
        {
            if(tracker->next==NULL)
            {
                flag=1; break;
            }
            temp=tracker;
            tracker=tracker->next;
        }
        if(flag==1)
        {
            printf("Position out of bounds!\n");
            return;
        }
        else
        {
            temp->next=tracker->next;
            free(tracker);
            temp->next->prev=temp;
        }
    }
    }
}

void afterinsert(int key, int val)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=val;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        temp->prev=head;
    }
    else
    {
        node* tracker=head;
        while(tracker->data!=key && tracker->next!=NULL) tracker=tracker->next;
        if(tracker->next==NULL)
        {
            printf("Element does not exist!\n");
            return;
            free(temp);
        }
        else
        {
            temp->next=tracker->next;
            temp->prev=tracker;
            tracker->next->prev=temp;
            tracker->next=temp;
        }
    }
}

void traverse()
{
    if(head==NULL) printf("Empty List!\n");
    else{
    node* newnode;
    printf("%d",head->data);
    for(newnode=head->next;newnode!=NULL;newnode=newnode->next)
        printf(" <-> %d", newnode->data);
    printf("\n");}
}

int main()
{
    endinsert(1);
    traverse();
    endinsert(3);
    traverse();
    endinsert(5);
    traverse();
    endelete();
    traverse();
    endelete();
    traverse();
    endelete();
    traverse();
    endelete();
    traverse();
    endinsert(1);
    traverse();
    endinsert(2);
    traverse();
    endinsert(3);
    traverse();
    midinsert(2,5);
    traverse();
    midelete(5);
    traverse();
    afterinsert(5,4);
    return 0;
}
