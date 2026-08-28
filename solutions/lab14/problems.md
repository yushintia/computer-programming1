# Lab 14: Debugging, Analysis and Project Build — Problem Set

Adapted from `src/labs/lab14-debugging-project.md`. These are the problem
statements only; see `answer-key/` for reference solutions. Bug locations
and trace answers are intentionally NOT revealed here.

## Guided In-Lab Exercises

### Exercise 1: Bug hunt

The professor provides `buggy.c`, a program with 3 deliberate bugs (at
least one compile-time, at least one logic bug). Your task:
1. Compile and read the errors.
2. Use `printf`-tracing to find the logic bug(s).
3. Fix all bugs. Write a comment near each fix: `/* BUG FIX: ... */`

File: submit the corrected `lab14_buggy.c`

### Exercise 2: Trace the program

Given `mystery.c` (provided — a function that sums up some subset of the
integers from 1 to n), predict the output for inputs 5, 10, and 0.
Write your predictions in a comment at the top, then run and compare.

File: `lab14_trace.c` (add your comment block)

### Exercise 3: Project finalization and submission

Use this time to:
- Run your project on several test inputs.
- Fix any remaining bugs.
- Write or complete your README.
- Submit to LMS before the session ends.

(No standalone solution file — this exercise is about each student's own
individual semester project, not a generic coding problem.)

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Corrected buggy program | `lab14_buggy.c` | 4 |
| Trace exercise with predictions | `lab14_trace.c` | 2 |
| **Project artifact + README** | `project/` folder | **30% of final grade** |
