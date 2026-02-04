#include <stdio.h>
#include <string.h>

#define MAX 100

struct student {
    int roll;
    char name[30];
    float marks;
};

struct student s[MAX];
int count = 0;

/* Function declarations */
void addStudent();
void displayStudents();
void searchStudent();
void updateMarks();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Marks\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateMarks(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void addStudent() {
    if (count < MAX) {
        printf("Enter Roll Number: ");
        scanf("%d", &s[count].roll);
        printf("Enter Name: ");
        scanf(" %[^\n]", s[count].name); // To read full name with spaces
        printf("Enter Marks: ");
        scanf("%f", &s[count].marks);
        count++;
        printf("Student added successfully!\n");
    } else {
        printf("Student list full!\n");
    }
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Student Found: Roll: %d, Name: %s, Marks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
            return;
        }
    }
    printf("Student not found!\n");
}

void updateMarks() {
    int roll;
    printf("Enter Roll Number to update marks: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Enter new marks for %s: ", s[i].name);
            scanf("%f", &s[i].marks);
            printf("Marks updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void deleteStudent() {
    int roll, i, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    for (i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < count - 1; j++) {
            s[j] = s[j + 1]; // Shift all students left
        }
        count--;
        printf("Student deleted successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}
