import java.util.Scanner;
class Replace
{
public static void main(String args[])
{
//String s="My bike is red. The bike is also expensive. The bike is very fast!";
Scanner sc=new Scanner(System.in);
System.out.println("Enter string to input:- ");
String s=sc.nextLine();
System.out.println("Enter regex:- ");
String regex=sc.nextLine();
System.out.println("String before replace = "+s);
String replacer="";
for(int i=0;i<regex.length();i++)
replacer=replacer.concat("A");
s=s.replaceAll(regex,replacer);
System.out.println("After replace = "+s);
}
}