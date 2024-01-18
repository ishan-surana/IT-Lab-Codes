#include <stdio.h>
#include <stdlib.h>

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
        // {
        //     for(int j=s->top;j>-1;j--)
        //     {
        //         if(a[i]==']' && pop(s,size)=='[') {flag=1;break;}
        //         else if(a[i]=='}' && pop(s,size)=='{') {flag=1;break;}
        //         else if(a[i]==')' && pop(s,size)=='(') {flag=1;break;}
        //         else continue;
        //     }
        //     if(flag==0) {printf("Invalid!\n");break;}
        // }
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
    int size;
    printf("Enter size of array:- ");
    scanf("%d",&size);
    char *a=(char*)malloc(size*sizeof(char));
    s.arr=(char*)malloc(size*sizeof(char));
    printf("Enter elements:- \n");
    getchar();
    gets(a);
    isValid(&s,size,a);
    return 0;
}