#include<stdio.h>
int stack[10];
void push(int seg, int ele, int top[], int boundary[])
{
    if(top[(seg-1)]==boundary[(seg-1)]) printf("OVERFLOW!\n");
    else stack[++top[(seg-1)]]=ele;
}
void pop(int seg, int top[], int boundary[])
{
    if(seg==1 && top[(seg-1)]==-1) printf("UNDERFLOW!\n");
    else if(top[(seg-1)]==(boundary[(seg-2)])) printf("UNDERFLOW!\n");
    else printf("%d was popped!\n",stack[top[(seg-1)]--]);
}
int main()
{
    int i,n;
    int key=1, choice;
    printf("Enter number of segments:- ");
    scanf("%d",&n);
    int top[n], boundary[n];
    top[0]=-1;
    for(i=1;i<n;i++)
    {
        top[i]=(10/n*i-1);
        boundary[i-1]=top[i];
    }
    boundary[i-1]=9;
    
    while(key==1)
    {
        printf("Push or Pop or Print(1/2/3)?:- ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter segment to push in:- ");
            int seg;
            scanf("%d",&seg);
            printf("Enter element to push:- ");
            int ele;
            scanf("%d",&ele);
            push(seg,ele,top,boundary);
            printf("\n");
        }
        else if(choice==2)
        {
            printf("Enter segment to pop:- ");
            int seg;
            scanf("%d",&seg);
            pop(seg,top,boundary);
        }
        
        else if(choice==3)
        {
            for(int k=9;k>=0;k--)
            printf("%d\n",stack[k]);
            printf("\n");
        }
        printf("\n\nContinue? (1/2)\n");
        scanf("%d",&key);
    }
}