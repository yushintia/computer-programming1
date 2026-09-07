# Lab 06: Loops I: while and do-while

| | |
|---|---|
| **Week** | 6 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 05 (conditionals, relational operators) |

**Why this lab matters:** Imagine writing code to sum 1000 survey responses, process every line in a log file, or keep prompting a user until they enter a valid value. Writing 1000 individual statements is impractical. Loops let a small piece of code repeat as many times as needed, which is why virtually every useful program, from a data-analysis script to a web server handling requests, contains at least one loop. This lab introduces the two loop forms that check a condition before or after each step.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap · 30 while / do-while loop anatomy · 15 live demo |
| B (Guided practice) | 50 | 30 guided counting/accumulation lab · 10 runtime-debugging moment · 10 debrief and pitfalls |
| C (Independent and wrap) | 50 | 35 independent exercises · 10 challenge · 5 submit and Week 7 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Write `while` and `do-while` loops with correct init/condition/update structure.
2. Use loops for counting and accumulation.
3. Read input until a sentinel value (e.g., -1 to stop).
4. Diagnose a misbehaving loop using `printf`-tracing.

---

## Recap

In Week 5 you used `if-else` to choose between paths.
Loops let you repeat a block of code: the computer can do something a thousand times
as easily as once, so you just have to describe the repetition, not write it out.

---

## Background

### What Is a Loop?

> **In plain words: loop / iteration**
> A loop is a way of telling the computer: "repeat this block of instructions until a
> certain condition is no longer true." Each individual run of the block is called an
> *iteration* (one pass through the loop). Think of a song with a chorus: the chorus
> is the loop body, and "repeat the chorus 3 times" is the loop condition.
>
> Loops are one of the most powerful ideas in programming. Without them, to add up
> 1000 numbers you would need 1000 separate lines of code. With a loop, you need 4.

### `while` Loop Flowchart

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 400 320" style="max-width:380px;display:block;margin:1.5em auto;">
  <title>while loop flowchart with standard Start and End terminals. A Start oval leads down to an init process box, then to a condition diamond. If false the arrow exits right to an End oval. If true the arrow goes down into a box labeled Execute loop body, then to an update box. An arrow curves back up to the condition diamond.</title>
  <defs>
    <marker id="arr-06" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Start terminal -->
  <ellipse cx="160" cy="16" rx="50" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="160" y="20" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">Start</text>
  <line x1="160" y1="30" x2="160" y2="46" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-06)"/>
  <!-- Init box -->
  <rect x="95" y="48" width="130" height="28" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="160" y="66" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle">init (e.g. i = 1)</text>
  <line x1="160" y1="76" x2="160" y2="92" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-06)"/>
  <!-- Condition diamond -->
  <polygon points="160,94 240,127 160,160 80,127" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="160" y="124" font-family="sans-serif" font-size="10" fill="#c07000" text-anchor="middle" font-weight="bold">condition</text>
  <text x="160" y="138" font-family="monospace" font-size="10" fill="#c07000" text-anchor="middle">true / false?</text>
  <!-- FALSE arrow right to End -->
  <line x1="240" y1="127" x2="330" y2="127" stroke="#c00" stroke-width="1.5" marker-end="url(#arr-06)"/>
  <text x="265" y="119" font-family="sans-serif" font-size="10" fill="#c00">false</text>
  <!-- End terminal -->
  <ellipse cx="360" cy="127" rx="40" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="360" y="131" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">End</text>
  <!-- TRUE arrow down -->
  <line x1="160" y1="160" x2="160" y2="189" stroke="#2e7d32" stroke-width="1.5" marker-end="url(#arr-06)"/>
  <text x="168" y="179" font-family="sans-serif" font-size="10" fill="#2e7d32">true</text>
  <!-- Body box -->
  <rect x="80" y="192" width="160" height="40" rx="6" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="160" y="212" font-family="sans-serif" font-size="11" fill="#2e7d32" text-anchor="middle" font-weight="bold">Execute loop body</text>
  <text x="160" y="226" font-family="monospace" font-size="10" fill="#2e7d32" text-anchor="middle">{ ... }</text>
  <!-- Update box -->
  <line x1="160" y1="232" x2="160" y2="255" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-06)"/>
  <rect x="100" y="257" width="120" height="30" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="160" y="277" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle">update (i++)</text>
  <!-- Back arrow to condition -->
  <path d="M100,272 Q30,272 30,127 Q30,94 80,94" fill="none" stroke="#0b3d66" stroke-width="1.5" stroke-dasharray="6,3" marker-end="url(#arr-06)"/>
  <text x="52" y="200" font-family="sans-serif" font-size="9" fill="#888" transform="rotate(-90,52,200)">back to top</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 6.1.</strong> The while loop, step by step (standard flowchart notation).</em></p>

### `while` Loop Syntax

```c
/* init */
while (condition) {
    /* body */
    /* update */
}
```

The condition is checked **before** each iteration.
If it is false from the start, the body never runs.

```c
int i = 1;
while (i <= 5) {
    printf("%d\n", i);
    i++;           /* update: advance i */
}
```

### `do-while` Loop

```c
do {
    /* body */
} while (condition);   /* condition checked AFTER body */
```

The body runs **at least once**: useful for menus and input validation.

```c
int choice;
do {
    printf("Enter 1-3: ");
    scanf("%d", &choice);
} while (choice < 1 || choice > 3);
printf("You chose %d\n", choice);
```

### Counting and Accumulation Patterns

**Pseudocode** for sum 1 to N:

```
INPUT n
SET sum = 0
SET i = 1
WHILE i <= n DO
    SET sum = sum + i
    SET i = i + 1
END WHILE
OUTPUT sum
```

```c
/* Sum of 1 to N */
int n, sum = 0, i = 1;
scanf("%d", &n);
while (i <= n) {
    sum += i;   /* accumulate */
    i++;
}
printf("Sum = %d\n", sum);
```

### Input-Until-Sentinel

> **In plain words: sentinel value**
> A *sentinel* is a special "stop" value that the user types to signal "I'm done entering
> data." We use `-1` a lot because scores, counts, and prices are never negative, so
> `-1` cannot be a real data value. When the program sees `-1`, it knows to stop asking
> and start processing. Think of a sentinel like the word "STOP" at the end of an old
> telegram: it does not carry real information; it just means "message over."

```c
int val, total = 0, count = 0;
printf("Enter values (-1 to stop): ");
scanf("%d", &val);
while (val != -1) {
    total += val;
    count++;
    scanf("%d", &val);
}
printf("Sum=%d, Count=%d\n", total, count);
```

> **Under the Hood: loops as backward jumps**
>
> A `while` loop compiles to a compare and conditional jump at the top,
> and an unconditional **backward jump** at the bottom.
> The CPU jumps back and re-executes the condition check on each pass.
> Infinite loops happen when the backward jump always fires; you never reach the exit condition.

---

## Worked Examples

### Example 1: Number-guessing game

```c
/* lab06_guess.c (outline) */
#include <stdio.h>

int main(void) {
    int secret = 42, guess;
    printf("Guess my number (1-100)!\n");
    do {
        printf("Your guess: ");
        scanf("%d", &guess);
        if (guess < secret)
            printf("Too low.\n");
        else if (guess > secret)
            printf("Too high.\n");
    } while (guess != secret);
    printf("Correct!\n");
    return 0;
}
```

### Line by line

| Line | What it does |
|------|-------------|
| `int secret = 42, guess;` | Declares two variables in one line. `secret` is initialised to 42 (the number to guess). `guess` has no value yet; `scanf` will fill it. |
| `printf("Guess my number (1-100)!\n");` | Prints one line of welcome text before the loop starts. |
| `do {` | Begins a `do-while` loop. The body runs at least once, which is exactly what we need: ask for a guess before we can check it. |
| `printf("Your guess: ");` | Prompts the user. No `\n` here so the cursor stays on the same line waiting for input. |
| `scanf("%d", &guess);` | Reads one integer from the keyboard and stores it in `guess`. The `&` gives `scanf` the address of `guess` so it can write there. |
| `if (guess < secret)` | Checks if the guess is too small. If yes, the next line prints "Too low." The `else if` line is skipped. |
| `else if (guess > secret)` | Only reaches here if the guess was NOT too small. Checks if it is too large. |
| `} while (guess != secret);` | The condition is checked AFTER the body. If `guess` still does not equal `secret`, the body runs again. The loop keeps going until the player finds the right number. |
| `printf("Correct!\n");` | Only printed once, after the loop exits, meaning `guess == secret`. |

**Sample run:**
```
Guess my number (1-100)!
Your guess: 20
Too low.
Your guess: 60
Too high.
Your guess: 42
Correct!
```

**Key insight:** a `do-while` is the right choice here because we always need at least one
guess before we can know whether the player has won. If you used a plain `while`, you
would need to fake an initial guess to start the loop.

### Example 2: Running average

```c
/* lab06_avg.c (outline) */
/* Reads numbers until -1, prints count and average */
#include <stdio.h>

int main(void) {
    int val, count = 0;
    double sum = 0;
    printf("Enter integers (-1 to stop): ");
    scanf("%d", &val);
    while (val != -1) {
        sum += val;
        count++;
        scanf("%d", &val);
    }
    if (count > 0)
        printf("Average of %d values: %.2f\n", count, sum / count);
    else
        printf("No values entered.\n");
    return 0;
}
```

---

## Guided In-Lab Exercises

### Exercise 1: Sum 1 to N (Part B)

Read N from the user and print the sum 1 + 2 + ... + N.
Also print the formula result N x (N+1)/2 to verify.

File: `lab06_sum.c`

### Exercise 2: Input validation loop (Part B)

Ask the user for a grade percentage (0 to 100). Keep asking until they enter a valid value.
Then print the corresponding letter grade.

File: `lab06_validate.c`

### Exercise 3: Guessing game (Part C)

Implement the guessing game from Example 1.
After the user guesses correctly, print how many guesses it took.

File: `lab06_guess.c`

---

## Runtime-Debugging Moment (Part B, ~10 min)

**Scenario:** A student writes the sum-to-N program but gets the wrong total.

```c
int i = 0, sum = 0;
while (i <= n) {
    sum += i;
    /* forgot i++; */
}
```

This is an **infinite loop**: the program runs forever.
**How to debug:** add a `printf` inside the loop:

```c
printf("DEBUG: i=%d, sum=%d\n", i, sum);
```

> **In plain words: printf-tracing**
> Printf-tracing means adding temporary `printf` lines inside your loop (or function) to
> print the values of variables on every pass. It lets you see what the program is
> actually doing, step by step, instead of guessing. Once the bug is fixed, delete the
> debug lines. This is the simplest debugging technique; you will use it every week.

Now you can see the variable values on each pass.
This is your first debugging tool.

Note: this is a *runtime* bug (the code compiles fine but misbehaves).
You will practice systematic debugging in Week 14.

---

## Challenge Problem

Write a program that finds and prints all **perfect numbers** up to 1000.
A perfect number equals the sum of its proper divisors (e.g., 6 = 1 + 2 + 3).

File: `lab06_perfect.c`

---

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

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Missing update (`i++`) inside the loop | Infinite loop; program freezes | Always include the update step |
| Condition is false before loop starts | Loop body never executes | Check that the init value satisfies the first condition |
| Off-by-one: `while (i < n)` vs `while (i <= n)` | One too few or one too many iterations | Trace manually with a small value of n |
| Using `=` instead of `!=` in sentinel check | Loop exits immediately or never | Use `while (val != -1)` |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Sum 1 to N | `lab06_sum.c` | 3 |
| Input validation | `lab06_validate.c` | 3 |
| Guessing game | `lab06_guess.c` | 4 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 6 "Loops"
- K&R, Ch. 3 "Control Flow"
- [Debugging Tips](../appendix/debugging-tips.md)
- [Pseudocode & Flowcharts](../appendix/pseudocode-flowchart.md) - symbol reference and worked examples
- [Reading and Tracing a Program](../appendix/tracing-a-program.md) - how to build a trace table to follow loop variables step by step
