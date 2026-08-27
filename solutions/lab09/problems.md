# Lab 09: Functions I - Basics - Guided Exercises and Challenge

Prompts only, adapted from the lab text. See `answer-key/` for reference solutions.

## Guided In-Lab Exercises

### Exercise 1: Extend the math library

Add these functions to the mini math library example (which already provides
`max`, `min`, and `is_prime`):
- `int gcd(int a, int b)` - greatest common divisor using Euclid's algorithm.
- `double power(double base, int exp)` - base raised to the integer exponent,
  without `<math.h>`.

Test each function from `main` with at least two inputs.

File: `lab09_mathlib.c`

### Exercise 2: Input validator as a function

Write a function `int read_positive(void)` that:
1. Prompts "Enter a positive integer: "
2. Reads an integer
3. If it is 0 or negative, prints "Invalid, try again." and loops
4. Returns the valid positive integer

Use this function from `main` to read two values, then print their sum.

File: `lab09_validator.c`

### Exercise 3: Modular grade printer

Write three functions:
- `double read_score(const char* label)` prints `label`, reads a double 0 to 100.
- `char grade_letter(double score)` returns the letter grade ('A' to 'F').
- `void print_report(double s1, double s2, double s3)` prints each score with
  its grade and the average.

File: `lab09_grades.c`

## Challenge Problem

Write a function `int count_digits(int n)` that counts how many digits the
integer `n` has.
Write a function `int reverse_num(int n)` that reverses the digits of `n`.
Test both with several inputs including 0 and negative numbers.
