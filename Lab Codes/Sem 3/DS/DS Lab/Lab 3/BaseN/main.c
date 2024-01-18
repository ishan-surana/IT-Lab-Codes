#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char stack[100];
int top=(-1);

void push(char item)
{
    if(top==99)
    {
        printf("Stack Overflow!");
        return;
    }
    top+=1;
    stack[top]=item;
    printf("%c has been pushed to stack at position %d\n",item, top);
}

char pop()
{
    if(top==(-1))
    {
        printf("Stack Underflow!");
        return;
    }
    char item = stack[top];
    top-=1;
    return item;
}

void printstack()
{
    for(int i=0;i<=top;i++)
        printf("%c",stack[i]);
}

void convert(int n, int b)
{
    //max power of base < n, set to 1, repeat for n%powerb
    int i,d,md=0,q;
    for(i=1;md<=n;i=i*b)
        md=i;
    md=(md/b);
    for(d=md;d>0;d/=b)
    {
        q=(n/d);
        if(q<10)
            push((q + '0'));
        else
            push((q - 10 + 'A'));
        n=(n%d);
    }//20 base 3 = 202
}

int main()
{
    int n, b;
    printf("Enter decimal number:- ");
    scanf("%d",&n);
    printf("Enter base to convert to [within range [2,36]:- ");
    scanf("%d",&b);
    convert(n,b);
    printf("\nThe number after conversion is:- ");
    printstack();
    printf("\n");
}
