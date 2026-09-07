---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 7: Loops II - for and Nested Loops

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Recap Week 6 (while / do-while) in one line, then move to
today's pain: counting a fixed number of times still needs three
separate lines of bookkeeping every time.
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
<div class="wk now"><div class="n">Wk 7</div><div class="t">Loops II: for</div></div>
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

- **Last week delivered:** `while` and `do-while`, so a program can
  repeat a block until a condition changes, plus your first debugging
  tool, `printf`-tracing.
- **Last week left broken:** `while` repeats until a condition
  changes, but counting a fixed number of times still takes extra
  bookkeeping lines - init, condition, and update, written separately.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# Three Lines Just to Count to Ten

<div class="pain">

Picture a seating chart, a pixel grid, or a game board: rows and
columns of related items, where you need to visit every single
position. Or picture printing a multiplication table, five rows by
five columns.

You already know how to repeat something with `while`, but every
single time you want to count "from 1 to n," you write three separate
lines: set the counter, check the counter, update the counter. For a
grid, you need to do that twice - once for rows, once for columns
inside each row - and it is easy to forget one piece.

</div>

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Writing the init/condition/update as three separate, scattered lines
  makes it easy to forget the update, or to update the wrong variable,
  especially once loops are nested inside each other.
- Grid-shaped problems (tables, patterns, seating charts, images)
  cannot be written cleanly without a compact, reliable way to count.

<div class="why">
<strong>In industry:</strong> the <code>for</code> loop is the most
commonly used loop in production C code, and nested loops are direct
preparation for 2-D arrays, image processing, and matrix arithmetic -
all things you will meet very soon.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How does a program count a known number of times, cleanly, and repeat that over a whole grid?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Write `for` loops and explain why they are preferred when the
   iteration count is known.
2. Write nested loops to generate 2-D output (multiplication tables,
   patterns).
3. Use `break` to exit a loop early and `continue` to skip to the next
   iteration.
4. Solve problems using a combination of loops and conditionals.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

<div class="thread">Under the hood: nested loops and work.</div>

A `for` loop compiles to the exact same compare-and-jump machinery as
`while` - it is really just `while` with its three bookkeeping pieces
bundled onto one line, for convenience and safety.

If the outer loop runs N times and the inner loop runs M times, the
body executes N x M times. Doubling N doubles the total work. This is
why nested loops can get slow for large inputs - a topic you will
study in depth in **Algorithms and Data Structures**.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# `for` Loop: Definition

> A `for` loop bundles the **init**, **condition**, and **update** of
> a counted repetition into one line: `for (init; condition; update)`.
> Use `for` when the number of iterations is known before the loop
> starts; use `while` when you are waiting for an event, like a
> sentinel value.

```c
for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

---

<!-- SLOT 10: Mechanics - anatomy of for -->

# Anatomy of a `for` Loop

<div class="pipeline">
<div class="stage"><div class="h">① init</div><div class="s">int i = 1 - runs once, before anything else</div></div>
<div class="arrow">&rarr;</div>
<div class="stage"><div class="h">② condition</div><div class="s">i &lt;= 5 - checked before every pass</div></div>
<div class="arrow">&rarr;</div>
<div class="stage"><div class="h">③ update</div><div class="s">i++ - runs after the body, then loops back</div></div>
</div>

All three pieces sit in the `for (...)` header, in that order, so
nothing gets scattered or forgotten. The body itself only has to
contain the actual work.

---

<!-- SLOT 11: Mechanics - for vs while -->

# `for` vs `while`: Same Machine, Different Packaging

```c
/* while version */              /* for version, same thing */
int i = 1;                       for (int i = 1; i <= 5; i++) {
while (i <= 5) {                     printf("%d\n", i);
    printf("%d\n", i);           }
    i++;
}
```

Both loops do exactly the same thing. `for` just keeps init,
condition, and update together in one place, so there is one less way
to forget a piece.

---

<!-- SLOT 12: Mechanics - nested loops -->

# Nested Loops: a Grid of Iterations

```c
for (int row = 1; row <= 3; row++) {
    for (int col = 1; col <= 4; col++) {
        printf("%4d", row * col);
    }
    printf("\n");
}
```

The inner loop runs fully for each single step of the outer loop. A
3x4 nested loop does 3 x 4 = 12 iterations total.

**Analogy:** a washing machine's program selector (outer loop)
combined with the drum's spin cycles (inner loop). For each wash
program, the drum spins a fixed number of times before the machine
moves to the next program. The inner loop always finishes completely
before the outer loop advances.

---

<!-- SLOT 13: Mechanics - break -->

# `break`: Stop the Loop Now

`break` immediately stops the loop and jumps to the first line
**after** the closing `}`. Use it once you have found what you were
looking for and there is no reason to keep iterating.

**Important:** `break` only exits the **innermost** loop. If you are
inside a nested loop, the outer loop keeps running.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;   /* exit loop when i reaches 5 */
    printf("%d\n", i);   /* prints 1, 2, 3, 4 */
}
```

---

<!-- SLOT 14: Mechanics - continue -->

# `continue`: Skip This Pass Only

`continue` skips the rest of the current loop body and goes straight
to the update step, then re-checks the condition. Use it to skip one
iteration without exiting the loop entirely.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;         /* exit loop when i reaches 5 */
    if (i % 2 == 0) continue;  /* skip even numbers */
    printf("%d\n", i);         /* prints 1, 3 */
}
```

---

<!-- SLOT N-2: Worked example -->

# Worked Example: Multiplication Table

<div class="thread">n x n table, read the size, print the products.</div>

```c
int main(void) {
    int n;
    printf("Print n x n table. n = ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    return 0;
}
```

---

<!-- Worked example line by line -->

# Multiplication Table: Line by Line

<div class="cardlist">
<div class="card"><div class="h">for (i = 1; i &lt;= n; i++)</div><div class="d">Outer loop. i is the current row, from 1 to n.</div></div>
<div class="card"><div class="h">for (j = 1; j &lt;= n; j++)</div><div class="d">Inner loop. For each row i, j runs all the way from 1 to n before i advances.</div></div>
<div class="card"><div class="h">printf("%4d", i * j);</div><div class="d">Prints i*j in a 4-character field so columns line up. No newline: stays on the row.</div></div>
<div class="card"><div class="h">printf("\n"); (outer)</div><div class="d">After the inner loop finishes one full row, move to the next line.</div></div>
</div>

**Sample output (n = 4):** row 2 gives `2*1=2, 2*2=4, 2*3=6, 2*4=8` -
each row is just that row number's own multiplication table.

---

<!-- Second worked example -->

# Worked Example: Triangle Pattern (1/2)

```c
int main(void) {
    int rows;
    printf("Number of rows: ");
    scanf("%d", &rows);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
```

---

# Worked Example: Triangle Pattern (2/2)

**Sample output (rows = 4):**
```
*
* *
* * *
* * * *
```

The inner loop's limit is `i`, not a fixed number - so each row prints
one more star than the row before it.

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Modifying the loop variable inside the body</div><div class="d">Loop runs the wrong number of times. Keep the update in the for header only.</div></div>
<div class="card"><div class="h">Off-by-one in nested loop bounds</div><div class="d">One extra or missing row/column. Trace with a small n (e.g. 3) on paper first.</div></div>
<div class="card"><div class="h">break only exits the innermost loop</div><div class="d">Outer loop keeps running. Use a flag variable if you need to exit multiple levels.</div></div>
<div class="card"><div class="h">Infinite for(;;) with empty condition</div><div class="d">Never terminates without a break. Make sure there is always a condition or a break.</div></div>
</div>

---

<!-- SLOT N: Check yourself -->

# Check Yourself

1. You need to print a right-aligned triangle, with spaces on the
   left so every row lines up on the right edge. How many nested
   loops do you need, and what does each one control?
2. Trace `for (int i = 1; i <= 3; i++) { for (int j = 1; j <= 2; j++)
   printf("*"); }`. How many stars print in total?
3. Inside a nested loop, you want to skip printing when a cell is on
   the border but keep looping. Do you use `break` or `continue`?

---

# Answers

1. Three: one for the row, one for the leading spaces (counts down as
   the row number goes up), one for the stars (counts up to the row
   number). Or two loops if spaces and stars are combined cleverly -
   but the leading-space count still depends on the row.
2. 6 stars: the outer loop runs 3 times, and for each one the inner
   loop prints 2 stars (3 x 2 = 6).
3. `continue` - you want to skip just that one cell and keep the loop
   running, not stop the whole loop.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What Loops Cannot Do Yet

<div class="limits">
Loops can repeat and nest, so a program can now process any amount of
data without pasting lines by hand. But a whole block of related loop
logic still cannot be reused without copy-pasting it - if you need the
same multiplication-table logic in three different places in your
program, you still have to write it out three times.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 7 leaves **reusing a block of logic without copy-pasting it**
unsolved. Next class is the **midterm exam** (Week 8, covering Weeks 1
to 7) - review the pre-midterm problems from Part C of this lab.
Afterward, **Week 9** addresses the reuse gap: Functions I.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- `for (init; condition; update)` bundles counted repetition into one
  line; prefer it whenever the number of iterations is known.
- Nested loops visit every cell of a grid: the inner loop finishes
  completely before the outer loop advances one step.
- `break` exits the innermost loop immediately; `continue` skips just
  the current pass.
- **Lab page:** `book/src/labs/lab07-loops-for-nested.md` for the
  triangle, hollow rectangle, and pre-midterm review problems.
- **Prepare:** the midterm (Week 8) covers Weeks 1-7, live in-lab
  coding - practice the Part C review problems (largest/smallest,
  divisible-by, digit reversal) before then.

---

<!-- SLOT N+4: Thank You -->
<!-- _class: end -->

# Thank You
