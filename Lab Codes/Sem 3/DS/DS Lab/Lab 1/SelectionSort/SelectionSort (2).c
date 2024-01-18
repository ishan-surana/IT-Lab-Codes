#include <stdio.h>
int main()
{
    int i, j, n,max,temp,index;
    printf("Enter number of elements:- ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array of elements:- ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    for(i=0;i<n;i++)                               //n=3
    {
        max=arr[0];                                //max=arr[0]=2
        for(j=1;j<(n-i);j++)                       //0 to 2 loop
        {
            if(arr[j]>max){index=j;}
        }
        temp=arr[index];
        arr[index]=arr[n-i-1];
        arr[n-i-1]=temp;
    }

    for(i=0;i<n;i++) printf("%d\n",arr[i]);
}



/*
Enter number of elements:- 3
Enter array of elements:- 2 1 3
1
3
2
*/
