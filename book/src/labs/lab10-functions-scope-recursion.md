# Lab 10: Functions II: Scope & Recursion

| | |
|---|---|
| **Week** | 10 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 09 (function definition, call, prototype) |

**Why this lab matters:** Understanding variable scope prevents a whole category of bugs that beginners encounter when they expect a change inside a function to affect a variable outside it. Recursion, where a function calls itself, is the natural solution to a set of real problems: traversing a file-system tree, parsing nested data, and implementing algorithms like merge sort. Tracing recursion on paper also builds your mental model of the call stack, which is essential background for debugging and for system-level programming.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap · 30 scope, pass-by-value, recursion basics · 15 live demo |
| B (Guided practice) | 50 | 40 guided recursive lab · 10 debrief and pitfalls |
| C (Independent and wrap) | 50 | 35 independent exercises · 10 challenge · 5 submit and Week 11 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Distinguish between local and global scope and explain why global variables are avoided.
2. Explain pass-by-value: why changing a parameter inside a function does not change the caller's variable.
3. Write a simple recursive function with a clear base case and recursive case.
4. Trace a recursive call on paper using a call-stack diagram.

---

## Recap

In Week 9 you learned to define, prototype, and call functions.
This week you go deeper: how does scope work, why can't you change a caller's variable from inside a function,
and what is recursion, a function that calls itself?

---

## Background

### Key Terms

> **In plain words: scope**
> The *scope* of a variable is the region of the program where that variable exists
> and can be used. A variable declared inside a function (between `{` and `}`) is
> *local* to that function. It is created when the function starts and destroyed when
> the function returns. A variable declared outside all functions is *global*: every
> function can see it. Prefer local variables; global variables make programs hard to
> reason about because any function can change them at any time.

> **In plain words: pass-by-value**
> When you call a function and pass a variable, C makes a **copy** of the value and
> puts it in the parameter. The function works on the copy. If the function changes
> the copy, the original variable in the caller is NOT affected. This is called
> pass-by-value. Think of faxing a document: the recipient gets a copy; writing on it
> does not change your original. To let a function change a caller's variable, you
> pass a pointer (Week 13).

> **In plain words: recursion**
> A function is *recursive* if it calls itself. Each call works on a smaller version
> of the problem. You must define:
> 1. A **base case**: a simple situation where the function returns without calling itself.
> 2. A **recursive case**: a call that moves one step closer to the base case.
>
> Think of Russian nesting dolls: opening a doll reveals a smaller doll inside.
> You keep opening until you reach the smallest doll that cannot open further (base case).
> Then you close them back up one at a time, going back to the original.

> **In plain words: stack frame**
> Every function call gets its own private workspace in a region of memory called the
> *call stack*. This workspace is called a *stack frame*. It holds the function's local
> variables and the address to return to when done. When a recursive function calls
> itself, a new frame is pushed on top. Frames are popped off as each call returns.
> Calling too deeply fills the stack and crashes the program (stack overflow).
>
> Think of a stack of plates. Each function call adds one plate to the top. Each
> return removes the top plate. You can only ever work on the top plate.

### Local Scope and Pass-by-Value

Every variable declared inside a function is **local** to that function.
It exists only while the function is running; calling the function again gives a fresh copy.

```c
void increment(int x) {
    x = x + 1;          /* changes local x, NOT the caller's copy */
    printf("%d\n", x);  /* prints caller's value + 1 */
}

int main(void) {
    int a = 5;
    increment(a);       /* a is still 5 here */
    printf("%d\n", a);  /* prints 5 */
    return 0;
}
```

This is **pass-by-value**: C copies the value into the parameter.
To modify the caller's variable, you need pointers (introduced in Week 13).

### Recursion and the Call Stack

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 500 260" style="max-width:480px;display:block;margin:1.5em auto;">
  <title>Call stack diagram for factorial(4). Four frames are stacked. The bottom frame shows factorial(1) returns 1. Above it factorial(2) waiting for factorial(1). Above that factorial(3) waiting for factorial(2). At the top factorial(4) waiting for factorial(3). Arrows on the right show return values flowing back down: 1, then 2, then 6, then 24.</title>
  <defs>
    <marker id="arr-10" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#2e7d32"/>
    </marker>
  </defs>
  <!-- Stack label -->
  <text x="140" y="15" font-family="sans-serif" font-size="11" fill="#888" text-anchor="middle">Call Stack (grows upward)</text>
  <!-- Frame 4: factorial(1): bottom, runs first -->
  <rect x="10" y="200" width="260" height="45" rx="5" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="140" y="220" font-family="monospace" font-size="12" fill="#2e7d32" text-anchor="middle" font-weight="bold">factorial(1)</text>
  <text x="140" y="237" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">base case: return 1</text>
  <!-- Frame 3: factorial(2) -->
  <rect x="10" y="150" width="260" height="45" rx="5" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="140" y="170" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">factorial(2)</text>
  <text x="140" y="187" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">return 2 * factorial(1)</text>
  <!-- Frame 2: factorial(3) -->
  <rect x="10" y="100" width="260" height="45" rx="5" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="140" y="120" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">factorial(3)</text>
  <text x="140" y="137" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">return 3 * factorial(2)</text>
  <!-- Frame 1: factorial(4): top -->
  <rect x="10" y="50" width="260" height="45" rx="5" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="140" y="70" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">factorial(4)</text>
  <text x="140" y="87" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">return 4 * factorial(3)</text>
  <!-- Return value arrows -->
  <line x1="300" y1="222" x2="300" y2="182" stroke="#2e7d32" stroke-width="1.5" marker-end="url(#arr-10)"/>
  <text x="340" y="210" font-family="sans-serif" font-size="10" fill="#2e7d32">return 1</text>
  <line x1="300" y1="172" x2="300" y2="132" stroke="#2e7d32" stroke-width="1.5" marker-end="url(#arr-10)"/>
  <text x="340" y="160" font-family="sans-serif" font-size="10" fill="#2e7d32">return 2</text>
  <line x1="300" y1="122" x2="300" y2="82" stroke="#2e7d32" stroke-width="1.5" marker-end="url(#arr-10)"/>
  <text x="340" y="110" font-family="sans-serif" font-size="10" fill="#2e7d32">return 6</text>
  <text x="340" y="60" font-family="sans-serif" font-size="10" fill="#0b3d66" font-weight="bold">result = 24</text>
  <text x="340" y="76" font-family="sans-serif" font-size="9" fill="#888">(4 x 3 x 2 x 1)</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 10.1.</strong> The call stack for factorial(4).</em></p>

A function is **recursive** if it calls itself.
Every recursive function needs:
1. A **base case**: a condition where it returns without calling itself.
2. A **recursive case**: a call that moves toward the base case.

```c
int factorial(int n) {
    if (n <= 1) return 1;           /* base case */
    return n * factorial(n - 1);   /* recursive case */
}
```

> **Under the Hood: the call stack and recursion**
>
> Each recursive call pushes a new **stack frame** onto the call stack.
> `factorial(4)` pushes 4 frames before any return.
> Deep recursion (thousands of levels) can **overflow the stack**, crashing the program.
> In **System Programming** you will learn the exact size of the call stack
> and techniques to work around its limits.
> For this course, keep recursion depth reasonable (less than a few thousand).

---

## Worked Examples

### Example 1: Recursive countdown

```c
/* lab10_countdown.c */
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

### Line by line

| Line | What it does |
|------|-------------|
| `void countdown(int n)` | Function header. Return type `void` (nothing returned). Parameter `n` is a local copy of whatever the caller passes. |
| `if (n <= 0)` | **Base case check.** If n has reached zero or below, stop recurring. |
| `printf("Go!\n"); return;` | The base case action. Prints "Go!" then returns to whoever called this invocation. `return;` with no value is valid in a `void` function. |
| `printf("%d...\n", n);` | Print the current value of n. This happens BEFORE the recursive call, so numbers count down: 5, 4, 3... |
| `countdown(n - 1);` | **Recursive case.** Call countdown again with n minus 1. This pushes a new frame. The current frame waits here until the recursive call returns. |

**Trace for `countdown(3)`:**
```
countdown(3): print "3...", then call countdown(2)
  countdown(2): print "2...", then call countdown(1)
    countdown(1): print "1...", then call countdown(0)
      countdown(0): print "Go!", return
    (countdown(1) returns)
  (countdown(2) returns)
(countdown(3) returns)
```

**Expected output (`countdown(5)`):**
```
5...
4...
3...
2...
1...
Go!
```

### Example 2: Recursive sum of digits

```c
int digit_sum(int n) {
    if (n < 10) return n;               /* single digit: base case */
    return n % 10 + digit_sum(n / 10); /* peel last digit */
}
```

### Example 3: Recursion with two calls

A recursive function can call itself twice in one step. This `sum_range` adds the integers
from `lo` to `hi` by splitting the range in half, so each call makes two smaller calls:

```c
/* lab10_range_demo.c */
#include <stdio.h>

int sum_range(int lo, int hi) {
    if (lo == hi) return lo;                              /* base case: one number */
    int mid = (lo + hi) / 2;
    return sum_range(lo, mid) + sum_range(mid + 1, hi);  /* two recursive calls */
}

int main(void) {
    printf("sum_range(1, 4) = %d\n", sum_range(1, 4));
    return 0;
}
```

**Expected output:** `sum_range(1, 4) = 10`

**Trace:**
```
sum_range(1, 4): mid = 2, calls sum_range(1, 2) and sum_range(3, 4)
  sum_range(1, 2): mid = 1, calls sum_range(1, 1) and sum_range(2, 2)
    sum_range(1, 1) returns 1
    sum_range(2, 2) returns 2
  sum_range(1, 2) returns 3
  sum_range(3, 4): mid = 3, calls sum_range(3, 3) and sum_range(4, 4)
    sum_range(3, 3) returns 3
    sum_range(4, 4) returns 4
  sum_range(3, 4) returns 7
sum_range(1, 4) returns 3 + 7 = 10
```

Each call that is not a base case makes two calls, so one call creates a tree of calls
rather than a single chain. This example makes 7 calls in total. Every branch of the tree
must end at a base case, or the recursion never stops.

---

## Guided In-Lab Exercises

### Exercise 1: Recursive power (Part B)

Write `double power(double base, int exp)` recursively:
- Base case: `exp == 0` gives `1.0`
- Recursive case: `base * power(base, exp - 1)`

Test it and compare with your iterative version from Week 9.

File: `lab10_power.c`

### Exercise 2: Refactor a Week-7 program (Part B and C)

Take your `lab07_rtriangle.c` (right-aligned triangle) and rewrite it using
three functions:
- `void print_spaces(int n)` prints n spaces
- `void print_stars(int n)` prints n star characters and a newline
- `void print_triangle(int rows)` calls the above

File: `lab10_triangle.c`

### Exercise 3: Fibonacci (Part C)

Write `int fib(int n)` that returns the nth Fibonacci number recursively:
- `fib(0) = 0`, `fib(1) = 1`, `fib(n) = fib(n-1) + fib(n-2)`

Print `fib(0)` through `fib(10)` and note how slow it becomes for larger n.
(Why? Each call spawns two more calls: exponential growth.)

File: `lab10_fib.c`

---

## Challenge Problem

Write a recursive function `int gcd(int a, int b)` using the Euclidean algorithm:
- Base case: `b == 0` gives `a`
- Recursive case: `gcd(b, a % b)`

Compare with an iterative version and verify they give the same results.

File: `lab10_gcd.c`

---

## Practice Problems

These are ungraded: extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Donation total (recursive)

Write `int sum_to_n(int n)` recursively to total the first n days of a fundraiser's
daily donations, where day 1 collects 1 unit, day 2 collects 2 units, and so on through
day n. Base case: `n <= 0` returns 0. Test it with at least three values of n.

File: `lab10_practice1_donations.c`

Sample run:
```
sum_to_n(5) = 15
sum_to_n(10) = 55
sum_to_n(1) = 1
```

### Practice 2: Box packing multiplier (recursive)

Write `int recursive_multiply(int a, int b)` that computes `a * b` using recursive
repeated addition instead of the `*` operator, modeling the total items in `b` boxes of
`a` items each. Base case: `b == 0` returns 0. Test it with at least three pairs,
including a pair where `b` is 0.

File: `lab10_practice2_boxes.c`

Sample run:
```
recursive_multiply(6, 4) = 24
recursive_multiply(7, 0) = 0
recursive_multiply(5, 3) = 15
```

### Practice 3: Shopping cart discount (pass-by-value)

Write `int apply_discount(int price)` that returns a price after a 20% discount. In
`main`, call it on a shopping cart price and print the original price both before and
after the call to show it is unchanged (pass-by-value), then explicitly reassign the
caller's variable from the function's return value and print it again. Repeat for a
second price.

File: `lab10_practice3_discount.c`

Sample run:
```
Original price: 100
Price is unchanged after calling apply_discount: 100
Discounted price returned by the function: 80
After reassigning, original price is now: 80
Original price: 250
Price is unchanged after calling apply_discount: 250
Discounted price returned by the function: 200
After reassigning, original price is now: 200
```

### Practice 4: Stadium row seat counter (recursive)

Write `int total_seats(int n)` recursively to total the seats in the first n rows of a
stadium section, where row 1 has 1 seat and each following row has 2 more seats than
the row before it. Base case: `n <= 0` returns 0. Test it with at least three values
of n.

File: `lab10_practice4_seats.c`

Sample run:
```
total_seats(3) = 9
total_seats(5) = 25
total_seats(1) = 1
```

### Practice 5: Gym membership fee (recursive arithmetic sequence)

Write `int nth_term(int first_term, int common_diff, int n)` recursively to compute the
nth term of an arithmetic sequence, modeling a gym membership fee that starts at
`first_term` and increases by `common_diff` every year. Base case: `n == 1` returns
`first_term`. Test it with at least three combinations of starting fee, increase, and
term number.

File: `lab10_practice5_membership.c`

Sample run:
```
nth_term(50, 10, 4) = 80
nth_term(50, 10, 1) = 50
nth_term(100, 25, 5) = 200
```

### Practice 6: Binary representation printer (recursive)

Write `void print_binary(int n)` that recursively prints the binary digits of a
non-negative integer, most significant bit first, with no trailing newline. Recursive
case: recurse on `n / 2` before printing `n % 2`. Test it with at least three values,
including 0.

File: `lab10_practice6_binary.c`

Sample run:
```
print_binary(13) = 1101
print_binary(2) = 10
print_binary(0) = 0
```

### Practice 7: Digit product and multiplicative persistence (recursive)

Write `int digit_product(int n)` that recursively multiplies together the decimal
digits of a non-negative integer (base case: `n < 10` returns `n`). Then, in `main`,
repeatedly apply `digit_product` to 277 until the result is a single digit, printing
each step, and report how many steps it took (this is called the number's
multiplicative persistence).

File: `lab10_practice7_digitproduct.c`

Sample run:
```
digit_product(4) = 4
digit_product(39) = 27
digit_product(277) = 98
Multiplicative persistence of 277:
  277 -> 98
  98 -> 72
  72 -> 14
  14 -> 4
Persistence steps: 4, final digit: 4
```

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Missing base case | Stack overflow crash | Every recursive function must have a base case that terminates |
| Base case is never reached | Same as above | Ensure the recursive call moves toward the base case |
| Expecting pass-by-value to modify caller | Variable unchanged | Return the modified value, or use pointers (Week 13) |
| Global variable to share state | Works but fragile | Pass data via parameters and return values |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Recursive power | `lab10_power.c` | 3 |
| Refactored triangle | `lab10_triangle.c` | 3 |
| Fibonacci | `lab10_fib.c` | 4 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 9 "Functions"
- K&R, Ch. 4 "Functions and Program Structure"
