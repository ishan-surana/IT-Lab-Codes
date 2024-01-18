import java.util.Scanner;
class Diagonal
{
    public static void main(String[] args)
    {
        int m,n,i,j,arr[][],s=0;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of rows and columns of the square matrix:- ");
        m=sc.nextInt();
        n=sc.nextInt();
        if(m!=n)
        {
            System.out.println("The number of rows and columns should be same!");
            System.exit(0);
        }
        arr=new int[n][n];
        System.out.println("\nEnter elements:-");
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        arr[i][j]=sc.nextInt();
        System.out.println("\nThe diagonal elements and their sum is as follows:-");
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(i==j)
        {
            System.out.println("arr["+i+"]["+j+"] = "+arr[i][j]);
            s+=arr[i][j];
        }
        System.out.println("\nSum = "+s);
    }
}