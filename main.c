#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUBJECTS 5

struct Student {
    int rollNo;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float average;
    char grade;
};

struct Student s[MAX];
int count = 0;

// Calculate Grade
char calculateGrade(float average) {
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

// Add Student
void addStudent() {
    int i, roll;

    if (count >= MAX) {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {
            printf("\nRoll Number Already Exists!\n");
            return;
        }
    }

    s[count].rollNo = roll;

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s[count].name);

    s[count].total = 0;

    for (i = 0; i < SUBJECTS; i++) {
        printf("Enter Marks of Subject %d: ", i + 1);
        scanf("%f", &s[count].marks[i]);

        if (s[count].marks[i] < 0 || s[count].marks[i] > 100) {
            printf("Invalid Marks! Enter marks between 0 and 100.\n");
            return;
        }

        s[count].total += s[count].marks[i];
    }

    s[count].average = s[count].total / SUBJECTS;

    s[count].grade = calculateGrade(s[count].average);

    count++;

    printf("\nStudent Added Successfully!\n");
}

// Display All Students
void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    for (i = 0; i < count; i++) {
        printf("\nRoll Number: %d", s[i].rollNo);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Marks: %.2f", s[i].total);
        printf("\nAverage: %.2f", s[i].average);
        printf("\nGrade: %c\n", s[i].grade);
    }
}

// Search Student
void searchStudent() {
    int roll, i;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", s[i].name);
            printf("Total Marks: %.2f\n", s[i].total);
            printf("Average: %.2f\n", s[i].average);
            printf("Grade: %c\n", s[i].grade);
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n===== STUDENT GRADE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Total Students\n");
        printf("0. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("\nTotal Students: %d\n", count);
                break;

            case 0:
                printf("\nThank You for Using Our Project!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 0);

    return 0;
}
