import java.util.Scanner;
class Bitwise
{
public static void main(String args[])
{
int i;
Scanner sc = new Scanner(System.in);
System.out.println("Enter integer to perform operation:- ");
i = sc.nextInt();
System.out.println("Choose operation:-\n1)Multiply by 2\n2)Divide by 2\n");
if(sc.nextInt()==1) i<<=1;
else i>>=1;
System.out.println("\nValue after operation is = " + i);
}
}