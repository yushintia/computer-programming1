# Lab 09: Functions I: Basics

| | |
|---|---|
| **Week** | 9 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 07 (all control flow), midterm experience |

**Why this lab matters:** Professional programs are never written as one long block of code. They are organized into named, reusable functions, in the same way a recipe is broken into steps that can be reused across many dishes. Functions let you write code once, test it in isolation, and call it from anywhere in your program. Every library you will ever use, from the C standard library to a graphics toolkit to a network API, is a collection of functions. This lab teaches you to write and use your own.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap midterm · 30 functions: definition, call, prototype, return · 15 live demo |
| B (Guided practice) | 50 | 40 guided mini-library lab · 10 debrief and pitfalls |
| C (Independent and wrap) | 50 | 35 independent exercises · 10 challenge · 5 submit and Week 10 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Define a function with a return type, parameter list, and body.
2. Declare a function prototype before `main` and define it after.
3. Call a function and use its return value.
4. Explain why breaking code into functions makes programs easier to write, test, and read.

---

## Recap

Until now, all your code has been inside `main`.
As programs grow, a single large `main` becomes hard to read and debug.
Functions let you **name a piece of logic**, call it anywhere, and test it independently.

---

## Background

### What Is a Function?

> **In plain words: function**
> A function is a named block of code that performs one specific task. You write it once
> and can call it (run it) as many times as you like, from anywhere in your program.
> Think of a function like a **recipe**: once you have written the recipe for "make toast,"
> you can follow it every morning without re-writing it. The recipe takes inputs
> (bread, butter) and produces an output (toast). In C, inputs are called *parameters*
> and the output is called the *return value*.
>
> Using functions has three big benefits:
> 1. **No repetition.** Write once, call many times.
> 2. **Easier to test.** You can test each recipe separately.
> 3. **Easier to read.** `max(a, b)` is far clearer than an in-line if-else every time.

> **In plain words: parameter vs argument**
> A *parameter* is the variable name in the function definition:
> `int max(int a, int b)` has parameters `a` and `b`.
> An *argument* is the actual value you pass when you call it:
> `max(10, 25)` passes arguments `10` and `25`.
> C copies each argument into its corresponding parameter. Changing the parameter inside
> the function does NOT change the original variable in the caller.

> **In plain words: return value**
> The *return value* is what the function sends back to the caller.
> `return 25;` hands the number 25 back so the caller can use it.
> A function can only return one value. If you need to change multiple variables,
> use pointers (Week 13) or restructure your design.

### Function Call and Return: the Jump

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 520 220" style="max-width:500px;display:block;margin:1.5em auto;">
  <title>Diagram showing function call and return flow. On the left is main with an arrow pointing right labeled call max(10, 25). On the right is the max function body. When return is reached an arrow labeled return 25 points back left to main where result equals 25 continues.</title>
  <defs>
    <marker id="arr-09" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
    <marker id="arr-09r" markerWidth="7" markerHeight="7" refX="2" refY="3" orient="auto">
      <path d="M7,0 L7,6 L0,3 z" fill="#2e7d32"/>
    </marker>
  </defs>
  <!-- main box -->
  <rect x="10" y="20" width="180" height="175" rx="8" fill="#eef4fa" stroke="#0b3d66" stroke-width="2"/>
  <text x="100" y="42" font-family="sans-serif" font-size="12" font-weight="bold" fill="#0b3d66" text-anchor="middle">main()</text>
  <text x="25" y="68" font-family="monospace" font-size="11" fill="#333">int bigger =</text>
  <rect x="25" y="78" width="150" height="28" rx="4" fill="#ddeeff" stroke="#0b3d66" stroke-width="1"/>
  <text x="100" y="97" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle">max(10, 25);</text>
  <text x="25" y="130" font-family="monospace" font-size="11" fill="#888">/* bigger = 25 */</text>
  <text x="25" y="150" font-family="monospace" font-size="11" fill="#333">printf(...,</text>
  <text x="25" y="165" font-family="monospace" font-size="11" fill="#333">    bigger);</text>
  <!-- max box -->
  <rect x="330" y="20" width="180" height="175" rx="8" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <text x="420" y="42" font-family="sans-serif" font-size="12" font-weight="bold" fill="#c07000" text-anchor="middle">max(a, b)</text>
  <text x="345" y="70" font-family="monospace" font-size="11" fill="#333">if (a &gt; b)</text>
  <text x="345" y="87" font-family="monospace" font-size="11" fill="#333">  return a;</text>
  <text x="345" y="104" font-family="monospace" font-size="11" fill="#333">else</text>
  <rect x="345" y="110" width="148" height="24" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1"/>
  <text x="419" y="127" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">return b; /* 25 */</text>
  <!-- call arrow -->
  <line x1="190" y1="92" x2="328" y2="92" stroke="#0b3d66" stroke-width="2" marker-end="url(#arr-09)"/>
  <text x="259" y="82" font-family="sans-serif" font-size="10" fill="#0b3d66" text-anchor="middle">call max(10, 25)</text>
  <!-- return arrow -->
  <line x1="328" y1="140" x2="190" y2="140" stroke="#2e7d32" stroke-width="2" marker-end="url(#arr-09r)"/>
  <text x="259" y="160" font-family="sans-serif" font-size="10" fill="#2e7d32" text-anchor="middle">return 25</text>
</svg>
<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 9.1.</strong> A function call and its return.</em></p>

### Function Anatomy

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

| Part | Purpose |
|------|---------|
| Return type (`int`) | The type of value the function sends back |
| Name (`max`) | How you call it |
| Parameters (`int a, int b`) | Input values the caller provides |
| Body `{ ... }` | What the function does |
| `return` | Sends a value back to the caller |

### `void` Functions

```c
void print_line(int n) {   /* no return value */
    for (int i = 0; i < n; i++) printf("-");
    printf("\n");
}
```

Call with: `print_line(30);`
No `return` needed (or write `return;` with no value).

> **Under the Hood: function calls**
>
> When you call a function, the CPU:
> 1. Pushes the arguments and return address onto the **call stack** (a region of RAM).
> 2. Jumps to the function's first instruction.
> 3. When `return` is reached, pops the stack and jumps back.
>
> Each function invocation gets its own **stack frame**, its own copy of local variables.
> The call stack is finite; calling functions recursively many thousands of times can overflow it.
> You will study the stack in depth in **System Programming**.

---

## Worked Examples

### Example 1: Mini math library

```c
/* lab09_mathlib.c */
#include <stdio.h>

int max(int a, int b);
int min(int a, int b);
int is_prime(int n);

int main(void) {
    printf("max(7,12) = %d\n", max(7, 12));
    printf("min(7,12) = %d\n", min(7, 12));
    printf("is_prime(17) = %d\n", is_prime(17));
    printf("is_prime(15) = %d\n", is_prime(15));
    return 0;
}

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
```

### Line by line

The three prototypes at the top tell the compiler: "these functions exist; trust me."
The definitions at the bottom provide the actual bodies.

| Line | What it does |
|------|-------------|
| `int max(int a, int b);` | Prototype for `max`. Declares that `max` takes two `int` parameters and returns one `int`. No body here; the semicolon ends the declaration. |
| `int min(int a, int b);` | Prototype for `min`. Same shape. |
| `int is_prime(int n);` | Prototype for `is_prime`. Takes one `int`, returns one `int` (1 = yes, 0 = no). |
| `printf("max(7,12) = %d\n", max(7, 12));` | Calls `max(7, 12)`. The call happens inside `printf`'s argument list. The return value (12) is plugged into `%d` and printed. `main` never sees a temporary variable; the value goes straight to `printf`. |
| `int max(int a, int b) { return (a > b) ? a : b; }` | Definition of `max`. `(a > b) ? a : b` is the ternary operator: "if a > b, give a; otherwise give b." This is equivalent to the if-else version but shorter. |
| `if (n < 2) return 0;` | Inside `is_prime`: any number below 2 is not prime. Return `0` (false) immediately. |
| `for (int i = 2; i * i <= n; i++)` | Only check divisors up to the square root of n. If n has no divisors up to sqrt(n), it is prime. This is a classic optimization. |
| `if (n % i == 0) return 0;` | If any divisor divides n evenly (remainder = 0), n is not prime. Return `0` and exit. |
| `return 1;` | If the loop finished without finding any divisor, n is prime. Return `1` (true). |

**Expected output:**
```
max(7,12) = 12
min(7,12) = 7
is_prime(17) = 1
is_prime(15) = 0
```

### Example 2: `factorial` function

```c
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}
```

---

## Guided In-Lab Exercises

### Exercise 1: Extend the math library (Part B)

Add these functions to the example above:
- `int gcd(int a, int b)` (greatest common divisor using Euclid's algorithm).
- `double power(double base, int exp)` (base raised to the integer exponent, without `<math.h>`).

Test each function from `main` with at least two inputs.

File: `lab09_mathlib.c`

### Exercise 2: Input validator as a function (Part B and C)

Write a function `int read_positive(void)` that:
1. Prompts "Enter a positive integer: "
2. Reads an integer
3. If it is 0 or negative, prints "Invalid, try again." and loops
4. Returns the valid positive integer

Use this function from `main` to read two values, then print their sum.

File: `lab09_validator.c`

### Exercise 3: Modular grade printer (Part C)

Write three functions:
- `double read_score(const char* label)` prints `label`, reads a double 0 to 100.
- `char grade_letter(double score)` returns the letter grade ('A' to 'F').
- `void print_report(double s1, double s2, double s3)` prints each score with its grade and the average.

File: `lab09_grades.c`

---

## Challenge Problem

Write a function `int count_digits(int n)` that counts how many digits the integer `n` has.
Write a function `int reverse_num(int n)` that reverses the digits of `n`.
Test both with several inputs including 0 and negative numbers.

File: `lab09_digits.c`

---

## Practice Problems

These are ungraded — extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Road trip distance converter

Write two functions that convert between kilometers and miles for a road trip planner:
`double km_to_miles(double km)` and `double miles_to_km(double miles)`. Test each
function with at least two distances and print the results with two decimal places.

File: `lab09_practice1_distance.c`

Sample run:
```
10.0 km = 6.21 miles
100.0 km = 62.14 miles
50.0 miles = 80.47 km
26.2 miles = 42.16 km
```

### Practice 2: Square and cube reporter

Write two functions `int square(int n)` and `int cube(int n)` that return the square and
cube of an integer. Call both functions from `main` for at least three different
integers, including a negative one, and print the results.

File: `lab09_practice2_squarecube.c`

Sample run:
```
square(3) = 9, cube(3) = 27
square(5) = 25, cube(5) = 125
square(-2) = 4, cube(-2) = -8
```

### Practice 3: Triangular garden plot calculator

Write `double triangle_area(double base, double height)` and
`double triangle_perimeter(double side_a, double side_b, double side_c)` for a
landscaper laying out triangular garden plots. Test both functions on two different
plots and print the area and perimeter for each, with two decimal places.

File: `lab09_practice3_triangle.c`

Sample run:
```
Plot 1: area = 24.00 (base 6.0, height 8.0)
Plot 1: perimeter = 24.00 (sides 6.0, 8.0, 10.0)
Plot 2: area = 54.00 (base 9.0, height 12.0)
Plot 2: perimeter = 36.00 (sides 9.0, 12.0, 15.0)
```

### Practice 4: Book reading pace estimator

Write `double pages_per_day(int total_pages, int days)` that computes a reader's average
pace, and `int days_to_finish(int total_pages, double pace)` that computes how many
whole days are needed to finish a book at a given pace, rounding any partial day up.
Test both functions with at least two scenarios.

File: `lab09_practice4_reading.c`

Sample run:
```
pages_per_day(300, 10) = 30.0 pages/day
days_to_finish(300, 30.0) = 10 days
days_to_finish(250, 40.0) = 7 days
```

### Practice 5: Parking garage fee calculator

Write `double parking_fee(int hours)` for a parking garage that charges a flat rate for
the first hour, an hourly rate for each additional hour, and never charges more than a
fixed daily maximum. Test the function with a short stay, a medium stay, and a stay long
enough to hit the maximum.

File: `lab09_practice5_parking.c`

Sample run:
```
parking_fee(1) = 5.00
parking_fee(4) = 11.00
parking_fee(10) = 20.00
```

### Practice 6: Recipe ingredient scaler

Write `double scaled_liquid(double base_amount, int base_servings, int target_servings)`
to scale a liquid ingredient to a new serving size, and
`int scaled_whole_items(int base_amount, int base_servings, int target_servings)` to
scale a whole-count ingredient (such as eggs), rounding to the nearest whole number.
Test both functions by scaling a 4-serving recipe up to two different serving sizes.

File: `lab09_practice6_recipe.c`

Sample run:
```
Scaling recipe from 4 to 6 servings:
Milk: 3.00 cups
Eggs: 5

Scaling recipe from 4 to 10 servings:
Milk: 5.00 cups
Eggs: 8
```

### Practice 7: Clock hour advancer

Write `int advance_hour(int start_hour, int hours_to_add)` that advances an hour on a
12-hour clock (hours numbered 1 to 12), wrapping from 12 back to 1. Support negative
shifts too, so the function can also rewind the clock, wrapping from 1 back to 12. Test
it with a shift that wraps forward, one that lands exactly on 12, and one negative
shift.

File: `lab09_practice7_clock.c`

Sample run:
```
advance_hour(10, 5) = 3
advance_hour(11, 3) = 2
advance_hour(5, -7) = 10
```

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Calling a function before its prototype | Warning: implicit declaration | Write the prototype above `main` |
| Wrong return type | Compiler warning; truncated value | Match the return type to what you `return` |
| Expecting a function to modify a caller variable | Variable unchanged in `main` | C passes by value. Return the new value or use a pointer (Week 13). |
| Missing `return` in non-void function | Undefined behaviour | All paths must reach a `return` |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Extended math library | `lab09_mathlib.c` | 4 |
| Input validator | `lab09_validator.c` | 3 |
| Modular grade printer | `lab09_grades.c` | 3 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 9 "Functions"
- K&R, Ch. 4 "Functions and Program Structure"
