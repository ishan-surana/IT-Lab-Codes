import java.util.Scanner;

// Custom exception for negative marks
class NegativeMarkException extends Exception {
    public NegativeMarkException(String message) {
        super(message);
    }
}

// Custom exception for out-of-range marks
class OutOfRangeException extends Exception {
    public OutOfRangeException(String message) {
        super(message);
    }
}

// Interface for marks
interface Mark {
    void dispMark();
}

// Student class implementing the Mark interface
class Student implements Mark {
    String studentName;
    String regNo;
    String category;
    int[] marks = new int[3];
    double average;
    String grade;

    Student(String studentName, String regNo, String category) {
        this.studentName = studentName;
        this.regNo = regNo;
        this.category = category;
    }

    // Input method to read marks
    void input() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            try {
                System.out.print("Enter mark " + (i + 1) + ": ");
                int mark = scanner.nextInt();
                if (mark < 0) {
                    throw new NegativeMarkException("Negative marks are not allowed.");
                } else if (mark < 0 || mark > 100) {
                    throw new OutOfRangeException("Mark out of range (0-100).");
                }
                marks[i] = mark;
            } catch (NumberFormatException e) {
                System.err.println("Invalid input. Please enter a valid mark.");
                i--;
            } catch (NegativeMarkException e) {
                System.err.println(e.getMessage());
                i--;
            } catch (OutOfRangeException e) {
                System.err.println(e.getMessage());
                i--;
            }
        }
    }

    // Calculate average and grade
    void calculate() {
        int sum = 0;
        for (int mark : marks) {
            sum += mark;
        }
        average = (double) sum / marks.length;

        if (average >= 90) {
            grade = "A";
        } else if (average >= 80) {
            grade = "B";
        } else if (average >= 70) {
            grade = "C";
        } else if (average >= 60) {
            grade = "D";
        } else {
            grade = "F";
        }
    }

    // Display marks
    public void dispMark() {
        System.out.println("Student Name: " + studentName);
        System.out.println("Reg No: " + regNo);
        System.out.println("Category: " + category);
        System.out.println("Average Mark: " + average);
        System.out.println("Grade: " + grade);
    }
}

public class Q3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numStudents = scanner.nextInt();
        scanner.nextLine();
        Student[] students = new Student[numStudents];

        for (int i = 0; i < numStudents; i++) {
            System.out.println("Enter details for Student " + (i + 1));
            System.out.print("Name: ");
            String studentName = scanner.nextLine();
            System.out.print("Reg No: ");
            String regNo = scanner.nextLine();
            System.out.print("Category (UG/PG): ");
            String category = scanner.nextLine();

            Student student = new Student(studentName, regNo, category);
            student.input();
            student.calculate();
            students[i] = student;
        }

        System.out.println("Details of the first 3 toppers with highest average marks:");
        // Sort students by average marks (descending order)
        for (int i = 0; i < numStudents - 1; i++) {
            for (int j = 0; j < numStudents - i - 1; j++) {
                if (students[j].average < students[j + 1].average) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        int no=3;
        if(numStudents<3) no=numStudents;
        for (int i = 0; i<no; i++) {
            System.out.println();
            students[i].dispMark();
        }
    }
}
