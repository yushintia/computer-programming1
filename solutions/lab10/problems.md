# Lab 10: Functions II - Scope & Recursion - Guided Exercises and Challenge

Prompts only, adapted from the lab text. See `answer-key/` for reference solutions.

## Guided In-Lab Exercises

### Exercise 1: Recursive power

Write `double power(double base, int exp)` recursively:
- Base case: `exp == 0` gives `1.0`
- Recursive case: `base * power(base, exp - 1)`

Test it and compare with your iterative version from Week 9.

File: `lab10_power.c`

### Exercise 2: Refactor a Week-7 program

Take your `lab07_rtriangle.c` (right-aligned triangle) and rewrite it using
three functions:
- `void print_spaces(int n)` prints n spaces
- `void print_stars(int n)` prints n star characters and a newline
- `void print_triangle(int rows)` calls the above

File: `lab10_triangle.c`

### Exercise 3: Fibonacci

Write `int fib(int n)` that returns the nth Fibonacci number recursively:
- `fib(0) = 0`, `fib(1) = 1`, `fib(n) = fib(n-1) + fib(n-2)`

Print `fib(0)` through `fib(10)` and note how slow it becomes for larger n.
(Why? Each call spawns two more calls: exponential growth.)

File: `lab10_fib.c`

## Challenge Problem

Write a recursive function `int gcd(int a, int b)` using the Euclidean algorithm:
- Base case: `b == 0` gives `a`
- Recursive case: `gcd(b, a % b)`

Compare with an iterative version and verify they give the same results.
