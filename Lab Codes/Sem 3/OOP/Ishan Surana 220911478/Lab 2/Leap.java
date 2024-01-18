import java.util.Scanner;
class Leap
{
public static void main(String args[])
{
boolean isLeap=false;
int year;
Scanner sc = new Scanner(System.in);
System.out.println("Enter year to check if it is leap:- ");
year = sc.nextInt();
if(year%4==0)
{
isLeap=true;
if(year%100==0)
{
isLeap=false;
if(year%400==0)
isLeap=true;
}
}
if(isLeap) System.out.println("Given year " + year + " IS a leap year");
else System.out.println("Given year " + year + " is NOT a leap year");
}
}