/*
 * Project Title: Student Management System
 * Student Name:  Vishal Chauchan
 * Language:      C Programming
 * Description:   A menu-driven system for managing student records using 
 *                binary file handling for persistent data storage.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Student {
    int id;
    char name[50];
    char father_name[50];
    char mother_name[50];
    char phone[15];
    char address[100];
    char subject[50];
    char project[100];
    int year;
    int semester;
    float fees;
    float cgpa;
    float fine;
    float attendance;
};

// Function prototypes
void addStudent();
void displayAll();
void searchStudent();
void modifyStudent();
void deleteStudent();
void clearInputBuffer();

const char *FILENAME = "students.dat";

int main() {
    int choice;

    while (1) {
        printf("\n=========================================");
        printf("\n       STUDENT MANAGEMENT SYSTEM         ");
        printf("\n=========================================");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student by ID");
        printf("\n4. Modify Student Record");
        printf("\n5. Delete Student Record");
        printf("\n6. Exit");
        printf("\n=========================================");
        printf("\nEnter your choice: ");
        
        int res = scanf("%d", &choice);
        if (res == EOF) {
            printf("\nExiting system due to EOF.\n");
            exit(0);
        } else if (res != 1) {
            printf("\n[Error] Invalid input. Please enter a number (1-6).\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: 
                printf("\nExiting system. Thank you for using Student Management System!\n");
                exit(0);
            default:
                printf("\n[Error] Invalid choice. Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addStudent() {
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("\n[Error] Could not open file for writing.\n");
        return;
    }

    struct Student s;
    printf("\n--- Add New Student Record ---");
    printf("\nEnter Student ID (Numeric): ");
    if (scanf("%d", &s.id) != 1) {
        printf("\n[Error] Invalid ID format.\n");
        clearInputBuffer();
        fclose(fp);
        return;
    }
    clearInputBuffer();

    printf("Enter Full Name: ");
    if (fgets(s.name, 50, stdin)) s.name[strcspn(s.name, "\n")] = 0;
    
    printf("Enter Father's Name: ");
    if (fgets(s.father_name, 50, stdin)) s.father_name[strcspn(s.father_name, "\n")] = 0;
    
    printf("Enter Mother's Name: ");
    if (fgets(s.mother_name, 50, stdin)) s.mother_name[strcspn(s.mother_name, "\n")] = 0;
    
    printf("Enter Phone Number: ");
    if (fgets(s.phone, 15, stdin)) s.phone[strcspn(s.phone, "\n")] = 0;
    
    printf("Enter Home Address: ");
    if (fgets(s.address, 100, stdin)) s.address[strcspn(s.address, "\n")] = 0;
    
    printf("Enter Subject/Major: ");
    if (fgets(s.subject, 50, stdin)) s.subject[strcspn(s.subject, "\n")] = 0;
    
    printf("Enter Assigned Project: ");
    if (fgets(s.project, 100, stdin)) s.project[strcspn(s.project, "\n")] = 0;
    
    printf("Enter Academic Year: ");
    scanf("%d", &s.year);
    
    printf("Enter Semester: ");
    scanf("%d", &s.semester);
    
    printf("Enter Tuition Fees: ");
    scanf("%f", &s.fees);
    
    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);
    
    printf("Enter Pending Fines: ");
    scanf("%f", &s.fine);
    
    printf("Enter Attendance Percentage: ");
    scanf("%f", &s.attendance);
    clearInputBuffer();

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("\n[Success] Student record for '%s' (ID: %d) added successfully!\n", s.name, s.id);
}

void displayAll() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\n[Info] No records found. Please add a student first.\n");
        return;
    }

    struct Student s;
    int count = 0;
    printf("\n===============================================================================================");
    printf("\n                                    ALL STUDENT RECORDS                                        ");
    printf("\n===============================================================================================");
    printf("\n%-5s %-20s %-15s %-15s %-6s %-4s %-4s %-6s", "ID", "Name", "Phone", "Subject", "CGPA", "Year", "Sem", "Attn%");
    printf("\n-----------------------------------------------------------------------------------------------");
    
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("\n%-5d %-20s %-15s %-15s %-6.2f %-4d %-4d %-6.2f", 
               s.id, s.name, s.phone, s.subject, s.cgpa, s.year, s.semester, s.attendance);
        count++;
    }
    printf("\n\n-----------------------------------------------------------------------------------------------");
    printf("\nTotal Records: %d", count);
    printf("\n===============================================================================================\n");
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\n[Error] No records available to search.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Student ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("\n[Error] Invalid ID input.\n");
        clearInputBuffer();
        fclose(fp);
        return;
    }
    clearInputBuffer();

    struct Student s;
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.id == id) {
            found = 1;
            printf("\n-----------------------------------------");
            printf("\n         STUDENT PROFILE (ID: %d)       ", s.id);
            printf("\n-----------------------------------------");
            printf("\nName          : %s", s.name);
            printf("\nFather's Name : %s", s.father_name);
            printf("\nMother's Name : %s", s.mother_name);
            printf("\nPhone         : %s", s.phone);
            printf("\nAddress       : %s", s.address);
            printf("\nSubject       : %s", s.subject);
            printf("\nProject       : %s", s.project);
            printf("\nYear/Semester : Year %d, Sem %d", s.year, s.semester);
            printf("\nFees/Fine     : Fees: %.2f, Fine: %.2f", s.fees, s.fine);
            printf("\nPerformance   : CGPA: %.2f, Attendance: %.2f%%", s.cgpa, s.attendance);
            printf("\n-----------------------------------------\n");
            break;
        }
    }
    if (!found) printf("\n[Error] Student with ID %d was not found in our records.\n", id);
    fclose(fp);
}

void modifyStudent() {
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        printf("\n[Error] No records available to modify.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Student ID to modify: ");
    if (scanf("%d", &id) != 1) {
        printf("\n[Error] Invalid ID input.\n");
        clearInputBuffer();
        fclose(fp);
        return;
    }
    clearInputBuffer();

    struct Student s;
    long size = sizeof(struct Student);
    
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.id == id) {
            found = 1;
            printf("\n[Match Found] Modifying records for: %s (ID: %d)", s.name, s.id);
            
            printf("\nUpdate Name: ");
            if (fgets(s.name, 50, stdin)) s.name[strcspn(s.name, "\n")] = 0;
            
            printf("Update Phone: ");
            if (fgets(s.phone, 15, stdin)) s.phone[strcspn(s.phone, "\n")] = 0;
            
            printf("Update Subject: ");
            if (fgets(s.subject, 50, stdin)) s.subject[strcspn(s.subject, "\n")] = 0;
            
            printf("Update CGPA: ");
            scanf("%f", &s.cgpa);
            
            printf("Update Attendance %%: ");
            scanf("%f", &s.attendance);
            clearInputBuffer();
            
            fseek(fp, -size, SEEK_CUR);
            fwrite(&s, sizeof(struct Student), 1, fp);
            printf("\n[Success] Record for ID %d updated successfully.\n", id);
            break;
        }
    }
    if (!found) printf("\n[Error] Student ID %d not found.\n", id);
    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\n[Error] No records available to delete.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Student ID to DELETE permanently: ");
    if (scanf("%d", &id) != 1) {
        printf("\n[Error] Invalid ID input.\n");
        clearInputBuffer();
        fclose(fp);
        return;
    }
    clearInputBuffer();

    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("\n[Error] System error: could not create temporary file.\n");
        fclose(fp);
        return;
    }

    struct Student s;
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.id == id) {
            found = 1;
        } else {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.dat", FILENAME);
        printf("\n[Success] Student ID %d has been permanently removed.\n", id);
    } else {
        remove("temp.dat");
        printf("\n[Error] Record with ID %d not found.\n", id);
    }
}
