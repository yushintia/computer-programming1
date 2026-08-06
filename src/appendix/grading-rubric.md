# Grading Rubrics

This appendix documents the scoring criteria for all three graded categories:
weekly assignments, the midterm, and the final.

---

## 1. Weekly Assignment Rubric (Assignments 10%)

Each lab deliverable is scored out of 10 points.

| Criterion | Points | Description |
|-----------|:------:|-------------|
| **Compiles** | 2 | Program compiles with `gcc -Wall -Wextra -std=c99` without errors |
| **Correctness** | 4 | Output matches the expected result for the provided test cases |
| **Style & readability** | 2 | Follows the [Style Guide](style-guide.md): header block, names, indentation, comments |
| **Approach** | 2 | Algorithm is appropriate; no unnecessary complexity; code is concise |
| **Total** | **10** | |

> If the program does not compile, **Correctness** and **Approach** are not awarded.
> Fix all compiler errors before submitting.

---

## 2. Midterm Rubric: Live In-Lab Coding (Midterm 20%)

The midterm consists of **3–5 short tasks** (Week 8, covers Weeks 1–7).
Each task is scored independently; partial credit is available per task.

### Per-Task Rubric (10 points per task)

| Criterion | Points | Description |
|-----------|:------:|-------------|
| Compiles without errors | 2 | Program must compile |
| Correct output: sample test | 4 | Produces correct output for the provided test case |
| Correct output: hidden test | 2 | Produces correct output for an unseen test case |
| Code style | 1 | Clean indentation, meaningful names |
| Algorithm | 1 | Appropriate approach; no unnecessary code |

### Final Midterm Score Calculation

```
Midterm score = (sum of task scores / total available task points) × 20
```

Example: if there are 4 tasks (40 points total) and a student earns 32 points,
their midterm contribution is `(32/40) × 20 = 16%` of the final grade.

---

## 3. Project Artifact Rubric (Project 30%)

The artifact is the submitted code + README, **due at the end of Week 14**.

| Criterion | Weight | Description |
|-----------|:------:|-------------|
| Compiles and runs | 5% | `gcc *.c -o project -Wall -std=c99` succeeds; program starts and does not immediately crash |
| Core features work | 10% | All features described in the README behave correctly for valid input |
| Code quality | 8% | Functions used appropriately; naming, indentation, comments meet the style guide |
| README / report | 4% | Explains what the program does, how to compile and run, known limitations |
| Bonus features | 3% | Optional: additional features beyond the core requirement |
| **Total** | **30%** | |

---

## 4. Final Exam Rubric: Project Demo + Oral Defense (Final 30%)

The final is an **individual oral defense** of the submitted project (Week 15).
Each student has approximately 10–12 minutes.

| Criterion | Weight | Description |
|-----------|:------:|-------------|
| **Runs & meets spec** | 8% | Program runs without crashes during the demo; core features demonstrated |
| **Code understanding** | 10% | Student explains any code section accurately when asked; no major misconceptions |
| **Live modification** | 8% | Student successfully implements the examiner's small requested change (partial credit for correct direction) |
| **Presentation clarity** | 4% | Demo is organized; student communicates clearly |
| **Total** | **30%** | |

### Oral Defense Scoring Guide

| Score band | Code understanding | Live modification |
|------------|-------------------|------------------|
| Full marks | Explains all parts accurately; can reason about edge cases | Completes the modification correctly |
| 75% | Explains most parts; minor gaps | Correct approach; minor syntax error |
| 50% | Explains some parts; several gaps | Correct direction but incomplete |
| 25% | Struggles with most of own code | Unable to start the modification |
| 0% | Cannot explain any part | No attempt |

---

## 5. Grade Composition Summary

| Component | Weight | When |
|-----------|:------:|------|
| Midterm: live coding | 20% | Week 8 |
| Project: artifact | 30% | Submitted Week 14 |
| Final: demo + oral defense | 30% | Week 15 |
| Attendance | 10% | Ongoing |
| Assignments | 10% | Weeks 2–13 |
| **Total** | **100%** | |

Grade distribution (per university policy): A ≤ 40% · B ≤ 40% · C ≤ 20% of enrolled students.
