
import java.util.Scanner;
class Prime
{
    int isPrime(int a)
    {
        int flag=1;
        for(int i=2;i<a;i++)
        if(a%i==0)
        {
            flag=0;
            break;
        }
        if(flag==1) return 1;
        else return 0;
    }

    public static void main(String[] args)
    {
        Prime p = new Prime();
        int m,n,i;
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter lower limit m:- ");
        m=sc.nextInt();
        System.out.print("Enter upper limit n:- ");
        n=sc.nextInt();
        System.out.println("\nThe prime numbers between the given limits are:-\n");
        for(i=m;i<=n;i++)
        if(p.isPrime(i)==1) System.out.println(i);
    }
}