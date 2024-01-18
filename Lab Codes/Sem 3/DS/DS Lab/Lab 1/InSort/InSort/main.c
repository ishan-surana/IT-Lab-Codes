#include <stdio.h>
int main()
{
    int i, j, n, key;
    printf("Enter number of elements:- ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array of elements:- ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(i=1;i<n;i++)
    {
        key=arr[i];
        for(j=i-1;arr[j]>key && j>=0; j--)
        arr[j+1]=arr[j];
        arr[j+1]=key;
    }
    for(i=0;i<n;i++)
    printf("%d\n",arr[i]);
}
