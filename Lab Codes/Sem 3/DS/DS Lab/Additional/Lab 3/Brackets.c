#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int top;
    char *arr;
}stack;

void push(stack *s, int size, char element)
{
    if(s->top==size-1) printf("Overflow!\n");
    else s->arr[++(s->top)]=element;
}

char pop(stack *s, int size)
{
    if(s->top==-1) printf("Underflow!\n");
    else return s->arr[(s->top)--];
}

void display(stack *s, int size)
{
    for(int i=0; i<s->top; i++)
    printf("%c\n",s->arr[i]);
}

int isOpenBracket(char c)
{
    if(c=='('||c=='{'||c=='[') return 1;
    else return 0;
}

int isClosedBracket(char c)
{
    if(c==')'||c=='}'||c==']') return 1;
    else return 0;
}

void isValid(stack *s, int size, char *a)
{
    int ocount=0, ccount=0;
    int flag=0;
    for(int i=0;i<size;i++)
    {
        if(isOpenBracket(a[i])) 
        {
            push(s,size,a[i]);
            ++ocount;
        }
        else if(isClosedBracket(a[i]))
        {
            ++ccount;
            char topElement = pop(s, size);
            if ((a[i] == ']' && topElement != '[') ||
                (a[i] == '}' && topElement != '{') ||
                (a[i] == ')' && topElement != '('))
            {
                printf("Invalid!\n");
                return;
            }
        }
    }
    if(ocount==ccount) printf("Valid!\n");
    else printf("Invalid!\n");
}

int main()
{
    stack s;
    s.top=-1;
    char exp[100];
    printf("Enter elements:- \n");
    gets(exp);
    int i, size = strlen(exp);
    char *a=(char*)malloc(size*sizeof(char));
    s.arr=(char*)malloc(size*sizeof(char));
    for(i=0;i<size;i++)
    a[i]=exp[i];
    isValid(&s,size,a);
    return 0;
}