# Lab 05: Conditional Statements

| | |
|---|---|
| **Week** | 5 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab + Diagnostic Assessment |
| **Prerequisites** | Lab 04 (operators, relational/logical) |

**Why this lab matters:** Real programs must make decisions: charge a different tax rate for different income levels, show an error screen when a login fails, or flag a sensor reading only when it exceeds a threshold. Conditional statements are the mechanism that lets your code react to data rather than process everything the same way every time. Without them, a program can do only one fixed thing; with them, it can handle the full range of situations your users will encounter.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap · 30 if/else and switch · 15 live demo |
| B (Guided practice and diagnostic) | 50 | 30 guided lab · 10 diagnostic assessment · 10 debrief and pitfalls |
| C (Independent and wrap) | 50 | 35 independent exercises · 10 challenge · 5 submit and Week 6 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Write `if`, `if-else`, and nested `if` statements to branch program flow.
2. Combine conditions with `&&`, `||`, and `!`.
3. Write a `switch-case` statement and know when to prefer it over `if-else`.
4. Identify the `=` vs `==` bug and explain why it is dangerous.

---

## Recap

In Week 4 you learned relational (`<`, `>`, `==`) and logical (`&&`, `||`) operators,
which produce true/false (1/0) values. This week you use those values to make decisions:
the program takes different paths depending on the data.

---

## Background

### What Are Conditional Statements?

> **In plain words: conditional execution / branching**
> So far, every program you wrote ran every line, top to bottom, every time.
> A conditional statement lets the program ask a question and take a different path
> depending on the answer. If the answer is YES, do this block; if NO, do that block.
> This is called *branching*, like a fork in a road.
>
> Think of a vending machine: it checks whether you inserted enough money
> (the condition). If yes, it dispenses the drink (one branch). If no, it asks for more
> money (the other branch). Without branching, it would dispense a drink no matter what.

### if and if-else Flowchart

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 540 370" style="max-width:520px;display:block;margin:1.5em auto;">
  <title>Flowchart showing if-else if-else chain with Start and End terminals. A Start oval leads into a diamond asking score >= 90. If yes it flows to print A. If no it flows to a second diamond asking score >= 80. If yes it prints B. If no it flows to a third diamond asking score >= 70. If yes it prints C. If no it prints F. All paths merge at the bottom into an End oval.</title>
  <defs>
    <marker id="arr-05" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Start terminal -->
  <ellipse cx="170" cy="18" rx="50" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="170" y="22" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">Start</text>
  <line x1="170" y1="32" x2="170" y2="48" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-05)"/>
  <!-- Decision 1: score >= 90 -->
  <polygon points="170,50 260,75 170,100 80,75" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="170" y="72" font-family="monospace" font-size="11" fill="#c07000" text-anchor="middle">score &gt;= 90?</text>
  <!-- YES: print A -->
  <line x1="260" y1="75" x2="360" y2="75" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-05)"/>
  <text x="310" y="68" font-family="sans-serif" font-size="10" fill="#2e7d32">YES</text>
  <rect x="360" y="60" width="80" height="30" rx="6" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="400" y="80" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">print "A"</text>
  <!-- NO: arrow down -->
  <line x1="170" y1="100" x2="170" y2="128" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-05)"/>
  <text x="178" y="118" font-family="sans-serif" font-size="10" fill="#c00">NO</text>
  <!-- Decision 2: score >= 80 -->
  <polygon points="170,130 260,155 170,180 80,155" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="170" y="152" font-family="monospace" font-size="11" fill="#c07000" text-anchor="middle">score &gt;= 80?</text>
  <!-- YES: print B -->
  <line x1="260" y1="155" x2="360" y2="155" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-05)"/>
  <text x="310" y="148" font-family="sans-serif" font-size="10" fill="#2e7d32">YES</text>
  <rect x="360" y="140" width="80" height="30" rx="6" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="400" y="160" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">print "B"</text>
  <!-- NO: arrow down -->
  <line x1="170" y1="180" x2="170" y2="208" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-05)"/>
  <text x="178" y="198" font-family="sans-serif" font-size="10" fill="#c00">NO</text>
  <!-- Decision 3: score >= 70 -->
  <polygon points="170,210 260,235 170,260 80,235" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="170" y="232" font-family="monospace" font-size="11" fill="#c07000" text-anchor="middle">score &gt;= 70?</text>
  <!-- YES: print C -->
  <line x1="260" y1="235" x2="360" y2="235" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-05)"/>
  <text x="310" y="228" font-family="sans-serif" font-size="10" fill="#2e7d32">YES</text>
  <rect x="360" y="220" width="80" height="30" rx="6" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="400" y="240" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">print "C"</text>
  <!-- NO: print F -->
  <line x1="170" y1="260" x2="170" y2="280" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-05)"/>
  <rect x="110" y="280" width="120" height="28" rx="6" fill="#ffebee" stroke="#c62828" stroke-width="1.5"/>
  <text x="170" y="299" font-family="monospace" font-size="11" fill="#c62828" text-anchor="middle">print "F (Fail)"</text>
  <!-- Merge lines from print A, B, C down to End -->
  <line x1="400" y1="90" x2="490" y2="90" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2"/>
  <line x1="400" y1="170" x2="490" y2="170" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2"/>
  <line x1="400" y1="250" x2="490" y2="250" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2"/>
  <line x1="490" y1="90" x2="490" y2="340" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2"/>
  <line x1="490" y1="340" x2="230" y2="340" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2" marker-end="url(#arr-05)"/>
  <!-- print F also goes down to End -->
  <line x1="170" y1="308" x2="170" y2="340" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-05)"/>
  <!-- End terminal -->
  <ellipse cx="170" cy="353" rx="50" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="170" y="357" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">End</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 5.1.</strong> if / else-if decision flow (Start and End terminals follow standard flowchart notation).</em></p>

```c
if (score >= 90) {
    printf("A\n");
} else if (score >= 80) {
    printf("B\n");
} else if (score >= 70) {
    printf("C\n");
} else {
    printf("F\n");
}
```

### `switch-case`

```c
int day = 3;
switch (day) {
    case 1: printf("Monday\n");    break;
    case 2: printf("Tuesday\n");   break;
    case 3: printf("Wednesday\n"); break;
    default: printf("Unknown\n");  break;
}
```

- `switch` works on **integer** (and `char`) values only. It cannot test floating-point numbers or strings.
- `default` handles any value not matched by a `case`. Always include it.
- Always write `break` at the end of each case body.

> **In plain words: fall-through**
> When a `switch` case matches, execution starts there and *keeps going* through the
> lines below until it hits a `break` or the end of the `switch`. This is called
> fall-through. If you forget `break`, the code "falls through" into the next case
> even though that case did not match. For example, if `day == 1` and case 1 has no
> `break`, then "Monday" AND "Tuesday" would both print. This is almost always a bug.
> There are rare intentional uses for fall-through, but in this course, always add `break`.

> **Under the Hood: branches as jumps**
>
> An `if` statement compiles to a **compare** instruction followed by a **conditional jump**.
> The CPU tests the condition; if it is false, execution jumps past the `if` body.
> Programs do not "know" which branch they will take; they decide at runtime.
> Multiple `else if` chains compile to a series of comparisons;
> `switch` with many cases often compiles to a **jump table** (faster).

---

## Worked Examples

### Example 1: Grade classifier

**Pseudocode** (design the logic before writing C):

```
INPUT score
IF score < 0 OR score > 100 THEN
    OUTPUT "Invalid score"
ELSE IF score >= 90 THEN
    OUTPUT "Grade: A"
ELSE IF score >= 80 THEN
    OUTPUT "Grade: B"
ELSE IF score >= 70 THEN
    OUTPUT "Grade: C"
ELSE IF score >= 60 THEN
    OUTPUT "Grade: D"
ELSE
    OUTPUT "Grade: F (Fail)"
END IF
```

```c
/* lab05_grade.c */
#include <stdio.h>

int main(void) {
    int score;
    printf("Enter score (0-100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Invalid score.\n");
    } else if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F (Fail)\n");
    }
    return 0;
}
```

### Line by line

| Line | What it does |
|------|-------------|
| `int score;` | Reserves a box called `score` to hold the user's number. |
| `printf("Enter score (0-100): ");` | Prints a prompt. No `\n` so the cursor stays on the same line, right after the colon. |
| `scanf("%d", &score);` | Waits for the user to type a number and press Enter. Stores it in `score`. |
| `if (score < 0 \|\| score > 100)` | The first guard: checks that the number is valid. `\|\|` means OR; the condition is true if *either* part is true. |
| `printf("Invalid score.\n");` | Only runs if the guard above is true. The `else if` chain below is skipped entirely. |
| `else if (score >= 90)` | Only checked if the score was valid. Is it 90 or above? If yes, run the next line. If no, move to the next `else if`. |
| `printf("Grade: A\n");` | Runs only for scores 90-100. |
| `else if (score >= 80)` | At this point we already know score < 90 (the previous branch did not match). So this checks 80-89. |
| `else { printf("Grade: F ..."); }` | The final fallback. Runs if none of the conditions above were true. At this point score must be below 60. |
| `return 0;` | Program ends successfully. |

**Key point:** once one `else if` condition is true, all the remaining ones are skipped.
The chain exits after the first match.

**Sample runs:**
```
Enter score (0-100): 85   → Grade: B
Enter score (0-100): 55   → Grade: F (Fail)
Enter score (0-100): 150  → Invalid score.
```

### Example 2: Day-of-week with `switch`

```c
/* lab05_day.c */
#include <stdio.h>

int main(void) {
    int d;
    printf("Enter day number (1=Mon ... 7=Sun): ");
    scanf("%d", &d);
    switch (d) {
        case 1: printf("Monday\n");    break;
        case 2: printf("Tuesday\n");   break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n");  break;
        case 5: printf("Friday\n");    break;
        case 6: printf("Saturday\n");  break;
        case 7: printf("Sunday\n");    break;
        default: printf("Invalid day.\n"); break;
    }
    return 0;
}
```

---

## Guided In-Lab Exercises

### Exercise 1: Leap year checker (Part B)

A year is a leap year if it is divisible by 4, *except* years divisible by 100
are *not* leap years, *except* years divisible by 400 *are*.

Write a program that reads a year and prints "Leap year" or "Not a leap year".

File: `lab05_leap.c`

### Exercise 2: Menu with switch (Part B and C)

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

### Exercise 3: Diagnostic assessment (Part B, ~10 min, ungraded)

The professor will provide a short set of questions (5 to 8 problems) covering Weeks 1 to 5.
Answer individually. Results will be used to adjust upcoming sessions and are not graded for marks.

### Exercise 4: Days in a month (Part C)

Read a month number from 1 to 12 and print how many days that month has in a
non-leap year: 28 for February, 30 for April, June, September, and November, and 31 for
the rest. Print "Invalid month." for any other number. Use `switch-case`, and group the
30-day months with stacked `case` labels instead of writing each one out.

Sample run:
```
Enter month (1-12): 9
Days in month 9: 30
Enter month (1-12): 2
Days in month 2: 28
Enter month (1-12): 13
Invalid month.
```

Hint: a `case` with no `break` falls through to the next case. Stacking `case 4:`,
`case 6:`, `case 9:`, and `case 11:` on consecutive lines, with one `break` at the end,
uses that behavior on purpose. Add a comment saying so.

File: `lab05_month_days.c`

---

## Challenge Problem

Write a program that takes three integers and prints them in **ascending order**
without using arrays or sorting functions. Use only `if-else`.

File: `lab05_sort_three.c`

---

## Practice Problems

These are ungraded: extra practice for the concepts in this lab. Solutions are not distributed with this page.

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

---

## Common Pitfalls

| Mistake | Effect | Fix |
|---------|--------|-----|
| `if (x = 5)` instead of `if (x == 5)` | Always true! Assigns 5 to x. | Use `==` for comparison |
| Missing `break` in `switch` | Fall-through to next case | Add `break` after each case body |
| Empty `else` leaving an unhandled case | Program silently does nothing | Add `else` or `default` |
| Nested `if` without braces | Only the first statement is in the branch | Always use `{ }` even for one-liners |

> **The `=` vs `==` bug is one of the most common in C.**
> Many compilers warn about `if (x = 5)` with `-Wall`. This is why we always compile with warnings on.

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Leap year checker | `lab05_leap.c` | 3 |
| Menu with switch | `lab05_menu.c` | 4 |
| Days in a month with switch | `lab05_month_days.c` | 3 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 5 "Selection Statements"
- K&R, Ch. 3 "Control Flow"
- [Pseudocode & Flowcharts](../appendix/pseudocode-flowchart.md) - symbol reference and worked examples
