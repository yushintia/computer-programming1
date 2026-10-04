---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 11: Arrays I - One-Dimensional Arrays

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: The project is announced this week too (see the lab page) -
mention it briefly at the end, it is not part of the slide content.
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
<div class="wk now"><div class="n">Wk 11</div><div class="t">Arrays I: 1-D</div></div>
<div class="wk"><div class="n">Wk 12</div><div class="t">Arrays II: 2-D &amp; Strings</div></div>
<div class="wk"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** functions that call themselves (recursion)
  and a clear picture of where variables actually live (scope).
- **Last week left broken:** every program so far holds only ONE
  value per variable - never a whole list of them.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# Thirty Names for Thirty Numbers

<div class="pain">

Imagine your program needs to remember 30 exam scores. Right now, the
only tool you have is one variable per value: `score1`, `score2`,
`score3`, all the way to `score30`. Adding them up means writing
`score1 + score2 + score3 + ...` by hand. Finding the highest one
means comparing thirty names, one by one, in your code.

Loops already solved "do this ten times." But there is still nothing
for the ten things being repeated *on* - each one still needs its own
separate name.

</div>

<!-- notes: This restates Week 10's limit almost verbatim: recursion
and scope are solved, but every program so far holds only ONE value
per variable, never a whole list of them. -->

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- A program with 30 separate variable names for 30 related values is
  slow to write, easy to typo, and impossible to loop over.
- Any task involving a *collection* - a list of readings, a set of
  prices, a batch of names - has no clean way to be written yet.

<div class="why">
<strong>In industry:</strong> arrays are the foundation everything
else is built on - a spreadsheet column, an image's pixels, a
database table's rows, all begin as an array in memory. "Array
indexing" and "off-by-one errors" are some of the most common topics
in entry-level coding interviews.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How do you store, and process, a whole collection of values under one name?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Declare, initialize, and index a one-dimensional array.
2. Traverse an array with a loop and implement sum, average,
   minimum/maximum, and linear search.
3. Explain why indexing starts at 0, and what out-of-bounds access
   causes.
4. Recognize that a text string is a row of characters ending in a
   special end marker, and preview how sorting and searching an array
   work.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

An array is a **contiguous block of memory** - one long, unbroken run
of boxes, all the same size, sitting right next to each other.

`a[i]` names the element at position `i`, counting from 0. Because the
elements sit side by side in order, the computer can find any of them
by counting from the start of the array. That is *why* `a[5]` on a
5-element array (valid positions are 0 to 4) reads whatever sits past
the end of the array. The computer does not check this for you; you
must.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# Array: Definition

> An **array** is a row of boxes in memory, all holding the same
> type, all sharing one name. You access each box by its position
> number, called the **index**.

Think of a row of numbered lockers in a school hallway: all lockers
are the same size (type), they sit in a row (contiguous memory), and
you find any one instantly by its number. Locker `#0` is the *first*
one, not locker `#1`.

---

<!-- SLOT 10: Mechanics -->

# Declaring and Initializing Arrays

```c
int scores[5];                     /* uninitialized: garbage values */
int primes[5] = {2, 3, 5, 7, 11}; /* initialized element by element */
int zeros[10] = {0};               /* all 10 elements set to 0 */
double data[] = {1.5, 2.5, 3.5};  /* compiler counts: size = 3 */
```

Without an array, storing 100 exam scores needs 100 separate variable
names. With one: `int scores[100];` creates all 100 boxes at once,
under a single name.

---

<!-- SLOT 11: Mechanics -->

# Index 0, and Out-of-Bounds

An array declared `int a[5]` has elements `a[0]` through `a[4]` - the
**last valid index is always `size - 1`**, here `4`. `a[5]` does not
exist, but C will not stop you from writing it.

<div class="why">
Reading or writing <code>a[5]</code> on a 5-element array is called
<strong>out-of-bounds access</strong>. The compiler does not check
this. The program touches whatever memory happens to be at that
address - another variable, a return address, anything. The result is
unpredictable: a crash, garbage output, or something that looks fine
until it suddenly isn't. Always make sure your loop condition is
<code>i &lt; n</code>, never <code>i &lt;= n</code>.
</div>

---

<!-- SLOT 12: Mechanics -->

# Traversal with a Loop

```c
int a[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
    printf("a[%d] = %d\n", i, a[i]);
}
```

A `for` loop is the natural match for an array: `i` starts at 0,
stops before `5`, and `a[i]` reads the box at position `i` on every
pass. This one loop pattern is the base for almost everything else
today - sum, average, min, max, and search all start this way.

---

<!-- SLOT 13: Mechanics -->

# Common Operations: Sum, Average, Min/Max

```c
/* Sum and average */
int sum = 0;
for (int i = 0; i < n; i++) sum += a[i];
double avg = (double)sum / n;

/* Minimum */
int min = a[0];
for (int i = 1; i < n; i++)
    if (a[i] < min) min = a[i];
```

Each pattern is the same shape: start with a running value (`sum` at
0, or `min` at the first element), then update it once per element as
the loop walks the array.

---

<!-- SLOT 14: Mechanics -->

# Arrays as Function Parameters

```c
void print_array(int a[], int n) {  /* array size is lost here */
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
```

A function receiving an array has no way to know how big it is - the
size information does not travel with it. **Always pass the size
`n` as a separate parameter**, every time you write a function that
takes an array.

---

<!-- SLOT 15: Mechanics -->

# Linear Search

```c
int search(int a[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (a[i] == target) return i;
    return -1;
}
```

Check each element left to right; return its index the moment it
matches, or `-1` if the loop finishes without a match. This works on
**any** array, sorted or not - but in the worst case it checks every
single element.

---

<!-- SLOT 16: Mechanics (preview) -->

# Preview: Strings Are Char Arrays

A **string** in C is not a special type - it is a one-dimensional
array of `char`, with one extra rule: the last real character is
followed by `'\0'` (the null terminator), marking "the text ends
here."

```c
char word[] = "Hi";        /* 'H', 'i', '\0' - 3 bytes */
printf("%s\n", word);      /* prints: Hi   */
printf("%c\n", word[0]);   /* prints: H    */
```

Because it is just an array, `word[0]` is the first character, like
any other array. The full string toolkit (`strlen`, `strcpy`,
`strcmp`) is next week's topic, in Lab 12.

---

<!-- SLOT 17: Mechanics (preview) -->

# Preview: Putting an Array in Order

To **sort** an array is to rearrange it into order. The simplest
method, **bubble sort**, walks left to right comparing neighbours and
swapping any pair that's out of order - after one pass, the largest
value has "bubbled" to the end.

```
start:  5 2 4 1
pass 1: 2 4 1 5     (5 bubbles to the end)
pass 2: 2 1 4 5
pass 3: 1 2 4 5     (sorted)
```

Bubble sort is slow on large arrays but easy to follow, which is why
it's the first sort most people learn. Faster methods, and how to
measure speed (Big-O), belong to a later Data Structures course.

---

<!-- SLOT 18: Mechanics (preview) -->

# Preview: Search Faster on Sorted Data

Linear search checks every element. On a **sorted** array, **binary
search** is much faster: check the middle element, discard the half
that can't contain the target, and repeat on what's left.

```
target = 16, sorted array: 1 4 8 15 16 23 42
step 1: mid = 15 -> 15 < 16 -> search the right half
step 2: mid = 23 -> 23 > 16 -> search the left half
step 3: mid = 16 -> found!
```

Each step **halves** the range - a 1000-element array takes at most
10 comparisons, not 1000. Binary search only works on data that is
already sorted.

---

<!-- SLOT N-2: Worked example -->

# Worked Example: Array Statistics (1/2)

```c
#include <stdio.h>
#define N 8

int main(void) {
    int a[N] = {34, 17, 88, 5, 62, 41, 99, 23};
    int sum = 0, min = a[0], max = a[0];

    for (int i = 0; i < N; i++) {
        sum += a[i];
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
```

The loop visits every element once, updating a running sum, minimum,
and maximum together - one pass, three statistics.

---

# Worked Example: Array Statistics (2/2)

```c
    printf("Sum: %d\n", sum);
    printf("Avg: %.2f\n", (double)sum / N);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    return 0;
}
```

---

# Worked Example: Reading It

| Line | What it does |
|---|---|
| `#define N 8` | A named constant - every `N` is replaced by `8` before compiling |
| `int sum = 0, min = a[0], max = a[0];` | Start `min` and `max` at the first element: a standard pattern |
| `for (int i = 0; i < N; i++)` | `i < N`, not `i <= N` - the last valid index is `N - 1` |
| `if (a[i] < min) min = a[i];` | Updates the running minimum only when a smaller value shows up |
| `(double)sum / N` | Casts before dividing, so the average keeps its decimal part |

**Output:** `Sum: 369`  `Avg: 46.12`  `Min: 5`  `Max: 99`

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Off-by-one: `i <= n`</div><div class="d">Reads or writes past the end of the array (crash or garbage). Always use `i < n`</div></div>
<div class="card"><div class="h">Accessing an uninitialized array</div><div class="d">Garbage values. Always fill it with `scanf` or assignment before reading it back</div></div>
<div class="card"><div class="h">Forgetting to pass the size</div><div class="d">Wrong results, possible out-of-bounds. Always pass `n` as a separate parameter</div></div>
<div class="card"><div class="h">`a = b` to copy an array</div><div class="d">Compilation error. Copy element by element, with a loop</div></div>
</div>

---

<!-- SLOT N: Sample questions -->

# Sample Question 1

**Question:** `int a[5]` is declared. What is the valid range of indices, and
what happens if you read `a[5]`?

---

# Sample Question 1: Answer

**Answer:** Valid indices are `0` through `4`. `a[5]` is out-of-bounds - it
reads whatever memory happens to sit right after the array, which
is unpredictable and never safe.

---

# Sample Question 2

**Question:** Write a loop that finds the **maximum** value in an array `a` of
size `n`.

---

# Sample Question 2: Answer

**Answer:** ```c
int max = a[0];
for (int i = 1; i < n; i++)
    if (a[i] > max) max = a[i];
```

---

# Sample Question 3

**Question:** Why must you always pass an array's size `n` into a function
alongside the array itself?

---

# Sample Question 3: Answer

**Answer:** A function receiving an array parameter has no way to know how
many elements it holds - that information doesn't travel with the
array. Without `n`, the function cannot know where to stop.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What 1-D Arrays Cannot Do Yet

<div class="limits">
A single list of numbers works, but real data is a grid (rows and
columns), and text itself has no dedicated type yet.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 11 leaves **grids of data, and a real toolkit for text**
unsolved. **Week 12** addresses it: Arrays II - 2-D Arrays & Strings.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- An array stores many values of one type under one name; index from
  `0` to `size - 1`; the compiler never checks bounds for you.
- Sum, average, min/max, and linear search all share one shape: walk
  the array once with a `for` loop, updating a running value.
- Always pass an array's size `n` as a separate function parameter.
- **Lab page:** [Lab 11: Arrays I: One-Dimensional Arrays](../book/labs/lab11-arrays-1d.html) - the guided stats lab, and this
  week's project announcement (due end of Week 14).
- **Prepare:** review today's `search` function before Week 12, which
  builds on it for searching arrays of strings.

---

<!-- SLOT N+4: Thank You (Act 4 / CLOSE) -->
<!-- _class: end -->

# Thank You
