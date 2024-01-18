import java.util.Scanner;
class SquareMatrixException extends Exception
{
    public static void main(String[] args)
    {
        System.out.println("Enter rows and columns:-");
        Scanner sc=new Scanner(System.in);
        try
        {
        int r=sc.nextInt();
        int c=sc.nextInt();
        if(r!=c)
        {
            SquareMatrixException e=new SquareMatrixException();
            throw e;
        }
        System.out.println("Enter elements:- ");
        int arr[][]=new int[r][r];
        for(int i=0;i<r;i++)
            for(int j=0;j<r;j++)
                arr[i][j]=sc.nextInt();
        System.out.println("The matrix is:- ");
        for(int i=0;i<r;i++){
            for(int j=0;j<r;j++)
                System.out.print(arr[i][j]+" ");
                System.out.println();}
        }
        catch(SquareMatrixException f)
        {
            System.out.println("Not a Square Matrix!");
        }
    }
}