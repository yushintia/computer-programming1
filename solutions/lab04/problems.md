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
