#include <stdio.h>
int main()
{
int i,n,key;
printf("Enter number of elements:- ");
scanf("%d",&n);
int arr[n];
printf("Enter elements:- ");
for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
printf("Enter element to be found:- ");
scanf("%d",&key);
for(i=0;i<n;i++) if(arr[i]==key) break;
if(i!=n) printf("Element found at position %d",(i+1));
else printf("Not found!");
}
