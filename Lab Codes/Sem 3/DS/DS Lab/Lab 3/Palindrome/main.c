#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[100];
int top=(-1);

void push(char item)
{
    if(top==99)
    {
        printf("Stack Overflow!");
        return;
    }
    stack[++top]=item;
}

char pop()
{
    if(top==(-1))
    {
        printf("Stack Underflow!");
        return '\0';
    }
    return stack[top--];
}

int isPalindrome(char arr[])
{
    int i,j,len = strlen(arr);
    for (i=0; i<len/2; i++)
        push(arr[i]);
    if (len%2==1)
        i++;
    for (j=i; j<len; j++)
        if (arr[j] != pop())
            return 0;
    return 1;
}

int main()
{
    int item;
    char arr[100];
    printf("Enter string to check:- ");
    scanf("%s",arr);
    if(isPalindrome(arr)) printf("Palidrome!");
    else printf("Not a palindrome");
    return 0;
}