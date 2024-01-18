import java.util.Scanner;

class Account
{
    String name, type;
    int accno;
    double balance=0;
}

class Current extends Account
{
    Current(String name, String type, int accno)
    {
        this.name=name;
        this.type=type;
        this.accno=accno;
    }
    void deposit(int d)
    {
        balance+=d;
        display();
    }
    void display()
    {
        System.out.println("The balance is "+balance);
    }
    void withdraw(int n)
    {
        balance-=n;
        display();
    }
    void checkmin()
    {
        if(balance<500)
        {
            balance-=50;
            System.out.println("Lower than min!");
        display();
        }
        else System.out.println("Above min. Balance is "+balance);
    }
}

class Savings extends Account
{
    double r=5.0;
    Savings(String name, String type, int accno)
    {
        this.name=name;
        this.type=type;
        this.accno=accno;
    }
     void deposit(int d)
    {
        balance+=d;
        display();
    }
    void display()
    {
        System.out.println("The balance is "+balance);
    }
    void withdraw(int n)
    {
        balance-=n;
        display();
    }
    void interest(int t)
    {
        balance=balance+(balance*r*t/100);
        display();
    }
     
}

public class Banking
{
    public static void main(String args[])
    {
        Savings s1=new Savings("Ishan", "Savings", 220968210);
        Current c1=new Current("Surana", "Current", 220911478);
        int dep, with, time;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter deposit amount for Savings");
        dep=in.nextInt();
        s1.deposit(dep);
        System.out.println("Enter deposit amount for current");
        dep=in.nextInt();
        c1.deposit(dep);
        System.out.println("Enter withdrawal amount for savings");
        with=in.nextInt();
        s1.withdraw(with);
        System.out.println("Enter withdrawal amount for current");
        with=in.nextInt();
        c1.withdraw(with);
        System.out.println("Enter the time for interest on savings");
        time=in.nextInt();
        s1.interest(time);
        System.out.println("Checking min balance in current acc");
        c1.checkmin();
    }
}