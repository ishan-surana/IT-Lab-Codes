import java.util.Scanner;
class Rectangle
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.print("Enter length of rectangle:- ");
int l=sc.nextInt();
System.out.print("\nEnter breadth of rectangle:- ");
int b=sc.nextInt();
int a=(l*b),p=2*(l+b);
System.out.println("\n\nThe area of rectangle is "+a+" and the perimeter is "+p+".");
}
}