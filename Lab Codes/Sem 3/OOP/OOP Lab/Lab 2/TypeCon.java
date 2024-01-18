import java.util.Scanner;
class TypeCon
{
public static void main(String args[])
{
int i, o;
byte b;
double d;
char c;
Scanner sc = new Scanner(System.in);
System.out.println("Choose from the following:-\n1)int to byte\n2)char to int\n3)double to byte\n4)double to int\n");
o = sc.nextInt();
System.out.println("\n");
switch(o)
{
case 1:
{
System.out.print("Enter integer:- ");
i = sc.nextInt();
b = (byte) i;
System.out.print("Byte value after conversion is:- " + b);
break;
}

case 2:
{
System.out.print("Enter character:- ");
c = sc.next().charAt(0);
i = (int) c;
System.out.print("Integer value after conversion is:- " + i);
break;
}

case 3:
{
System.out.print("Enter double:- ");
d = sc.nextDouble();
b = (byte) d;
System.out.print("Byte value after conversion is:- " + b);
break;
}

case 4:
{
System.out.print("Enter double:- ");
d = sc.nextDouble();
i = (int) d;
System.out.print("Integer value after conversion is:- " + i);
break;
}
}
}
}