# Lab 04 — Problems (Guided Exercises & Challenge)

## Exercise 1: Receipt formatter

Write a program that reads a unit price and quantity, then prints a receipt:

```
Item price : 12500.00
Quantity   :        3
-----------------------
Subtotal   : 37500.00
Tax (10%)  :  3750.00
Total      : 41250.00
```

Use `printf` width and precision to align the numbers.

File: `lab04_receipt.c`

## Exercise 2: Boolean expressions

Write a program that reads two integers and prints the result (0 or 1) of:

- `a > b`
- `a == b`
- `a > 0 && b > 0`
- `!(a == b)`

File: `lab04_bool.c`

## Exercise 3: Precedence puzzle

Without running the code, predict the output of:

```c
int x = 2 + 3 * 4 - 1;
int y = (2 + 3) * (4 - 1);
int z = 10 / 3 + 10 % 3;
printf("%d %d %d\n", x, y, z);
```

Then write the program, run it, and check your prediction.

File: `lab04_precedence.c` (include your predicted values in a comment)

## Challenge Problem: Won banknote breakdown

Write a program that reads a price in Korean won and prints the breakdown in:

- 50,000-won notes
- 10,000-won notes
- 5,000-won notes
- 1,000-won notes
- Remaining coins (won less than 1000)

Example: 127,300 won gives 2 x 50,000 + 2 x 10,000 + 1 x 5,000 + 2 x 1,000
+ 300 won coins.

File: `lab04_challenge_won.c`

## Practice Problems

These are ungraded - extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Field width explorer

Write a program that reads an integer and prints it three times using
three different width specifiers: right-aligned in a 6-character field,
left-aligned in a 6-character field, and zero-padded in a 6-character
field. Wrap each printed value in square brackets so the padding is
visible.

File: `lab04_practice1_width.c`

Sample run:
```
Enter an integer: 42
Right-aligned width 6: [    42]
Left-aligned width 6 : [42    ]
Zero-padded width 6  : [000042]
```

### Practice 2: Precision explorer

Write a program that reads a decimal price and prints it three times using
three different precisions: 0, 1, and 3 digits after the decimal point.

File: `lab04_practice2_precision.c`

Sample run:
```
Enter a price: 19.995
0 decimals: 20
1 decimal : 20.0
3 decimals: 19.995
```

### Practice 3: Fuel purchase formatter

Write a program that reads the liters of fuel pumped and the price per
liter, computes the total cost, and prints an aligned two-column summary
(label and value) for liters, price per liter, and total, using `printf`
width and precision so the numbers line up.

File: `lab04_practice3_fuel.c`

Sample run:
```
Enter liters pumped: 35.5
Enter price per liter: 1650.0
Liters          35.50
Price/L       1650.00
----------------------
Total        58575.00
```

### Practice 4: Password strength checks

Write a program that reads a password's length and a flag (1 or 0) for
whether it contains a digit, then prints the 0/1 result of four checks:
length at least 8, has a digit, both conditions together, and the logical
negation of "has a digit". Use relational and logical operators only; `if`
is not needed (or expected) yet.

File: `lab04_practice4_password.c`

Sample run:
```
Enter the password length: 10
Does it contain a digit? (1 = yes, 0 = no): 1
length >= 8            : 1
has_digit == 1          : 1
length >= 8 && has_digit: 1
!(has_digit == 1)       : 0
```

### Practice 5: Discount and tax in one expression

Write a program that reads a price, a discount percentage, and a tax
percentage, then computes the final price using a single expression that
applies the discount and then the tax, relying on parentheses and operator
precedence rather than separate intermediate steps.

File: `lab04_practice5_discount.c`

Sample run:
```
Enter the original price: 100000
Enter the discount percent (e.g., 20): 20
Enter the tax percent (e.g., 10): 10
Final price: 88000.00
```

### Practice 6: BMI category flags

Write a program that reads a weight in kilograms and a height in meters,
computes the body mass index (`bmi = weight / (height * height)`), prints
it with two decimal places in a 6-character field, and then prints 0/1
flags for three BMI bands (underweight, normal, overweight) using
relational and logical operators.

File: `lab04_practice6_bmi.c`

Sample run:
```
Enter weight in kg: 70
Enter height in meters: 1.75
BMI:  22.86
Underweight (< 18.5)      : 0
Normal (18.5 to < 25)     : 1
Overweight (>= 25)        : 0
```

### Practice 7: Minutes to clock time

Write a program that reads the total minutes since midnight, formats the
time of day as zero-padded `HH:MM` using `/` and `%`, and then prints 0/1
flags for whether it is afternoon (hour at least 12) and whether the time
falls on an exact hour.

File: `lab04_practice7_clock.c`

Sample run:
```
Enter total minutes since midnight: 930
Time: 15:30
Is afternoon (hours >= 12): 1
Is exact hour (minutes == 0): 0
```
