import java.util.Scanner;
class Input_Exception extends Exception
{
    Input_Exception()
    {
    System.out.println("No floating point allowed!");
    }
}
class Additional1
{
    public static void main(String[] args)
    {
        int sum=0, a, key=1;
        while(key!=-1)
        {
            try
            {
            a=sc.nextInt();
            if(a-(int)a!=0) throw Input_Exception;
            if(a==-1)
            {
                System.out.println("Sum = "+sum);
                break;
            }
            sum+=a;
            }
            catch (Input_Exception e) 
            {
                System.out.println("Invalid input. Please enter an integer.");
            }
        }
    }
}