import java.util.Scanner;
class Armstrong
{
public static void main(String args[])
{
int n, a, b, s=0, i,j,l,r;
Scanner sc = new Scanner(System.in);
System.out.print("Enter number to check if it is an Armstrong number:- ");
n = sc.nextInt();
a=b=n;
for(l=0;b>0;l++)
b/=10;
for(i=0;n>0;i++)
{
int rs=1;
r=n%10;
for(j=0;j<l;j++)
rs*=r;
s+=rs;
n/=10;
}
if(s==a) System.out.println("\nEntered number IS an Armstrong number!");
else System.out.println("\nEntered number is NOT an Armstrong number!");
}
}