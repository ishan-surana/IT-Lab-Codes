import java.util.Scanner;
class Employee{
    String name,city;
    int salary;
    double da,hra,total=0;
    void getdata(){
        Scanner sc=new Scanner(System.in);
        System.out.print("\nName:- ");
        name=sc.nextLine();
        System.out.print("City:- ");
        city=sc.nextLine();
        System.out.print("Salary:- ");
        salary=sc.nextInt();
        System.out.print("Dearness Allowance (%):- ");
        da=sc.nextDouble();
        System.out.print("House Rent Allowance (%):- ");
        hra=sc.nextDouble();
    }
    void calculate(){
        total=(salary+(salary*da/100)+(salary*hra/100));
    }
    void display(){
        System.out.println("\nTotal salary is:- $"+total);
    }
}

class EmployeeDetails{
    public static void main(String[] args) {
        Employee E=new Employee();
        System.out.println("Enter employee details:-\n");
        E.getdata();
        E.calculate();
        E.display();
    }
}