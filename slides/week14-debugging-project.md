---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 14: Debugging, Analysis and Project Build

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Week 14. Last week: struct groups a record cleanly. This week:
nothing yet catches the bugs that slip into a growing program - today
we assemble a systematic method, then finalize and submit the semester
project. Capstone session, not a first exposure to bugs.
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
<div class="wk review"><div class="n">Wk 8</div><div class="t">Midterm Exam</div></div>
<div class="wk"><div class="n">Wk 9</div><div class="t">Functions I</div></div>
<div class="wk"><div class="n">Wk 10</div><div class="t">Functions II: Recursion</div></div>
<div class="wk"><div class="n">Wk 11</div><div class="t">Arrays I: 1-D</div></div>
<div class="wk"><div class="n">Wk 12</div><div class="t">Arrays II: 2-D &amp; Strings</div></div>
<div class="wk"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk now"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

<!-- notes: Point at Week 14. Capstone: pulls together 13 weeks of
material into one systematic debugging method, then finalizes the
individual project due this week. -->

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** `struct` groups fields of different types
  under one name, and an array of structs keeps many complete records
  in sync automatically.
- **Last week left broken:** `struct` models one real record cleanly,
  but nothing yet catches the bugs that slip into a growing program.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# Your Program Runs, and the Answer Is Wrong

<div class="pain">

Your project compiles. It runs. It even prints something. But the
number is wrong, or it crashes on one particular input, or it works for
your test case and nobody else's. You stare at the code, change a line
at random, run it again - still wrong. You have no plan, just guessing.

</div>

<!-- notes: Ask: "Has this happened to you already, this semester?"
Everyone raises a hand. That is exactly the point - this is not new,
it has been happening since Week 2, we just never named the method. -->

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Random guessing ("change a line, run again, hope") burns hours and
  often introduces a *second* bug while chasing the first.
- Fixing only the one test case you noticed, instead of the root
  cause, leaves the same bug live for every other input.

<div class="why">
<strong>In industry:</strong> professional developers spend more time
reading and debugging code than writing new code. "Can you debug this?"
is a standard interview task, and a systematic process is exactly what
separates a confident answer from a guess.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How do you track down and fix a bug with a repeatable method, instead of guessing?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Apply a systematic debugging process: reproduce → isolate →
   identify → fix → verify.
2. Use tracing (printing variable values as the program runs) and the
   rubber-duck method to find a bug.
3. Use a debugger to pause a program, step through it line by line,
   and inspect a variable's value.
4. Read and trace an unfamiliar program and predict its output.
5. Submit your individual project (artifact + README).

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

Every compiler error and wrong answer you have hit since Week 2 was
already a debugging problem - you just solved each one ad hoc, in the
moment. Professional debugging just names the steps you were already
doing unevenly and does them *in order, every time*: confirm the bug is
real, narrow down where it lives, understand why, fix the smallest
thing that fixes it, then check the fix didn't just patch one symptom.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# Systematic Debugging: Definition

> **Systematic debugging** is a repeatable five-step process:
> **reproduce → isolate → identify → fix → verify.** Skipping a step
> (especially *isolate*) is why random guessing feels faster but
> usually takes longer.

1. **Reproduce** - confirm you can make the bug happen consistently.
2. **Isolate** - narrow down *where* in the code it occurs.
3. **Identify** - understand *why* it goes wrong.
4. **Fix** - make the smallest change that corrects it.
5. **Verify** - test the original case *and* a few others.

---

<!-- SLOT 9: Core concept - one bug walked through the five steps -->

# Systematic Debugging: One Bug, Five Steps

A program should print the average of three scores, but `3, 4, 6`
prints `4` instead of `4.33`.

1. **Reproduce:** enter `3`, `4`, `6` again. It prints `4` every time,
   so the bug is repeatable.
2. **Isolate:** print `total` and `count` just before the average line.
   They show `13` and `3`, which are correct, so the bug is in the
   division line.
3. **Identify:** both values are whole numbers, so C divides them as
   whole numbers and drops the `.33`.
4. **Fix:** make one value a decimal, such as `13.0 / count`. Change
   nothing else.
5. **Verify:** run `3, 4, 6` (now `4.33`), then `10, 10` (`10.00`), and
   a single score `5` (`5.00`).

---

<!-- SLOT 10: Mechanics - printf-tracing -->

# Tool 1: `printf`-Tracing

The simplest debugger: print variable values at key points, and check
whether they match what you expect.

```c
printf("DEBUG: i=%d, sum=%d\n", i, sum);
```

- Place it right before and after the line you suspect.
- Compare the printed value against what the line *should* have
  produced - the first mismatch is where the bug is (isolate).
- Remove or comment out every `DEBUG:` line before submitting.

---

<!-- SLOT 11: Mechanics - rubber-duck debugging -->

# Tool 2: Rubber-Duck Debugging

Explain your code, line by line, out loud, to an imaginary rubber duck
(or a classmate) - as if they know nothing about the program.

- The act of explaining forces you to state every assumption.
- Most of the time, you catch the wrong assumption yourself, mid
  sentence, before the "duck" says a word.
- Costs nothing, needs no tool - try this before anything else.

---

<!-- SLOT 12: Mechanics - gdb intro -->

# Tool 3: `gdb`, Five Commands

```bash
gcc -g myprogram.c -o myprogram   # compile with debug info
gdb ./myprogram                   # start debugger
```

```
(gdb) break main      # set breakpoint at main
(gdb) run             # start program; stops at breakpoint
(gdb) next            # execute one line (step over functions)
(gdb) print x         # print the value of variable x
(gdb) quit             # exit gdb
```

These five commands are enough for now - full `gdb` is covered in
System Programming.

---

<!-- SLOT 13: Mechanics - reading and tracing unfamiliar code -->

# Reading Code You Didn't Write

Debugging your own project also means reading *unfamiliar* code and
predicting what it does, before you run it:

- Trace on paper first: a table of every variable, updated line by
  line, exactly like tracing your own loop bugs since Week 6-7.
- Only after you have a predicted output do you run the program - if
  the real output disagrees with your trace, your trace (your
  understanding), not just the code, has a bug.
- See [Reading and Tracing a Program](../book/appendix/tracing-a-program.html)
  for the full trace-table method.

---

<!-- SLOT 14: Worked example -->

# Worked Example: Trace This Before Running It

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

1. What does `mystery` compute? (sum of the odd numbers from 1 to `n`)
2. Trace by hand: `i` runs 1..7; `result` accumulates 1+3+5+7 = 16.
3. Predict the printed value *before* compiling, then run and verify -
   this is the reproduce/verify habit from slot 9, applied to reading.

---

<!-- SLOT 15: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Submitting code that does not compile</div><div class="d">Compiler errors must be fixed first - a program that doesn't build cannot be graded on logic at all.</div></div>
<div class="card"><div class="h">Fixing the symptom, not the cause</div><div class="d">Patching only the one test case you noticed skips "isolate" and "identify" - the same bug stays live for every other input.</div></div>
<div class="card"><div class="h">Leaving DEBUG: printf lines in</div><div class="d">Remove or comment out every printf-trace line before you submit.</div></div>
<div class="card"><div class="h">No README</div><div class="d">Write at minimum: what the program does, and how to compile and run it.</div></div>
</div>

---

<!-- SLOT 16: Sample questions -->

# Sample Question 1

**Question:** What are the five steps of systematic debugging, in order?

---

# Sample Question 1: Answer

**Answer:** Reproduce → isolate → identify → fix → verify.

---

# Sample Question 2

**Question:** Why must you `printf`-trace *before* changing the suspect line, not
after?

---

# Sample Question 2: Answer

**Answer:** Tracing before changing anything tells you *where* the value first
goes wrong (isolate) - change first and you've lost that evidence.

---

# Sample Question 3

**Question:** In the `mystery(n)` example, what would change if the condition
were `i % 2 == 0` instead of `!= 0`?

---

# Sample Question 3: Answer

**Answer:** It would sum the *even* numbers 1..n instead of the odd ones (for
`n=7`: 2+4+6 = 12 instead of 16).

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE) -->

# What This Week Sets You Up For

<div class="limits">
A systematic process - reproduce, isolate, identify, fix, verify - is
now something you can apply to any bug, in this project or the next
course. It does not, by itself, explain your project's design choices
out loud, under questions, to another person. That is a different
skill, and it's exactly what Week 15's oral defense assesses.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 14 gives you a working, debugged project - but a working project
alone doesn't yet demonstrate that *you* understand every line of it.
**Week 15** addresses that: the final project demo and individual oral
defense.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- Systematic debugging: reproduce → isolate → identify → fix → verify -
  a repeatable method, not guessing.
- `printf`-tracing and rubber-duck debugging cost nothing and catch
  most logic bugs; `gdb`'s five commands (`break`, `run`, `next`,
  `print`, `quit`) go deeper when needed.
- Reading unfamiliar code means tracing by hand *before* running it.
- **Lab page:** [Lab 14: Debugging, Analysis and Project Build](../book/labs/lab14-debugging-project.html), for the bug
  hunt, trace exercise, and full project submission checklist/rubric.
- **Prepare:** finalize and submit your project (artifact + README)
  before this session ends; be ready to explain every part of it in
  Week 15's oral defense.

---

<!-- SLOT N+4: Thank You (Act 4 / CLOSE) -->
<!-- _class: end -->

# Thank You
