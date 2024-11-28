#include <stdio.h>

// Structure to hold student details
struct Student {
    int rollNumber;
    char name[100];
    int totalMarks;
};

int main() {
    FILE *file = fopen("LNMIITSTUDENT.DAT", "a");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    int n;
    printf("Enter the number of students to append: ");
    scanf("%d", &n);

    struct Student students[n];

    // Read student details and append to file
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Total Marks: ");
        scanf("%d", &students[i].totalMarks);

        fprintf(file, "Roll Number: %d\nName: %s\nTotal Marks: %d\n\n", students[i].rollNumber, students[i].name, students[i].totalMarks);
    }

    fclose(file);
    return 0;
}