import java.util.Scanner;
interface Area
{
    void area();
}
class Circle implements Area
{
    int r;
    Circle()
    {
        r=5;
    }
    Circle(int x)
    {
        r=x;
    }
    public void area()
    {
        double a=(3.14159*r*r);
        System.out.println("Area of circle = "+a);
    }
}
class Rectangle implements Area
{
    int l,b;
    Rectangle()
    {
        l=2;
        b=5;
    }
    Rectangle(int x, int y)
    {
        l=x;
        b=y;
    }
    public void area()
    {
        double a=(l*b);
        System.out.println("Area of rectangle = "+a);
    }
}
class InterfaceArea
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int a,b,r;
        System.out.print("Enter length, breadth and radius:- ");
        a=sc.nextInt();
        b=sc.nextInt();
        r=sc.nextInt();
        Rectangle r1=new Rectangle();
        Rectangle r2=new Rectangle(a,b);
        Circle c1=new Circle();
        Circle c2=new Circle(r);
        System.out.println("For rectangle 1:-");
        r1.area();
        System.out.println("For rectangle 2:-");
        r2.area();
        System.out.println("For circle 1:-");
        c1.area();
        System.out.println("For circle 2:-");
        c2.area();
    }
}