import java.util.Scanner;
class Table
{
public static void main(String args[])
{
int i, n;
Scanner sc=new Scanner(System.in);
System.out.println("Enter number to get table:- ");
n=sc.nextInt();
System.out.println("Table:- \n");
for(i=1;i<=10;i++)
System.out.println(n+" * "+i+" = "+(n*i));
}
}