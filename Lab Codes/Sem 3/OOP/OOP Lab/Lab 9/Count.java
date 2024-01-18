import java.util.Scanner;
class Count
{
public static void main(String args[])
{
//String s="1+javaprog 2 for 34\tquestion\n1\nof Lab 9";
Scanner sc=new Scanner(System.in);
System.out.print("Enter string:- ");
String s=sc.nextLine();
System.out.println("Number of characters are:- "+s.length());
String[] words=s.split("[ \t\n+]");
System.out.println("\nNumber of words are:- "+words.length);
for(String a:words)
System.out.println(a);
String[] lines=s.split("\n");
System.out.println("\nNumber of lines are:- "+lines.length);
for(String b:lines)
System.out.println(b);
char arr[]=s.toCharArray();
int a=0,e=0,i=0,o=0,u=0;
for(int j=0;j<arr.length;j++)
{
if(arr[j]=='a') ++a;
if(arr[j]=='e') ++e;
if(arr[j]=='i') ++i;
if(arr[j]=='o') ++o;
if(arr[j]=='u') ++u;
}
System.out.println("\nVowel counts:-\nA = "+a+"\nE = "+e+"\nI = "+i+"\nO = "+o+"\nU = "+u);
}
}