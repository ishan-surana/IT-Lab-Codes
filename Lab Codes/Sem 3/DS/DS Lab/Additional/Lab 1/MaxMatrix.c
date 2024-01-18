#include <stdio.h>
int main()
{
    int i,j,r,c;
    printf("Enter rows and columns of the matrices:-");
    scanf("%d %d",&r,&c);
    int a[r][c],b[r][c],m[r][c];
    printf("Enter elements of matrix 1:-\n");
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    scanf("%d",&a[i][j]);
    printf("Enter elements of matrix 2:-\n");
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    scanf("%d",&b[i][j]);
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    {
        if(b[i][j]>a[i][j]) m[i][j]=b[i][j];
        else m[i][j]=a[i][j];
    }
    printf("\nMatrix 1:-\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("\nMatrix 2:-\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        printf("%d\t",b[i][j]);
        printf("\n");
    }
   printf("\nMax Matrix:-\n"); 
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        printf("%d\t",m[i][j]);
        printf("\n");
    }
}