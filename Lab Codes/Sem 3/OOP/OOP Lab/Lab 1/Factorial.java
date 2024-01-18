import java.util.Scanner;
class Factorial
{
public static void main(String args[])
{
int n,i;
long f=1;
Scanner sc = new Scanner(System.in);
System.out.println("Enter number:- ");
n = sc.nextInt();
for(i=1;i<=n;i++)
f*=i;
System.out.println("The factorial of entered number is = "+f);
}
}