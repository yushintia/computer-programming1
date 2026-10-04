---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 5: Conditional Statements

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Recap Week 4 (formatted I/O and operators) in one line, then move
straight into today's pain: a program that can only ever do one thing,
no matter what the input is.
-->

---

<!-- SLOT 2: Where we are (Act 0 / LOCATE) -->

# Where We Are

<div class="roadmap">
<div class="wk"><div class="n">Wk 1</div><div class="t">Introduction</div></div>
<div class="wk"><div class="n">Wk 2</div><div class="t">Program Structure &amp; I/O</div></div>
<div class="wk"><div class="n">Wk 3</div><div class="t">Variables &amp; Data Types</div></div>
<div class="wk"><div class="n">Wk 4</div><div class="t">I/O &amp; Operators</div></div>
<div class="wk now"><div class="n">Wk 5</div><div class="t">Conditionals</div></div>
<div class="wk"><div class="n">Wk 6</div><div class="t">Loops I: while</div></div>
<div class="wk"><div class="n">Wk 7</div><div class="t">Loops II: for</div></div>
<div class="wk review"><div class="n">Wk 8</div><div class="t">Midterm Exam</div></div>
<div class="wk"><div class="n">Wk 9</div><div class="t">Functions I</div></div>
<div class="wk"><div class="n">Wk 10</div><div class="t">Functions II: Recursion</div></div>
<div class="wk"><div class="n">Wk 11</div><div class="t">Arrays I: 1-D</div></div>
<div class="wk"><div class="n">Wk 12</div><div class="t">Arrays II: 2-D &amp; Strings</div></div>
<div class="wk"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** precise, formatted output and the relational
  (`<`, `>`, `==`) and logical (`&&`, `||`) operators that produce
  true/false values.
- **Last week left broken:** output can be formatted precisely, but
  there is still no way for a program to *decide* between two paths.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# One Program, Every Situation, Same Answer

<div class="pain">

Think about charging a different tax rate depending on someone's
income, or showing an error screen only when a login fails, or
flagging a sensor reading only when it goes above a safe limit.

Every program you have written so far runs every single line, top to
bottom, every time, no matter what the input was. It cannot yet look
at the data and choose to do one thing instead of another.

</div>

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- A program that cannot branch treats every user, every score, every
  reading exactly the same, even when the correct response is
  completely different.
- Any task with an "if this happens, do that" rule (grading, login
  checks, alarms, menus) simply cannot be built.

<div class="why">
<strong>In industry:</strong> almost every interview coding question and
almost every real bug report boils down to "the program took the wrong
branch." Reading and writing correct conditions is one of the most
tested basic skills in technical interviews.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How does a program look at data and choose which path to run?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Write conditional branches (one-way, two-way, and nested) to
   choose the program's path.
2. Combine true/false conditions with AND, OR, and NOT.
3. Write a multi-way choice on one value and know when it fits better
   than a chain of two-way checks.
4. Identify the assign-versus-compare bug and explain why it is
   dangerous.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

<div class="thread">Under the hood: branches as jumps.</div>

An `if` statement compiles down to a **compare** instruction followed
by a **conditional jump**. The CPU tests the condition, and if it is
false, execution jumps past the `if` body entirely.

The program does not "know" ahead of time which branch it will take;
it decides at runtime, one comparison at a time. A long `else if`
chain becomes a series of these comparisons; a `switch` with many
cases often compiles to a **jump table** instead, which is faster.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# Conditional Execution: Definition

> A conditional statement lets a program ask a question and take a
> different path depending on the answer. If the answer is YES, run
> one block; if NO, run another. This is called **branching**, like a
> fork in a road.

Think of a vending machine: it checks whether you inserted enough
money. If yes, it dispenses the drink. If no, it asks for more money.
Without branching, it would dispense a drink no matter what.

---

<!-- SLOT 10: Mechanics - if / else if / else -->

# `if` / `else if` / `else`

```c
if (score >= 90) {
    printf("A\n");
} else if (score >= 80) {
    printf("B\n");
} else if (score >= 70) {
    printf("C\n");
} else {
    printf("F\n");
}
```

- Conditions are checked **top to bottom**. The first one that is true
  runs its block, and every remaining `else if` / `else` is skipped.
- If none of the `if` / `else if` conditions match, the final `else`
  (if present) runs as the fallback.

---

<!-- SLOT 11: Mechanics - flowchart -->

# Seeing the Branch: Flowchart

A chain of `if` / `else if` is a series of yes/no forks. Each "no"
sends control down to the next question; each "yes" jumps straight to
that branch's output and skips everything after it.

<div class="pipeline">
<div class="stage"><div class="h">score &gt;= 90?</div><div class="s">yes &rarr; "A" · no &rarr; next check</div></div>
<div class="arrow">&rarr;</div>
<div class="stage"><div class="h">score &gt;= 80?</div><div class="s">yes &rarr; "B" · no &rarr; next check</div></div>
<div class="arrow">&rarr;</div>
<div class="stage"><div class="h">score &gt;= 70?</div><div class="s">yes &rarr; "C" · no &rarr; "F"</div></div>
</div>

Exactly one branch runs per pass through the chain.

---

<!-- SLOT 12: Mechanics - combining conditions -->

# Combining Conditions

- `&&` (AND): true only if **both** sides are true.
- `||` (OR): true if **either** side is true.
- `!` (NOT): flips true to false and false to true.

```c
if (score < 0 || score > 100) {
    printf("Invalid score.\n");
}
```

`||` here means the guard fires if *either* part is true: score below
0, OR score above 100. Either one alone is enough to make the whole
condition true.

---

<!-- SLOT 13: Mechanics - switch-case -->

# `switch-case`

```c
int day = 3;
switch (day) {
    case 1: printf("Monday\n");    break;
    case 2: printf("Tuesday\n");   break;
    case 3: printf("Wednesday\n"); break;
    default: printf("Unknown\n");  break;
}
```

- `switch` works on **integer** (and `char`) values only. It cannot
  test floating-point numbers or strings.
- `default` handles any value not matched by a `case`. Always include
  it.
- Always write `break` at the end of each case body.

---

<!-- SLOT 14: Mechanics - fall-through -->

# Fall-Through: Why `break` Matters

When a `switch` case matches, execution starts there and **keeps
going** through the lines below until it hits a `break` or the end of
the `switch`. This is called fall-through.

If you forget `break` and `day == 1`, "Monday" **and** "Tuesday" both
print, even though case 2 did not match. This is almost always a bug.

There are rare intentional uses for fall-through, but in this course,
always add `break`.

---

<!-- SLOT N-2: Worked example -->

# Worked Example: Grade Classifier (1/2)

```c
/* lab05_grade.c */
#include <stdio.h>

int main(void) {
    int score;
    printf("Enter score (0-100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Invalid score.\n");
    } else if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    /* ...continued next slide */
```

---

# Worked Example: Grade Classifier (2/2)

```c
    /* ...continued from previous slide */
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F (Fail)\n");
    }
    return 0;
}
```

---

<!-- Worked example line by line, part 1 -->

# Grade Classifier: Line by Line (1/2)

<div class="cardlist">
<div class="card"><div class="h">int score;</div><div class="d">Reserves a box called score to hold the user's number.</div></div>
<div class="card"><div class="h">scanf("%d", &amp;score);</div><div class="d">Waits for the user to type a number, stores it in score.</div></div>
<div class="card"><div class="h">if (score &lt; 0 || score &gt; 100)</div><div class="d">The first guard: checks the number is valid before anything else.</div></div>
<div class="card"><div class="h">else if (score &gt;= 90)</div><div class="d">Only checked once the score is known valid. Is it 90 or above?</div></div>
</div>

---

<!-- Worked example line by line, part 2 -->

# Grade Classifier: Line by Line (2/2)

<div class="cardlist">
<div class="card"><div class="h">else if (score &gt;= 80)</div><div class="d">At this point score &lt; 90 is already known, so this checks 80-89.</div></div>
<div class="card"><div class="h">else { "F" }</div><div class="d">Final fallback. Runs only if nothing above matched: score &lt; 60.</div></div>
</div>

**Key point:** once one `else if` condition is true, all the remaining
ones are skipped. The chain exits after the first match.

**Sample runs:**
```
Enter score (0-100): 85   -> Grade: B
Enter score (0-100): 55   -> Grade: F (Fail)
Enter score (0-100): 150  -> Invalid score.
```

---

<!-- Second worked example: switch -->

# Worked Example: Day-of-Week with `switch`

```c
#include <stdio.h>
int main(void) {
    int d;
    printf("Enter day number (1=Mon ... 7=Sun): ");
    scanf("%d", &d);
    switch (d) {
        case 1: printf("Monday\n");    break;
        case 2: printf("Tuesday\n");   break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n");  break;
        case 5: printf("Friday\n");    break;
        case 6: printf("Saturday\n");  break;
        case 7: printf("Sunday\n");    break;
        default: printf("Invalid day.\n"); break;
    }
    return 0;
}
```

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">if (x = 5) instead of if (x == 5)</div><div class="d">Always true! This assigns 5 to x instead of comparing. Use == for comparison.</div></div>
<div class="card"><div class="h">Missing break in switch</div><div class="d">Fall-through into the next case. Add break after each case body.</div></div>
<div class="card"><div class="h">Empty else, unhandled case</div><div class="d">Program silently does nothing. Add an else or a default.</div></div>
<div class="card"><div class="h">Nested if without braces</div><div class="d">Only the first statement is really inside the branch. Always use { } even for one line.</div></div>
</div>

<div class="why">
The <code>=</code> vs <code>==</code> bug is one of the most common in
C. Many compilers warn about <code>if (x = 5)</code> with
<code>-Wall</code> - this is why we always compile with warnings on.
</div>

---

<!-- SLOT N: Sample questions -->

# Sample Question 1

**Question:** A year is a leap year if divisible by 4, except years divisible by
100 (which are NOT), except years divisible by 400 (which ARE).
What kind of `if` structure do you need to express three rules like
this, where later rules override earlier ones?

---

# Sample Question 1: Answer

**Answer:** Nested `if` (or an `if-else if` chain with `&&`): check divisible
by 400 first (leap), else divisible by 100 (not leap), else
divisible by 4 (leap), else not leap - order matters because later
checks only run when earlier ones were false.

---

# Sample Question 2

**Question:** Your `switch` menu program has cases 1 to 4. What line do you add
so that typing 9 does not silently do nothing?

---

# Sample Question 2: Answer

**Answer:** A `default:` case, so any unmatched choice gets a clear response
instead of silence.

---

# Sample Question 3

**Question:** What is wrong with `if (x = 5) { ... }`, and what should it say
instead?

---

# Sample Question 3: Answer

**Answer:** It assigns 5 to `x` and the condition is always true, instead of
comparing. It should say `if (x == 5)`.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What Conditionals Cannot Do Yet

<div class="limits">
A program can now choose once, between paths. But any repeated task -
printing a line 1000 times, adding up a list of scores, asking for
input until it is valid - still needs the same lines pasted over and
over. Choosing once is not the same as repeating.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 5 leaves **repetition** unsolved: a program can choose once, but
any repeated task still needs the same lines pasted over and over.
**Week 6** addresses it: Loops I - `while` and `do-while`.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- `if` / `else if` / `else` branches on any condition; `switch` is a
  cleaner choice when branching on one integer or char value.
- `&&`, `||`, `!` combine conditions; always use `==` to compare,
  never `=`.
- **Lab page:** [Lab 05: Conditional Statements](../book/labs/lab05-conditionals.html) for the leap
  year checker, the switch menu, and the challenge problem.
- **Prepare:** Part B includes a short, ungraded diagnostic covering
  Weeks 1-5 - just a check-in, not a test. No need to study specially,
  just come having done the reading.

---

<!-- SLOT N+4: Thank You -->
<!-- _class: end -->

# Thank You
