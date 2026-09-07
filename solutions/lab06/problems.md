# Lab 06: Loops I: while and do-while — Problems

## Guided In-Lab Exercises

### Exercise 1: Sum 1 to N

Read N from the user and print the sum 1 + 2 + ... + N.
Also print the formula result N x (N+1)/2 to verify.

File: `lab06_sum.c`

### Exercise 2: Input validation loop

Ask the user for a grade percentage (0 to 100). Keep asking until they enter a valid value.
Then print the corresponding letter grade.

File: `lab06_validate.c`

### Exercise 3: Guessing game

Implement a number-guessing game: the program picks (or is given) a secret number and the
user repeatedly guesses until correct, receiving "Too low." / "Too high." hints after each
guess. After the user guesses correctly, print how many guesses it took.

File: `lab06_guess.c`

## Challenge Problem

Write a program that finds and prints all **perfect numbers** up to 1000.
A perfect number equals the sum of its proper divisors (e.g., 6 = 1 + 2 + 3).

## Practice Problems

These are ungraded — extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Countdown

Read a starting number and use a `while` loop to count down from it to 1, printing each
number, then print "Liftoff!" on the same line after the last number.

File: `lab06_practice1_countdown.c`

Sample run:
```
Enter start number: 5   → 5 4 3 2 1 Liftoff!
```

### Practice 2: Sum of even numbers

Read N and use a `while` loop to add up only the even numbers from 1 to N.

File: `lab06_practice2_sum_evens.c`

Sample run:
```
Enter N: 10   → Sum of even numbers from 1 to 10: 30
```

### Practice 3: Digit counter

Read a positive integer and use a `while` loop that repeatedly divides by 10 to count
how many digits it has.

File: `lab06_practice3_digit_count.c`

Sample run:
```
Enter a positive integer: 4527   → Number of digits: 4
```

### Practice 4: PIN attempt limiter

Using a `do-while` loop, give the user up to 3 attempts to enter a correct 4-digit PIN
(hard-code the correct PIN as 1234). Print "Access granted." if they succeed, or
"Account locked." if all 3 attempts fail.

File: `lab06_practice4_pin_attempts.c`

Sample run:
```
Enter PIN: 1111
Incorrect PIN. Attempts left: 2
Enter PIN: 2222
Incorrect PIN. Attempts left: 1
Enter PIN: 1234
Access granted.
```

### Practice 5: Positive/negative counter

Read integers until the user enters a sentinel of 0, using a `while` loop. Count how
many entries were positive and how many were negative (0 itself just ends input).

File: `lab06_practice5_pos_neg_count.c`

Sample run (inputs: 5, -3, 8, -1, 0):
```
Positive count: 2
Negative count: 2
```

### Practice 6: Greatest common divisor

Read two positive integers and compute their greatest common divisor using a `while`
loop that applies the Euclidean algorithm (repeatedly replace the larger number with
the remainder of dividing by the smaller).

File: `lab06_practice6_gcd.c`

Sample run:
```
Enter two positive integers: 48 18   → GCD: 6
```

### Practice 7: Collatz step counter

Read a positive integer n. Using a `while` loop, repeatedly apply the rule: if n is
even, divide it by 2; if n is odd, replace it with 3n + 1. Count how many steps it
takes until n reaches 1.

File: `lab06_practice7_collatz_steps.c`

Sample run:
```
Enter a positive integer: 6   → Steps to reach 1: 8
```
