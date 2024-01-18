import java.util.Scanner;
class NFE
{
    public static void main(String[] args)
    {
        System.out.println("Enter string:- ");
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        double a;
        try
        {
            a=Double.parseDouble(s);
            System.out.println("Number entered is:- "+a);
        }
        catch (NumberFormatException e)
        {
            System.out.println("Invalid Input! Enter a valid number!");
        }
    }
}