#include<stdio.h>
#include<stdlib.h>

void bankers(int num, int rescount, int (*matrix)[3*rescount+1], int *available)
{
    int flag=0;
    int change=1;
    while (flag==0)
    {
        flag=1;
        for(int i=0;i<num;i++) if(matrix[i][3*rescount]==0) flag=0;
        if(flag==1) break;
        for(int i=0;i<num;i++)
        {
            if(matrix[i][3*rescount]==1) continue;
            change=1;
            for(int j=0;j<rescount;j++) if(matrix[i][j+2*rescount]>available[j]) change=0;
            if(change==1)
            {
                for(int j=0;j<rescount;j++) available[j]+=matrix[i][rescount];
                matrix[i][3*rescount]=1;
                printf("Process %d done!\n", i);
            }
        }
        if(change==0) break;
    }
}

int main()
{
    int num, rescount;
    printf("Enter number of processes:- ");
    scanf("%d", &num);
    printf("Enter number of types of resources:- ");
    scanf("%d", &rescount);
    int matrix[num][3*rescount+1];
    for(int i=0;i<num;i++) matrix[i][3*rescount]=0;
    printf("Enter allocated status:- ");
    for(int i=0;i<num;i++) for(int j=0;j<rescount;j++) scanf("%d", &matrix[i][j]);
    printf("Enter maximum demand status:- ");
    for(int i=0;i<num;i++) for(int j=rescount;j<2*rescount;j++) scanf("%d", &matrix[i][j]);
    for(int i=0;i<num;i++) for(int j=0; j<rescount; j++) matrix[i][2*rescount+j] = matrix[i][rescount+j] - matrix[i][j];
    printf("Enter initial avialability:-");
    int available[rescount];
    for(int i=0;i<rescount;i++) scanf("%d", &available[i]);
    printf("INITIAL\n    Allocated\t\t\tMax\t\t\tNeed\t\tDone\n");
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<3*rescount+1;j++) printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("Initial Availability = ");
    for(int i=0;i<rescount;i++) printf("%d ", available[i]);
    printf("\n\n");
    bankers(num, rescount, matrix, available);
    printf("FINAL\n    Allocated\t\t\tMax\t\t\tNeed\t\tDone\n");
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<3*rescount+1;j++) printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("Final Availability = ");
    for(int i=0;i<rescount;i++) printf("%d ", available[i]);
    printf("\n");
    return 0;
}

/*
3
3
0 1 0 2 0 0 3 0 2
7 5 3 3 2 2 9 0 2
5 2 2
*/