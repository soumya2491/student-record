
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void add_student() {
    FILE *fp = fopen("students.txt", "a");
    Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
}

void view_students() {
    FILE *fp = fopen("students.txt", "r");
    Student s;
    printf("\nAll Students:\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks);
    }
    fclose(fp);
}

void search_student() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    FILE *fp = fopen("students.txt", "r");
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll) {
            printf("Found: Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found!\n");
    fclose(fp);
}

void delete_student() {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll != roll) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found)
        printf("Student deleted successfully.\n");
    else
        printf("Student not found!\n");
}
