# Lab 08: Midterm: Live In-Lab Coding

| | |
|---|---|
| **Week** | 8 |
| **Duration** | 150 min (single continuous block) |
| **Method** | Examination (live coding) |
| **Scope** | Weeks 1 to 7 (variables, I/O, operators, conditionals, loops) |
| **Weight** | **20%** of final grade |

**Time allocation**

| Phase | Min | Activity |
|-------|-----|----------|
| Setup | 10 | Rules, seat assignment, confirm environment works |
| Live coding | 120 | Several independent tasks (see format below) |
| Submission | 20 | Upload/submit files; buffer for technical issues |

---

## Exam Format

- **Open-book:** you may use your compiler, reference sheets, and the course lab pages.
- **Restricted network:** no internet browsing, no messaging, no AI tools.
- **Invigilated:** work independently; talking to classmates is not permitted.
- **Partial credit per task:** each task is graded independently. Completing 3 of 4 tasks correctly earns 75% of the exam mark. A partially correct solution earns more than a blank answer.

### Typical Task Structure

The exam contains **3 to 5 short tasks**, each solvable in 20 to 40 minutes.
Each task:
- Has a clear input specification and expected output.
- Is self-contained (you do not need the output of task 1 for task 2).
- Is graded on: Compiles, Correct output, Code style, Approach.

### Submission

- Submit each task as a separate `.c` file: `m1.c`, `m2.c`, etc.
- Files are submitted through the LMS or a designated folder before time is up.
- Do not submit files that fail to compile; fix the error first even if the output is wrong.

---

## Learning Outcomes Being Assessed

This exam assesses all outcomes from Weeks 1 to 7:

1. Write a syntactically correct C program from scratch.
2. Use `int`, `double`, `char` variables and `printf`/`scanf` for I/O.
3. Apply arithmetic, relational, and logical operators correctly.
4. Use `if-else` and `switch-case` to branch based on conditions.
5. Write `while`, `do-while`, and `for` loops for counting and accumulation.
6. Read error messages and fix compilation errors.

---

## What to Bring

- Your lab machine (or a laptop with gcc installed).
- A printed or offline copy of the reference sheet (provided by professor).
- No notes on electronic devices other than your own source files from labs.

---

## Sample Practice Problems

> These are **not** the actual exam questions, but they are representative in scope and style.

**Practice 1:** Read N and print the sum of odd numbers from 1 to N.

File: `lab08_practice1_sum_odds.c`

**Practice 2:** Read a temperature in Celsius and classify it:
- Below 0: "Freezing"
- 0 to 15: "Cold"
- 16 to 30: "Comfortable"
- Above 30: "Hot"

File: `lab08_practice2_celsius.c`

**Practice 3:** Read numbers until the user enters 0. Print the count of positive numbers,
the count of negative numbers, and the average of all entered values.

File: `lab08_practice3_pos_neg_avg.c`

**Practice 4:** Print the numbers 1 to 50, but for multiples of 3 print "Fizz",
for multiples of 5 print "Buzz", and for multiples of both print "FizzBuzz".

File: `lab08_practice4_fizzbuzz.c`

---

## Exam Rubric (per task)

| Criterion | Points |
|-----------|--------|
| Program compiles without errors | 2 |
| Correct output for sample test case | 4 |
| Correct output for hidden test case | 2 |
| Code style (names, indentation, comments) | 1 |
| Appropriate algorithm / no unnecessary code | 1 |
| **Task total** | **10** |

> If the program does not compile, style and algorithm points are not awarded. Fix compilation errors before moving on.

---

## After the Exam

Results and feedback will be returned within one week.
The **project** (30%) will be assigned around Weeks 11 to 12;
the **final exam** (30%) is your Week-15 project demo plus individual oral defense.

---

## Further Reading

- Review [Lab 01](lab01-intro-and-concepts.md) through [Lab 07](lab07-loops-for-nested.md).
- [Debugging Tips](../appendix/debugging-tips.md)
