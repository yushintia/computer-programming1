# Lab 07: Loops II: for and Nested Loops — Problems

## Guided In-Lab Exercises

### Exercise 1: Right-aligned triangle

Print a triangle that is **right-aligned** (spaces on the left):
```
      *
    * *
  * * *
* * * *
```
Read the number of rows from the user.

File: `lab07_rtriangle.c`

### Exercise 2: Hollow rectangle

Print a hollow rectangle of `*` characters given width and height:
```
* * * * *
*       *
*       *
* * * * *
```

File: `lab07_hollow.c`

### Exercise 3: Pre-midterm review problems

Solve these mixed problems (one file per task):

- **Review A:** Read N integers and print the largest and smallest.
- **Review B:** Print all integers from 1 to 100 that are divisible by 3 or 5 (but not both).
- **Review C:** Read a positive integer and print its digits in reverse order.

Files: `lab07_rev_a.c`, `lab07_rev_b.c`, `lab07_rev_c.c`

## Challenge Problem

Print a diamond pattern:
```
    *
   ***
  *****
 *******
  *****
   ***
    *
```
The number of rows in the top half is read from the user.

File: `lab07_diamond.c`

## Practice Problems

These are ungraded: extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Multiples of seven

Use a `for` loop to print every multiple of 7 from 7 up to 70, separated by spaces.

File: `lab07_practice1_multiples_of_seven.c`

Sample run:
```
Multiples of 7 up to 70:
7 14 21 28 35 42 49 56 63 70
```

### Practice 2: Sum of squares

Read n and use a `for` loop to compute 1^2 + 2^2 + ... + n^2.

File: `lab07_practice2_sum_of_squares.c`

Sample run:
```
Enter n: 5   → Sum of squares: 55
```

### Practice 3: Checkerboard grid

Read a board size n and use nested `for` loops to print an n x n grid that alternates
`X` and `O` like a checkerboard, based on whether `row + col` is even or odd.

File: `lab07_practice3_checkerboard.c`

Sample output (n = 4):
```
X O X O
O X O X
X O X O
O X O X
```

### Practice 4: Prime checker with break

Read a positive integer and use a `for` loop with `break` to test whether it is prime
(stop checking as soon as a divisor is found).

File: `lab07_practice4_prime_check.c`

Sample runs:
```
Enter a positive integer: 17   → 17 is Prime
Enter a positive integer: 15   → 15 is Not prime
```

### Practice 5: Sum skipping multiples

Read n and k. Use a `for` loop with `continue` to sum the integers from 1 to n while
skipping any multiple of k.

File: `lab07_practice5_sum_skip_multiples.c`

Sample run:
```
Enter n: 10
Enter k (skip multiples of k): 3   → Sum (excluding multiples of 3): 37
```

### Practice 6: ASCII bar chart

Read the number of categories, then for each one read a count and use nested `for`
loops to print a bar of that many `*` characters (no arrays: process and print each
category immediately after reading it).

File: `lab07_practice6_bar_chart.c`

Sample run:
```
Enter number of categories: 3
Category 1 count: 4
****
Category 2 count: 2
**
Category 3 count: 5
*****
```

### Practice 7: Armstrong number finder

A 3-digit Armstrong number equals the sum of the cubes of its own digits
(e.g., 153 = 1^3 + 5^3 + 3^3). Read a range (low, high, both between 100 and 999) and
use a `for` loop to print every 3-digit Armstrong number in that range.

File: `lab07_practice7_armstrong_finder.c`

Sample run:
```
Enter range start: 100
Enter range end: 500   → Armstrong numbers: 153 370 371 407
```
