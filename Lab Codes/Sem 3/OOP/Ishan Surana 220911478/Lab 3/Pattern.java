class Pattern
{
public static void main(String args[])
{
int i, j;
System.out.println("Pattern using nested for loop:-\n");
for(i=1;i<=5;i++)
{
for(j=1;j<=i;j++)
System.out.print(i+" ");
System.out.print("\n");
}
System.out.print("\n");
System.out.println("Pattern using nested for-each loop:-\n");
int arr[]={1,2,3,4,5};
for(int k:arr) {
    for(i=0;i<k;i++)
    System.out.print(k+" ");
    System.out.print("\n");
}
}
}