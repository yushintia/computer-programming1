---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 4: Input/Output & Operators

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Recap Week 3 (variables, scanf) in one line. Today: control
exactly how output looks, and get the full set of operators for
correct calculations.
-->

---

<!-- SLOT 2: Where we are (Act 0 / LOCATE) -->

# Where We Are

<div class="roadmap">
<div class="wk"><div class="n">Wk 1</div><div class="t">Introduction</div></div>
<div class="wk"><div class="n">Wk 2</div><div class="t">Program Structure &amp; I/O</div></div>
<div class="wk"><div class="n">Wk 3</div><div class="t">Variables &amp; Data Types</div></div>
<div class="wk now"><div class="n">Wk 4</div><div class="t">I/O &amp; Operators</div></div>
<div class="wk"><div class="n">Wk 5</div><div class="t">Conditionals</div></div>
<div class="wk"><div class="n">Wk 6</div><div class="t">Loops I: while</div></div>
<div class="wk"><div class="n">Wk 7</div><div class="t">Loops II: for</div></div>
<div class="wk review"><div class="n">Wk 8</div><div class="t">Midterm Exam</div></div>
<div class="wk"><div class="n">Wk 9</div><div class="t">Functions I</div></div>
<div class="wk"><div class="n">Wk 10</div><div class="t">Functions II: Recursion</div></div>
<div class="wk"><div class="n">Wk 11</div><div class="t">Arrays I: 1-D</div></div>
<div class="wk"><div class="n">Wk 12</div><div class="t">Arrays II: 2-D &amp; Strings</div></div>
<div class="wk"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** variables that store a value, and `scanf`
  that reads one in from the user.
- **Last week left broken:** variables and `scanf` bring in one raw
  value, but every program still runs exactly one path, no matter the
  input.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# The Receipt That Cannot Be Trusted

<div class="pain">

You write a program to split a 7,000-won snack bill between 2 friends.
It answers "3,500 each" - reasonable. Now try splitting 7,000 won
between 2 friends where the answer should include change: your program
quietly says each pays 3,000, and the leftover 1,000 just disappears.

At the same time, your receipt line-items refuse to line up: item
names, quantities, and prices sit at random distances from each other,
jagged and hard to read, however carefully you type spaces between
them.

</div>

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- A calculation that silently drops part of the answer produces a
  wrong total nobody notices until a customer, or a grader, complains.
- Output that will not line up cannot be used for anything that looks
  like a real receipt, invoice, or report table.

<div class="why">
<strong>In industry:</strong> a calculation quietly losing its decimal
part is one of the most common real-world bugs (a famous cause of
mis-priced totals), and reading/predicting an expression's exact result
is a routine interview and code-review question.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How does a program compute the correct result from mixed values, and control exactly how that result is displayed?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Format `printf` output using width, precision, and alignment
   specifiers.
2. Use arithmetic, relational, and logical operators correctly.
3. Predict the result of a mixed-type expression and apply explicit
   casts.
4. Explain operator precedence and use parentheses to override it.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

<div class="thread">Under the hood: operators map to CPU instructions.</div>

Each arithmetic operator you write compiles down to a single CPU
instruction: `+` becomes ADD, `-` becomes SUB, and so on. The CPU works
in a fixed number of bits at a time, which is exactly why `int / int`
throws away the remainder: the integer-division instruction itself
discards it. A cast does not change any bits in memory - it changes how
the compiler tells the CPU to interpret the bits it already has.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# Operator Precedence: Definition

> When an expression mixes more than one operator, C does not evaluate
> them left to right by default - it evaluates higher-precedence
> operators first, exactly like "multiply before you add" in
> arithmetic class.

`2 + 3 * 4` is `14`, not `20`, because `*` outranks `+`. Same-rank
operators (like two `-` in a row) fall back to left-to-right.

---

<!-- Act 3 / BUILD -->

<!-- SLOT 10: Mechanics - field width and precision -->

# Formatted Output: Width and Precision

```c
printf("%8d\n", 42);       /* right-aligned in 8 chars: "      42" */
printf("%-8d|\n", 42);     /* left-aligned:              "42      |" */
printf("%08d\n", 42);      /* zero-padded:                "00000042" */
printf("%.4f\n", 3.14159); /* 4 decimal places:           "3.1416"   */
```

`%8d`: the `8` is the *minimum field width* - printf pads with spaces
on the left so every number lines up at the right edge of its column.
`%.4f`: the `.4` is the *precision* - how many digits to show after
the decimal point; extra digits are cut, the stored value is unchanged.

---

<!-- SLOT 11: Mechanics - format specifier table -->

# Reading a Format Specifier

`%10.2f` breaks down piece by piece:

<div class="cardlist">
<div class="card"><div class="h">%</div><div class="d">Start of a format specifier.</div></div>
<div class="card"><div class="h">10</div><div class="d">Minimum field width - at least 10 characters.</div></div>
<div class="card"><div class="h">.2</div><div class="d">Precision - 2 digits after the decimal point.</div></div>
<div class="card"><div class="h">f</div><div class="d">Conversion specifier - type: floating-point number.</div></div>
</div>

`%d`/`%i` int · `%f` float/double · `%lf` double (scanf) · `%c` char ·
`%s` string · `%x` hex · `%%` a literal `%`.

---

<!-- SLOT 12: Mechanics - arithmetic operators -->

# Arithmetic Operators

| Op | Meaning | Example | Result |
|----|---------|---------|--------|
| `+` | Add | `3 + 4` | `7` |
| `-` | Subtract | `7 - 2` | `5` |
| `*` | Multiply | `3 * 4` | `12` |
| `/` | Divide | `7 / 2` | `3` (int!), `3.5` (float) |
| `%` | Modulo (remainder) | `7 % 2` | `1` |

`%` gives the *remainder* after division, not the quotient - `7 % 2`
is `1`, because `7 = 3x2 + 1`.

---

<!-- SLOT 13: Mechanics - relational and logical operators -->

# Relational & Logical Operators

<div class="chip-row">
<div class="chip">==</div><div class="chip">!=</div><div class="chip">&lt;</div><div class="chip">&gt;</div><div class="chip">&lt;=</div><div class="chip">&gt;=</div><div class="chip">&amp;&amp;</div><div class="chip">||</div><div class="chip">!</div>
</div>

Relational operators (`==`, `!=`, `<`, `>`, `<=`, `>=`) compare two
values. Logical operators (`&&` AND, `||` OR, `!` NOT) combine
true/false results. Every one of these returns `1` (true) or `0`
(false) - you will use them heavily starting next week.

---

<!-- SLOT 14: Mechanics - precedence pyramid -->

# Operator Precedence, Highest to Lowest

<div class="pipeline">
<div class="stage"><div class="h">( )</div><div class="s">highest</div></div>
<div class="arrow">&gt;</div>
<div class="stage"><div class="h">! unary -</div><div class="s">negate / not</div></div>
<div class="arrow">&gt;</div>
<div class="stage"><div class="h">* / %</div><div class="s">mult, div, mod</div></div>
<div class="arrow">&gt;</div>
<div class="stage"><div class="h">+ -</div><div class="s">add, subtract</div></div>
<div class="arrow">&gt;</div>
<div class="stage"><div class="h">&lt; &gt; &amp;&amp; ||</div><div class="s">compare, lowest</div></div>
</div>

Same-rank operators evaluate left to right: `10 - 3 - 2` is
`(10 - 3) - 2 = 5`, not `10 - (3 - 2) = 9`. When in doubt, use
parentheses - they cost nothing and prevent bugs.

---

<!-- SLOT 15: Mechanics - casts -->

# Type Conversion and Casts

```c
int a = 7, b = 2;
double result = (double)a / b;  /* cast a to decimal; result is 3.5 */
int truncated = (int)3.99;      /* cast to int: 3 (truncation, not rounding) */
```

A cast tells the compiler "treat this value as a different type, just
for this calculation" - it does not change what is stored in `a`, only
how that one expression reads it. Truncation always cuts toward zero:
`(int)3.99` is `3`, and `(int)-3.99` is `-3`.

---

<!-- SLOT N-2: Worked example -->

# Worked Example: Formatted Table

```c
/* lab04_table.c */
#include <stdio.h>

int main(void) {
    printf("%-10s %8s %10s\n", "Item", "Qty", "Price");
    printf("%-10s %8d %10.2f\n", "Pencil", 5, 1500.0);
    printf("%-10s %8d %10.2f\n", "Notebook", 2, 8500.0);
    return 0;
}
```

**Expected output:**
```
Item           Qty      Price
Pencil           5    1500.00
Notebook         2    8500.00
```

---

# Formatted Table: Line by Line

<div class="cardlist">
<div class="card"><div class="h">%-10s "Item"</div><div class="d">Left-aligned in a 10-char column: "Item      " - the "-" means left-align.</div></div>
<div class="card"><div class="h">%8s "Qty"</div><div class="d">No "-", so right-aligned in an 8-char column: "     Qty".</div></div>
</div>

Every data row reuses the same column widths (`%-10s`, `%8d`,
`%10.2f`), so the numbers line up vertically - this is why formatted
output matters for tables and receipts.

---

# Worked Example: Integer Division Pitfall

```c
/* lab04_divide.c */
#include <stdio.h>

int main(void) {
    int x = 5, y = 2;
    printf("5 / 2        = %d\n",   x / y);          /* 2   */
    printf("(double)5/2  = %.1f\n", (double)x / y);  /* 2.5 */
    printf("5 %% 2       = %d\n",   x % y);          /* 1   */
    return 0;
}
```

`x / y` with two `int`s gives `2`, dropping the `.5`. Casting one side
to `double` keeps the full decimal answer, `2.5`.

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">int / int when you want decimals</div><div class="d">e.g. 1/2 gives 0. Cast one operand: (double)a / b.</div></div>
<div class="card"><div class="h">Confusing = with ==</div><div class="d">a = 5 sets a; a == 5 tests a. Mixing them gives silent wrong results.</div></div>
<div class="card"><div class="h">Forgetting %% in printf</div><div class="d">A lone % disappears or warns. Use %% to print a literal percent sign.</div></div>
<div class="card"><div class="h">Wrong precedence assumed</div><div class="d">Unexpected result from a complex expression. Add parentheses to be sure.</div></div>
</div>

---

<!-- SLOT N: Check yourself -->

# Check Yourself

1. What does `2 + 3 * 4 - 1` evaluate to, and why?
2. `int x = 5, y = 2;` - what does `x / y` give, and how do you get
   `2.5` instead?
3. Why does `printf("100%\n");` not print `100%` correctly, and what
   is the fix?

---

# Answers

1. `13`: `*` (level 3) runs before `+`/`-` (level 4), so `3 * 4 = 12`
   first, then `2 + 12 - 1 = 13` left to right.
2. `2` (integer division truncates); cast one operand:
   `(double)x / y` gives `2.5`.
3. A lone `%` starts a format specifier, and `\n` after it is not a
   valid conversion letter, so it prints garbage or gets flagged by
   the compiler; write `%%` to print a literal `%`.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What Operators and Formatting Cannot Do Yet

<div class="limits">
Output can be formatted precisely, but there is still no way for a
program to <em>decide</em> between two paths.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 4 leaves **branching on a condition** unsolved: every program so
far still runs every line, every time. **Week 5** addresses it:
Conditional Statements - `if`, `else`, and `switch`.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- Format specifiers (`%8d`, `%.2f`, `%-10s`) control field width,
  precision, and alignment.
- Arithmetic, relational, and logical operators each return a value;
  precedence decides which one runs first in a mixed expression.
- Integer division truncates; cast with `(double)` to keep the decimal
  part.
- **Lab page:** `book/src/labs/lab04-io-and-operators.md` for the
  receipt formatter, boolean-expression, and precedence-puzzle
  exercises.
- **Prepare:** review `&&`, `||`, and `!` before class - Week 5 builds
  directly on these logical operators.

---

<!-- SLOT N+4: Thank You -->
<!-- _class: end -->

# Thank You
