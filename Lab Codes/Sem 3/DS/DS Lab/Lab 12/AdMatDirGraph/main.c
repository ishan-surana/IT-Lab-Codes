#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number of nodes:- ");
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    int key=1;
    while(key)
    {
        int a,b;
        printf("\nEnter edge vertices:- ");
        scanf("%d %d",&a,&b);
        if(a>n||b>n||a<1||b<1)
           {
               printf("Invalid vertex set! Try again");
               continue;
           }
        printf("Enter distance:- ");
        int d;
        scanf("%d",&d);
        arr[a-1][b-1]=d;
        arr[b-1][a-1]=d;
        printf("Edge between %d and %d added!\nDo you want to enter any more edges? (1/0)",a,b);
        scanf("%d",&key);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) printf("%d ",arr[i][j]);
        printf("\n");
    }
    return 0;
}
