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
