class NumberCheck
{
public static void main(String args[])
{
int arr[]=new int[10];
int i,p=0,n=0,z=0;
for(i=0;i<10;i++)
arr[i]=Integer.parseInt(args[i]);
System.out.println("The ten numbers entered as arguments are ennumerated as below:-");
for(i=0;i<10;i++)
{
if(arr[i] > 0) ++p;
else if(arr[i] < 0) ++n;
else ++z;
}
System.out.println("Number of positive numbers entered = "+p);
System.out.println("Number of negative numbers entered = "+n);
System.out.println("Number of zeroes entered = "+z);
}
}