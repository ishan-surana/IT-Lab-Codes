#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList
{
    struct DoublyLinkedList* prev;
    int data;
    struct DoublyLinkedList* next;
} node;

node* head=NULL;

void posdelete(int pos)
{
    if(pos==1)
    {
        if(head==NULL)
        {
            printf("List Empty! Cannot delete further.\n");
            return;
        }

        node* temp=head;
        if(temp->next==temp)
        {
            head=NULL;
        }
        else
        {
            head=temp->next;
            head->prev=temp->prev;
            temp->prev->next=head;
        }

        free(temp);
    }
    else
    {
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
            for(int i=0; i < index; i++)
            {
                if(tracker==NULL)
                {
                    flag=1;
                    break;
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
                tracker->next->prev=temp;
                free(tracker);
            }
        }
    }
}

void posinsert(int pos, int val)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=val;
    if(head==NULL)
    {
        head=temp;
        head->prev=head;
        head->next=head;
    }
    else if(pos==1)
    {
        temp->next=head;
        temp->prev=head->prev;
        head->prev->next=temp;
        head->prev=temp;
        head=temp;
    }
    else
    {
        node* tracker=head;
        int i=0;
        while(i<(pos-2) && tracker->next!=head)
        {
            tracker=tracker->next;
            i++;
        }
        temp->next=tracker->next;
        temp->prev=tracker;
        tracker->next->prev=temp;
        tracker->next=temp;
    }
}

void traverse()
{
    if(head==NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        node* newnode=head;
        printf("%d", head->data);
        newnode=newnode->next;
        while(newnode != head)
        {
            printf(" <-> %d", newnode->data);
            newnode=newnode->next;
        }
        printf("\n");
    }
}

int main()
{
    posinsert(1,1);
    traverse();
    posinsert(2,3);
    traverse();
    posinsert(2,4);
    traverse();
    posinsert(2,5);
    traverse();
    posdelete(2);
    traverse();
    posdelete(3);
    traverse();
    return 0;
}
