# Lab 05: Conditional Statements — Problems

## Guided In-Lab Exercises

### Exercise 1: Leap year checker

A year is a leap year if it is divisible by 4, *except* years divisible by 100
are *not* leap years, *except* years divisible by 400 *are*.

Write a program that reads a year and prints "Leap year" or "Not a leap year".

File: `lab05_leap.c`

### Exercise 2: Menu with switch

Write a program that presents a menu:
```
1. Circle area
2. Square area
3. Triangle area
4. Quit
```
Read the user's choice (1 to 4). For choices 1 to 3, read the necessary dimensions
and print the area. For 4, print "Goodbye." Use `switch-case`.

File: `lab05_menu.c`

## Challenge Problem

Write a program that takes three integers and prints them in **ascending order**
without using arrays or sorting functions. Use only `if-else`.

## Practice Problems

These are ungraded — extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Even or odd

Read one integer and print "Even" or "Odd" using the modulo operator.

File: `lab05_practice1_even_odd.c`

Sample run:
```
Enter an integer: 7   → Odd
```

### Practice 2: Temperature advisory

Read a Celsius temperature (it may have a decimal part) and print one of "Freezing"
(below 0), "Cold" (0 up to 15), "Mild" (15 up to 25), or "Hot" (25 and above).

File: `lab05_practice2_temp_advisory.c`

Sample runs:
```
Enter temperature (C): 30   → Hot
Enter temperature (C): -5   → Freezing
```

### Practice 3: Triangle type checker

Read three side lengths. First check whether they can form a valid triangle (the sum
of any two sides must exceed the third). If valid, classify it as Equilateral (all
sides equal), Isosceles (exactly two equal), or Scalene (all different).

File: `lab05_practice3_triangle_type.c`

Sample runs:
```
Enter three side lengths: 3 4 5   → Valid triangle: Scalene
Enter three side lengths: 1 1 5   → Not a valid triangle
```

### Practice 4: Character classifier

Read one character and print "Vowel", "Digit", "Consonant", or "Other" depending on
what kind of character it is.

File: `lab05_practice4_char_classify.c`

Sample runs:
```
Enter a character: e   → Vowel
Enter a character: 7   → Digit
```

### Practice 5: Movie ticket pricing menu

Display a menu of ticket categories (1. Child $6.00, 2. Adult $12.00, 3. Senior $9.00).
Read the chosen category with `switch-case` and print the price. Then ask whether it is
a weekend showing; if so, add a $1.50 surcharge.

File: `lab05_practice5_ticket_price.c`

Sample run:
```
Enter category (1-3): 2
Weekend? (1=yes, 0=no): 1
Ticket price: $13.50
```

### Practice 6: Coordinate quadrant locator

Read an x and y coordinate. Print "Origin" if both are 0, "On x-axis" or "On y-axis" if
exactly one is 0, otherwise print which quadrant (I to IV) the point falls in.

File: `lab05_practice6_quadrant.c`

Sample runs:
```
Enter x and y: 3 -4   → Quadrant IV
Enter x and y: 0 0    → Origin
```

### Practice 7: Rock-paper-scissors judge

Read two players' choices as integers (1=Rock, 2=Paper, 3=Scissors) and print which
player wins the round, or that it is a tie, using only nested `if-else` and logical
operators (no arrays).

File: `lab05_practice7_rps_judge.c`

Sample runs:
```
Player 1: 1   Player 2: 3   → Player 1 wins!
Player 1: 2   Player 2: 2   → It's a tie!
```
