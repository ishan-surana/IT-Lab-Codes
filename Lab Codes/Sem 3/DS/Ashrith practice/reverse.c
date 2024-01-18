#include<stdio.h>
#include<stdlib.h>
#define max_size 100

typedef struct 
{
    int top;
    int *arr;
}stack;

int push(stack *s , int num, int a)
{
    if (s->top == a - 1) {
        printf("Stack is full\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = num;
    }
    return 0;
}
void display(stack *s){
    if (s->top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        for (int i = 0; i<=(s->top); i++)
        {
            printf("%d \n",s->arr[i]);
        }
        
    }
}
int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int k = s->arr[s->top];
        s->top--;
    }
    return 0;
}

void reversestack(stack *s , int count ,int a){
    if (count == a/2)
    {
        pop(s);
        return ;
    }

    int num  = s->arr[s->top];
    pop(s);

    reversestack( s , ++count ,a);

    push(s ,num, a);
}
int main(){
    int a;
    int temp;
    int count = 0;
    stack s;
    printf("ENTER SIZE OF ARRAY\n");
    scanf("%d",&a);
    s.arr = (int*)malloc(a*sizeof(int));
    s.top = -1;
    for (int i = 0; i < a; i++)
    {
        scanf("%d",&temp);
        push(&s,temp,a);
    }
    
    reversestack( &s , count , a);
    printf("\n\n\n");
    display(&s);
}