import java.util.Scanner;
class Symmetric
{
    public static void main(String[] args)
    {
        int m,n,i,j,flag=1,arr[][],s=0;
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
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(arr[i][j]!=arr[j][i])
        {
            flag=0;
            break;
        }
        if(flag==1) System.out.println("\nThe matrix IS symmetric!");
        else System.out.println("\nThe matrix is NOT symmetric!");
    }
}