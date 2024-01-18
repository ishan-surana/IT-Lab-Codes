import java.util.Scanner;
class Number
{
    private double d;
    Number(double a)
    {
        d=a;
    }
    boolean isZero()
    {
        return (d==0);
    }
    boolean isPositive()
    {
        return (d>0);
    }
    boolean isNegative()
    {
        return (d<0);
    }
    boolean isOdd()
    {
        return (d%2==1);
    }
    boolean isEven()
    {
        return (d%2==0);
    }
    boolean isPrime()
    {
        if(d<=1)
        return false;
        for(int i=2;i<d;i++)
        if(d%i==0) return false;
        return true;
    }
    boolean isArmstrong()
    {
        int r,s=0,n=(int)d;
        while(n>0)
        {
            r=n%10;
            s+=r*r*r;
            n/=10;
            System.out.print("\n\n"+n+"\n\n");
        }
        System.out.print("\n\n"+s+"\n\n");
        if(s==d) return true;
        return false;
    }
    public static void main(String[] args)
    {
        Number n = new Number(153);
        System.out.println("Zero? "+n.isZero());
        System.out.println("Positive? "+n.isPositive());
        System.out.println("Negative? "+n.isNegative());
        System.out.println("Odd? "+n.isOdd());
        System.out.println("Even? "+n.isEven());
        System.out.println("Prime? "+n.isPrime());
        System.out.println("Armstrong? "+n.isArmstrong());
    }
}