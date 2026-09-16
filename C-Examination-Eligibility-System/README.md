# University Examination Eligibility and Result Processing System

## Group 1

### Group Members
1. **FRANKLINE ANTONY TUMAINI** — C026-01-0984/2025
2. **LEVY JUMA** — C026-01-0977/2025
3. **Vessly Clement** — C026-01-0938/2025

## System Description

The University Examination Eligibility and Result Processing System is a C-based system that checks whether students meet the requirements to sit for university examinations and processes their examination results.

The system stores student information using a structure, validates marks, checks examination eligibility, calculates total marks, assigns grades, displays results, calculates basic statistics, and runs tests.

## Eligibility Rules

A student is eligible when:

- The fee balance is zero.
- An examination card is available.
- The student has registered for between 4 and 8 units.
- The student has no disciplinary restriction.
- The marks entered are within the permitted ranges.

## Mark Ranges

- CAT: 0–30
- Practical: 0–20
- Examination: 0–50
- Maximum total: 100

## Grading

| Total | Grade |
|---|---|
| 70–100 | A |
| 60–69 | B |
| 50–59 | C |
| 40–49 | D |
| Below 40 | F |

## How the System Works

1. A dynamic dataset of students is created using `malloc`.
2. Each student's information is stored in a `Student` structure.
3. Marks are validated.
4. Examination eligibility is checked using the fee, examination-card, unit, and disciplinary conditions.
5. CAT, practical, and examination marks are added to obtain the total.
6. A grade is assigned according to the total mark.
7. Student results are displayed.
8. Basic statistics are calculated.
9. Tests demonstrate important system conditions and C programming concepts.
10. Dynamically allocated memory is released using `free`.

## Programming Language

**C**

## Programming Language Concepts Demonstrated

### Variable Attributes
The program uses different variables with different data types and storage characteristics.

### Named Constants
`#define` is used for fixed values such as `MIN_UNITS`, `MAX_UNITS`, `MAX_CAT`, and `PASS_MARK`.

### L-values and R-values
The program demonstrates the difference between an l-value, which identifies a storage location, and an r-value, which represents a value used in an expression.

### Aliasing and Pointers
`moderateMark` receives a pointer to a mark, allowing a function to modify the original value. Pointer aliasing is also demonstrated in the tests.

### Scope
The program contains global and local variables. `systemVersion` is global while variables inside functions have local/block scope.

### Static Storage
The global variable `systemVersion` has static storage duration.

### Dynamic Storage
Student records are dynamically allocated using `malloc` and released using `free`.

### Structures
The `Student` structure groups related student information into one data type.

### Modularity
The program is divided into functions such as `validateMarks`, `checkEligibility`, `processStudent`, `displayStudentResult`, and `calculateStatistics`.

### Testing
The `runTests` function checks valid marks, maximum marks, the pass mark, invalid CAT marks, invalid unit registration, and pointer aliasing.

## Compilation and Execution

Using GCC:

```bash
gcc main.c -o examination_system
./examination_system
```

On Windows:

```bash
examination_system.exe
```
