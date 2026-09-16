#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_UNITS 4
#define MAX_UNITS 8
#define MAX_CAT 30
#define MAX_PRACTICAL 20
#define MAX_EXAM 50
#define PASS_MARK 50
#define MIN_STUDENTS 5

int systemVersion = 1;

typedef struct {
    char name[100];
    char registrationNumber[30];
    int registeredUnits;
    float catMark;
    float practicalMark;
    float examMark;
    float total;
    char grade;
    float feeBalance;
    int examCardAvailable;
    int disciplinaryRestriction;
    int eligible;
} Student;

int validateMarks(const Student *s) {
    return s->catMark >= 0 && s->catMark <= MAX_CAT &&
           s->practicalMark >= 0 && s->practicalMark <= MAX_PRACTICAL &&
           s->examMark >= 0 && s->examMark <= MAX_EXAM;
}

void moderateMark(float *mark, float adjustment) {
    *mark += adjustment;
    if (*mark < 0) *mark = 0;
    if (*mark > MAX_CAT) *mark = MAX_CAT;
}

void demonstrateLValueRValue(void) {
    int x = 10;
    int *ptr = &x;
    int y = x + 5;
    printf("\nL-value/R-value demonstration:\n");
    printf("x is an l-value; x + 5 is an r-value; *ptr refers to the value stored at x.\n");
    printf("y = %d, *ptr = %d\n", y, *ptr);
}

void demonstrateScope(void) {
    int localVersion = systemVersion;
    printf("\nScope demonstration: global systemVersion = %d, localVersion = %d\n",
           systemVersion, localVersion);
}

int checkEligibility(const Student *s) {
    return s->feeBalance == 0 &&
           s->examCardAvailable &&
           s->registeredUnits >= MIN_UNITS &&
           s->registeredUnits <= MAX_UNITS &&
           !s->disciplinaryRestriction;
}

void processStudent(Student *s) {
    if (!validateMarks(s)) {
        s->eligible = 0;
        s->total = 0;
        s->grade = 'F';
        return;
    }

    s->eligible = checkEligibility(s);
    s->total = s->catMark + s->practicalMark + s->examMark;

    if (s->total >= 70)
        s->grade = 'A';
    else if (s->total >= 60)
        s->grade = 'B';
    else if (s->total >= PASS_MARK)
        s->grade = 'C';
    else if (s->total >= 40)
        s->grade = 'D';
    else
        s->grade = 'F';
}

Student *createStudentDataset(int count) {
    Student *students = malloc(count * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    Student sample[MIN_STUDENTS] = {
        {"FRANKLINE ANTONY TUMAINI", "C026-01-0984/2025", 6, 25, 18, 42, 0, 'F', 0, 1, 0, 0},
        {"LEVY JUMA", "C026-01-0977/2025", 5, 24, 17, 40, 0, 'F', 0, 1, 0, 0},
        {"Vessly Clement", "C026-01-0938/2025", 7, 28, 19, 45, 0, 'F', 0, 1, 0, 0},
        {"Sample Student 4", "TEST/004", 4, 20, 15, 35, 0, 'F', 0, 1, 0, 0},
        {"Sample Student 5", "TEST/005", 8, 27, 18, 44, 0, 'F', 0, 1, 0, 0}
    };

    for (int i = 0; i < count; i++)
        students[i] = sample[i % MIN_STUDENTS];

    return students;
}

void displayStudentResult(const Student *s) {
    printf("\nName: %s\n", s->name);
    printf("Registration Number: %s\n", s->registrationNumber);
    printf("Registered Units: %d\n", s->registeredUnits);
    printf("CAT Mark: %.2f\n", s->catMark);
    printf("Practical Mark: %.2f\n", s->practicalMark);
    printf("Exam Mark: %.2f\n", s->examMark);
    printf("Total: %.2f\n", s->total);
    printf("Grade: %c\n", s->grade);
    printf("Fee Balance: %.2f\n", s->feeBalance);
    printf("Exam Card: %s\n", s->examCardAvailable ? "Available" : "Not Available");
    printf("Disciplinary Restriction: %s\n", s->disciplinaryRestriction ? "Yes" : "No");
    printf("Examination Eligibility: %s\n", s->eligible ? "Eligible" : "Not Eligible");
}

void calculateStatistics(const Student *students, int count) {
    float totalMarks = 0;
    int passed = 0;

    for (int i = 0; i < count; i++) {
        totalMarks += students[i].total;
        if (students[i].total >= PASS_MARK)
            passed++;
    }

    printf("\n--- Statistics ---\n");
    printf("Number of students: %d\n", count);
    printf("Average total mark: %.2f\n", totalMarks / count);
    printf("Students with total >= %d: %d\n", PASS_MARK, passed);
}

void runTests(void) {
    printf("\n--- System Tests ---\n");

    Student valid = {"Test Student", "TEST/001", 4, 30, 20, 50, 0, 'F', 0, 1, 0, 0};
    processStudent(&valid);
    printf("Valid/max marks test: %s\n", validateMarks(&valid) ? "PASS" : "FAIL");
    printf("Total calculation test: %s\n", valid.total == 100 ? "PASS" : "FAIL");

    Student exactPass = {"Pass Mark Test", "TEST/002", 4, 15, 10, 25, 0, 'F', 0, 1, 0, 0};
    processStudent(&exactPass);
    printf("Exact pass mark test: %s\n", exactPass.total == 50 && exactPass.grade == 'C' ? "PASS" : "FAIL");

    Student invalidCat = {"Invalid CAT", "TEST/003", 4, 31, 10, 30, 0, 'F', 0, 1, 0, 0};
    printf("Invalid CAT test: %s\n", !validateMarks(&invalidCat) ? "PASS" : "FAIL");

    Student invalidUnits = {"Invalid Units", "TEST/004", 3, 20, 10, 30, 0, 'F', 0, 1, 0, 0};
    processStudent(&invalidUnits);
    printf("Invalid units eligibility test: %s\n", !invalidUnits.eligible ? "PASS" : "FAIL");

    float mark = 20;
    float *alias = &mark;
    *alias += 5;
    printf("Pointer aliasing test: %s\n", mark == 25 ? "PASS" : "FAIL");
}

int main(void) {
    printf("UNIVERSITY EXAMINATION ELIGIBILITY AND RESULT PROCESSING SYSTEM\n");
    printf("System Version: %d\n", systemVersion);

    Student *students = createStudentDataset(MIN_STUDENTS);

    for (int i = 0; i < MIN_STUDENTS; i++) {
        processStudent(&students[i]);
        displayStudentResult(&students[i]);
    }

    calculateStatistics(students, MIN_STUDENTS);
    demonstrateLValueRValue();
    demonstrateScope();
    runTests();

    free(students);
    return 0;
}
