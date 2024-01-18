#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char stack[100];
int top=(-1);

/*struct tb
{
    int n;
    int top[n];
    int boundary[n];
};*/

void push(int i, char item, int top[], int boundary[])
{
    if(top[i]==boundary[i+1])
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top[i]]=item;
    printf("%c has been pushed to stack at position %d!\n",item, top[i]);
}

char pop()
{
    if(top==(-1))
    {
        printf("Stack Underflow!\n");
        return 0;
    }
    return stack[top--];
}

void printstack()
{
    if(top==-1) {printf("Empty!\n"); return;}
    for(int i=0;i<=top;i++)
        printf("%c\n",stack[i]);
}

int main()
{
    int i, n, size=100;
    char k;
    printf("Do want to enter size of stack or default 100? (y/n):- ");
    scanf("%c",&k);
    if(k=='y')
    {
        printf("Enter size:- ");
        scanf("%d",&size);
    }
    printf("Enter number of stacks:- ");
    scanf("%d",&n);
    int top[n],boundary[n];
    for(i=0;i<n;i++)
    boundary[i]=(((size/n)*i)-1);
    boundary[n]=(size-1);
}