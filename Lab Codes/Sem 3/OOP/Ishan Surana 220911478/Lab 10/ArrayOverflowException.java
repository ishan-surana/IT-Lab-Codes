import java.util.Scanner;
class ArrayOverflowException extends Exception
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter size of array:- ");
        int n=sc.nextInt();
        int arr[]=new int[n];
        System.err.println("Enter elements:- ");
        try
        {
            for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
            System.out.println("Which element do you want to access?");
            int a=sc.nextInt();
            System.out.println("Element is "+arr[a-1]);
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("ArrayOverflowException!");
        }
    }
}