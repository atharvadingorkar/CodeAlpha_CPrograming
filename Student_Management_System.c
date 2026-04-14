Task 3 : Student Management System

#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[30];
    float marks;
};

void addRecord() {
    FILE *fp;
    struct student s;
    fp = fopen("student.dat", "ab");

    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Record added successfully\n");
}

void displayRecord() {
    FILE *fp;
    struct student s;
    fp = fopen("student.dat", "rb");

    printf("\nStudent Records:\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll: %d  Name: %s  Marks: %.2f\n", s.roll, s.name, s.marks);
    }
    fclose(fp);
}

void searchRecord() {
    FILE *fp;
    struct student s;
    int roll, found = 0;

    fp = fopen("student.dat", "rb");
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Record Found: %d %s %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Record not found\n");
}

void updateRecord() {
    FILE *fp;
    struct student s;
    int roll, found = 0;

    fp = fopen("student.dat", "rb+");
    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Enter new name: ");
            scanf("%s", s.name);
            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found)
        printf("Record updated successfully\n");
    else
        printf("Record not found\n");
}

void deleteRecord() {
    FILE *fp, *temp;
    struct student s;
    int roll;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll != roll)
            fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    printf("Record deleted successfully\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecord(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}