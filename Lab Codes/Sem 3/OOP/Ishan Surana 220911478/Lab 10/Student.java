import java.util.Scanner;
class Details
{
    String name;
    long roll;
    int marks1;
    int marks2;
    int marks3;
    double percentage;
    char grade;
    Details()
    {
        Scanner csc=new Scanner(System.in);
        System.out.println("Enter name, roll no., and all 3 marks:-");
        name=csc.nextLine();
        roll=csc.nextLong();
        csc.nextLine();
        try
        {
            marks1=Integer.parseInt(csc.nextLine());
            if(marks1<0) 
            {
                NumberFormatException e=new NumberFormatException();
                throw e;
            }
            marks2=Integer.parseInt(csc.nextLine());
            if(marks2<0)
            {
                NumberFormatException e=new NumberFormatException();
                throw e;
            }
            marks3=Integer.parseInt(csc.nextLine());
            if(marks3<0)
            {
                NumberFormatException e=new NumberFormatException();
                throw e;
            }
            percentager();
            grader();
        }
        catch(NumberFormatException e)
        {
            System.out.println("Invalid Number!");
        }
    }
    void percentager()
    {
        percentage=(marks1+marks2+marks3)/3;
        System.out.println("Percentage = "+percentage);
    }
    void grader()
    {
        if(percentage>=90) grade='A';
        else if(percentage>=80) grade='B';
        else if(percentage>=70) grade='C';
        else if(percentage>=60) grade='D';
        else if(percentage>=50) grade='E';
        else grade='F';
        System.out.println("Grade = "+grade);
    }
}
class Student
{
    public static void main(String[] args)
    {
        Details s=new Details();
    }
}