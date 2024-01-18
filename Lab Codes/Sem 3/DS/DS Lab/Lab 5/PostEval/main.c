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
    //printf("%c has been pushed to stack\n",item);
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

char eval(char postfix[])
{
    /*char ch;
    int i=0;
    while((ch=postfix[i++])!='\0')
    {
        if(IsOperand(ch)) push(ch);
        if(IsOperator(ch))
        {
            char ca=pop(), cb=pop();
            int a=(int) ca;
            int b=(int) cb;
            
        }
    }
    }
    return pop();*/
    char ch;
    int i = 0;
    int j = 0;

    while ((ch = postfix[i++]) != '\0')
    {
        if (IsOperand(ch))
        {
            if(ch>='1' && ch<='9')
            push((ch-'0'));
            else {printf("Invalid!\n"); exit(0);}
        }
        else if (IsOperator(ch))
        {
            int a = pop();
            int b = pop();
            switch (ch) {
            case '+':
                push(((char)(a+b)));
                break;
            case '-':
                push(((char)(a-b)));
                break;
            case '*':
                push(((char)(a*b)));
                break;
            case '/':
                push(((char)(a/b)));
                break;
            case '^':
                push(((char)pow(a,b)));
                break;
            // infix[j++] = '(';
            // infix[j++] = ca;
            // infix[j++] = ch;
            // infix[j++] = cb;
            // infix[j++] = ')';
            // push(infix[j - 1]);
        }
    }
    //infix[j] = '\0';
}
return pop();
}
int main()
{
    char postfix[100];
    gets(postfix);
    printf("Answer:- %d ",eval(postfix));
    return 0;
}
