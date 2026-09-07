# Lab 03 — Problems (Guided Exercises & Challenge)

## Exercise 1: Temperature converter

Write a program that:

1. Asks the user for a temperature in Celsius.
2. Converts it to Fahrenheit: `F = C x 9/5 + 32`
3. Prints the result with 2 decimal places.

Watch out: `9/5` is integer division (result: 1). Use `9.0/5.0` or cast.

File: `lab03_temp.c`

## Exercise 2: Circle geometry

Write a program that:

1. Reads the radius from the user.
2. Computes area = pi * r^2 and circumference = 2 * pi * r.
3. Prints both with 4 decimal places.

Use `const double PI = 3.14159265;`

File: `lab03_circle.c`

## Exercise 3: Swap two values

Ask the user for two integers. Swap their values and print them after the swap.

Hint: you need a temporary variable (a third box to hold one value while you
rearrange the other two).

File: `lab03_swap.c`

## Challenge Problem: Digit splitter

Write a program that reads a four-digit integer (e.g., 2025) and prints its
individual digits:

```
Thousands: 2
Hundreds:  0
Tens:      2
Units:     5
```

Hint: use integer division and modulo. For example, `2025 / 1000` gives `2`,
and `2025 % 1000` gives `025`.

File: `lab03_challenge_digits.c`

## Practice Problems

These are ungraded - extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Rectangle area and perimeter

Write a program that reads a rectangle's length and width (as `double`s),
then computes and prints its area and perimeter, each with two decimal
places.

File: `lab03_practice1_rectangle.c`

Sample run:
```
Enter the rectangle length: 5
Enter the rectangle width: 3
Area: 15.00
Perimeter: 16.00
```

### Practice 2: Sum, difference, and product

Write a program that reads two integers and prints their sum, difference,
and product, each on its own line.

File: `lab03_practice2_arithmetic.c`

Sample run:
```
Enter the first integer: 8
Enter the second integer: 3
Sum: 11
Difference: 5
Product: 24
```

### Practice 3: Next letter

Write a program that reads a single lowercase letter and prints the next
letter in the alphabet, computed with `char` arithmetic (adding 1 to the
character). Print both the entered letter and the next letter together
with their ASCII codes.

File: `lab03_practice3_nextletter.c`

Sample run:
```
Enter a lowercase letter: a
You entered 'a' (ASCII 97)
The next letter is 'b' (ASCII 98)
```

### Practice 4: Feet and inches to centimeters

Write a program that reads a height in feet and inches (as `int`s) and
converts it to centimeters using a typed constant
`const double CM_PER_INCH = 2.54;`. Print the result with two decimal
places.

File: `lab03_practice4_height.c`

Sample run:
```
Enter feet: 5
Enter inches: 7
Height: 170.18 cm
```

### Practice 5: Simple interest calculator

Write a program that reads a loan principal, an annual interest rate (as a
decimal, e.g. `0.05` for 5%), and a number of years, then computes and
prints the simple interest and the total amount owed, each with two
decimal places.

File: `lab03_practice5_interest.c`

Sample run:
```
Enter the principal amount: 1000
Enter the annual interest rate (e.g., 0.05 for 5%): 0.05
Enter the number of years: 3
Interest: 150.00
Total owed: 1150.00
```

### Practice 6: Split a bill

Write a program that reads a total bill in won and a number of friends
splitting it, then uses integer division to find each friend's equal share
and modulo to find the leftover won that cannot be split evenly.

File: `lab03_practice6_billsplit.c`

Sample run:
```
Enter the total bill in won: 50000
Enter the number of friends splitting it: 3
Each friend pays: 16666 won
Leftover (cannot be split evenly): 2 won
```

### Practice 7: Seconds to hours, minutes, seconds

Write a program that reads a duration in total seconds and breaks it down
into hours, minutes, and remaining seconds using chained integer division
and modulo (similar in spirit to the Challenge Problem's digit splitter,
but for a clock duration instead of a four-digit number).

File: `lab03_practice7_time.c`

Sample run:
```
Enter a duration in total seconds: 3725
Hours:   1
Minutes: 2
Seconds: 5
```
