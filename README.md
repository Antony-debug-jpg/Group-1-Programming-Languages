# GROUP 1 – PROGRAMMING LANGUAGES

## DEDAN KIMATHI UNIVERSITY OF TECHNOLOGY

This repository contains two Programming Languages projects developed by Group 1.

---

# GROUP MEMBERS

| No. | Name | Registration Number |
|---|---|---|
| 1 | FRANKLINE ANTONY TUMAINI | C026-01-0984/2025 |
| 2 | LEVY JUMA | C026-01-0977/2025 |
| 3 | Vessly Clement | C026-01-0938/2025 |

---

# PROJECT 1: UNIVERSITY EXAMINATION ELIGIBILITY AND RESULT PROCESSING SYSTEM

## Programming Language
C

## 1. INTRODUCTION

The University Examination Eligibility and Result Processing System is a C programming project designed to demonstrate the application of programming language concepts in a university examination and result-processing environment.

The system processes student information, checks examination eligibility, validates marks, calculates total marks, assigns grades, displays student results, calculates statistics, and performs system tests.

The project also demonstrates important C programming concepts including structures, functions, pointers, pointer aliasing, L-values and R-values, scope, storage concepts, dynamic memory allocation, modularity, validation, and testing.

## 2. PROBLEM STATEMENT

A university needs to determine whether students are eligible to sit for examinations before their examination results are processed.

Eligibility depends on conditions such as fee clearance, examination card availability, the number of registered units, and disciplinary restrictions.

The system provides a programmatic approach for checking these conditions and processing student examination results.

## 3. OBJECTIVES

The objectives of the system are to:

- Process student information.
- Check examination eligibility.
- Validate student marks.
- Calculate total marks.
- Assign grades.
- Display student results.
- Calculate statistics.
- Demonstrate C programming concepts.
- Demonstrate pointer aliasing.
- Demonstrate L-values and R-values.
- Demonstrate variable scope.
- Demonstrate dynamic memory allocation.
- Perform system tests.

## 4. SYSTEM CONSTANTS

The program uses named constants for important system requirements.

| Constant | Value | Description |
|---|---:|---|
| MIN_UNITS | 4 | Minimum number of registered units |
| MAX_UNITS | 8 | Maximum number of registered units |
| MAX_CAT | 30 | Maximum CAT mark |
| MAX_PRACTICAL | 20 | Maximum practical mark |
| MAX_EXAM | 50 | Maximum examination mark |
| PASS_MARK | 50 | Pass mark |
| MIN_STUDENTS | 5 | Minimum number of students |

The program also maintains a system version variable.

## 5. STUDENT DATA

The program uses a `Student` structure to store information about each student.

The structure contains:

- Student name
- Registration number
- Number of registered units
- CAT mark
- Practical mark
- Examination mark
- Total mark
- Grade
- Fee balance
- Examination card availability
- Disciplinary restriction
- Eligibility status

## 6. EXAMINATION ELIGIBILITY

The system checks the following conditions:

1. The student's fee balance must be zero.
2. The student must have an examination card.
3. The student must have registered between 4 and 8 units.
4. The student must not have a disciplinary restriction.

A student who satisfies the required conditions is considered eligible for the examination.

## 7. MARKS VALIDATION

The program validates the examination marks before processing the student's result.

The maximum marks are:

| Component | Maximum Marks |
|---|---:|
| CAT | 30 |
| Practical | 20 |
| Examination | 50 |
| Total | 100 |

The total mark is calculated as:

Total = CAT + Practical + Examination

## 8. GRADING SYSTEM

| Total Marks | Grade |
|---|---|
| 70 – 100 | A |
| 60 – 69 | B |
| 50 – 59 | C |
| 40 – 49 | D |
| Below 40 | F |

The pass mark used by the system is 50.

## 9. MAIN FUNCTIONS

### processStudent()

Processes the information and result of a student.

### checkEligibility()

Checks whether a student satisfies the examination eligibility requirements.

### validateMarks()

Validates CAT, practical, and examination marks.

### moderateMark()

Demonstrates modification of a mark using a pointer.

### demonstrateLValueRValue()

Demonstrates the difference between L-values and R-values.

### demonstrateScope()

Demonstrates variable scope.

### createStudentDataset()

Creates the student dataset using dynamic memory allocation.

### displayStudentResult()

Displays the student's processed examination result.

### calculateStatistics()

Calculates statistics from the student dataset.

### runTests()

Runs the tests included in the system.

## 10. C PROGRAMMING CONCEPTS DEMONSTRATED

### Variables and Data Types

Variables are used to store student information, marks, totals, grades, eligibility information, and other system data.

### Named Constants

Named constants are used for values such as minimum units, maximum marks, and the pass mark.

### Structures

The `Student` structure groups related student information into one data structure.

### Functions

The system is divided into multiple functions to improve modularity and organization.

### Pointers

Pointers are used to work with memory addresses and demonstrate modification of values through references.

### Pointer Aliasing

Pointer aliasing is demonstrated by allowing a pointer to refer to an existing variable and modify its value.

### L-values and R-values

The project demonstrates the distinction between L-values, which identify storage locations, and R-values, which represent values.

### Scope

The project demonstrates variable scope including global, local, and block-level scope.

### Storage Concepts

The project demonstrates static storage and dynamic storage concepts.

### Dynamic Memory Allocation

Dynamic memory allocation is used to create the student dataset.

### Validation

The program validates marks and student information before processing.

### Testing

The program contains tests for valid and boundary cases as well as pointer aliasing.

## 11. SYSTEM WORKFLOW

START
  |
  v
Create Student Dataset
  |
  v
Process Student Information
  |
  v
Validate Student Data
  |
  v
Check Examination Eligibility
  |
  +---- Not Eligible ----> Display Eligibility Status
  |
  v
Validate Marks
  |
  v
Calculate Total
  |
  v
Assign Grade
  |
  v
Display Student Result
  |
  v
Calculate Statistics
  |
  v
Run Tests
  |
  v
END

## 12. TESTING

The system includes tests for:

- Valid marks.
- Maximum marks.
- Exact pass mark.
- Invalid CAT marks.
- Invalid number of registered units.
- Pointer aliasing.

## 13. C PROJECT FILES

C-Examination-Eligibility-System/
├── main.c
└── README.md

The main source code is contained in `main.c`.

---

# PROJECT 2: MATATU TERMINUS SCHEDULER

## Programming Language
Lua

## 1. INTRODUCTION

The Matatu Terminus Scheduler is a Lua programming project designed to demonstrate the use of Lua coroutines and cooperative scheduling.

The system models four matatu routes and manages passenger boarding, waiting passengers, and route departures.

The four routes are:

- Rongai
- Thika
- Ngong
- Kitengela

Each route maintains its own passenger and waiting state and is managed using a coroutine.

## 2. PROBLEM STATEMENT

A busy matatu terminus may have several routes operating continuously.

The project demonstrates how Lua coroutines can be used to manage different routes while allowing the routes to share execution through cooperative scheduling.

The scheduler processes each route in a round-robin sequence.

## 3. OBJECTIVES

The objectives of the system are to:

- Demonstrate Lua coroutines.
- Create a coroutine for each route.
- Manage passenger boarding.
- Track waiting passengers.
- Determine when a matatu should depart.
- Demonstrate cooperative scheduling.
- Demonstrate round-robin scheduling.
- Check coroutine status.
- Handle coroutine execution errors.
- Display the final state of each route.

## 4. ROUTE DATA

The system contains four routes:

- Rongai
- Thika
- Ngong
- Kitengela

Each route begins with:

- Passengers = 0
- Waiting = 0

Each route is represented using a Lua table.

## 5. ROUTE COROUTINES

A coroutine is created for every route using the route coroutine creation function.

The coroutine continuously waits for a command from the scheduler.

The coroutine uses:

`coroutine.yield()`

to pause its execution and return control to the scheduler.

The scheduler can later resume the coroutine and provide a command.

## 6. BOARD COMMAND

When a route receives the `"board"` command:

- The passenger count increases by 1.
- The waiting count is reset.
- The current passenger state is displayed.

The operation represents a passenger boarding a matatu on the selected route.

## 7. WAIT COMMAND

When a route receives the `"wait"` command:

- The waiting count increases by 1.
- The current waiting cycle is displayed.

This represents a route waiting for additional passengers or another scheduling opportunity.

## 8. DEPARTURE CONDITIONS

A route can depart under two conditions.

### Condition 1: Passenger Capacity

A route departs when:

Passengers >= 8

When this happens:

- A departure message is displayed.
- Passenger count is reset to 0.
- Waiting count is reset to 0.

### Condition 2: Waiting Condition

A route also departs when:

Waiting > 3

AND

Passengers >= 5

After departure, both passenger and waiting counts are reset.

## 9. COROUTINE MANAGEMENT

The system creates a separate coroutine for each route and stores the coroutines in a route-coroutine collection.

The status of a coroutine is checked using:

`coroutine.status()`

A coroutine is resumed using:

`coroutine.resume()`

The coroutine can yield control using:

`coroutine.yield()`

These operations allow the scheduler to control the execution of each route.

## 10. ROUND-ROBIN SCHEDULING

The scheduler uses a round-robin approach.

The routes are processed in the following order:

Rongai
   ↓
Thika
   ↓
Ngong
   ↓
Kitengela
   ↓
Rongai
   ↓
...

After Kitengela is processed, the scheduler returns to Rongai.

This allows every route to receive an opportunity to execute.

## 11. SCHEDULING LOGIC

The scheduler maintains the current route.

For every scheduling cycle, the scheduler checks the passenger count.

If:

Passengers < 5

the scheduler sends:

`"board"`

If:

Passengers >= 5

the scheduler sends:

`"wait"`

The selected command is then sent to the route coroutine.

## 12. COROUTINE RESUMING

The scheduler resumes a route coroutine using:

`coroutine.resume(co, command)`

The result of the resume operation is checked.

If an error occurs, the program reports the error together with the relevant route information.

## 13. COOPERATIVE SCHEDULING

The project demonstrates cooperative scheduling.

A route coroutine does not continue executing indefinitely. Instead, it uses `coroutine.yield()` to voluntarily return control to the scheduler.

The scheduler can then resume another route.

This allows multiple route processes to share execution.

## 14. NUMBER OF SCHEDULING CYCLES

The scheduler is executed for 40 cycles using:

`scheduler(40)`

During these cycles, the routes are processed in round-robin order.

After the 40 cycles are completed, the final state of every route is displayed.

## 15. LUA PROGRAMMING CONCEPTS DEMONSTRATED

### Tables

Lua tables are used to store route information and route states.

### Functions

Functions are used to organize the route and scheduler operations.

### Coroutines

Coroutines are the main programming language concept demonstrated by the project.

### coroutine.create()

Creates a coroutine for a route.

### coroutine.resume()

Resumes a suspended coroutine and sends it a command.

### coroutine.yield()

Suspends the coroutine and returns control to the scheduler.

### coroutine.status()

Checks the current state of a coroutine.

### Cooperative Scheduling

The route coroutines cooperate with the scheduler by yielding control.

### Round-Robin Scheduling

The scheduler processes each route in sequence and repeatedly cycles through all routes.

### Error Handling

The result of coroutine execution is checked so that errors can be handled and displayed.

### State Management

Each route maintains its own passenger and waiting state.

## 16. LUA SYSTEM WORKFLOW

START
  |
  v
Create Four Routes
  |
  v
Create Coroutine for Each Route
  |
  v
Start Scheduler
  |
  v
Select Current Route
  |
  v
Check Passenger Count
  |
  +---- Passengers < 5 ----> BOARD
  |
  +---- Passengers >= 5 ---> WAIT
  |
  v
Resume Route Coroutine
  |
  v
Update Route State
  |
  v
Check Departure Conditions
  |
  +---- Passengers >= 8 ----> DEPART
  |
  +---- Waiting > 3 AND
  |     Passengers >= 5 ----> DEPART
  |
  v
Move to Next Route
  |
  v
Continue Until 40 Cycles
  |
  v
Display Final Route States
  |
  v
END

## 17. LUA PROJECT FILES

Lua-Matatu-Terminus-Scheduler/
├── main.lua
└── README.md

The main source code is contained in `main.lua`.

## 18. EXECUTION

The Lua project can be executed using a Lua environment or an online Lua compiler.

The documented OneCompiler version of the project is:

https://onecompiler.com/lua/453e8nqtn

---

# REPOSITORY STRUCTURE

The two projects are stored in the same GitHub repository and separated into different folders.

Group-1-Programming-Languages/
│
├── README.md
│
├── C-Examination-Eligibility-System/
│   ├── main.c
│   └── README.md
│
└── Lua-Matatu-Terminus-Scheduler/
    ├── main.lua
    └── README.md

---

# TECHNOLOGIES USED

## Project 1 – C

- C Programming Language
- Structures
- Functions
- Pointers
- Pointer Aliasing
- L-values and R-values
- Scope
- Static Storage
- Dynamic Memory Allocation
- Validation
- Testing

## Project 2 – Lua

- Lua Programming Language
- Tables
- Functions
- Coroutines
- coroutine.create()
- coroutine.resume()
- coroutine.yield()
- coroutine.status()
- Cooperative Scheduling
- Round-Robin Scheduling
- Error Handling
- State Management

---

# OVERALL CONCLUSION

The two projects demonstrate the application of programming language concepts to practical systems.

The C project demonstrates how C can be used to process student examination information, determine eligibility, validate marks, calculate results, assign grades, and demonstrate concepts such as structures, pointers, aliasing, scope, and dynamic memory allocation.

The Lua project demonstrates how Lua coroutines can be used to model and manage multiple matatu routes through cooperative round-robin scheduling. The system manages boarding, waiting, departure conditions, coroutine execution, and route states.

Both projects are contained in the same GitHub repository and are organized into separate project folders.

---

# GROUP 1 MEMBERS

### 1. FRANKLINE ANTONY TUMAINI
Registration Number: C026-01-0984/2025

### 2. LEVY JUMA
Registration Number: C026-01-0977/2025

### 3. Vessly Clement
Registration Number: C026-01-0938/2025

---

# INSTITUTION

Dedan Kimathi University of Technology

# UNIT

Programming Languages – CCS 2105

# GROUP

Group 1
