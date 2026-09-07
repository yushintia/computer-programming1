# Lab 03: Variables, Data Types & Expressions

| | |
|---|---|
| **Week** | 3 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 02 (printf, basic structure) |

**Why this lab matters:** Computers store everything, from a name to a price to a sensor reading to a pixel color, as numbers in memory. Choosing the right data type ensures your program stores values correctly, uses memory efficiently, and avoids errors such as storing a decimal as an integer and silently losing the fractional part. Data types are the vocabulary of programming: knowing them lets you express any real-world value precisely in code.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap · 30 types, declaration, expressions · 15 live demo |
| B (Guided practice) | 50 | 40 guided `scanf` and interactive program · 10 debrief and pitfalls |
| C (Independent and wrap) | 50 | 35 independent exercises (conversions) · 10 challenge · 5 submit and Week 4 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Declare variables of type `int`, `float`/`double`, and `char`.
2. Assign values, use constants (`const`, `#define`), and perform arithmetic.
3. Use `scanf` to read a value from the user, making programs interactive.
4. Explain that a variable is a named location in memory with a fixed type and size.

---

## Recap

In Week 2 you learned the structure of a C program and used `printf` for output.
Programs that only print fixed text are not very useful.
This week you add **variables** (places to store data)
and **`scanf`** (a way to read data from the keyboard)
so your programs can react to whatever the user types.

---

## Background

### What Is a Variable?

> **In plain words: variable**
> A variable is a labelled storage box inside the computer's memory (RAM).
> You give it a name, say what kind of data it holds (its *type*), and the
> computer reserves the right amount of space. Whenever you use the name in your
> code, the computer goes to that box and reads or writes the value inside.
>
> Think of RAM as a long shelf of identical small boxes. Each box holds a tiny
> piece of information. A variable is one of those boxes with a sticky label
> on it so you can find it by name instead of by shelf number.

### Variables as Labeled Boxes in Memory

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 580 160" style="max-width:560px;display:block;margin:1.5em auto;">
  <title>Three variable declarations shown as labeled boxes in RAM. int age occupies 4 bytes, double gpa occupies 8 bytes, and char grade occupies 1 byte. Each box shows the variable name, its value, and its byte size.</title>
  <defs>
    <marker id="arr-03" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- RAM label -->
  <rect x="10" y="10" width="560" height="100" rx="8" fill="#f5f9fd" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="285" y="130" font-family="sans-serif" font-size="11" fill="#0b3d66" text-anchor="middle" font-weight="bold">RAM (Main Memory)</text>
  <!-- int age: 4 bytes -->
  <rect x="30" y="30" width="48" height="60" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="78" y="30" width="48" height="60" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="126" y="30" width="48" height="60" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="174" y="30" width="48" height="60" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <!-- brace + label for age -->
  <text x="126" y="25" font-family="sans-serif" font-size="10" fill="#0b3d66" text-anchor="middle">int age = 20</text>
  <text x="54" y="65" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle">20</text>
  <text x="102" y="65" font-family="monospace" font-size="11" fill="#bbb" text-anchor="middle">0</text>
  <text x="150" y="65" font-family="monospace" font-size="11" fill="#bbb" text-anchor="middle">0</text>
  <text x="198" y="65" font-family="monospace" font-size="11" fill="#bbb" text-anchor="middle">0</text>
  <text x="126" y="82" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">4 bytes</text>
  <!-- double gpa: 8 bytes -->
  <rect x="250" y="30" width="30" height="60" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <rect x="280" y="30" width="30" height="60" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <rect x="310" y="30" width="30" height="60" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <rect x="340" y="30" width="30" height="60" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <rect x="370" y="30" width="30" height="60" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <rect x="400" y="30" width="30" height="60" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <rect x="430" y="30" width="30" height="60" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <rect x="460" y="30" width="30" height="60" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <text x="365" y="25" font-family="sans-serif" font-size="10" fill="#c07000" text-anchor="middle">double gpa = 3.75</text>
  <text x="365" y="65" font-family="monospace" font-size="9" fill="#c07000" text-anchor="middle">3.75</text>
  <text x="365" y="82" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">8 bytes (64-bit)</text>
  <!-- char grade: 1 byte -->
  <rect x="510" y="30" width="48" height="60" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="534" y="25" font-family="sans-serif" font-size="10" fill="#2e7d32" text-anchor="middle">char grade</text>
  <text x="534" y="56" font-family="monospace" font-size="12" fill="#2e7d32" text-anchor="middle">'A'</text>
  <text x="534" y="71" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">(65)</text>
  <text x="534" y="84" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">1 byte</text>
</svg>
<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 3.1.</strong> Variables as labeled boxes in RAM.</em></p>

The diagram above shows how three variables look in RAM:

- `int age = 20` takes up **4 boxes** (4 bytes) on the shelf. The number 20 is stored in the first byte; the rest hold 0.
- `double gpa = 3.75` takes up **8 boxes** (8 bytes). Decimal numbers need more space to store the fractional part.
- `char grade = 'A'` takes up **1 box** (1 byte). The letter 'A' is stored as the number 65.

Each type uses a fixed amount of space. That is why you must tell C what type a variable is: the compiler needs to know how many bytes to reserve.

> **In plain words: ASCII (characters are numbers)**
> A `char` does not actually store a picture of a letter; it stores a small integer.
> The integer is a code from a standard table called **ASCII** (American Standard Code
> for Information Interchange), which assigns a number to every printable character.
> That is why `'A'` prints as `65` and why the diagram shows `(65)` inside the box.
>
> | Character | ASCII code |
> |-----------|-----------|
> | `'A'` | 65 |
> | `'a'` | 97 |
> | `'0'` | 48 |
> | `' '` (space) | 32 |
>
> Because `char` values are integers, arithmetic works on them:
> `'A' + 1` equals `66`, which is `'B'`.
> This is also why `char` is only 1 byte: the 128 (or 256) ASCII codes fit in a single byte.

---

### Data Types

> **In plain words: data type**
> A data type tells the computer two things: how many bytes to reserve for a variable,
> and how to interpret the bits stored there. The same four bytes mean completely
> different things if you tell the computer "this is an integer" versus "this is a
> decimal number". Choosing the right type means choosing the right-sized, right-shaped box.

| Type | Size | Range / precision | Use |
|------|------|-------------------|-----|
| `int` | 4 bytes | roughly -2 billion to +2 billion | whole numbers |
| `float` | 4 bytes | ~6 to 7 significant digits | decimal numbers (less precise) |
| `double` | 8 bytes | ~15 to 16 significant digits | decimal numbers (preferred) |
| `char` | 1 byte | single character (e.g., `'A'`) | letters, symbols |

**Prefer `double` over `float`** for decimal numbers in this course.
`float` has less precision and causes hard-to-find rounding bugs.

---

### Declaration and Initialization

> **In plain words: declaration vs initialization**
> *Declaring* a variable means telling C "I need a box called X of type Y."
> The box exists but its contents are unknown garbage until you put something in.
> *Initializing* means putting a starting value into the box at the same time you create it.
> Always initialize variables before reading them; reading an uninitialized box is a bug.

```c
int age;           /* declaration only: box exists, value is garbage */
age = 20;          /* assignment: put 20 into the box */
int score = 95;    /* declaration AND initialization in one line */
```

Think of it like buying a new notebook. Declaring it is buying the notebook (it exists).
Initializing it is writing your name on the first page right away.

---

### Constants

Two ways to create a value that should not change:

> **In plain words: `const` and `#define`**
> `const double PI = 3.14159;` creates a named constant. The compiler knows the
> type and warns you if you try to change it. This is the safest way.
>
> `#define MAX 100` is a preprocessor shortcut. Before compiling, the preprocessor
> finds every word `MAX` in your file and replaces it with `100`. It does not know
> about types. Think of it like a find-and-replace in a text editor that runs before
> the compiler even starts. Use `const` for most constants; use `#define` when you
> need a simple integer or string label shared across multiple files.

```c
const double PI = 3.14159;   /* typed constant: the compiler will not let you change it */
#define MAX 100              /* preprocessor replacement: MAX becomes 100 everywhere */
```

---

### Expressions and Arithmetic

```c
int a = 10, b = 3;
int sum  = a + b;   /* 13 */
int diff = a - b;   /* 7  */
int prod = a * b;   /* 30 */
int quot = a / b;   /* 3  (integer division: decimal part is dropped) */
int rem  = a % b;   /* 1  (remainder after division: 10 = 3x3 + 1) */
```

**Integer division:** `10 / 3` gives `3`, not `3.333...`.
The decimal part is simply dropped, not rounded. This is called **truncation**.
To get the decimal result, force one of the numbers to be a decimal by casting:
`(double)a / b` gives `3.333...`

> **In plain words: truncation vs rounding**
> Truncation means "cut off the decimal part, no matter what." So 3.9 becomes 3, and
> 3.1 also becomes 3. It is NOT rounding. Rounding would turn 3.9 into 4, but
> truncation always goes toward zero. Integer division in C always truncates.

---

### Reading Input with `scanf`

Up to now your programs printed fixed text. `scanf` makes them interactive:
they ask the user a question and use whatever the user types.

```c
int x;
printf("Enter a number: ");
scanf("%d", &x);
printf("You entered: %d\n", x);
```

> **In plain words: the `&` in `scanf`**
> `&x` means "the memory address of the box called `x`"; in other words, where on
> the RAM shelf the box `x` is located. `scanf` needs this address so it can write
> the value the user types directly into the right box. Without `&`, you are telling
> `scanf` the *contents* of the box (the current garbage value), not *where* the box is.
> This is one of the most common beginner mistakes and causes a program crash.
> Always write `scanf("%d", &x)`, not `scanf("%d", x)`.
>
> You will understand addresses more deeply in Week 13 (pointers). For now, just
> remember: `scanf` always needs `&` in front of each variable name.

| Format specifier | Use with |
|------------------|----------|
| `%d` | `int` |
| `%f` | `float` |
| `%lf` | `double` |
| `%c` | `char` |

---

> **Under the Hood: a variable is a labeled box of bytes**
>
> When you declare `int age;`, the computer sets aside 4 bytes of RAM
> and gives them the label `age`. The type `int` tells the compiler
> how many bytes to use and how to interpret the bits stored there.
> This is why `int / int` drops the decimal: the result box can only hold an integer,
> so any fractional part is thrown away when the result is stored.

---

## Worked Examples

### Example 1: Interactive greeting

```c
/* lab03_greet.c */
#include <stdio.h>

int main(void) {
    int age;
    char initial;
    printf("Enter your first initial: ");
    scanf(" %c", &initial);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Hello, %c! You are %d years old.\n", initial, age);
    return 0;
}
```

### Line by line

| Line | What it does | Why |
|------|-------------|-----|
| `#include <stdio.h>` | Pulls in the I/O library | Gives us `printf` and `scanf` |
| `int age;` | Declares a box called `age` that holds a whole number | We will store the user's age here |
| `char initial;` | Declares a box called `initial` that holds one character | We will store the user's first letter here |
| `printf("Enter your first initial: ");` | Prints a prompt on screen (no newline) | Tells the user what to type next |
| `scanf(" %c", &initial);` | Waits for the user to type a character; stores it in `initial` | The space before `%c` skips any leftover whitespace (like a newline from a previous Enter press) |
| `printf("Enter your age: ");` | Prints the second prompt | Tells the user what to type next |
| `scanf("%d", &age);` | Waits for the user to type an integer; stores it in `age` | `%d` matches an `int`; `&age` is the address of the box |
| `printf("Hello, %c! You are %d years old.\n", initial, age);` | Prints the result using both stored values | `%c` is replaced by the letter; `%d` is replaced by the number |
| `return 0;` | Tells the OS the program finished without errors | A return value of 0 means success |

**Sample run:**
```
Enter your first initial: A
Enter your age: 20
Hello, A! You are 20 years old.
```

---

### Example 2: Integer vs float division

```c
/* lab03_division.c */
#include <stdio.h>

int main(void) {
    int a = 7, b = 2;
    printf("int / int = %d\n", a / b);               /* 3   */
    printf("cast to double = %.2f\n", (double)a / b); /* 3.50 */
    return 0;
}
```

`(double)a` converts the value of `a` to a decimal number before the division happens.
When C divides a decimal by an integer, it promotes the integer to decimal first,
so the result is `3.50` instead of `3`.

---

## Guided In-Lab Exercises

### Exercise 1: Temperature converter (Part B)

Write a program that:
1. Asks the user for a temperature in Celsius.
2. Converts it to Fahrenheit: `F = C x 9/5 + 32`
3. Prints the result with 2 decimal places.

File: `lab03_temp.c`

Watch out: `9/5` is integer division (result: 1). Use `9.0/5.0` or cast.

### Exercise 2: Circle geometry (Part B and C)

Write a program that:
1. Reads the radius from the user.
2. Computes area = pi * r^2 and circumference = 2 * pi * r.
3. Prints both with 4 decimal places.

Use `const double PI = 3.14159265;`

File: `lab03_circle.c`

### Exercise 3: Swap two values (Part C)

Ask the user for two integers. Swap their values and print them after the swap.
Hint: you need a temporary variable (a third box to hold one value while you rearrange the other two).

File: `lab03_swap.c`

---

## Challenge Problem

Write a program that reads a four-digit integer (e.g., 2025) and prints its individual digits:
```
Thousands: 2
Hundreds:  0
Tens:      2
Units:     5
```
Hint: use integer division and modulo. For example, `2025 / 1000` gives `2`, and `2025 % 1000` gives `025`.

File: `lab03_challenge_digits.c`

---

## Practice Problems

These are ungraded - extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Rectangle area and perimeter

Write a program that reads a rectangle's length and width (as `double`s), then computes and prints its area and perimeter, each with two decimal places.

File: `lab03_practice1_rectangle.c`

Sample run:
```
Enter the rectangle length: 5
Enter the rectangle width: 3
Area: 15.00
Perimeter: 16.00
```

### Practice 2: Sum, difference, and product

Write a program that reads two integers and prints their sum, difference, and product, each on its own line.

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

Write a program that reads a single lowercase letter and prints the next letter in the alphabet, computed with `char` arithmetic (adding 1 to the character). Print both the entered letter and the next letter together with their ASCII codes.

File: `lab03_practice3_nextletter.c`

Sample run:
```
Enter a lowercase letter: a
You entered 'a' (ASCII 97)
The next letter is 'b' (ASCII 98)
```

### Practice 4: Feet and inches to centimeters

Write a program that reads a height in feet and inches (as `int`s) and converts it to centimeters using a typed constant `const double CM_PER_INCH = 2.54;`. Print the result with two decimal places.

File: `lab03_practice4_height.c`

Sample run:
```
Enter feet: 5
Enter inches: 7
Height: 170.18 cm
```

### Practice 5: Simple interest calculator

Write a program that reads a loan principal, an annual interest rate (as a decimal, e.g. `0.05` for 5%), and a number of years, then computes and prints the simple interest and the total amount owed, each with two decimal places.

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

Write a program that reads a total bill in won and a number of friends splitting it, then uses integer division to find each friend's equal share and modulo to find the leftover won that cannot be split evenly.

File: `lab03_practice6_billsplit.c`

Sample run:
```
Enter the total bill in won: 50000
Enter the number of friends splitting it: 3
Each friend pays: 16666 won
Leftover (cannot be split evenly): 2 won
```

### Practice 7: Seconds to hours, minutes, seconds

Write a program that reads a duration in total seconds and breaks it down into hours, minutes, and remaining seconds using chained integer division and modulo (similar in spirit to the Challenge Problem's digit splitter, but for a clock duration instead of a four-digit number).

File: `lab03_practice7_time.c`

Sample run:
```
Enter a duration in total seconds: 3725
Hours:   1
Minutes: 2
Seconds: 5
```

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Forgetting `&` in `scanf` | Program crashes or reads garbage | Always use `&variable` with `scanf` |
| `int / int` when you want decimals | Result is truncated (e.g., `7/2` gives `3`) | Cast: `(double)a / b` |
| Wrong format specifier (`%d` for `double`) | Garbage output | Use `%lf` for `double` in `scanf`; `%f` or `%lf` both work in `printf` |
| Reading an uninitialized variable | Unpredictable value (could be anything) | Always assign a value before reading |
| Using `=` where you need `==` | (More relevant in Week 5, but start noticing now) | `=` assigns; `==` compares |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Temperature converter | `lab03_temp.c` | 4 |
| Circle geometry | `lab03_circle.c` | 4 |
| Swap | `lab03_swap.c` | 2 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 3 "Formatted Input/Output", Ch. 4 "Expressions"
- King, Ch. 7 "Basic Types"
