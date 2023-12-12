//Implement a student database system using a file. Include features to add, delete, modify,
and display student records.

#include <stdio.h>
#include <stdlib.h>
struct Detail {
    int id;
    char name[50];
    int age;
    float grade;
};
void add();
void display();
void deleteStudent(int studentId);
void modify(int studentId);
int main() {
    int choice;
    do {
        printf("\nStudent Database System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Modify Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                {
                    int studentId;
                    printf("Enter student ID to delete: ");
                    if (scanf("%d", &studentId) != 1) {
                        printf("Invalid input. Please enter a number.\n");
                        while (getchar() != '\n');  // Clear the input buffer
                        continue;
                    }
                    deleteStudent(studentId);
                }
                break;
            case 4:
                {
                    int studentId;
                    printf("Enter student ID to modify: ");
                    if (scanf("%d", &studentId) != 1) {
                        printf("Invalid input. Please enter a number.\n");
                        while (getchar() != '\n');  // Clear the input buffer
                        continue;
                    }
                    modify(studentId);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
void add() {
    FILE* fileptr = fopen("students.txt", "a");
    if (fileptr == NULL) {
        perror("Error opening file");
        return;
    }
    struct Detail st;
    printf("Enter student ID: ");
    scanf("%d", &st.id);
    printf("Enter student name: ");
    scanf("%s", st.name);
    printf("Enter student age: ");
    scanf("%d", &st.age);
    printf("Enter student grade: ");
    scanf("%f", &st.grade);
    fprintf(fileptr, "%d %s %d %.2f\n", st.id, st.name, st.age, st.grade);
    fclose(fileptr);
    printf("Student added successfully.\n");
}
void display() {
    struct Detail student;
    FILE* fileptr = fopen("students.txt", "r");
    if (fileptr == NULL) {
        perror("Error opening file");
        return;
    }
    printf("\nStudent Records:\n");
    printf("ID\tName\tAge\tGrade\n");
    while (fscanf(fileptr, "%d %s %d %f", &student.id, student.name, &student.age, &student.grade) != EOF) {
        printf("%d\t%s\t%d\t%.2f\n", student.id, student.name, student.age, student.grade);
    }
    fclose(fileptr);
}
void deleteStudent(int studentId) {
    FILE* fileptr = fopen("students.txt", "r");
    FILE* tempFile = fopen("temp.txt", "w");
    struct Detail student;
    int found = 0;
    while (fscanf(fileptr, "%d %s %d %f", &student.id, student.name, &student.age, &student.grade) != EOF) {
        if (student.id != studentId) {
            fprintf(tempFile, "%d %s %d %.2f\n", student.id, student.name, student.age, student.grade);
        } else {
            found = 1;
        }
    }
    fclose(fileptr);
    fclose(tempFile);
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        printf("Student with ID %d deleted successfully.\n", studentId);
    } else {
        printf("Student with ID %d not found.\n", studentId);
    }
}
void modify(int studentId) {
    FILE* fileptr = fopen("students.txt", "r");
    FILE* tempFile = fopen("temp.txt", "w");
    struct Detail student;
    int found = 0;
    while (fscanf(fileptr, "%d %s %d %f", &student.id, student.name, &student.age, &student.grade) != EOF) {
        if (student.id == studentId) {
            printf("Enter new information for student ID %d:\n", studentId);
            printf("Name: ");
            scanf("%s", student.name);
            printf("Age: ");
            scanf("%d", &student.age);
            printf("Grade: ");
            scanf("%f", &student.grade);
            found = 1;
        }

        fprintf(tempFile, "%d %s %d %.2f\n", student.id, student.name, student.age, student.grade);
    }
    fclose(fileptr);
    fclose(tempFile);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found) {
        printf("Student with ID %d modified successfully.\n", studentId);
    } else {
        printf("Student with ID %d not found.\n", studentId);
    }
}