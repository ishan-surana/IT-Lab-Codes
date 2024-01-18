import java.util.Scanner;
class NegativeRoot extends Exception
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number to calculate square root:- ");
        try
        {
            double a=sc.nextInt();
            if(a<0)
            {
                NegativeRoot e=new NegativeRoot();
                throw e;
            }
            System.out.println("Square root = "+Math.sqrt(a));
        }
        catch(NegativeRoot n)
        {
            System.out.println("Negative Number is inavlid input!");
        }
    }
}