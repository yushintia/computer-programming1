---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 12: Arrays II: 2-D Arrays & Strings

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Week 12. Last week: one list of values, indexed by one number. This
week: two new ideas that both build directly on arrays - grids (rows and
columns), and text (a string is just a char array with a rule).
-->

---

<!-- SLOT 2: Where we are (Act 0 / LOCATE) -->

# Where We Are

<div class="roadmap">
<div class="wk"><div class="n">Wk 1</div><div class="t">Introduction</div></div>
<div class="wk"><div class="n">Wk 2</div><div class="t">Program Structure &amp; I/O</div></div>
<div class="wk"><div class="n">Wk 3</div><div class="t">Variables &amp; Data Types</div></div>
<div class="wk"><div class="n">Wk 4</div><div class="t">I/O &amp; Operators</div></div>
<div class="wk"><div class="n">Wk 5</div><div class="t">Conditionals</div></div>
<div class="wk"><div class="n">Wk 6</div><div class="t">Loops I: while</div></div>
<div class="wk"><div class="n">Wk 7</div><div class="t">Loops II: for</div></div>
<div class="wk review"><div class="n">Wk 8</div><div class="t">Midterm Exam</div></div>
<div class="wk"><div class="n">Wk 9</div><div class="t">Functions I</div></div>
<div class="wk"><div class="n">Wk 10</div><div class="t">Functions II: Recursion</div></div>
<div class="wk"><div class="n">Wk 11</div><div class="t">Arrays I: 1-D</div></div>
<div class="wk now"><div class="n">Wk 12</div><div class="t">Arrays II: 2-D &amp; Strings</div></div>
<div class="wk"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

<!-- notes: Point at Week 12. Two topics this week, one per class period:
2-D arrays in the morning half, strings in the afternoon half. -->

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** a single list of numbers, indexed by one number,
  so we could store many values of one type without naming them one by one.
- **Last week left broken:** a list holds many values of ONE type, but real
  data is often a grid (rows and columns), and text has no dedicated type
  of its own yet.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# A Grade Sheet With No Table

<div class="pain">

Picture a classroom grade sheet: one row per student, one column per
assignment. You know how to store one row (a list of numbers). But a
whole sheet has rows AND columns - and right now you only have one way
to count through a list: one number at a time, in one direction.

At the same time: you want to store a student's name. A number can't
hold a name. You have never had a real way to store text in a program.

</div>

<!-- notes: Ask: "How would you store a 3x4 grade sheet using only what
you know from last week?" Let them struggle with nested arrays-of-arrays
in their heads before revealing the answer already has a name. -->

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Without a grid type, tabular data (grades, game boards, images) needs
  clumsy workarounds: separate arrays per row, easy to get out of sync.
- Without text handling, a program can't greet a user by name, read a
  word, or compare two names - most real programs touch text constantly.

<div class="why">
<strong>In industry:</strong> nearly every program processes text: file
names, user input, log messages, configuration. A 2-D grid is the same
shape behind a spreadsheet, a game board, and a small grayscale image.
Both ideas show up in almost every technical interview.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How do you store a table of numbers, and how do you store and process text, in C?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Declare and traverse a 2-D array using nested loops.
2. Compute row sums and column sums on a 2-D array.
3. Declare a C string as a `char` array and explain the `\0` terminator.
4. Use `strlen`, `strcpy`, `strcmp`, and `strcat` from `<string.h>`.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

Each `char` is stored as one byte: its ASCII code. `'A'` is 65, `'a'` is
97, `'0'` is 48, `'\0'` is 0.

C strings work by walking an array byte by byte until they hit a 0 byte.
That "ends at the first zero" rule is a design choice C made in the
1970s - it keeps a string as nothing more than a plain array, with no
extra length field, but it puts the responsibility on YOU to always
leave room for that final `\0`.

A 2-D array follows the same "no magic" philosophy: it is really one
flat block of memory, laid out row after row (**row-major order**), and
C computes `m[r][c]`'s position for you.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# 2-D Array & C String: Definitions

> A **2-D array** is a grid of values, all the same type, addressed by
> two indices: `m[row][col]`. `int m[3][4]` holds 3 x 4 = 12 integers.

> A **C string** is not a built-in type. It is a `char` array ending
> with the special value `'\0'` (the null terminator), which marks
> "the string stops here."

---

<!-- SLOT 10: Mechanics - declaring and reading a 2-D array -->

# Declaring a 2-D Array

```c
int matrix[3][4];                     /* 3 rows, 4 columns, empty */
int m[2][3] = { {1,2,3}, {4,5,6} };   /* initialized */

m[0][0]   /* row 0, col 0 -> 1 */
m[1][2]   /* row 1, col 2 -> 6 */
```

- Always write the **row** index first, then the **column** index.
- Think of a spreadsheet: rows go top to bottom, columns go left to right.
- In memory, C stores it flat: row 0's cells, then row 1's, then row 2's
  ("row-major order") - the double index is really a convenience on top
  of one long array.

---

<!-- SLOT 11: Mechanics - nested traversal -->

# Nested Traversal: A Loop Inside a Loop

```c
int rows = 3, cols = 4;
for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
        printf("%4d", matrix[r][c]);
    }
    printf("\n");
}
```

- The **outer** loop walks rows, one at a time.
- The **inner** loop walks every column, for the CURRENT row.
- Print a newline after each row finishes, so the grid prints as a grid.
- This pattern - loop inside a loop - is exactly how you touch every
  cell of a table.

---

<!-- SLOT 12: Mechanics - C strings in memory -->

# A String Is a `char` Array With a Rule

```c
char name[10] = "Alice";   /* stored: 'A','l','i','c','e','\0', ????? */
char word[]   = "Hi";      /* size = 3: 'H','i','\0' */
```

- `char name[10] = "Alice"` stores 6 meaningful bytes: `'A' 'l' 'i' 'c'
  'e' '\0'`. The remaining 4 bytes are leftover garbage - unused.
- `strlen(name)` walks the array and stops the instant it sees `'\0'`.
  It reports 5 - it does NOT count the terminator itself.
- **Always allocate room for `\0`.** A word of 5 letters needs at least
  6 bytes of array, not 5.
- Forget the `'\0'`: string functions keep reading past the array end.
  That is undefined behavior - a common, dangerous bug.

---

<!-- SLOT 13: Mechanics - string.h toolkit -->

# The `<string.h>` Toolkit

```c
#include <string.h>

strlen(s)           /* number of chars before '\0' */
strcpy(dst, src)     /* copy src into dst (dst must be large enough) */
strcat(dst, src)     /* append src onto the end of dst */
strcmp(s1, s2)       /* 0 if equal; negative if s1<s2; positive if s1>s2 */
```

- These are the four functions you need for this week's exercises.
- `strcmp` is the one real surprise: you CANNOT compare strings with
  `==` in C (that compares addresses, not letters) - `strcmp` is the
  only correct way to check if two strings hold the same text.
- Heavier functions (`strtok`, `strstr`, `sprintf`) exist, but they are
  take-home reading, not class content this week.

---

<!-- SLOT 14: Worked example -->

# Worked Example: Matrix Row & Column Sums (1/2)

```c
#include <stdio.h>
#define R 3
#define C 3

int main(void) {
    int m[R][C];
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            scanf("%d", &m[r][c]);

    for (int r = 0; r < R; r++) {
        int rsum = 0;
        for (int c = 0; c < C; c++) { printf("%4d", m[r][c]); rsum += m[r][c]; }
        printf("  | %d\n", rsum);
    }
```

First loop reads all 9 values. Second loop prints each row while
building that row's running sum, printed at the end of the row.

---

# Worked Example: Matrix Row & Column Sums (2/2)

```c
    for (int c = 0; c < C; c++) {
        int csum = 0;
        for (int r = 0; r < R; r++) csum += m[r][c];
        printf("%4d", csum);
    }
    printf("\n");
    return 0;
}
```

The last loop walks DOWN each column (outer loop = column, inner loop
= row) to build each column's sum - the opposite traversal order from
the row-sum loop above.

---

<!-- SLOT 15: Worked example - string version -->

# Worked Example: Palindrome Check

```c
/* Returns 1 if s is a palindrome, 0 otherwise */
int is_palindrome(const char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) return 0;
    }
    return 1;
}
```

- `const char s[]` promises the function will not modify the string.
- `len / 2`: only the first half needs checking - each character is
  compared against its mirror on the other side; first mismatch ->
  return 0 right away.
- `"level"`: every mirror pair matches -> returns 1. `"hello"`: `'h'`
  vs `'o'` mismatch -> returns 0.

---

<!-- SLOT 16: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">No room for '\0'</div><div class="d">A string of 5 characters needs at least 6 bytes of array. Skipping this corrupts memory - string functions read past the end.</div></div>
<div class="card"><div class="h">Comparing strings with ==</div><div class="d">== always compares addresses, never the letters inside. Use strcmp(s1, s2) == 0 to check if two strings match.</div></div>
<div class="card"><div class="h">strcpy into a small buffer</div><div class="d">Copying a long string into a short array overflows it and can crash the program. Make sure dst is large enough first.</div></div>
<div class="card"><div class="h">Wrong column size in a function parameter</div><div class="d">When a 2-D array is passed to a function, the inner (column) dimension must be specified, or the compiler cannot compute row offsets.</div></div>
</div>

---

<!-- SLOT 17: Check yourself -->

# Check Yourself

1. `int m[2][3];` - how many total integers does this array hold?
2. `char word[] = "Hi";` - what is stored in `word`, byte by byte?
3. Why is `if (s1 == s2)` almost never what you want when comparing two
   C strings?

---

# Answers

1. 2 x 3 = 6 integers.
2. `'H'`, `'i'`, `'\0'` - three bytes total, even though "Hi" is 2 letters.
3. `==` compares the two array addresses, not their contents - it is
   almost always false even when the text is identical. Use `strcmp`.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What Arrays & Strings Cannot Do Yet

<div class="limits">
Arrays hold many values of ONE type. But a single real-world record -
a student with an id, a name, and a GPA - mixes several types together
in one unit. Right now you would need three separate arrays kept in
sync by hand.
</div>

<!-- notes: Ask: how would you keep an id array, a name array, and a gpa
array in sync as students are added or removed? Painful by hand - that
pain is exactly what Week 13 solves. -->

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 12 leaves **grouping different types of data about ONE thing
together** unsolved. **Week 13** addresses it: Basic Data Structures
(the `struct`).

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- A 2-D array is a grid, addressed `m[row][col]`, traversed with a loop
  inside a loop.
- A C string is a `char` array ending in `'\0'` - always leave room for it.
- `<string.h>` gives you `strlen`, `strcpy`, `strcat`, `strcmp` - never
  compare strings with `==`.
- **Lab page:** `book/src/labs/lab12-arrays-2d-strings.md`, for the
  matrix, text-statistics, and name-sorter exercises, plus the
  transpose challenge.
- **Prepare:** think about a piece of real data (a contact, a product)
  that mixes types - that is next week's motivation.

---

<!-- SLOT N+4: Thank You (Act 4 / CLOSE) -->
<!-- _class: end -->

# Thank You
