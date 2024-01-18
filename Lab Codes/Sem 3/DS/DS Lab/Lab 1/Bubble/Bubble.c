#include <stdio.h>
int main()
{
int i,j,n,temp;
printf("Enter number of elements:- ");
scanf("%d",&n);
int arr[n];
printf("Enter array of elements:- ");
for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
for(i=0;i<n;i++)
{
    for(j=1;j<(n-i);j++)
    {
        if(arr[j]<arr[j-1])
        {
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
    }
}
        for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
}
