import java.util.Scanner;
class Expressions
{
public static void main(String args[])
{
int a,b,c;
boolean d;
Scanner sc = new Scanner(System.in);
System.out.println("Enter a and b:- ");
a=sc.nextInt();
b=sc.nextInt();
c = ((a << 2) + (b >> 2));
System.out.println(c);
d = (b > 0);
System.out.println(d);
c = ((a + b * 100) / 10);
System.out.println(c);
c = (a & b);
System.out.println(c);
}
}