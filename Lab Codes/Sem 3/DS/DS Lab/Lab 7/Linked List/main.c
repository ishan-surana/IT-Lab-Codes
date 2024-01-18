#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList* next;
} node;
node* head=NULL;

void beginsert(int val)
{
    node* temp=(node *)malloc(sizeof(node));
    temp->data=val;
    temp->next=head;
    head=temp;
}

void beforeinsert(int nextdata, int val)
{
    node* newnode;
    node* temp=(node *)malloc(sizeof(node));
    temp->data=val;

    if(head==NULL) head=temp;
    else
    {
        for(newnode=head;newnode->next->data!=nextdata;newnode=newnode->next);
        //now newnode is pointing to node after which we want to insert
        temp->next=newnode->next;
        newnode->next=temp;
    }
}

void afterinsert(int prevdata, int val)
{
    node* newnode;
    node* temp=(node *)malloc(sizeof(node));
    temp->data=val;

    if(head==NULL) head=temp;
    else
    {
        for(newnode=head;newnode->data!=prevdata;newnode=newnode->next);
        //now newnode is pointing to node after which we want to insert
        temp->next=newnode->next;
        newnode->next=temp;
    }
}

void del(int val)
{
    node* newnode;
    node* prevnode;
    for(newnode=head,prevnode=head;newnode!=NULL;prevnode=newnode,newnode=newnode->next)
    {
        if(newnode->data==val)
        {
            prevnode->next=newnode->next;
            free(newnode);
            return;
        }
    }
    printf("Element %d does not exist in the list!\n",val);
    return;
}

void traverse()
{
    if(head==NULL) printf("Empty List:");
    node* newnode;
    printf("%d",head->data);
    for(newnode=head->next;newnode!=NULL;newnode=newnode->next)
        printf(" -> %d", newnode->data);
    printf("\n");
}

void reverse()
{
    if(head==NULL) return;
    node* temp=(node*)malloc(sizeof(node));
    node* newnode=head->next;
    head->next=NULL;

    while(newnode!=NULL)
    {
        temp=newnode;
        newnode=newnode->next;
        temp->next=head;
        head=temp;
    }
}

void altdel()
{
    node* newnode=head;
    node* temp;
    while(newnode!=NULL)
    {
        temp=newnode->next;
        if(temp==NULL) return;
        newnode->next=temp->next;
        free(temp);
        newnode=newnode->next;
    }
}

void sortlist()
{
    node* temp1;
    node* temp2;
    if (head == NULL) return;
    else
    {
        for (temp1 = head; temp1->next != NULL; temp1 = temp1->next)
            for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
                if (temp1->data > temp2->data) 
                {
                    int temp=temp1->data;
                    temp1->data=temp2->data;
                    temp2->data=temp;
                }
    }
}

int main()
{
    beginsert(1);
    traverse();
    beginsert(2);
    traverse();
    beginsert(3);
    traverse();
    beginsert(4);
    traverse();
    afterinsert(3,5);
    traverse();
    beforeinsert(5,6);
    traverse();
    del(7);
    traverse();
    reverse();
    traverse();
    sortlist();
    traverse();
    //altdel();
    //traverse();
    return 0;
}
/*Follow the steps below to solve the problem:
Initialize three pointers prev as NULL, curr as head, and next as NULL.
Iterate through the linked list.
In a loop, do the following:
	Before changing the next of curr, store the next node  next = curr -> next
	Now update the next pointer of curr to the prev  curr -> next = prev
	Update prev as curr and curr as next  prev = curr  curr = next */
