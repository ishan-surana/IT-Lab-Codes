#include <stdio.h>
#include <string.h>

// Structure to represent a student record
struct StudentRecord {
    char name[50];
    int rollNo;
    char grade;
    char branch[50];
};

// Function to write student records to a text file
void writeStudentRecordsToFile(const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening the file %s.\n", fileName);
        return;
    }

    int numRecords;
    printf("Enter the number of student records: ");
    scanf("%d", &numRecords);

    struct StudentRecord student;

    // Write student records to the file
    for (int i = 0; i < numRecords; i++) {
        printf("Enter student name: ");
        scanf("%s", student.name);
        printf("Enter roll number: ");
        scanf("%d", &student.rollNo);
        printf("Enter grade: ");
        scanf(" %c", &student.grade);
        printf("Enter branch: ");
        scanf("%s", student.branch);

        fprintf(file, "%s %d %c %s\n", student.name, student.rollNo, student.grade, student.branch);
    }

    fclose(file);
}

// Function to read student records from a text file and store them branch-wise in separate files
void storeStudentRecordsByBranch(const char *inputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening the file %s.\n", inputFileName);
        return;
    }

    struct StudentRecord student;
    char branchFileName[50];

    while (fscanf(inputFile, "%s %d %c %s", student.name, &student.rollNo, &student.grade, student.branch) != EOF) {
        // Create a separate file for each branch
        snprintf(branchFileName, sizeof(branchFileName), "%s.txt", student.branch);
        FILE *branchFile = fopen(branchFileName, "a");
        if (branchFile == NULL) {
            printf("Error opening the file %s.\n", branchFileName);
            fclose(inputFile);
            return;
        }

        // Write the student record to the branch-specific file
        fprintf(branchFile, "%s %d %c %s\n", student.name, student.rollNo, student.grade, student.branch);
        fclose(branchFile);
    }

    fclose(inputFile);
}

int main() {
    const char *inputFileName = "student_records.txt";

    // Write student records to the text file
    writeStudentRecordsToFile(inputFileName);

    // Store student records branch-wise in separate files
    storeStudentRecordsByBranch(inputFileName);

    printf("Student records have been stored branch-wise in separate files.\n");

    return 0;
}
