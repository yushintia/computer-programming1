---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 6: Loops I - while and do-while

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Recap Week 5 (conditionals) in one line, then move to today's
pain: a program that can choose once, but cannot yet repeat anything
without pasting the same lines over and over.
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
<div class="wk now"><div class="n">Wk 6</div><div class="t">Loops I: while</div></div>
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

- **Last week delivered:** `if` / `else if` / `else` and `switch`, so
  a program can choose between paths based on data.
- **Last week left broken:** a program can choose once, but any
  repeated task still needs the same lines pasted over and over.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# Typing the Same Line 1000 Times

<div class="pain">

Imagine writing code to add up 1000 survey responses, or to check
every single line in a file, or to keep asking someone for a value
until they finally type something valid.

Right now, the only way you know how to do this is to write out the
same instruction once for every single item. For 1000 responses, that
is 1000 near-identical lines. That is not just tiring - it does not
even work if you don't know the count in advance.

</div>

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Any task that repeats - summing numbers, validating input,
  processing records - becomes unmanageable to write by hand.
- Code that is copy-pasted many times is hard to read, hard to fix
  (change one copy, forget the other nine), and simply cannot scale
  to "however many the user gives us."

<div class="why">
<strong>In industry:</strong> virtually every real program, from a
data-analysis script to a web server handling requests, contains at
least one loop. Not knowing how to write one is not an option.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How does a program repeat a block of code without writing it out by hand each time?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Write `while` and `do-while` loops with correct init/condition/
   update structure.
2. Use loops for counting and accumulation.
3. Read input until a sentinel value (e.g., -1 to stop).
4. Diagnose a misbehaving loop using `printf`-tracing.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

<div class="thread">Under the hood: loops as backward jumps.</div>

A `while` loop compiles to a compare-and-conditional-jump at the top,
and an unconditional **backward jump** at the bottom. The CPU jumps
back and re-executes the condition check on each pass.

Infinite loops happen when that backward jump always fires - the
program never reaches the exit condition, so it just keeps jumping
back forever.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# Loop / Iteration: Definition

> A loop tells the computer: "repeat this block of instructions until
> a certain condition is no longer true." Each individual run of the
> block is called an **iteration**, one pass through the loop.

Think of a song with a chorus: the chorus is the loop body, and
"repeat the chorus 3 times" is the loop condition. Without loops, to
add up 1000 numbers you would need 1000 separate lines of code. With a
loop, you need about 4.

---

<!-- SLOT 10: Mechanics - while syntax -->

# `while` Loop Syntax

```c
/* init */
while (condition) {
    /* body */
    /* update */
}
```

The condition is checked **before** each iteration. If it is false
from the very start, the body never runs at all.

```c
int i = 1;
while (i <= 5) {
    printf("%d\n", i);
    i++;           /* update: advance i */
}
```

---

<!-- SLOT 11: Mechanics - while flowchart -->

# Seeing It Run: while

<div class="pipeline">
<div class="stage"><div class="h">init</div><div class="s">runs once, e.g. i = 1</div></div>
<div class="arrow">&rarr;</div>
<div class="stage"><div class="h">condition?</div><div class="s">checked before every pass</div></div>
<div class="arrow">&rarr;</div>
<div class="stage"><div class="h">body, then update</div><div class="s">jumps back to condition</div></div>
</div>

If the condition is false the very first time it is checked, the body
never runs - not even once. That single fact is the whole difference
between `while` and `do-while`.

---

<!-- SLOT 12: Mechanics - do-while -->

# `do-while` Loop

```c
do {
    /* body */
} while (condition);   /* condition checked AFTER body */
```

The body runs **at least once** - useful for menus and input
validation, where you must show the menu or ask the question before
you have anything to check.

```c
int choice;
do {
    printf("Enter 1-3: ");
    scanf("%d", &choice);
} while (choice < 1 || choice > 3);
printf("You chose %d\n", choice);
```

---

<!-- SLOT 13: Mechanics - counting and accumulation -->

# Counting and Accumulation

**Pseudocode** for sum 1 to N:

```
INPUT n
SET sum = 0
SET i = 1
WHILE i <= n DO
    SET sum = sum + i
    SET i = i + 1
END WHILE
OUTPUT sum
```

```c
int n, sum = 0, i = 1;
scanf("%d", &n);
while (i <= n) {
    sum += i;   /* accumulate */
    i++;
}
```

---

<!-- SLOT 14: Mechanics - sentinel values -->

# Input-Until-Sentinel

A **sentinel** is a special "stop" value the user types to signal "I'm
done entering data." We often use `-1`, because scores, counts, and
prices are never negative, so `-1` cannot be a real data value.

Think of a sentinel like the word "STOP" at the end of an old
telegram: it carries no real information; it just means "message
over."

```c
int val, total = 0, count = 0;
scanf("%d", &val);
while (val != -1) {
    total += val;
    count++;
    scanf("%d", &val);
}
```

---

<!-- SLOT N-2: Worked example -->

# Worked Example: Number-Guessing Game (1/2)

```c
/* lab06_guess.c */
#include <stdio.h>

int main(void) {
    int secret = 42, guess;
    printf("Guess my number (1-100)!\n");
    do {
        printf("Your guess: ");
        scanf("%d", &guess);
        if (guess < secret)
            printf("Too low.\n");
        else if (guess > secret)
            printf("Too high.\n");
    /* ...continued next slide */
```

---

# Worked Example: Number-Guessing Game (2/2)

```c
    /* ...continued from previous slide */
    } while (guess != secret);
    printf("Correct!\n");
    return 0;
}
```

**Sample run:**
```
Guess my number (1-100)!
Your guess: 20   -> Too low.
Your guess: 60   -> Too high.
Your guess: 42   -> Correct!
```

---

<!-- Worked example line by line -->

# Guessing Game: Line by Line

<div class="cardlist">
<div class="card"><div class="h">do { ... }</div><div class="d">Runs at least once - we need one guess before we can check it.</div></div>
<div class="card"><div class="h">scanf("%d", &amp;guess);</div><div class="d">Reads one integer into guess. The & gives scanf the address to write to.</div></div>
<div class="card"><div class="h">if / else if</div><div class="d">Only one of "Too low" / "Too high" prints, or neither if the guess is correct.</div></div>
<div class="card"><div class="h">} while (guess != secret);</div><div class="d">Condition checked AFTER the body. Loop repeats until guess equals secret.</div></div>
</div>

**Key insight:** `do-while` is the right choice here because we always
need at least one guess before we can know whether the player has won.

---

<!-- Second worked example -->

# Worked Example: Running Average

<div class="thread">Reads numbers until -1, prints count and average.</div>

```c
int main(void) {
    int val, count = 0;
    double sum = 0;
    printf("Enter integers (-1 to stop): ");
    scanf("%d", &val);
    while (val != -1) {
        sum += val;
        count++;
        scanf("%d", &val);
    }
    if (count > 0)
        printf("Average: %.2f\n", sum / count);
    else
        printf("No values entered.\n");
    return 0;
}
```

---

<!-- Runtime-debugging moment, distinct pedagogical beat -->

<!-- _class: section -->

# The Runtime-Debugging Moment

<div class="driving-q">"How does a program repeat a block of code without writing it out by hand each time?"</div>

---

# When a Loop Misbehaves

**Scenario:** a student writes the sum-to-N program but the program
never finishes.

```c
int i = 0, sum = 0;
while (i <= n) {
    sum += i;
    /* forgot i++; */
}
```

This is an **infinite loop**: `i` never changes, so the condition
`i <= n` is always true, and the backward jump always fires.

---

# Printf-Tracing: Your First Debugging Tool

Add a temporary `printf` line inside the loop to print the variables
on every pass:

```c
printf("DEBUG: i=%d, sum=%d\n", i, sum);
```

**Printf-tracing** means adding temporary `printf` lines inside a loop
to print variable values on every pass, so you see what the program is
really doing instead of guessing. Delete the debug lines once fixed.

<div class="why">
This is a <strong>runtime</strong> bug: the code compiles fine, it
just misbehaves. You will use printf-tracing every week from here on,
and practice more systematic debugging in Week 14.
</div>

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Missing update (i++) in the loop</div><div class="d">Infinite loop; program freezes. Always include the update step.</div></div>
<div class="card"><div class="h">Condition false before the loop starts</div><div class="d">Loop body never executes. Check the init value satisfies the first condition.</div></div>
<div class="card"><div class="h">Off-by-one: i &lt; n vs i &lt;= n</div><div class="d">One too few or one too many iterations. Trace manually with a small n.</div></div>
<div class="card"><div class="h">Using = instead of != in a sentinel check</div><div class="d">Loop exits immediately or never. Use while (val != -1).</div></div>
</div>

---

<!-- SLOT N: Check yourself -->

# Check Yourself

1. You need to keep asking the user for a grade percentage (0-100)
   until they type a valid value, then print the letter grade. Should
   you use `while` or `do-while`? Why?
2. Trace this loop by hand: `int i = 0, sum = 0; while (i <= 3) { sum
   += i; i++; }`. What is `sum` when the loop ends?
3. In the sentinel-value pattern, why do we call `scanf` twice - once
   before the loop and once inside it?

---

# Answers

1. `do-while` - you must ask at least once before you have anything
   to validate, and the loop should keep repeating as long as the
   value is invalid.
2. `sum = 6` (0+1+2+3), after `i` becomes 4 and the condition `i <= 3`
   becomes false.
3. The first `scanf` (before the loop) gets the value the `while`
   condition needs to check for the very first time. The second
   `scanf` (inside the loop) reads the next value before the
   condition is checked again - otherwise the loop would test the
   same old value forever.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What `while` Cannot Do Yet

<div class="limits">
`while` repeats until a condition changes, and that solves repetition.
But when you already know exactly how many times you want to repeat -
say, exactly `n` times - you still need three separate lines: one to
initialize the counter, one for the condition, one for the update.
That is extra bookkeeping for a very common case.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 6 leaves **counting a fixed number of times** needing extra
bookkeeping lines unsolved: `while` repeats until a condition changes,
but counting still takes separate init/condition/update lines. **Week
7** addresses it: Loops II - `for` and nested loops.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- `while` checks its condition **before** the body; `do-while` checks
  it **after**, so the body always runs at least once.
- Loops handle counting, accumulation, and reading input until a
  sentinel value.
- `printf`-tracing is your first debugging tool: print variable values
  inside the loop to see what is really happening.
- **Lab page:** `book/src/labs/lab06-loops-while.md` for the sum-to-N,
  input validation, and guessing-game exercises.
- **Prepare:** review the sum-1-to-N pattern before next week - Week 7
  rewrites it with a `for` loop.

---

<!-- SLOT N+4: Thank You -->
<!-- _class: end -->

# Thank You
