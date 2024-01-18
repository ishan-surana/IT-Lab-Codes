import java.util.Scanner;

class Student_Detail {

    String name;
    long id;
    String college_name;
    static int count = 0;

    void set() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name:- ");
        name = sc.nextLine();
        System.out.println("Enter college name:- ");
        college_name = sc.nextLine();
        System.out.println("Enter college id:- ");
        id = sc.nextLong();

    }

    void display() {
        System.out.println("Name = " + name);
        System.out.println("College id = " + id);
        System.out.println("College name = " + college_name);
    }
}

class Student_Record_Count {
    public static void main(String args[]) {
        Student_Detail arr[] = new Student_Detail[2];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new Student_Detail();
            System.out.println("Enter details for student " + (i + 1) + ":-");
            arr[i].set();
            Student_Detail.count++;
        }
        System.out.println("Details of the students are as follows:-\n");
        for (int j = 0; j < arr.length; j++) {
            System.out.println("\nSTUDENT " + (j + 1) + ":-");
            arr[j].display();
        }
        System.out.println("\n\nNumber of objects = " + Student_Detail.count);
    }
}