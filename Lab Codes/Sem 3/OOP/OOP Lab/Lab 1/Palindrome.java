class Palindrome
{
public static void main(String args[])
{
int a=Integer.parseInt(args[0]),i,m=a,n=a,rev=0,r;
for(i=0;m>0;i++)
m=(m/10);
int l=i;
for(i=0;i<l;i++)
{
r=n%10;
rev=(rev*10 + r);
n=(n/10);
}
if(rev==a) System.out.println("Yes, "+a+" is a palindrome number.");
else System.out.println("No, "+a+" is not a palindrome");
}
}