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

## Practice Problems

These are ungraded — extra practice for the concepts in this lab. Solutions are not distributed with this page.

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
