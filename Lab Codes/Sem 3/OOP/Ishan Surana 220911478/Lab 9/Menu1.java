import java.util.Scanner;
class Menu1
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter string:- ");
String s=sc.nextLine();
int a,key=1;
System.out.println("1) Palindrome?\n2) Sort\n3) Reverse\n4) Concat string + reverse\n\n");
while(key==1)
{
//System.out.println("Enter string:- ");
//s=sc.nextLine();
System.out.println("Enter choice:- ");
a=sc.nextInt();
switch(a)
{
case 1:
String rs="";
char arr[]=s.toCharArray();
for(int i=(s.length()-1);i>=0;i--)
rs=rs+arr[i];
if(s.equals(rs)) System.out.println("Is a Palindrome!");
else System.out.println("Is NOT a Palindrome!");
break;

case 2:
char k,ele;
arr=s.toCharArray();
int n=s.length();
for(int i=0; i<n-1;i++)
for(int j=0;j<n-i-1;j++)
if(arr[j]>arr[j+1])
{
char temp=arr[j];  
arr[j]=arr[j+1];  
arr[j+1]=temp;  
}
String ss=new String(arr);
System.out.println(ss);
System.out.println("Sorted string:- "+ss);
break;

case 3:
rs="";
arr=s.toCharArray();
for(int i=(s.length()-1);i>=0;i--)
rs=rs+arr[i];
System.out.println("Reversed string is:- "+rs);
break;

case 4:
rs="";
arr=s.toCharArray();
for(int i=(s.length()-1);i>=0;i--)
rs=rs+arr[i];
String srs=s.concat(rs);
System.out.println("Reversed string concat is:- "+srs);
break;
}
System.out.println("Do you want to continue? (y=1/n=0):- ");
key=sc.nextInt();
}
}
}