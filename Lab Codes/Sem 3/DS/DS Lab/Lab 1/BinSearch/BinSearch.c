#include <stdio.h>
int main()
{
int i,j,n,key,flag,mid;
printf("Enter number of elements:- ");
scanf("%d",&n);
int arr[n];
printf("Enter sorted array of elements:- ");
for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
printf("Enter element to be found:- ");
scanf("%d",&key);

int low=0,high=n-1;
while(arr[low]<arr[high])
{
    mid=((low+high)/2);
    if(key<arr[mid]) high=mid;
    else if(key>arr[mid]) low=mid;
    else {
            flag=1;
            break;
        }
}
if(flag==1) printf("Element found at position %d",(mid+1));
else printf("Either element does not exist or the array is not sorted!");
}
