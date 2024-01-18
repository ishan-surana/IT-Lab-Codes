#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, x, y, count=0;
    printf("Enter rows and columns of the matrix:- ");
    scanf("%d%d",&x,&y);
    int arr[x][y];
    printf("\nEnter elements of the matrix:-\n");
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
        scanf("%d",&arr[i][j]);
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
        if(arr[i][j]!=0)
        ++count;
    int sparse[count][3],t=0;
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
        if(arr[i][j]!=0)
        {
            sparse[t][0]=i;
            sparse[t][1]=j;
            sparse[t][2]=arr[i][j];
            t++;
        }
    printf("\nSparse matrix is as follows:-\n\n");
    printf("Row Column Value\n");
    for(t=0;t<count;t++)
        printf(" %d     %d     %d\n",sparse[t][0],sparse[t][1],sparse[t][2]);
    printf("\n\nTranspose of the sparse matrix is as follows:-\n\n");
    printf("Row Column Value\n");
    for(t=0;t<count;t++)
        printf(" %d     %d     %d\n",sparse[t][1],sparse[t][0],sparse[t][2]);
    return 0;
}
