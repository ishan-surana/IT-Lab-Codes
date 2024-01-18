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
}

char pop()
{
    if(top==(-1))
    {
        printf("Stack Underflow!\n");
        return;
    }
    char item = stack[top];
    top-=1;
    return item;
}

int IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
    return 1;
    return 0;
}

int IsOperand(char c)
{
    if(c>='A'&&c<='Z' || c>='a'&&c<='z' || c>='0'&&c<='9')
    return 1;
    return 0;
}

void convert(char postfix[], char infix[])
{
    char ch;
    int i = 0;
    int j = 0;

    while ((ch = postfix[i++]) != '\0')
    {
        if (IsOperand(ch))
        {
            push(ch);
        }
        else if (IsOperator(ch))
        {
            infix[j++]='(';
            infix[j++]=pop();
            infix[j++]=ch;
            infix[j++]=pop();
            infix[j++]=')';
        }
    }
    infix[j]='\0';
}

int main()
{
    char postfix[100],infix[100];
    gets(postfix);
    convert(postfix, infix);
    puts(infix);
    return 0;
}
