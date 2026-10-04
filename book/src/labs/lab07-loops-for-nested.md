# Lab 07: Loops II: for and Nested Loops

| | |
|---|---|
| **Week** | 7 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 06 (while, do-while, accumulation) |

**Why this lab matters:** Patterns in output, tables of data, and grid-based problems such as seating charts, pixel grids, and game boards all require a loop running inside another loop. The `for` loop is the most compact form for counted repetition and is by far the most commonly used loop in production C code. Mastering nested loops here is also direct preparation for two-dimensional arrays, image processing, and matrix arithmetic in later labs.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap · 30 for loop, nested loops, break/continue · 15 live demo |
| B (Guided practice) | 50 | 40 guided pattern lab · 10 debrief and pitfalls |
| C (Independent and wrap) | 50 | 20 independent patterns · 15 pre-midterm mixed review · 5 submit and Week 8 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Write `for` loops and explain why they are preferred when the iteration count is known.
2. Write nested loops to generate 2-D output (multiplication tables, patterns).
3. Use `break` to exit a loop early and `continue` to skip to the next iteration.
4. Solve problems using a combination of loops and conditionals (pre-midterm review).

---

## Recap

In Week 6 you used `while` and `do-while` for repetition.
The `for` loop covers the same ground but bundles init, condition, and update into one line,
making it cleaner when you know how many times you want to loop.

---

## Background

### for Loop Anatomy

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 560 130" style="max-width:540px;display:block;margin:1.5em auto;">
  <title>Anatomy of a for loop. The for statement is shown with three labeled parts: init (int i = 1) runs once at the start, condition (i less than or equal to 5) is checked before each iteration, update (i++) runs after each iteration. The loop body is a separate box below with an arrow looping back to condition.</title>
  <defs>
    <marker id="arr-07" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- for line -->
  <rect x="10" y="20" width="530" height="40" rx="6" fill="#f5f9fd" stroke="#ccd" stroke-width="1.5"/>
  <text x="30" y="46" font-family="monospace" font-size="14" fill="#333">for (</text>
  <text x="82" y="46" font-family="monospace" font-size="14" fill="#2e7d32" font-weight="bold">int i = 1</text>
  <text x="185" y="46" font-family="monospace" font-size="14" fill="#333">;</text>
  <text x="200" y="46" font-family="monospace" font-size="14" fill="#c07000" font-weight="bold">i &lt;= 5</text>
  <text x="272" y="46" font-family="monospace" font-size="14" fill="#333">;</text>
  <text x="287" y="46" font-family="monospace" font-size="14" fill="#0b3d66" font-weight="bold">i++</text>
  <text x="323" y="46" font-family="monospace" font-size="14" fill="#333">) { ... }</text>
  <!-- Labels below -->
  <text x="115" y="75" font-family="sans-serif" font-size="10" fill="#2e7d32" text-anchor="middle" font-weight="bold">① init</text>
  <text x="115" y="88" font-family="sans-serif" font-size="10" fill="#2e7d32" text-anchor="middle">runs once</text>
  <text x="222" y="75" font-family="sans-serif" font-size="10" fill="#c07000" text-anchor="middle" font-weight="bold">② condition</text>
  <text x="222" y="88" font-family="sans-serif" font-size="10" fill="#c07000" text-anchor="middle">checked each pass</text>
  <text x="318" y="75" font-family="sans-serif" font-size="10" fill="#0b3d66" text-anchor="middle" font-weight="bold">③ update</text>
  <text x="318" y="88" font-family="sans-serif" font-size="10" fill="#0b3d66" text-anchor="middle">runs after body</text>
  <!-- Bracket lines -->
  <line x1="82"  y1="58" x2="115" y2="68" stroke="#2e7d32" stroke-width="1" stroke-dasharray="3,2"/>
  <line x1="184" y1="58" x2="115" y2="68" stroke="#2e7d32" stroke-width="1" stroke-dasharray="3,2"/>
  <line x1="200" y1="58" x2="222" y2="68" stroke="#c07000" stroke-width="1" stroke-dasharray="3,2"/>
  <line x1="270" y1="58" x2="222" y2="68" stroke="#c07000" stroke-width="1" stroke-dasharray="3,2"/>
  <line x1="287" y1="58" x2="318" y2="68" stroke="#0b3d66" stroke-width="1" stroke-dasharray="3,2"/>
  <line x1="322" y1="58" x2="318" y2="68" stroke="#0b3d66" stroke-width="1" stroke-dasharray="3,2"/>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 7.1.</strong> Anatomy of a for loop.</em></p>

```c
for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

**When to choose `for`:** use it when the number of iterations is known before the loop starts.
**When to choose `while`:** use it when you are waiting for an event (e.g., sentinel input).

**Pseudocode** for a counted for loop:

```
FOR i FROM 1 TO n DO
    OUTPUT i
END FOR
```

### for Loop Execution Flowchart

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 420 340" style="max-width:400px;display:block;margin:1.5em auto;">
  <title>for loop execution flowchart with standard Start and End terminals. Start oval leads to an init box labeled int i = 1 runs once. Then a condition diamond labeled i less than or equal to 5. If false the arrow goes right to an End oval. If true the arrow goes down to the loop body box, then to an update box labeled i++, and an arrow curves back up to the condition diamond.</title>
  <defs>
    <marker id="arr-07b" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Start terminal -->
  <ellipse cx="170" cy="16" rx="50" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="170" y="20" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">Start</text>
  <line x1="170" y1="30" x2="170" y2="46" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-07b)"/>
  <!-- Init box -->
  <rect x="80" y="48" width="180" height="30" rx="6" fill="#eef4fa" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="170" y="63" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">int i = 1  (init, once)</text>
  <line x1="170" y1="78" x2="170" y2="95" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-07b)"/>
  <!-- Condition diamond -->
  <polygon points="170,97 255,130 170,163 85,130" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="170" y="127" font-family="monospace" font-size="11" fill="#c07000" text-anchor="middle">i &lt;= 5?</text>
  <text x="170" y="142" font-family="sans-serif" font-size="9" fill="#c07000" text-anchor="middle">(condition)</text>
  <!-- FALSE arrow right to End -->
  <line x1="255" y1="130" x2="340" y2="130" stroke="#c00" stroke-width="1.5" marker-end="url(#arr-07b)"/>
  <text x="280" y="122" font-family="sans-serif" font-size="10" fill="#c00">false</text>
  <!-- End terminal -->
  <ellipse cx="370" cy="130" rx="40" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="370" y="134" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">End</text>
  <!-- TRUE arrow down -->
  <line x1="170" y1="163" x2="170" y2="192" stroke="#2e7d32" stroke-width="1.5" marker-end="url(#arr-07b)"/>
  <text x="178" y="182" font-family="sans-serif" font-size="10" fill="#2e7d32">true</text>
  <!-- Body box -->
  <rect x="80" y="194" width="180" height="40" rx="6" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="170" y="212" font-family="sans-serif" font-size="11" fill="#2e7d32" text-anchor="middle" font-weight="bold">Execute loop body</text>
  <text x="170" y="228" font-family="monospace" font-size="10" fill="#2e7d32" text-anchor="middle">{ printf(...); }</text>
  <!-- Update box -->
  <line x1="170" y1="234" x2="170" y2="257" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-07b)"/>
  <rect x="105" y="259" width="130" height="30" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="170" y="279" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle">i++  (update)</text>
  <!-- Back arrow to condition -->
  <path d="M105,274 Q30,274 30,130 Q30,97 85,97" fill="none" stroke="#0b3d66" stroke-width="1.5" stroke-dasharray="6,3" marker-end="url(#arr-07b)"/>
  <text x="48" y="205" font-family="sans-serif" font-size="9" fill="#888" transform="rotate(-90,48,205)">back to top</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 7.3.</strong> for loop execution flow (standard flowchart notation).</em></p>

### Nested Loops: a Grid of Iterations

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 360 200" style="max-width:340px;display:block;margin:1.5em auto;">
  <title>A 3 by 4 grid showing nested loop iterations. Each cell shows row comma col. The outer loop controls rows 1 to 3 and the inner loop controls columns 1 to 4. Total iterations equals 12.</title>
  <!-- header row -->
  <text x="60" y="22" font-family="sans-serif" font-size="10" fill="#888" text-anchor="middle">col 1</text>
  <text x="140" y="22" font-family="sans-serif" font-size="10" fill="#888" text-anchor="middle">col 2</text>
  <text x="220" y="22" font-family="sans-serif" font-size="10" fill="#888" text-anchor="middle">col 3</text>
  <text x="300" y="22" font-family="sans-serif" font-size="10" fill="#888" text-anchor="middle">col 4</text>
  <!-- inner loop label -->
  <text x="180" y="190" font-family="sans-serif" font-size="10" fill="#c07000" text-anchor="middle">inner loop (col) runs 4 times per row  →  3 x 4 = 12 total</text>
  <!-- row labels -->
  <text x="12" y="68" font-family="sans-serif" font-size="10" fill="#888">row 1</text>
  <text x="12" y="118" font-family="sans-serif" font-size="10" fill="#888">row 2</text>
  <text x="12" y="168" font-family="sans-serif" font-size="10" fill="#888">row 3</text>
  <!-- cells -->
  <rect x="38" y="32" width="72" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="74" y="57" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">1,1</text>
  <rect x="118" y="32" width="72" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="154" y="57" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">1,2</text>
  <rect x="198" y="32" width="72" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="234" y="57" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">1,3</text>
  <rect x="278" y="32" width="72" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="314" y="57" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">1,4</text>
  <rect x="38" y="82" width="72" height="42" rx="4" fill="#ddeeff" stroke="#0b3d66" stroke-width="1"/>
  <text x="74" y="107" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">2,1</text>
  <rect x="118" y="82" width="72" height="42" rx="4" fill="#ddeeff" stroke="#0b3d66" stroke-width="1"/>
  <text x="154" y="107" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">2,2</text>
  <rect x="198" y="82" width="72" height="42" rx="4" fill="#ddeeff" stroke="#0b3d66" stroke-width="1"/>
  <text x="234" y="107" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">2,3</text>
  <rect x="278" y="82" width="72" height="42" rx="4" fill="#ddeeff" stroke="#0b3d66" stroke-width="1"/>
  <text x="314" y="107" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">2,4</text>
  <rect x="38" y="132" width="72" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="74" y="157" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">3,1</text>
  <rect x="118" y="132" width="72" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="154" y="157" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">3,2</text>
  <rect x="198" y="132" width="72" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="234" y="157" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">3,3</text>
  <rect x="278" y="132" width="72" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="314" y="157" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle">3,4</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 7.2.</strong> Nested loops as a grid of iterations.</em></p>

```c
for (int row = 1; row <= 3; row++) {
    for (int col = 1; col <= 4; col++) {
        printf("%4d", row * col);
    }
    printf("\n");
}
```

The inner loop runs fully for each step of the outer loop.
A 3x4 nested loop does 3 x 4 = 12 iterations total.

**Analogy:** think of a washing machine's program selector (outer loop) combined with the
drum spin cycles (inner loop). For each wash program (hot, warm, cold), the drum spins
a fixed number of times. You do not choose the next wash program until all spins for
the current one are done. The inner loop always finishes completely before the outer
loop advances.

### `break` and `continue`

> **In plain words: `break`**
> `break` immediately stops the loop and jumps to the first line *after* the closing `}`.
> Use it when you have found what you were looking for and there is no reason to keep
> iterating. For example, once you find a match in a list, you `break` out of the
> search loop. Important: `break` only exits the *innermost* loop. If you are inside
> a nested loop, the outer loop keeps running.

> **In plain words: `continue`**
> `continue` skips the rest of the current loop body and goes straight to the update
> step (`i++`), then re-checks the condition. Use it to skip an individual iteration
> without exiting the loop entirely. For example, to skip even numbers: if `i` is even,
> `continue`; otherwise process it.

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;          /* exit loop when i reaches 5 */
    if (i % 2 == 0) continue;  /* skip even numbers */
    printf("%d\n", i);          /* prints 1, 3 */
}
```

> **Under the Hood: nested loops and work**
>
> If the outer loop runs N times and the inner loop runs M times,
> the body executes N x M times. Doubling N doubles the total work.
> This is why nested loops can be slow for large inputs,
> a topic you will study in depth in **Algorithms and Data Structures**.

---

## Worked Examples

### Example 1: Multiplication table (n x n)

```c
/* lab07_table.c */
#include <stdio.h>

int main(void) {
    int n;
    printf("Print n x n table. n = ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    return 0;
}
```

### Line by line

| Line | What it does |
|------|-------------|
| `int n;` | Declares a variable to hold the table size the user will type. |
| `printf("Print n x n table. n = ");` | Prompts the user. No `\n` so the cursor waits on the same line. |
| `scanf("%d", &n);` | Reads the user's number into `n`. |
| `for (int i = 1; i <= n; i++)` | Outer loop. `i` represents the current **row**. Starts at 1, goes up to and including `n`, increments by 1 after each row. |
| `for (int j = 1; j <= n; j++)` | Inner loop. `j` represents the current **column**. For *each value of i*, this loop runs all the way from 1 to `n` before `i` advances. |
| `printf("%4d", i * j);` | Prints the product `i * j` in a 4-character-wide field. `%4d` aligns numbers in columns so they line up neatly. No `\n` here: we stay on the same row until the inner loop is done. |
| `printf("\n");` | After the inner loop finishes one complete row of numbers, move to the next line. This `printf` belongs to the *outer* loop. |

**Sample output (n = 4):**
```
   1   2   3   4
   2   4   6   8
   3   6   9  12
   4   8  12  16
```

Notice how `i = 2` (row 2) gives `2*1=2`, `2*2=4`, `2*3=6`, `2*4=8`.
Each row is just the multiplication table for that row number.

### Example 2: Triangle pattern

```c
/* lab07_triangle.c */
#include <stdio.h>

int main(void) {
    int rows;
    printf("Number of rows: ");
    scanf("%d", &rows);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
```

Sample output (rows = 4):
```
* 
* * 
* * * 
* * * * 
```

### Example 3: Padding a row with spaces

To push a row to the right, print spaces first. The number of spaces is the field width
minus the length of the text.

```c
/* lab07_pad_demo.c */
#include <stdio.h>

int main(void) {
    int width = 8;
    int len = 2;
    for (int s = 0; s < width - len; s++) {
        printf(" ");
    }
    printf("Hi\n");
    return 0;
}
```

Expected output: six spaces, then `Hi`. The loop runs `width - len` = 6 times (s = 0 to 5).
For a shape, use one padding loop per row, then the loop that prints the symbols.

### Example 4: Nested loops with an `if`

Inside the inner loop, an `if` chooses what to print for each cell. This grid prints `*`
on the diagonal (where row equals column) and `.` everywhere else.

```c
/* lab07_diag_demo.c */
#include <stdio.h>

int main(void) {
    for (int r = 1; r <= 4; r++) {
        for (int c = 1; c <= 4; c++) {
            if (r == c) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    return 0;
}
```

Expected output:
```
* . . .
. * . .
. . * .
. . . *
```

The outer loop picks the row. For each row, the inner loop visits all four columns, and the
`if` decides which symbol to print. The `if` runs 16 times in total (4 rows x 4 columns).

### Example 5: Tracking a largest and smallest value

Start by treating the first value as both the largest and the smallest. Then compare each
new value with them. This demo makes its values with a formula, so no input is needed.

```c
/* lab07_maxmin_demo.c */
#include <stdio.h>

int main(void) {
    int value = 7;                       /* first value: 7 */
    int largest = value, smallest = value;
    for (int i = 2; i <= 4; i++) {
        value = i * 7 % 10;              /* produces 4, then 1, then 8 */
        if (value > largest)  largest = value;
        if (value < smallest) smallest = value;
    }
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
    return 0;
}
```

| Step | `value` | `largest` | `smallest` |
|------|---------|-----------|------------|
| start | 7 | 7 | 7 |
| i = 2 | 4 | 7 | 4 |
| i = 3 | 1 | 7 | 1 |
| i = 4 | 8 | 8 | 1 |

Expected output: `Largest: 8` and `Smallest: 1`.

### Example 6: Peeling off digits

`n % 10` gives the last digit of `n`, and `n / 10` removes that last digit. Repeating both
steps until `n` is 0 visits the digits from right to left.

```c
/* lab07_digits_demo.c */
#include <stdio.h>

int main(void) {
    for (int n = 4096; n > 0; n /= 10) {
        printf("%d\n", n % 10);
    }
    return 0;
}
```

| `n` at the start of the pass | `n % 10` (printed) | `n / 10` (next `n`) |
|------------------------------|--------------------|---------------------|
| 4096 | 6 | 409 |
| 409 | 9 | 40 |
| 40 | 0 | 4 |
| 4 | 4 | 0 (loop stops) |

Expected output: `6`, `9`, `0`, `4`, each on its own line.

---

## Guided In-Lab Exercises

### Exercise 1: Right-aligned triangle (Part B)

Print a triangle that is **right-aligned** (spaces on the left):
```
      *
    * *
  * * *
* * * *
```
Read the number of rows from the user.

File: `lab07_rtriangle.c`

### Exercise 2: Hollow rectangle (Part B)

Print a hollow rectangle of `*` characters given width and height:
```
* * * * *
*       *
*       *
* * * * *
```

File: `lab07_hollow.c`

### Exercise 3: Pre-midterm review problems (Part C)

Solve these mixed problems (one file per task):

- **Review A:** Read N integers and print the largest and smallest.
- **Review B:** Print all integers from 1 to 100 that are divisible by 3 or 5 (but not both).
- **Review C:** Read a positive integer and print its digits in reverse order.

Files: `lab07_rev_a.c`, `lab07_rev_b.c`, `lab07_rev_c.c`

---

## Challenge Problem

**Challenge A: Perfect numbers.** Write a program that finds and prints all **perfect numbers**
up to 1000. A perfect number equals the sum of its proper divisors (e.g., 6 = 1 + 2 + 3).
Use an outer loop over the candidates and an inner loop over the possible divisors.

File: `lab07_perfect.c`

**Challenge B: Diamond.** Print a diamond pattern:
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

---

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

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Modifying loop variable inside the body | Loop runs wrong number of times | Keep the update in the `for` header |
| Off-by-one in nested loop bounds | One extra or missing row/column | Trace with small n (e.g., 3) on paper first |
| `break` only exits the **innermost** loop | Outer loop continues | Use a flag variable if you need to exit multiple levels |
| Infinite `for` loop with empty condition `for(;;)` | Never terminates without `break` | Ensure a condition or use `break` |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Right-aligned triangle | `lab07_rtriangle.c` | 3 |
| Hollow rectangle | `lab07_hollow.c` | 3 |
| Review problems (3 total) | `lab07_rev_a.c`, `_b.c`, `_c.c` | 4 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 6 "Loops"
- K&R, Ch. 3 "Control Flow"
- Practice the review problems in Exercise 3 until each one runs without help.
- [Pseudocode & Flowcharts](../appendix/pseudocode-flowchart.md) - symbol reference and worked examples
