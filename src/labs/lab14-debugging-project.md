# Lab 14: Debugging, Analysis and Project Build

| | |
|---|---|
| **Week** | 14 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab + Project Submission |
| **Prerequisites** | Labs 01–13 (entire course) |

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A | 50 | 5 recap · 30 systematic debugging (printf-tracing, rubber-duck, gdb intro) · 15 live demo |
| B | 50 | 30 program analysis (read & trace unfamiliar code) · 20 project finalization |
| C | 50 | 35 project finalization + submission · 10 oral defense preview + Q&A · 5 wrap-up |

> This is the **capstone** debugging session, not the first time.
> You have been reading error messages since Week 2 and meeting per-topic pitfalls all term.
> Today you assemble everything into a systematic approach.

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Apply a systematic debugging process: reproduce → isolate → identify → fix → verify.
2. Use `printf`-tracing and the rubber-duck method to find a bug.
3. Use `gdb` to set a breakpoint, step through code, and inspect a variable.
4. Read and trace an unfamiliar C program and predict its output.
5. Submit your individual project (artifact + README).

---

## Recap

Over the last 13 weeks you have encountered:
- Compile-time errors (Weeks 2, 3, 4: syntax, types, missing includes)
- Runtime crashes and wrong output (Weeks 6–7: loops, off-by-one, infinite loops)
- Logic bugs in conditionals and arrays (Weeks 5, 11)

Today you learn to attack any bug with a repeatable method.

---

## Background: Systematic Debugging

### The Process

1. **Reproduce:** confirm you can make the bug happen consistently.
2. **Isolate:** narrow down *where* in the code the problem occurs.
3. **Identify:** understand *why* it goes wrong.
4. **Fix:** make the smallest change that corrects the problem.
5. **Verify:** test with the original case *and* a few others.

### printf-Tracing

The simplest debugger: add temporary `printf` statements to print variable values
at key points. Check whether they match what you expect.

```c
printf("DEBUG: i=%d, sum=%d\n", i, sum);
```

Remove or comment out `DEBUG:` lines before submitting.

### Rubber-Duck Debugging

Explain your code, line by line, to an imaginary rubber duck (or a classmate).
The act of explaining often surfaces the assumption you got wrong.

### Intro to `gdb`: Three Commands

```bash
gcc -g myprogram.c -o myprogram   # compile with debug info
gdb ./myprogram                   # start debugger
```

Inside `gdb`:
```
(gdb) break main      # set breakpoint at main
(gdb) run             # start program; stops at breakpoint
(gdb) next            # execute one line (step over functions)
(gdb) print x         # print the value of variable x
(gdb) quit            # exit gdb
```

You only need these five commands for now. Full `gdb` is covered in System Programming.

---

## Worked Example: Tracing an Unfamiliar Program

Given this program (do not run it yet):

```c
#include <stdio.h>

int mystery(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) result += i;
    }
    return result;
}

int main(void) {
    printf("%d\n", mystery(7));
    return 0;
}
```

1. What does `mystery` compute?
2. What does `mystery(7)` return?
3. What is printed?

Trace it on paper first, then run and verify.
For a structured method to do this, see [Reading and Tracing a Program](../appendix/tracing-a-program.md).

---

## Guided In-Lab Exercises

### Exercise 1: Bug hunt (Part A)

The instructor provides `buggy.c`, a program with 3 deliberate bugs (at least one compile-time,
one logic bug). Your task:
1. Compile and read the errors.
2. Use `printf`-tracing to find the logic bug.
3. Fix all bugs. Write a comment near each fix: `/* BUG FIX: ... */`

File: submit the corrected `lab14_buggy.c`

### Exercise 2: Trace the program (Part B)

Given `mystery.c` (provided), predict the output for inputs 5, 10, and 0.
Write your predictions in a comment at the top, then run and compare.

File: `lab14_trace.c` (add your comment block)

### Exercise 3: Project finalization and submission (Part B–C)

Use this time to:
- Run your project on several test inputs.
- Fix any remaining bugs.
- Write or complete your README (see requirements below).
- Submit to LMS before the session ends.

---

## Project Submission Requirements

The **individual take-home project** counts for **30% of the final grade** (artifact).
The oral defense (30%) is in Week 15.

### Project Options (choose one)

| Option | Description |
|--------|-------------|
| A: Contact Book | Store/search/display contacts; struct array; string operations |
| B: Grade Manager | Read student scores; compute stats; letter grades; formatted report |
| C: Number Guessing Game | Configurable range; track attempts; high-score persistence |
| D: Calculator Suite | Multi-function calculator with history; functions for each operation |
| Custom | Propose your own to the instructor before Week 13 |

### Submission Checklist

- [ ] `main.c` (or multiple `.c` files with one `main` entry point)
- [ ] `README.txt` or `README.md` with: what the program does, how to compile and run it, known limitations, list of features implemented
- [ ] Compiles with `gcc *.c -o project -Wall -Wextra -std=c99` without errors
- [ ] Works for basic test cases

### Artifact Rubric (30%)

| Criterion | Weight |
|-----------|--------|
| Compiles and runs | 5% |
| Core features work correctly | 10% |
| Code quality (functions, naming, comments, style) | 8% |
| README / report | 4% |
| Bonus features | 3% (optional) |

---

## Common Pitfalls

| Mistake | Fix |
|---------|-----|
| Submitting code that does not compile | Compiler errors must be fixed first |
| No README | Write at minimum: "what it does" and "how to compile/run" |
| Only fixing the specific test case but not the root cause | Apply the systematic process: fix the underlying bug |
| Leaving `DEBUG:` printf lines in submitted code | Remove or comment them before submission |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Corrected buggy program | `lab14_buggy.c` | 4 |
| Trace exercise with predictions | `lab14_trace.c` | 2 |
| **Project artifact + README** | `project/` folder | **30% of final grade** |

Weekly lab deliverables: **6 points** (graded with the assignments 10% weight).

---

## Further Reading

- [Appendix: Debugging Tips](../appendix/debugging-tips.md): full error catalog + gdb quick reference
- [Reading and Tracing a Program](../appendix/tracing-a-program.md) - the trace-table method for predicting what a program does step by step
- K&R, Ch. 2–4 (for tracing unfamiliar programs)
- [Bonus: File I/O](../appendix/bonus/file-io.md): if your project needs to save data to disk
