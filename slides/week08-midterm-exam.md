---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 8: Midterm Exam

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: This is the midterm week. No new concept today - this session
covers exam logistics, format, and a short walk through sample practice
problems in the same style as the exam itself.
-->

---

<!-- SLOT 2: Where we are (Act 0 / LOCATE) -->

# Where We Are

<div class="roadmap">
<div class="wk"><div class="n">Wk 1</div><div class="t">Introduction</div></div>
<div class="wk"><div class="n">Wk 2</div><div class="t">Program Structure &amp; I/O</div></div>
<div class="wk"><div class="n">Wk 3</div><div class="t">Variables &amp; Data Types</div></div>
<div class="wk"><div class="n">Wk 4</div><div class="t">I/O &amp; Operators</div></div>
<div class="wk"><div class="n">Wk 5</div><div class="t">Conditionals</div></div>
<div class="wk"><div class="n">Wk 6</div><div class="t">Loops I: while</div></div>
<div class="wk"><div class="n">Wk 7</div><div class="t">Loops II: for</div></div>
<div class="wk review now"><div class="n">Wk 8</div><div class="t">Midterm Exam</div></div>
<div class="wk"><div class="n">Wk 9</div><div class="t">Functions I</div></div>
<div class="wk"><div class="n">Wk 10</div><div class="t">Functions II: Recursion</div></div>
<div class="wk"><div class="n">Wk 11</div><div class="t">Arrays I: 1-D</div></div>
<div class="wk"><div class="n">Wk 12</div><div class="t">Arrays II: 2-D &amp; Strings</div></div>
<div class="wk"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

<!-- notes: Seven weeks of new material behind you: variables, I/O,
operators, conditionals, and loops. Today checks what stuck. -->

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Weeks 1-7 delivered:** variables and I/O, operators, conditionals,
  and loops (`while`, `do-while`, `for`, nested) - everything you need
  to write a complete, correct program from scratch.
- **Today is not a new lesson.** It is a checkpoint: can you put those
  seven weeks together, live, under exam conditions?

---

# Today: The Midterm

<div class="why">
<strong>150 minutes, one continuous block, worth 20% of your final grade.</strong>
Scope: everything from Week 1 through Week 7 - variables, I/O,
operators, conditionals, and loops. No new material.
</div>

<div class="cardlist">
<div class="card"><div class="h">Setup - 10 min</div><div class="d">Rules, seat assignment, confirm your environment compiles</div></div>
<div class="card"><div class="h">Live coding - 120 min</div><div class="d">3 to 5 independent tasks, each solvable in 20-40 minutes</div></div>
<div class="card"><div class="h">Submission - 20 min</div><div class="d">Upload your files; buffer time for technical issues</div></div>
<div class="card"><div class="h">Each task stands alone</div><div class="d">Task 2 never depends on task 1's output</div></div>
</div>

---

# Exam Rules & Submission

<div class="cardlist">
<div class="card"><div class="h">Open-book</div><div class="d">Your compiler, printed reference sheets, and course lab pages are allowed</div></div>
<div class="card"><div class="h">Restricted network</div><div class="d">No internet browsing, no messaging, no AI tools</div></div>
<div class="card"><div class="h">Work independently</div><div class="d">Invigilated; talking to classmates is not permitted</div></div>
<div class="card"><div class="h">Partial credit per task</div><div class="d">Each task graded separately - 3 of 4 correct still earns 75%</div></div>
</div>

- **Submit** each task as its own file: `m1.c`, `m2.c`, `m3.c` ...
- **Do not submit code that fails to compile** - fix the error first,
  even if the output is still wrong. A program that compiles with a
  wrong answer earns far more than one that does not compile at all.

<!-- notes: Point out the rubric: compiles (2 pts), correct sample output
(4), correct hidden output (2), style (1), approach (1) - 10 per task.
If it doesn't compile, style and approach points are also lost. -->

---

<!-- _class: section -->

# Practice Time

<div class="driving-q">Four sample problems, in the same style as the real exam. Not the actual questions - but representative.</div>

---

# Practice 1

**Read `N` and print the sum of odd numbers from 1 to `N`.**

Example: `N = 10` → odd numbers are 1, 3, 5, 7, 9 → sum = 25.

What loop and what condition do you need?

---

# Practice 1: Approach

```c
#include <stdio.h>

int main(void) {
    int n, sum = 0;
    printf("Enter N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) sum += i;   /* i is odd */
    }

    printf("Sum of odds: %d\n", sum);
    return 0;
}
```

A `for` loop counts 1 to `N`; an `if` inside filters the odd ones.

---

# Practice 2

**Read a temperature in Celsius and classify it:**

- Below 0: "Freezing"
- 0 to 15: "Cold"
- 16 to 30: "Comfortable"
- Above 30: "Hot"

Which control structure fits four ranges like this?

---

# Practice 2: Approach

```c
#include <stdio.h>

int main(void) {
    double temp;
    printf("Enter temperature (C): ");
    scanf("%lf", &temp);

    if (temp < 0)        printf("Freezing\n");
    else if (temp <= 15)  printf("Cold\n");
    else if (temp <= 30)  printf("Comfortable\n");
    else                  printf("Hot\n");

    return 0;
}
```

A chain of `if-else if` checks each range in order, low to high.

---

# Practice 3

**Read numbers until the user enters 0.** Print the count of positive
numbers, the count of negative numbers, and the average of all
entered values.

Which loop keeps going until a specific input stops it?

---

# Practice 3: Approach

```c
int x, pos = 0, neg = 0, count = 0, sum = 0;
printf("Enter a number (0 to stop): ");
scanf("%d", &x);
while (x != 0) {
    if (x > 0) pos++; else neg++;
    sum += x;
    count++;
    printf("Enter a number (0 to stop): ");
    scanf("%d", &x);
}
printf("Positive: %d, Negative: %d\n", pos, neg);
printf("Average: %.2f\n", count > 0 ? (double)sum / count : 0.0);
```

A `while` loop, since you don't know the count in advance.

---

# Practice 4

**Print the numbers 1 to 50.** For multiples of 3, print "Fizz". For
multiples of 5, print "Buzz". For multiples of both, print "FizzBuzz".

Which condition must you check first, and why?

---

# Practice 4: Approach

```c
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 50; i++) {
        if (i % 3 == 0 && i % 5 == 0)      printf("FizzBuzz\n");
        else if (i % 3 == 0)                printf("Fizz\n");
        else if (i % 5 == 0)                printf("Buzz\n");
        else                                 printf("%d\n", i);
    }
    return 0;
}
```

Check "multiple of both" **first** - if you check "multiple of 3"
first, a number like 15 would print "Fizz" and never reach the
"both" case.

---

<!-- SLOT N+1: What to focus on next (replaces Limits for review week) -->

# What to Focus On Next

<div class="limits">
If any of these four problems felt shaky, review it before the exam:

1. **Loop choice** - `for` when the count is known, `while` when it
   isn't.
2. **Conditional chains** - ordering `if-else if` from the most
   specific case to the most general.
3. **Accumulator patterns** - running sum, running count, min/max,
   updated once per loop iteration.
4. **Input handling** - matching `scanf` format specifiers to
   variable types (`%d`, `%lf`, `%c`).
</div>

---

<!-- SLOT N+2: Bridge -->

# Next Week

The midterm closes out Weeks 1-7. **Week 9** starts new material:
**Functions** - packaging code into named, reusable blocks instead of
one long `main`.

---

<!-- SLOT N+3: Summary -->

# Summary

- Midterm: 150 minutes, 20% of your grade, scope Weeks 1-7, open-book
  (compiler and your own reference sheets only), restricted network.
- 3-5 independent tasks, submitted as separate `.c` files
  (`m1.c`, `m2.c`, ...). A non-compiling file earns almost nothing.
- **Lab page:** `lab08-midterm-exam.md` for the full rubric and more
  practice problems.
- **Prepare:** review loops, conditionals, and I/O patterns from
  Weeks 1-7; bring your printed reference sheet.

---

<!-- SLOT N+4: Thank You -->
<!-- _class: end -->

# Thank You
