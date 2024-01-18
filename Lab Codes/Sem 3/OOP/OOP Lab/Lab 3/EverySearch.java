import java.util.Scanner;
class EverySearch
{
    public static void main(String[] args)
    {
        int i,n,key,arr[];
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements:- ");
        n=sc.nextInt();
        arr=new int[n];
        System.out.println("Enter elements of the array: -");
        for(i=0;i<n;i++)
        arr[i]=sc.nextInt();
        System.out.print("Enter element to be searched:- ");
        key=sc.nextInt();
        System.out.println("The element "+key+" was found at the following location:-");
        i=0;
        for(int k:arr){
        if(k==key)
        System.out.println("a["+i+"] (position "+(i+1)+")");
	++i;}
    }
}