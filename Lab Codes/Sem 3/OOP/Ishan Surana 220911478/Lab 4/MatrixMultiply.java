import java.util.Scanner;
class MatrixMultipy
{
    public static void main(String[] args)
    {
        int a,b,m,n,i,j,k,arr1[][],arr2[][],arr3[][];
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of rows and columns of the matrix 1:- ");
        a=sc.nextInt();
        b=sc.nextInt();
        System.out.print("\nEnter number of rows and columns of the matrix 2:- ");
        m=sc.nextInt();
        n=sc.nextInt();
        if(m!=b)
        {
            System.out.println("The number of columns in matix 1 and rows in matrix 2 should be same!");
            System.exit(0);
        }
        arr1=new int[a][b];
        arr2=new int[m][n];
        arr3=new int[a][n];
        System.out.println("\nEnter elements of matrix 1:-");
        for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        arr1[i][j]=sc.nextInt();
        System.out.println("\nEnter elements of matrix 1:-");
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        arr2[i][j]=sc.nextInt();
        for(i=0;i<a;i++)
        for(j=0;j<n;j++)
        {
            arr3[i][j]=0;
            for(k=0;k<m;k++)
            arr3[i][j]+=arr1[i][k]*arr2[k][j];
        }
        System.out.println("\n\nThe result of multiplication of above matrices is:-\n");
        for(i=0;i<a;i++)
        {
        for(j=0;j<n;j++)
        System.out.print(arr3[i][j]+" ");
        System.out.println();
        }
    }
}