#include <stdio.h>
#include <stdlib.h>

int front=(-1), rear=(-1);
char queue[5];

void enqueue(char item)
{

    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=item;
        printf("%c has been enqueued at position %d!\n\n",queue[rear],rear);
    }
    else if(((rear+1)%5)==front)
        printf("Queue has overflowed! More elements cannot be added.\n");
    else {
        rear = ((rear+1)%5);
        queue[rear]=item;
        printf("%c has been enqueued at position %d!\n",queue[rear],rear);
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
        printf("Queue is in underflow! No element exists to remove.\n");
    else if(front==rear){
        printf("The dequeued element is %c", queue[front]);
        front=rear=-1;
    }
    else{
        printf("The dequeued element is %c", queue[front]);
        front=((front+1)%5);
    }
}

void printqueue()
{
    if(rear>=front) for(int i=front; i<=rear; i++)
        printf("%c ",queue[i]);
    else {
        for(int i=0;i<rear;i++)
        printf("%c ",queue[i]);
        for(int i=rear;i<=5;i++)
        printf("%c ",queue[i]);
    }
}
int main()
{
    int a,item;
    char key='y';
    printf("The circular queue has following functions:-\n1)Enqueue\n2)Dequeue\n3)Print\n");
    do{
        printf("\nEnter operation number:- ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                {
                    fflush(stdin);
                    printf("Enter element to enqueue:- ");
                    scanf("%c",&item);
                    enqueue(item);
                    break;
                }
            case 2:
                {
                    dequeue();
                    break;
                }
            case 3:
                {
                    printqueue();
                    break;
                }
        }
        printf("\nDo you want to continue? (y/n):- ");
        fflush(stdin);
        scanf("%c",&key);
    }while(key=='y');
    return 0;
}
