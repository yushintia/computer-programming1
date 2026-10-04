---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 3: Variables, Data Types & Expressions

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Recap Week 2 in one line (program structure, printf). Today we
give programs somewhere to store data, and a way to read it from the
user.
-->

---

<!-- SLOT 2: Where we are (Act 0 / LOCATE) -->

# Where We Are

<div class="roadmap">
<div class="wk"><div class="n">Wk 1</div><div class="t">Introduction</div></div>
<div class="wk"><div class="n">Wk 2</div><div class="t">Program Structure &amp; I/O</div></div>
<div class="wk now"><div class="n">Wk 3</div><div class="t">Variables &amp; Data Types</div></div>
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
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** the structure of a C program, and `printf`
  to print text, numbers, and escape sequences to the screen.
- **Last week left broken:** we can print fixed text, but every value
  in a program is still typed by hand, never provided by the user.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# The Program That Only Greets "Alice"

<div class="pain">

Suppose you write a program that prints "Hello, Alice! You are 20
years old." It works - but only for Alice, who is 20. If your
classmate Ben runs the exact same program, it still greets "Alice."

To greet Ben instead, you would have to open the code, change the
text by hand, and recompile the whole program. A program that cannot
remember or receive new information is not very useful to anyone but
the one person whose details are baked into it.

</div>

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Every program you write would need to be rewritten and recompiled
  for every new person, every new number, every new situation.
- Nothing you build could be interactive - no calculator, no
  converter, no form, no game that reacts to what someone types.

<div class="why">
<strong>In industry:</strong> almost no real software has its data
baked into the source code. Choosing the right type for a value (a
whole count vs. a price vs. a single character) is a daily decision,
and picking the wrong one is a classic source of bugs, like silently
losing the decimal part of a price.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How does a program store a value it doesn't know yet, and let the user provide it?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Name the basic data types (whole numbers, decimal numbers, single
   characters) and declare a variable of each.
2. Assign values to variables, define named constants that cannot
   change, and perform arithmetic.
3. Read a value typed by the user into a variable, making programs
   interactive.
4. Explain that a variable is a named location in memory with a fixed
   type and size.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

<div class="thread">Under the hood: a variable is a labeled box of bytes.</div>

When you declare `int age;`, the computer sets aside 4 bytes of RAM
and gives them the label `age`. The type `int` tells the compiler how
many bytes to use and how to interpret the bits stored there.

This is also why dividing one whole number by another drops the
decimal part: the result box can only hold a whole number, so any
fractional part is simply thrown away when the answer is stored.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# Variable: Definition

> A variable is a labelled storage box inside the computer's memory
> (RAM). You give it a name, say what kind of data it holds (its
> *type*), and the computer reserves the right amount of space.

Think of RAM as a long shelf of small boxes. A variable is one of
those boxes with a sticky label, so you can find it by name instead
of by shelf number.

---

<!-- Act 3 / BUILD -->

<!-- SLOT 10: Mechanics - variables as labeled boxes -->

# Variables as Labeled Boxes in RAM

<div class="cardlist">
<div class="card"><div class="h">int age = 20;</div><div class="d">Takes 4 bytes. The number 20 is stored; the rest hold 0.</div></div>
<div class="card"><div class="h">double gpa = 3.75;</div><div class="d">Takes 8 bytes. Decimal numbers need more space for the fractional part.</div></div>
<div class="card"><div class="h">char grade = 'A';</div><div class="d">Takes 1 byte. The letter 'A' is stored as the number 65.</div></div>
</div>

Each type uses a fixed amount of space, which is why you must tell C
what type a variable is: the compiler needs to know how many bytes to
reserve.

---

<!-- SLOT 11: Mechanics - data types table -->

# Data Types

A data type tells the computer two things: how many bytes to reserve,
and how to interpret the bits stored there.

| Type | Size | Range / precision | Use |
|------|------|-------------------|-----|
| `int` | 4 bytes | roughly -2 billion to +2 billion | whole numbers |
| `float` | 4 bytes | ~6-7 significant digits | decimal numbers |
| `double` | 8 bytes | ~15-16 significant digits | decimal numbers (preferred) |
| `char` | 1 byte | single character (e.g. `'A'`) | letters, symbols |

**Prefer `double` over `float`** in this course - `float` has less
precision and causes hard-to-find rounding bugs.

---

<!-- SLOT 12: Mechanics - ASCII -->

# Characters Are Numbers

A `char` does not store a picture of a letter - it stores a small
integer, a code from a standard table called **ASCII**.

| Character | ASCII code |
|-----------|-----------|
| `'A'` | 65 |
| `'a'` | 97 |
| `'0'` | 48 |
| `' '` (space) | 32 |

Because `char` values are integers, arithmetic works on them:
`'A' + 1` equals `66`, which is `'B'`.

---

<!-- SLOT 13: Mechanics - declaration vs initialization -->

# Declaration vs. Initialization

*Declaring* a variable means telling C "I need a box called X of type
Y" - the box exists, but its contents are unknown garbage.
*Initializing* means putting a starting value in at the same time.

```c
int age;           /* declaration only: box exists, value is garbage */
age = 20;          /* assignment: put 20 into the box */
int score = 95;    /* declaration AND initialization in one line */
```

Like buying a notebook: declaring it is buying it (it exists).
Initializing it is writing your name on the first page right away.
Always initialize before reading a variable.

---

<!-- SLOT 14: Mechanics - constants -->

# Constants: `const` and `#define`

```c
const double PI = 3.14159;   /* typed constant: compiler enforces it */
#define MAX 100              /* preprocessor replacement */
```

`const double PI = 3.14159;` creates a named constant - the compiler
knows the type and stops you from changing it. `#define MAX 100` is a
find-and-replace that runs before the compiler even starts; it does
not know about types.

Use `const` for most constants in this course.

---

<!-- SLOT 15: Mechanics - expressions and arithmetic -->

# Expressions and Arithmetic

```c
int a = 10, b = 3;
int sum  = a + b;   /* 13 */
int diff = a - b;   /* 7  */
int prod = a * b;   /* 30 */
int quot = a / b;   /* 3  (integer division: decimal part is dropped) */
int rem  = a % b;   /* 1  (remainder: 10 = 3x3 + 1) */
```

`%` is the **modulo** operator: it gives the remainder after division,
not the quotient.

---

<!-- SLOT 16: Mechanics - truncation -->

# Integer Division: Truncation, Not Rounding

`10 / 3` gives `3`, not `3.333...` - the decimal part is dropped, not
rounded. This is called **truncation**: it always cuts toward zero, so
`3.9` becomes `3`, same as `3.1` becomes `3`.

To get the decimal result, write one number as a decimal first:

```c
10.0 / 3   /* gives 3.333... instead of 3 */
```

---

<!-- SLOT 17: Mechanics - scanf -->

# Reading Input with `scanf`

```c
int x;
printf("Enter a number: ");
scanf("%d", &x);
printf("You entered: %d\n", x);
```

`&x` means "the memory address of the box called `x`" - where on the
RAM shelf it lives. `scanf` needs this address to write the value
directly into the right box. Forgetting `&` is one of the most common
beginner mistakes, and it can crash the program.

| Specifier | Use with |
|-----------|----------|
| `%d` | `int` |
| `%f` | `float` |
| `%lf` | `double` |
| `%c` | `char` |

---

<!-- SLOT N-2: Worked example -->

# Worked Example: Interactive Greeting

```c
/* lab03_greet.c */
#include <stdio.h>

int main(void) {
    int age;
    char initial;
    printf("Enter your first initial: ");
    scanf(" %c", &initial);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Hello, %c! You are %d years old.\n", initial, age);
    return 0;
}
```

---

# Interactive Greeting: Line by Line (1/2)

<div class="cardlist">
<div class="card"><div class="h">int age; char initial;</div><div class="d">Declares two boxes: one whole number, one single character.</div></div>
<div class="card"><div class="h">scanf(" %c", &amp;initial);</div><div class="d">Waits for a character, stores it in initial. The leading space skips leftover whitespace from a previous Enter press.</div></div>
</div>

---

# Interactive Greeting: Line by Line (2/2)

<div class="cardlist">
<div class="card"><div class="h">scanf("%d", &amp;age);</div><div class="d">Waits for a whole number, stores it in age. %d matches an int; &amp;age is the address of the box.</div></div>
<div class="card"><div class="h">printf("Hello, %c! ... %d ...", initial, age);</div><div class="d">%c is replaced by the letter, %d by the number - now using both values the user typed in.</div></div>
</div>

**Sample run:**
```
Enter your first initial: A
Enter your age: 20
Hello, A! You are 20 years old.
```

---

# `printf` Precision: One New Piece

In `%.2f`, the `.2` is the **precision**: how many digits to print
after the decimal point. `%.2f` prints 2 digits, `%.4f` prints 4 - the
stored value keeps its full precision, only the display is shortened.
(Lab 4 covers the rest of a format specifier - width, alignment, and
more.)

---

# Worked Example: Integer vs. Float Division

```c
/* lab03_division.c */
#include <stdio.h>

int main(void) {
    int a = 7, b = 2;
    printf("int / int = %d\n", a / b);               /* 3   */
    printf("with a decimal = %.2f\n", 7.0 / b);     /* 3.50 */
    return 0;
}
```

`7.0` is written as a decimal number, so the division keeps its
fractional part: `3.50`, not `3`.

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Forgetting &amp; in scanf</div><div class="d">Program crashes or reads garbage. Always write scanf("%d", &amp;x), never scanf("%d", x).</div></div>
<div class="card"><div class="h">int / int when you want decimals</div><div class="d">Result is truncated, e.g. 7/2 gives 3. Write one side as a decimal: 7.0 / 2.</div></div>
<div class="card"><div class="h">Wrong format specifier</div><div class="d">%d for a double gives garbage output. Use %lf for double in scanf.</div></div>
<div class="card"><div class="h">Reading an uninitialized variable</div><div class="d">Unpredictable value - could be anything. Always assign before reading.</div></div>
</div>

---

<!-- SLOT N: Sample questions -->

# Sample Question 1

**Question:** You write `9 / 5` in C to convert Celsius to Fahrenheit. What does
this give you, and how would you fix it so it computes correctly?

---

# Sample Question 1: Answer

**Answer:** `9 / 5` is integer division, giving `1`, not `1.8`. Write `9.0 / 5.0`
so the division works on decimal numbers and gives the correct result.

---

# Sample Question 2

**Question:** What happens if you call `scanf("%d", x)` instead of
`scanf("%d", &x)`?

---

# Sample Question 2: Answer

**Answer:** `scanf` gets the current (garbage) *value* of `x` instead of its
*address*, so it does not know where to write the input - this
typically crashes the program or corrupts memory.

---

# Sample Question 3

**Question:** You need a value that never changes throughout the program, like
the number of days in a week. Which tool from this week fits, and
why?

---

# Sample Question 3: Answer

**Answer:** `const` (e.g. `const int DAYS = 7;`) - it is a typed constant the
compiler will not let you accidentally change.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What Variables and `scanf` Cannot Do Yet

<div class="limits">
Variables and `scanf` bring in one raw value, but every program still
runs exactly one path, no matter the input.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 3 leaves **precise control over how values are computed and
displayed** unsolved. **Week 4** addresses it: Input/Output &
Operators - formatted output, the full set of arithmetic, relational,
and logical operators, and explicit type casts.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- A variable is a named, typed box in memory: `int`, `double`, and
  `char` reserve different amounts of space.
- `scanf("%d", &x)` reads a value from the user into a variable -
  never forget the `&`.
- Integer division truncates (`7/2` is `3`); write `7.0 / 2` to keep
  the decimal part.
- **Lab page:** [Lab 03: Variables, Data Types & Expressions](../book/labs/lab03-variables-datatypes.html) for the
  temperature converter, circle geometry, and swap exercises.
- **Prepare:** review `%d`, `%f`/`%lf`, and `%c` before class - Week 4
  builds directly on these format specifiers.

---

<!-- SLOT N+4: Thank You -->
<!-- _class: end -->

# Thank You
