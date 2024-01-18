import java.util.Scanner;
class Ternary
{
public static void main(String args[])
{
int a,b,c,max,min;
Scanner sc = new Scanner(System.in);
System.out.println("Enter a, b and c:- ");
a=sc.nextInt();
b=sc.nextInt();
c=sc.nextInt();
max=(a>b)?a:b;
max=(c>max)?c:max;
System.out.println("\nLargest number is "+max);
min=(a<b)?a:b;
min=(c<min)?c:min;
System.out.println("\nSmallest number is "+min+"\n");
}
}