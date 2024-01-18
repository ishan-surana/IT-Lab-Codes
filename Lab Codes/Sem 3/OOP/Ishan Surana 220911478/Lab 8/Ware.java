import java.util.Scanner;
interface Sales
{
    String Company="MyCompany";
    int sales=0;
}
class Hardware implements Sales
{
    char Category;
    String Manufacturer;
    static int hsales=sales;
    Hardware()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Hardware Category:-");
        Category=sc.next().charAt(0);
        sc.nextLine();
        System.out.println("Enter Hardware Manufacturer:-");
        Manufacturer=sc.nextLine();
        ++hsales;
    }
}
class Software implements Sales
{
    char Type;
    String OS;
    static int ssales=sales;
    Software()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Software Type:-");
        Type=sc.next().charAt(0);
        System.out.println("Enter compatible Operating System:-");
        OS=sc.nextLine();
        ++ssales;
    }
}
class Ware
{
    public static void main(String[] args)
    {
        System.out.println("Choose hardware or software and get total sale after entering all sales:-");
        Scanner sc=new Scanner(System.in);
        for(int i=1;i<=3;i++)
        {
        char a='y';
        System.out.println("Enter sales of month "+i);
        while(a=='y')
        {
            System.out.println("Choose type:-\n1) Hardware\n2) Software\n");
            int k=sc.nextInt();
            if(k==1)
            {
                Hardware h=new Hardware();
            }
            else
            {
                Software s=new Software();
            }
            System.out.println("\nDo you want to continue? (y/n):-");
            a=sc.next().charAt(0);
        }
        System.out.println("Total sales are:\nHARDWARE = "+Hardware.hsales+"\nSOFTWARE = "+Software.ssales);
        Hardware.hsales=0;
        Software.ssales=0;
        System.out.println("\n");
        }
    }
}