import java.util.Scanner;
class Student{
    Scanner scan= new Scanner(System.in);
    int regno;
    String name;
    int age;
    Student()
    {
        System.out.println("Enter the name of the student:");
        this.name = scan.nextLine();
        System.out.println("Enter the registration number of the student:");
        this.regno = scan.nextInt();
        scan.nextLine();
        System.out.println("Enter the age of the student:");
        this.age = scan.nextInt();
    }

    void disp()
    {
        System.out.println("The semester and fees are as follows:");    
    }
}
class UG extends Student{
    int semester;
    double fees;
    UG()
    {
        super();
        System.out.println("Enter the semester:");
        this.semester = scan.nextInt();
        System.out.println("Enter the fees:");
        this.fees = scan.nextDouble();
    }
    void display(){
        disp();
        System.out.println(semester);
        System.out.println(fees);
    }
}
class PG extends Student{
    int semester;
    double fees;
    PG()
    {
        super();
        System.out.println("Enter the semester:");
        this.semester = scan.nextInt();
        System.out.println("Enter the fees:");
        this.fees = scan.nextDouble();
    }
    void display()
    {
        disp();
        System.out.println(semester);
        System.out.println(fees);
    }
}

class UGPG
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int key=1;
        UG ug[]=new UG[10];
        PG pg[]=new PG[10];
        int ugc=0,pgc=0;
        while(key==1)
        {
        System.out.println("Do you want to enter details for UG student or PG student? (1/2):- ");
        int s=sc.nextInt();
        if(s==1)
        {
        UG u=new UG();
        ug[ugc++]=u;
        }
        else
        {
        PG p=new PG();
        pg[pgc++]=p;
        }
        System.out.print("Do you want to continue? (1/0):- ");
        key=sc.nextInt();
        }
        System.out.println("\n\nThe details of UG students are as follows:-\n");
        for(int i=0;i<ugc;i++){
        System.out.println("Student "+(i+1));
        ug[i].display();}
        System.out.println("\n\nThe details of PG students are as follows:-\n");
        for(int i=0;i<pgc;i++){
        System.out.println("Student "+(i+1));
        pg[i].display();}
        System.out.println("Total UG students = "+ugc+" and total PG students = "+pgc);
    }
}