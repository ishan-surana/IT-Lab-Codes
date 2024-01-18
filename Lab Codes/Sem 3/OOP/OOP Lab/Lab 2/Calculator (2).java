import java.util.Scanner;
class Calculator
{
public static void main(String args[])
{
double a,b;
char c,key='y';
Scanner sc = new Scanner(System.in);
System.out.println("\nWelcome to the Javalculator. 4 operations are supported, namely addition(+), subtraction(-), multiplication(*) and division(/). Only one operation can be carried out at a time, and calculator can be used multiple times until you choose to exit.\n");
do
{
System.out.println("\nEnter operation WITH spaces and without brackets, in the form (num1) operation (num2):-");
a=sc.nextDouble();
c=sc.next().charAt(0);
b=sc.nextDouble();

if(c=='+') System.out.println("Answer = " + (a+b));
else if(c=='-') System.out.println("Answer = " + (a-b));
else if(c=='*') System.out.println("Answer = " + (a*b));
else System.out.println("Answer = " + (a/b));

System.out.println("\nDo you want to perform another operation (y/n):- ");
key=sc.next().charAt(0);
}
while(key=='y');
}
}