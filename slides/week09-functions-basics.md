---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 9: Functions I - Basics

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: First new-content week after the midterm. Everything so far has
lived inside one main function. Today that changes.
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
<div class="wk now"><div class="n">Wk 9</div><div class="t">Functions I</div></div>
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

- **The midterm delivered:** proof that you can combine variables,
  I/O, operators, conditionals, and loops into a complete program.
- **It also left something exposed:** every one of those programs was
  one long `main`. Nothing you wrote could be reused without
  copy-pasting it.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# The Same Lines, Over and Over

<div class="pain">

Suppose your program needs to find the bigger of two numbers, in
three different places. Right now, you would write the same
comparison three separate times. If you later find a mistake in that
comparison, you have to fix it in three places - and hope you don't
miss one.

Loops solved repeating a single block many times in a row. They never
solved reusing a whole piece of logic in many different places,
across a program.

</div>

<!-- notes: This restates Week 7's limit almost verbatim: loops repeat
and nest, but a block of related loop logic still can't be reused
without copy-pasting it. -->

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Copy-pasted logic means copy-pasted bugs - fix one copy, forget the
  other two, and they quietly disagree with each other.
- A `main` that does everything becomes hard to read, hard to test,
  and hard to hand to someone else.

<div class="why">
<strong>In industry:</strong> every library you will ever use - the C
standard library, a graphics toolkit, a network API - is just a
collection of functions someone else already wrote and tested. Job
postings for entry-level programming roles list "writes modular,
reusable code" as a baseline expectation, not a bonus skill.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How do you name a piece of logic once, and reuse it anywhere in your program?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Define a function: its name, the inputs it takes, the result it
   hands back, and the steps it runs.
2. Declare a function before the code that calls it, and define it
   separately (a declaration, then a definition).
3. Call a function and use its return value.
4. Explain why breaking code into functions makes programs easier to
   write, test, and read.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

When you call a function, the CPU does three things:

1. Pushes the arguments and a return address onto the **call stack**
   (a region of RAM).
2. Jumps to the function's first instruction.
3. When `return` is reached, pops the stack and jumps back.

Each call gets its own **stack frame** - its own private copy of local
variables. The call stack is finite: calling functions very deeply can
overflow it. You will study the stack in depth in System Programming;
for now, just know it is what makes "jump there, then come back" work.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# Function: Definition

> A **function** is a named block of code that performs one specific
> task. You write it once and can call (run) it as many times as you
> like, from anywhere in your program.

Think of a function like a **recipe**: once you have written the
recipe for "make toast," you follow it every morning without
rewriting it. The recipe takes inputs (bread, butter) and produces an
output (toast). In C, inputs are **parameters** and the output is the
**return value**.

---

<!-- SLOT 10: Mechanics -->

# Function Anatomy

```c
/* PROTOTYPE (declaration): goes before main */
int max(int a, int b);

int main(void) {
    int bigger = max(10, 25);      /* CALL */
    printf("Max = %d\n", bigger);
    return 0;
}

/* DEFINITION: goes after main */
int max(int a, int b) {
    if (a > b) return a;
    else        return b;
}
```

---

<!-- SLOT 10 (cont.): Mechanics -->

# Function Anatomy: The Parts

| Part | Purpose |
|---|---|
| Return type (`int`) | Type of value sent back |
| Name (`max`) | How you call it |
| Parameters (`int a, int b`) | Input values the caller provides |
| Body `{ ... }` | What the function actually does |
| `return` | Sends a value back to the caller |

---

<!-- SLOT 11: Mechanics -->

# Parameters vs. Arguments

- A **parameter** is the variable name in the function's definition:
  `int max(int a, int b)` has parameters `a` and `b`.
- An **argument** is the actual value you pass when you call it:
  `max(10, 25)` passes arguments `10` and `25`.

C copies each argument into its matching parameter. Changing the
parameter inside the function does **not** change the original
variable in the caller - more on exactly why next week.

---

<!-- SLOT 12: Mechanics -->

# Return Values

`return 25;` hands the number 25 back to whoever called the function.

- A function can only return **one** value.
- The call and its return value can be used directly, without a
  temporary variable:

```c
printf("Max = %d\n", max(7, 12));   /* prints 12 directly */
```

If a task needs to change several values at once, `return` alone
isn't enough - that needs pointers, which come in Week 13.

---

<!-- SLOT 13: Mechanics -->

# `void` Functions

Not every function needs to send a value back.

```c
void print_line(int n) {   /* no return value */
    for (int i = 0; i < n; i++) printf("-");
    printf("\n");
}
```

Call it with `print_line(30);` - no `return` is needed (or write
`return;` with no value, to exit early).

---

<!-- SLOT N-2: Worked example -->

# Worked Example: A Mini Math Library (1/2)

```c
#include <stdio.h>

int max(int a, int b);
int min(int a, int b);
int is_prime(int n);

int main(void) {
    printf("max(7,12) = %d\n", max(7, 12));
    printf("is_prime(17) = %d\n", is_prime(17));
    printf("is_prime(15) = %d\n", is_prime(15));
    return 0;
}
```

The three prototypes above let `main` call these functions before
their real bodies appear below.

---

# Worked Example: A Mini Math Library (2/2)

```c
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}
```

---

# Worked Example: Reading It

- The three **prototypes** at the top tell the compiler "these
  functions exist, trust me" - the real bodies come later.
- `max(a, b)` uses the **ternary operator**: `(a > b) ? a : b` means
  "if a > b, give a; otherwise give b" - shorter than an if-else.
- `is_prime` returns `0` (false) the moment it finds a divisor, and
  only checks up to `i * i <= n` - a classic shortcut.
- `printf("... %d", max(7, 12))` calls `max` directly inside
  `printf`'s argument list - the return value goes straight to
  `%d`, no temporary variable needed.

**Output:** `max(7,12) = 12`, `is_prime(17) = 1`, `is_prime(15) = 0`

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Calling before the prototype</div><div class="d">Compiler warning: implicit declaration. Write the prototype above `main`</div></div>
<div class="card"><div class="h">Wrong return type</div><div class="d">Warning, and the value gets silently truncated. Match the return type to what you `return`</div></div>
<div class="card"><div class="h">Expecting a caller variable to change</div><div class="d">C passes by value - the caller's variable is untouched. Return the new value instead</div></div>
<div class="card"><div class="h">Missing `return` in a non-void function</div><div class="d">Undefined behaviour. Every path through the function must reach a `return`</div></div>
</div>

---

<!-- SLOT N: Sample questions -->

# Sample Question 1

**Question:** What is the difference between a function **prototype** and a
function **definition**?

---

# Sample Question 1: Answer

**Answer:** A prototype is just the header plus a semicolon, placed before
`main`, so the compiler knows the function exists. The definition
is the full header plus the `{ ... }` body, with the actual logic.

---

# Sample Question 2

**Question:** Write a function `int square(int n)` that returns `n * n`, then
show how you would call it inside a `printf`.

---

# Sample Question 2: Answer

**Answer:** `int square(int n) { return n * n; }`, called as
`printf("%d\n", square(5));`

---

# Sample Question 3

**Question:** Why can't a single function return two different values at once?

---

# Sample Question 3: Answer

**Answer:** A `return` statement can only send back one value. To change or
report more than one value, you need pointers (Week 13) or you
restructure the design (e.g., use a `struct`, later this course).

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What Functions Cannot Do Yet

<div class="limits">
Functions package logic, but a function can't call itself, and every
variable inside it disappears the moment it's needed again.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 9 leaves **a function calling itself, and variables that vanish
between calls** unsolved. **Week 10** addresses it: Functions II -
Scope & Recursion.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- A function has a return type, a name, parameters, and a body -
  declared with a prototype, called by name, defined once.
- Arguments are copied into parameters; a function can return exactly
  one value, or none (`void`).
- **Lab page:** [Lab 09: Functions I: Basics](../book/labs/lab09-functions-basics.html) for the guided mini-library
  lab and the independent exercises.
- **Prepare:** review today's `max`/`is_prime` example before Week 10 -
  next week asks *why* changing a parameter never affects the caller.

---

<!-- SLOT N+4: Thank You (Act 4 / CLOSE) -->
<!-- _class: end -->

# Thank You
