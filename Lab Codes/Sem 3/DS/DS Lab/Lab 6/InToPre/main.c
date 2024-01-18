#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int precedence(char op)
{
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

int equalORhigher(char op1, char op2)
{
    if(precedence(op1)==precedence(op2))
    {
        if(op1=='^')
        return 0;
        return 1;
    }
    return(precedence(op1)>precedence(op2)?1:0);
}

void convert(char infix[], char prefix[])
{
    char s[100], ch, top=-1;
    int i=0,j=0;
    strrev(infix);
    while((ch=infix[i++])!='\0')
    {
        if(ch==' ') continue;
        else if(ch==')') s[++top]=ch;
        else if(IsOperand(ch))
            prefix[j++]=ch;
        else if(IsOperator(ch))
        {
            while(top!=-1 && equalORhigher(s[top],ch))
                prefix[j++]=s[top--];
            s[++top]=ch;
        }
        else if(ch=='(')
            {
                while(top!='-1' && s[top]!=')')
                        prefix[j++]=s[top--];
                top--;
            }
    }
    while(top!= -1)
    prefix[j++]=s[top--];
    prefix[j]='\0';
    strrev(prefix);
}

int main()
{
    char infix[100], prefix[100];
    printf("Enter infix expression:- ");
    gets(infix);
    convert(infix,prefix);
    printf("\nPrefix expression is:- ");
    puts(prefix);
    return 0;
}
