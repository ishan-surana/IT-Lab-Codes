import java.util.*;
class SortUtility<T extends Comparable<T>> {
    T[] data;

    SortUtility(T[] data) {
        this.data = data;
    }

    void sort() {
        Arrays.sort(data);
    }

    void display() {
        for (T item : data) {
            System.out.println(item);
        }
    }
}

class Employee implements Comparable<Employee> {
    String name;
    int YoE;

    Employee(String name, int YoE) {
        this.name = name;
        this.YoE = YoE;
    }

    public int compareTo(Employee other) {
        return Integer.compare(this.YoE, other.YoE);
    }

    public String toString() {
        return "Employee details:-\n\tName = "+ name+"\n\tYoE = " + YoE;
    }
}

class Student implements Comparable<Student> {
    private String name;
    private String grade;

    Student(String name, String grade) {
        this.name = name;
        this.grade = grade;
    }

    public int compareTo(Student other) {
        return this.grade.compareTo(other.grade);
    }

    public String toString() {
        return "Student details:-\n\tName = "+ name+"\n\tGrade = " + grade;
    }
}

class Q1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number of employees: ");
        int numEmployees = sc.nextInt();
        sc.nextLine();

        Employee[] employees = new Employee[numEmployees];
        for (int i = 0; i < numEmployees; i++) {
            System.out.println("Enter details for Employee " + (i + 1));
            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Years of Experience (YoE): ");
            int YoE = sc.nextInt();
            sc.nextLine();
            employees[i] = new Employee(name, YoE);
        }
        
        System.out.print("\nEnter the number of students: ");
        int numStudents = sc.nextInt();
        sc.nextLine(); // Consume newline

        Student[] students = new Student[numStudents];
        for (int i = 0; i < numStudents; i++) {
            System.out.println("Enter details for Student " + (i + 1));
            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Grade: ");
            String grade = sc.nextLine();
            students[i] = new Student(name, grade);
        }

        SortUtility<Employee> employeeSorter = new SortUtility<>(employees);
        SortUtility<Student> studentSorter = new SortUtility<>(students);

        System.out.println("\nEmployees before sorting:");
        employeeSorter.display();
        employeeSorter.sort();
        System.out.println("Employees after sorting:");
        employeeSorter.display();
        System.out.println("\n\nStudents before sorting:");
        studentSorter.display();
        studentSorter.sort();
        System.out.println("Students after sorting:");
        studentSorter.display();
    }
}
