---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 10: Functions II - Scope & Recursion

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Goes deeper than Week 9: why parameters don't change the
caller's variable, and what happens when a function calls itself.
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
<div class="wk now"><div class="n">Wk 10</div><div class="t">Functions II: Recursion</div></div>
<div class="wk"><div class="n">Wk 11</div><div class="t">Arrays I: 1-D</div></div>
<div class="wk"><div class="n">Wk 12</div><div class="t">Arrays II: 2-D &amp; Strings</div></div>
<div class="wk"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** functions - a way to name a piece of logic
  once and call it anywhere, instead of copy-pasting it.
- **Last week left broken:** a function can't call itself, and every
  variable inside it disappears the moment it's needed again.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# A Job That Needs a Smaller Copy of Itself

<div class="pain">

Some tasks are naturally defined in terms of a smaller version of
themselves. "Count down from 5" is really "say 5, then count down
from 4." Right now, you have no way to write that - a function
finishing and calling itself again just isn't something you've done
yet.

And there's a second problem: two functions can't currently share a
running value between calls. Each time a function runs, it starts
completely fresh, with no memory of what happened last time.

</div>

<!-- notes: This restates Week 9's limit almost verbatim: a function
can't call itself, and every variable inside it disappears the moment
it's needed again. -->

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Tasks that are naturally "do this, then do a smaller version of the
  same thing" - like walking a folder of folders, or breaking a big
  number into digits - have no clean way to be written yet.
- Not understanding why a parameter change doesn't affect the caller
  leads to a very common class of "my function doesn't work" bugs.

<div class="why">
<strong>In industry:</strong> recursion is the natural solution for
tree and file-system traversal, parsing nested data (like JSON), and
algorithms such as merge sort. Interviewers ask candidates to trace
recursive calls on a whiteboard specifically to test this mental
model.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"Where does a variable actually live, and how can a function call a smaller version of itself?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Distinguish between local and global scope and explain why global
   variables are avoided.
2. Explain pass-by-value: why changing a parameter inside a function
   does not change the caller's variable.
3. Write a simple recursive function with a clear base case and
   recursive case.
4. Trace a recursive call on paper using a call-stack diagram.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

Every function call pushes a new **stack frame** onto the call stack -
its own private workspace in memory holding that call's local
variables and where to return to.

`factorial(4)` pushes 4 frames before any of them return. Deep
recursion (thousands of levels) can **overflow the stack** and crash
the program. In System Programming you will learn the exact size of
the call stack and how to work around its limits. For this course,
keep recursion depth reasonable - well under a few thousand calls.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# Scope: Definition

> The **scope** of a variable is the region of the program where that
> variable exists and can be used.

A variable declared inside a function is **local** to it: created
when the function starts, destroyed when it returns. A variable
declared outside all functions is **global**: every function can see
and change it. Prefer local variables - a global can be changed by
any function at any time, which makes programs hard to reason about.

---

<!-- SLOT 10: Mechanics -->

# Local Scope and Pass-by-Value

```c
void increment(int x) {
    x = x + 1;           /* changes local x, NOT the caller's copy */
    printf("%d\n", x);   /* prints caller's value + 1 */
}

int main(void) {
    int a = 5;
    increment(a);         /* a is still 5 here */
    printf("%d\n", a);    /* prints 5 */
    return 0;
}
```

When you pass `a` to `increment`, C makes a **copy** and gives it to
`x`. `increment` only ever touches its own copy.

---

<!-- SLOT 11: Mechanics -->

# Pass-by-Value: Why It Works This Way

Think of **faxing a document**: the recipient gets a copy. Writing on
their copy does not change your original.

- This is called **pass-by-value** - C copies the value into the
  parameter.
- It is why last week's rule held: a function can *use* the argument
  it's given, but never *change the caller's variable directly*.
- To let a function modify the caller's variable, you need pointers -
  introduced in Week 13.

---

<!-- SLOT 12: Mechanics -->

# Recursion: Base Case and Recursive Case

A function is **recursive** if it calls itself. Every recursive
function needs two parts:

1. A **base case**: a simple situation where it returns without
   calling itself again.
2. A **recursive case**: a call that moves one step closer to the
   base case.

```c
int factorial(int n) {
    if (n <= 1) return 1;          /* base case */
    return n * factorial(n - 1);  /* recursive case */
}
```

Think of **Russian nesting dolls**: you keep opening smaller dolls
until you reach the one that can't open further, then close them back
up one at a time.

---

<!-- SLOT 13: Mechanics -->

# Tracing the Call Stack

`factorial(4)` pushes four frames, each waiting on the one below it,
then unwinds as each `return` fires:

```
factorial(4) -> 4 * factorial(3)
  factorial(3) -> 3 * factorial(2)
    factorial(2) -> 2 * factorial(1)
      factorial(1) -> base case: return 1
    factorial(2) returns 2 * 1  = 2
  factorial(3) returns 3 * 2  = 6
factorial(4) returns 4 * 6  = 24
```

Each frame holds its **own** copy of `n` - that is exactly what
"local scope" means, applied to a function calling itself.

---

<!-- SLOT N-2: Worked example -->

# Worked Example: Recursive Countdown

```c
#include <stdio.h>

void countdown(int n) {
    if (n <= 0) {           /* base case */
        printf("Go!\n");
        return;
    }
    printf("%d...\n", n);
    countdown(n - 1);       /* recursive case */
}

int main(void) {
    countdown(5);
    return 0;
}
```

---

# Worked Example: Reading It

| Line | What it does |
|---|---|
| `if (n <= 0)` | Base case check - if `n` has reached zero, stop recurring |
| `printf("Go!\n"); return;` | Base case action: print, then return to the caller |
| `printf("%d...\n", n);` | Print `n` **before** the recursive call, so numbers count down |
| `countdown(n - 1);` | Recursive case: call again with `n - 1`, moving toward the base case |

**Output for `countdown(5)`:** `5...` `4...` `3...` `2...` `1...` `Go!`

Each call waits at `countdown(n - 1)` for its own recursive call to
finish, then simply returns - there's nothing left to do after it.

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Missing base case</div><div class="d">Stack overflow crash. Every recursive function must have a base case that terminates it</div></div>
<div class="card"><div class="h">Base case never reached</div><div class="d">Same crash. Make sure the recursive call actually moves toward the base case</div></div>
<div class="card"><div class="h">Expecting pass-by-value to modify the caller</div><div class="d">Variable stays unchanged. Return the new value, or use pointers (Week 13)</div></div>
<div class="card"><div class="h">Using a global variable to share state</div><div class="d">Works, but fragile. Pass data through parameters and return values instead</div></div>
</div>

---

<!-- SLOT N: Check yourself -->

# Check Yourself

1. In `increment(a)` from the local-scope example, why does `a` stay
   `5` in `main` after the call?
2. Write the base case and recursive case for a function
   `int digit_sum(int n)` that adds up the digits of `n` (hint:
   `n % 10` gives the last digit, `n / 10` drops it).
3. What happens if a recursive function is missing its base case?

---

# Answers

1. C passes arguments **by value** - `increment` receives a copy of
   `a` in its own local variable `x`. Changing `x` never touches the
   original `a` in `main`.
2. Base case: `if (n < 10) return n;` (a single digit is already its
   own sum). Recursive case:
   `return n % 10 + digit_sum(n / 10);` (add the last digit, then
   recurse on the rest).
3. It never stops calling itself. Each call pushes another stack
   frame until the call stack runs out of room - a stack overflow
   crash.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What Recursion and Scope Cannot Do Yet

<div class="limits">
Recursion and scope are solved, but every program so far holds only
ONE value per variable - never a whole list of them.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 10 leaves **storing more than one value under one name**
unsolved. **Week 11** addresses it: Arrays I - One-Dimensional Arrays.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- Local variables live and die inside their function; global
  variables are visible everywhere and should be avoided.
- C passes arguments **by value** - a function can never change the
  caller's variable directly through a parameter.
- Recursion needs a **base case** (stops the calls) and a
  **recursive case** (moves toward the base case).
- **Lab page:** `lab10-functions-scope-recursion.md` for the guided
  recursion lab and the Fibonacci exercise.
- **Prepare:** think about a list of 20 scores - how would you store
  all 20 with what you know today? Week 11 answers that.

---

<!-- SLOT N+4: Thank You (Act 4 / CLOSE) -->
<!-- _class: end -->

# Thank You
