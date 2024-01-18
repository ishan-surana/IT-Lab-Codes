import java.util.Scanner;
class Menu2
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter string:- ");
String s=sc.nextLine();
int a,key=1;
System.out.println("1) Compare\n2) Case Conversion\n3) Substring?\n\n");
while(key==1)
{
System.out.println("Enter choice:- ");
a=sc.nextInt();
switch(a)
{
case 1:
sc.nextLine();
System.out.print("Enter string to compare:- ");
String s2=sc.nextLine();
if(s.equals(s2)) System.out.println("Equal strings!");
else
{
    if(s.compareTo(s2)>0) System.out.println("String 1 is greater!");
    else System.out.println("String 2 is greater!");
}
break;

case 2:
char arr[]=s.toCharArray();
for(int i=0;i<arr.length;i++)
{
    if('a'<=arr[i] && arr[i]<='z') arr[i]=Character.toUpperCase(arr[i]);
    else if('A'<=arr[i] && arr[i]<='Z') arr[i]=Character.toLowerCase(arr[i]);
}
String arstring=new String(arr);
System.out.println("String after case change is:- "+arstring);
break;

case 3:
sc.nextLine();
System.out.print("Enter string to check for substring:- ");
String s1=s;
String substring=sc.nextLine();
if(s1.contains(substring)) 
{
    System.out.print("Yes it is a substring!\nDo you want to replace it by 'Hello'? (1/0)\n");
    int yes=sc.nextInt();
    if(yes==1) {
        s1=s1.replaceAll(substring, "Hello");
        System.out.println("Modified string is:- "+s1);
    }
}
else System.out.println("Not a substring!");
break;
}
System.out.println("Do you want to continue? (y=1/n=0):- ");
key=sc.nextInt();
}
}
}