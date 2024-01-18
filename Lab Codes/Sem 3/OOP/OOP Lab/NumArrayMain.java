//Create a class NumArray containing 1D array of size 10. Input the values and count and display the number of palindrome, prime and odd numbers in the array by using the methods isPalindrome(), isOdd( ), isPrime(). Use for each loop.
import java.util.Scanner;
class NumArray
{
    int arr[]=new int[10];
    int odd=0,palindrome=0,prime=0;
    NumArray()
    {
        for(int i=0;i<10;i++)
        arr[i]=0;
    }
    NumArray(int a[])
    {
        for(int i=0;i<10;i++)
        arr[i]=a[i];
    }

    boolean isOdd(int d)
    {
        return (d%2==1);
    }
    int countOdd()
    {
        for(int i=0;i<10;i++)
        if(isOdd(arr[i])) ++odd;
        return odd;
    }
    boolean isPrime(int d)
    {
        if(d<=1)
        return false;
        for(int i=2;i<d;i++)
        if(d%i==0) return false;
        return true;
    }
    int countPrime()
    {
        for(int i=0;i<10;i++)
        if(isPrime(arr[i])) ++prime;
        return prime;
    }
    
    boolean isPalindrome(int a)
    {
        int i,m=a,n=a,rev=0,r;
for(i=0;m>0;i++)
m=(m/10);
int l=i;
for(i=0;i<l;i++)
{
r=n%10;
rev=(rev*10 + r);
n=(n/10);
}
if(rev==a) return true;
else return false;
    }

    int countPalindrome()
    {
        for(int i=0;i<10;i++)
        if(isPalindrome(arr[i])) ++palindrome;
        return palindrome;
    }
}
class NumArrayMain
{
    public static void main(String[] args)
    {
        int a[]=new int[10];
        char c='n';
        Scanner sc=new Scanner(System.in);
        NumArray n=new NumArray();
        System.out.println("Do you want to input elements? (y/n)");
        c=sc.next().charAt(0);
        if(c=='y')
        {
            System.out.print("Enter elements:-\n");
            for(int i=0;i<10;i++)
            a[i]=sc.nextInt();
            n = new NumArray(a);
        }
        int o=n.countOdd();
        int pa=n.countPalindrome();
        int p=n.countPrime();
        System.out.println("Palindrome="+pa+"\nPrime="+p+"\nOdd="+o);
    }
}