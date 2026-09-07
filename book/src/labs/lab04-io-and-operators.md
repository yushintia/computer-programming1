# Lab 04: Input/Output & Operators

| | |
|---|---|
| **Week** | 4 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 03 (variables, scanf) |

**Why this lab matters:** Every program that calculates something, such as a tax bill, a body-mass index, a GPS distance, or a score in a game, uses arithmetic and logical expressions. This lab gives you the tools to build those calculations and to control exactly how values are formatted when displayed. The ability to write correct expressions is as fundamental to programming as arithmetic is to mathematics.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap · 30 formatted I/O, operators, and precedence · 15 live demo |
| B (Guided practice) | 50 | 40 guided calculator lab · 10 debrief and pitfalls (int division, cast) |
| C (Independent and wrap) | 50 | 35 independent exercises · 10 challenge · 5 submit and Week 5 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Format `printf` output using width, precision, and alignment specifiers.
2. Use arithmetic, relational, and logical operators correctly.
3. Predict the result of a mixed-type expression and apply explicit casts.
4. Explain operator precedence and use parentheses to override it.

---

## Recap

In Week 3 you stored data in variables and read it with `scanf`.
This week you learn to control *how* output looks (formatted I/O) and
deepen your understanding of the operations you can perform on data.

---

## Background

### Formatted Output: Width and Precision

> **In plain words: field width**
> When you write `%8d`, the `8` is the *minimum field width*: printf will use at least
> 8 characters to print the number, padding with spaces on the left if the number is
> shorter. Think of it like a fixed-width column in a table. Every number lines up
> at the right edge of its column, no matter how many digits it has.

> **In plain words: precision**
> When you write `%.4f`, the `.4` is the *precision*: how many digits to show after
> the decimal point. `printf("%.2f", 3.14159)` prints `3.14`; the extra digits are
> cut off (not rounded mathematically; the display is rounded, but the stored value
> is unchanged).

```c
printf("%8d\n", 42);       /* right-aligned in 8-char field: "      42" */
printf("%-8d|\n", 42);     /* left-aligned:                  "42      |" */
printf("%08d\n", 42);      /* zero-padded:                   "00000042" */
printf("%.4f\n", 3.14159); /* 4 decimal places:              "3.1416"  */
printf("%10.2f\n", 3.14);  /* width 10, 2 decimal places               */
```

**Reading a format specifier:** `%10.2f` breaks down as:
- `%` : start of a format specifier
- `10` : minimum field width (at least 10 characters)
- `.2` : precision (2 digits after the decimal point)
- `f` : type: floating-point number

The letter at the end of a format specifier is called the *conversion specifier*.
Width and precision (above) attach to these letters:

| Specifier | Type | Notes |
|-----------|------|-------|
| `%d` or `%i` | `int` | Decimal integer |
| `%u` | `unsigned int` | Unsigned decimal integer |
| `%f` | `float` / `double` (printf) | Decimal notation: `3.140000` |
| `%lf` | `double` (scanf) | Use `%lf` when reading with `scanf`; `%f` works in `printf` |
| `%e` | `float` / `double` | Scientific notation: `3.14e+00` |
| `%g` | `float` / `double` | Shorter of `%f` and `%e` |
| `%c` | `char` | Single character |
| `%s` | `char *` (string) | Character sequence until `\0` |
| `%x` | `int` | Hexadecimal (lowercase: `ff`) |
| `%o` | `int` | Octal |
| `%p` | pointer | Memory address (hex) |
| `%%` | (none) | Prints a literal `%` sign |

You met `%d`, `%f`, `%lf`, `%c` in Labs 02 and 03; the rest appear in later labs.

### Operator Precedence Pyramid

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 520 220" style="max-width:500px;display:block;margin:1.5em auto;">
  <title>Operator precedence pyramid. At the top (highest precedence) are parentheses, then unary operators, then multiply/divide/modulo, then add/subtract, then relational operators, then equality operators, then logical AND, and at the bottom (lowest precedence) logical OR.</title>
  <!-- pyramid rows, top = highest precedence -->
  <!-- Level 1: () -->
  <rect x="200" y="10" width="120" height="26" rx="5" fill="#0b3d66"/>
  <text x="260" y="28" font-family="monospace" font-size="12" fill="#fff" text-anchor="middle">( )  highest</text>
  <!-- Level 2: !, unary - -->
  <rect x="175" y="40" width="170" height="26" rx="5" fill="#1a5c99"/>
  <text x="260" y="58" font-family="monospace" font-size="12" fill="#fff" text-anchor="middle">!   unary -</text>
  <!-- Level 3: * / % -->
  <rect x="145" y="70" width="230" height="26" rx="5" fill="#2e7ab5"/>
  <text x="260" y="88" font-family="monospace" font-size="12" fill="#fff" text-anchor="middle">*   /   %</text>
  <!-- Level 4: + - -->
  <rect x="115" y="100" width="290" height="26" rx="5" fill="#4293cc"/>
  <text x="260" y="118" font-family="monospace" font-size="12" fill="#fff" text-anchor="middle">+   -</text>
  <!-- Level 5: < > <= >= -->
  <rect x="85" y="130" width="350" height="26" rx="5" fill="#6aaee0"/>
  <text x="260" y="148" font-family="monospace" font-size="12" fill="#fff" text-anchor="middle">&lt;   &gt;   &lt;=   &gt;=</text>
  <!-- Level 6: == != -->
  <rect x="55" y="160" width="410" height="26" rx="5" fill="#8ec7ee"/>
  <text x="260" y="178" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">==   !=</text>
  <!-- Level 7: && -->
  <rect x="25" y="190" width="470" height="26" rx="5" fill="#bbddf5"/>
  <text x="260" y="208" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">&amp;&amp;   then   ||   lowest</text>
</svg>
<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 4.1.</strong> Operator precedence, highest to lowest.</em></p>

**How to read the pyramid:** operators near the top are evaluated first (higher precedence).
Operators near the bottom are evaluated last. So in the expression `2 + 3 * 4`,
the `*` (level 3) happens before `+` (level 4), giving `2 + 12 = 14`, not `5 * 4 = 20`.

When two operators are at the same level, they are usually evaluated left to right:
`10 - 3 - 2` = `(10 - 3) - 2` = `5`, not `10 - (3 - 2)` = `9`.

When in doubt: **use parentheses**; they cost nothing and prevent bugs.

### Arithmetic Operators

| Op | Meaning | Example | Result |
|----|---------|---------|--------|
| `+` | Add | `3 + 4` | `7` |
| `-` | Subtract | `7 - 2` | `5` |
| `*` | Multiply | `3 * 4` | `12` |
| `/` | Divide | `7 / 2` | `3` (int!), `3.5` (float) |
| `%` | Modulo (remainder) | `7 % 2` | `1` |

### Relational and Logical Operators

| Op | Meaning |
|----|---------|
| `==`, `!=` | equal, not equal |
| `<`, `>`, `<=`, `>=` | comparisons |
| `&&` | logical AND |
| `\|\|` | logical OR |
| `!` | logical NOT |

These return `1` (true) or `0` (false). You will use them heavily in Week 5.

### Type Conversion and Casts

> **In plain words: cast**
> A cast is a way of telling the compiler: "treat this value as a different type, just
> for this one calculation." Writing `(double)a` does not change what is stored in `a`;
> it makes a temporary copy of `a`'s value as a decimal number for the division.
> Think of it like asking someone to read a measurement in inches when it was originally
> written in centimeters: the paper does not change, but the interpretation does.

```c
int a = 7, b = 2;
double result = (double)a / b;  /* cast a to decimal; result is 3.5 */
int truncated = (int)3.99;      /* cast to int: 3 (truncation, NOT rounding) */
```

Remember: truncation always goes toward zero. `(int)3.99` = 3. `(int)-3.99` = -3.

> **Under the Hood: operators map to CPU instructions**
>
> Each arithmetic operator compiles down to a single CPU instruction
> (ADD, SUB, MUL, DIV). The CPU works in a specific number of bits
> (32 or 64), which is why `int / int` discards the remainder.
> The integer division instruction throws it away.
> A cast changes how the compiler interprets the bits.

---

## Worked Examples

### Example 1: Formatted table

```c
/* lab04_table.c */
#include <stdio.h>

int main(void) {
    printf("%-10s %8s %10s\n", "Item", "Qty", "Price");
    printf("%-10s %8d %10.2f\n", "Pencil", 5, 1500.0);
    printf("%-10s %8d %10.2f\n", "Notebook", 2, 8500.0);
    printf("%-10s %8d %10.2f\n", "Eraser", 10, 500.0);
    return 0;
}
```

**Expected output:**
```
Item           Qty      Price
Pencil           5    1500.00
Notebook         2    8500.00
Eraser          10     500.00
```

### Line by line

Let's decode the header row: `printf("%-10s %8s %10s\n", "Item", "Qty", "Price");`

| Format piece | Value | What it prints | Why |
|-------------|-------|---------------|-----|
| `%-10s` | `"Item"` | `Item      ` (left-aligned in 10 chars) | `-` means left-align; `10` is the column width; `s` means string |
| `%8s` | `"Qty"` | `     Qty` (right-aligned in 8 chars) | No `-`, so right-align; 8-char column |
| `%10s` | `"Price"` | `     Price` (right-aligned in 10 chars) | 10-char column |
| `\n` | (none) | moves to the next line | newline character |

Every data row uses the same column widths (`%-10s`, `%8d`, `%10.2f`), so the numbers
line up vertically. This is why formatted output matters for tables and receipts.

### Example 2: Integer division pitfall

```c
/* lab04_divide.c */
#include <stdio.h>

int main(void) {
    int x = 5, y = 2;
    printf("5 / 2        = %d\n",   x / y);          /* 2 */
    printf("5.0 / 2      = %.1f\n", 5.0 / y);        /* 2.5 */
    printf("(double)5/2  = %.1f\n", (double)x / y);  /* 2.5 */
    printf("5 %% 2       = %d\n",   x % y);          /* 1 */
    return 0;
}
```

---

## Guided In-Lab Exercises

### Exercise 1: Receipt formatter (Part B)

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

### Exercise 2: Boolean expressions (Part B and C)

Write a program that reads two integers and prints the result (0 or 1) of:
- `a > b`
- `a == b`
- `a > 0 && b > 0`
- `!(a == b)`

File: `lab04_bool.c`

### Exercise 3: Precedence puzzle (Part C)

Without running the code, predict the output of:
```c
int x = 2 + 3 * 4 - 1;
int y = (2 + 3) * (4 - 1);
int z = 10 / 3 + 10 % 3;
printf("%d %d %d\n", x, y, z);
```
Then write the program, run it, and check your prediction.

File: `lab04_precedence.c` (include your predicted values in a comment)

---

## Challenge Problem

Write a program that reads a price in Korean won and prints the breakdown in:
- 50,000-won notes
- 10,000-won notes
- 5,000-won notes
- 1,000-won notes
- Remaining coins (won less than 1000)

Example: 127,300 won gives 2 x 50,000 + 2 x 10,000 + 1 x 5,000 + 2 x 1,000 + 300 won coins.

---

## Practice Problems

These are ungraded - extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Field width explorer

Write a program that reads an integer and prints it three times using three different width specifiers: right-aligned in a 6-character field, left-aligned in a 6-character field, and zero-padded in a 6-character field. Wrap each printed value in square brackets so the padding is visible.

File: `lab04_practice1_width.c`

Sample run:
```
Enter an integer: 42
Right-aligned width 6: [    42]
Left-aligned width 6 : [42    ]
Zero-padded width 6  : [000042]
```

### Practice 2: Precision explorer

Write a program that reads a decimal price and prints it three times using three different precisions: 0, 1, and 3 digits after the decimal point.

File: `lab04_practice2_precision.c`

Sample run:
```
Enter a price: 19.995
0 decimals: 20
1 decimal : 20.0
3 decimals: 19.995
```

### Practice 3: Fuel purchase formatter

Write a program that reads the liters of fuel pumped and the price per liter, computes the total cost, and prints an aligned two-column summary (label and value) for liters, price per liter, and total, using `printf` width and precision so the numbers line up.

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

Write a program that reads a password's length and a flag (1 or 0) for whether it contains a digit, then prints the 0/1 result of four checks: length at least 8, has a digit, both conditions together, and the logical negation of "has a digit". Use relational and logical operators only; `if` is not needed (or expected) yet.

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

Write a program that reads a price, a discount percentage, and a tax percentage, then computes the final price using a single expression that applies the discount and then the tax, relying on parentheses and operator precedence rather than separate intermediate steps.

File: `lab04_practice5_discount.c`

Sample run:
```
Enter the original price: 100000
Enter the discount percent (e.g., 20): 20
Enter the tax percent (e.g., 10): 10
Final price: 88000.00
```

### Practice 6: BMI category flags

Write a program that reads a weight in kilograms and a height in meters, computes the body mass index (`bmi = weight / (height * height)`), prints it with two decimal places in a 6-character field, and then prints 0/1 flags for three BMI bands (underweight, normal, overweight) using relational and logical operators.

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

Write a program that reads the total minutes since midnight, formats the time of day as zero-padded `HH:MM` using `/` and `%`, and then prints 0/1 flags for whether it is afternoon (hour at least 12) and whether the time falls on an exact hour.

File: `lab04_practice7_clock.c`

Sample run:
```
Enter total minutes since midnight: 930
Time: 15:30
Is afternoon (hours >= 12): 1
Is exact hour (minutes == 0): 0
```

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| `int / int` gives unexpected 0 or truncated result | e.g., `1/2` gives `0` | Cast one operand: `(double)a / b` |
| Confusing `=` (assign) with `==` (compare) | Silent wrong results | `a = 5` sets a; `a == 5` tests a |
| Forgetting `%%` to print a literal `%` in `printf` | `%` disappears or causes a warning | Use `%%` |
| Wrong precedence in complex expression | Unexpected result | Add parentheses |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Receipt formatter | `lab04_receipt.c` | 5 |
| Boolean expressions | `lab04_bool.c` | 3 |
| Precedence puzzle | `lab04_precedence.c` | 2 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 3 "Formatted Input/Output"
- King, Ch. 4 "Expressions"
- [Bonus: Bitwise Operators](../appendix/bonus/bitwise.md)
