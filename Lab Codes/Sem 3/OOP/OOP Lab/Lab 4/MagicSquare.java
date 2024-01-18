import java.util.Scanner;
class MagicSquare
{
    public static void main(String[] args)
    {
        int m,n,i,j,arr[][],sr=0,s=0,flag=1,dflag=1,rdflag=1;
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
        sr+=arr[i][0]; //1st column sum, now ref
        //System.out.println("\n\n"+sr+"\n\n");

        for(j=1;j<n;j++)
        {
            s=0;
            for(i=0;i<n;i++)
            s+=arr[i][j];
            //System.out.println("\n\n"+s+"\n\n");
            if(s!=sr)
            {
                flag=0;
                break;
            }
        }//every column checked now

        for(i=0;i<n;i++)
        {
            s=0;
            for(j=0;j<n;j++)
            s+=arr[i][j];
            //System.out.println("\n\n"+s+"\n\n");
            if(s!=sr)
            {
                flag=0;
                break;
            }
        }//every row checked

        s=0;
        for(i=0;i<n;i++)
        s+=arr[i][i];
        if(s!=sr)
        dflag=0;
        //System.out.println("\n\n"+s+"\n\n");

        s=0;
        for(i=0;i<n;i++)
        s+=arr[n-1-i][i];
        if(s!=sr)
        rdflag=0;
        //System.out.println("\n\n"+s+"\n\n");

        if(flag==0 || dflag==0 || rdflag==0)
        {
            System.out.println("Not a magic square!");
            System.exit(0);
        }
        else System.out.println("\nMagic Square!\n");
    }
}