# Lab 12: Arrays II: 2-D Arrays & Strings

| | |
|---|---|
| **Week** | 12 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 11 (1-D arrays, functions) |

**Why this lab matters:** Tables of data are everywhere: a classroom grade sheet with students in rows and assignments in columns, a game board, or an image stored as a two-dimensional grid of pixels. Two-dimensional arrays let you represent and process any tabular structure. Strings are the way C programs handle text, from names and messages to file contents, and every program that interacts with human-readable data uses them. Together, 2-D arrays and strings cover the two most common structured data forms in systems programming.

**Time allocation (one topic per part: tight week)**

| Part | Min | Activity |
|--------|-----|----------|
| A | 50 | 5 recap · 30 2-D array declaration and nested traversal · 15 matrix demo |
| B | 50 | 5 transition · 30 strings, `\0` terminator, `<string.h>` basics · 15 string demo |
| C | 50 | 35 independent exercises (matrix and text) · 10 challenge · 5 submit and Week 13 preview |

> Heavier `<string.h>` functions (`strtok`, `strstr`, `sprintf`) are take-home reading.
> Focus in class: the core concept of each part.

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Declare and traverse a 2-D array using nested loops.
2. Compute row/column sums on a 2-D array.
3. Declare a C string as a `char` array and understand the `\0` null terminator.
4. Use `strlen`, `strcpy`, `strcmp`, and `strcat` from `<string.h>`.

---

## Recap

In Week 11 you worked with 1-D arrays indexed by one number.
A 2-D array adds a second index: rows and columns.
Strings are also arrays: a C string is just an array of `char` values
ending with the special value `\0` (null terminator).

---

## Key Terms

> **In plain words: 2-D array**
> A 2-D array is a grid (table) of values, all of the same type, with two indices:
> row and column. `int m[3][4]` creates a table with 3 rows and 4 columns,
> holding 3 x 4 = 12 integers. You access one cell with `m[row][col]`.
> Think of a spreadsheet: rows go top to bottom, columns go left to right.
> Always write the row index first, then the column index.

> **In plain words: C string**
> In C, a string is not a built-in type; it is a `char` array with a special ending.
> The last character is always `'\0'` (null terminator, ASCII value 0), which marks
> "string ends here." `char name[10] = "Alice"` stores 6 bytes:
> `'A', 'l', 'i', 'c', 'e', '\0'`. Functions like `strlen` and `printf("%s", ...)`
> walk the array byte by byte and stop when they hit `'\0'`.
> If you forget to leave room for `'\0'`, these functions read past the array: undefined behavior.

> **In plain words: null terminator (`\0`)**
> `'\0'` is the character with ASCII code 0. It is invisible when printed.
> Its only job is to mark the end of a string. Without it, C has no way to know where
> the string ends, because a `char` array has no built-in "length" field.
> The convention "the string ends at the first zero byte" is a design choice C made in
> the 1970s; it is simple but puts responsibility on the programmer to always include it.

## Background: Part A: 2-D Arrays

### 2-D Array Row-Major Layout

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 560 202" style="max-width:540px;display:block;margin:1.5em auto;">
  <title>A 3 by 4 two-dimensional integer array shown in a grid. Rows are labeled 0 to 2 on the left and columns are labeled 0 to 3 at the top. Each cell shows the element value. Below the grid a flat memory layout shows the same elements stored row by row: row 0 first, then row 1, then row 2, demonstrating row-major order.</title>
  <!-- Column headers -->
  <text x="135" y="20" font-family="sans-serif" font-size="11" fill="#888" text-anchor="middle">col 0</text>
  <text x="215" y="20" font-family="sans-serif" font-size="11" fill="#888" text-anchor="middle">col 1</text>
  <text x="295" y="20" font-family="sans-serif" font-size="11" fill="#888" text-anchor="middle">col 2</text>
  <text x="375" y="20" font-family="sans-serif" font-size="11" fill="#888" text-anchor="middle">col 3</text>
  <!-- Row labels -->
  <text x="25" y="58" font-family="sans-serif" font-size="11" fill="#888" text-anchor="middle">row 0</text>
  <text x="25" y="98" font-family="sans-serif" font-size="11" fill="#888" text-anchor="middle">row 1</text>
  <text x="25" y="138" font-family="sans-serif" font-size="11" fill="#888" text-anchor="middle">row 2</text>
  <!-- Grid cells -->
  <rect x="95" y="30" width="80" height="40" rx="3" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/><text x="135" y="56" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">1</text>
  <rect x="175" y="30" width="80" height="40" rx="3" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/><text x="215" y="56" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">2</text>
  <rect x="255" y="30" width="80" height="40" rx="3" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/><text x="295" y="56" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">3</text>
  <rect x="335" y="30" width="80" height="40" rx="3" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/><text x="375" y="56" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">4</text>
  <rect x="95" y="70" width="80" height="40" rx="3" fill="#ddeeff" stroke="#0b3d66" stroke-width="1.2"/><text x="135" y="96" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">5</text>
  <rect x="175" y="70" width="80" height="40" rx="3" fill="#ddeeff" stroke="#0b3d66" stroke-width="1.2"/><text x="215" y="96" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">6</text>
  <rect x="255" y="70" width="80" height="40" rx="3" fill="#ddeeff" stroke="#0b3d66" stroke-width="1.2"/><text x="295" y="96" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">7</text>
  <rect x="335" y="70" width="80" height="40" rx="3" fill="#ddeeff" stroke="#0b3d66" stroke-width="1.2"/><text x="375" y="96" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">8</text>
  <rect x="95" y="110" width="80" height="40" rx="3" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/><text x="135" y="136" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">9</text>
  <rect x="175" y="110" width="80" height="40" rx="3" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/><text x="215" y="136" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">10</text>
  <rect x="255" y="110" width="80" height="40" rx="3" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/><text x="295" y="136" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">11</text>
  <rect x="335" y="110" width="80" height="40" rx="3" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/><text x="375" y="136" font-family="monospace" font-size="13" fill="#0b3d66" text-anchor="middle">12</text>
  <!-- Memory layout label -->
  <text x="95" y="165" font-family="sans-serif" font-size="10" fill="#888">In memory (row-major):</text>
  <text x="95" y="180" font-family="monospace" font-size="10" fill="#555">1  2  3  4  |  5  6  7  8  |  9  10  11  12</text>
  <text x="135" y="193" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">row 0</text>
  <text x="215" y="193" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">row 1</text>
  <text x="295" y="193" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">row 2</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 12.1.</strong> 2-D array stored in row-major order.</em></p>

```c
int matrix[3][4];         /* 3 rows, 4 columns */
int m[2][3] = { {1,2,3}, {4,5,6} };   /* initialized */

m[0][0]  /* row 0, col 0 -> 1 */
m[1][2]  /* row 1, col 2 -> 6 */
```

### Nested Traversal

```c
int rows = 3, cols = 4;
for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
        printf("%4d", matrix[r][c]);
    }
    printf("\n");
}
```

---

## Background: Part B: C Strings

### String Layout in Memory

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 500 110" style="max-width:480px;display:block;margin:1.5em auto;">
  <title>C string Alice stored in a char array of size 10. The first five cells contain the characters A, l, i, c, e. The sixth cell contains the null terminator backslash zero. The remaining four cells are shown as unused. An arrow labeled strlen = 5 points to the null terminator.</title>
  <defs>
    <marker id="arr-12" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <text x="10" y="20" font-family="monospace" font-size="13" fill="#0b3d66" font-weight="bold">char name[10] = "Alice";</text>
  <!-- cells -->
  <rect x="10"  y="30" width="45" height="45" rx="3" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <rect x="55"  y="30" width="45" height="45" rx="3" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <rect x="100" y="30" width="45" height="45" rx="3" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <rect x="145" y="30" width="45" height="45" rx="3" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <rect x="190" y="30" width="45" height="45" rx="3" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <rect x="235" y="30" width="45" height="45" rx="3" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <rect x="280" y="30" width="45" height="45" rx="3" fill="#f5f5f5" stroke="#ccc" stroke-width="1"/>
  <rect x="325" y="30" width="45" height="45" rx="3" fill="#f5f5f5" stroke="#ccc" stroke-width="1"/>
  <rect x="370" y="30" width="45" height="45" rx="3" fill="#f5f5f5" stroke="#ccc" stroke-width="1"/>
  <rect x="415" y="30" width="45" height="45" rx="3" fill="#f5f5f5" stroke="#ccc" stroke-width="1"/>
  <!-- chars -->
  <text x="32"  y="58" font-family="monospace" font-size="15" fill="#2e7d32" text-anchor="middle">'A'</text>
  <text x="77"  y="58" font-family="monospace" font-size="15" fill="#2e7d32" text-anchor="middle">'l'</text>
  <text x="122" y="58" font-family="monospace" font-size="15" fill="#2e7d32" text-anchor="middle">'i'</text>
  <text x="167" y="58" font-family="monospace" font-size="15" fill="#2e7d32" text-anchor="middle">'c'</text>
  <text x="212" y="58" font-family="monospace" font-size="15" fill="#2e7d32" text-anchor="middle">'e'</text>
  <text x="257" y="55" font-family="monospace" font-size="14" fill="#c07000" text-anchor="middle" font-weight="bold">'\0'</text>
  <text x="302" y="58" font-family="monospace" font-size="12" fill="#bbb" text-anchor="middle">?</text>
  <text x="347" y="58" font-family="monospace" font-size="12" fill="#bbb" text-anchor="middle">?</text>
  <text x="392" y="58" font-family="monospace" font-size="12" fill="#bbb" text-anchor="middle">?</text>
  <text x="437" y="58" font-family="monospace" font-size="12" fill="#bbb" text-anchor="middle">?</text>
  <!-- index labels -->
  <text x="32"  y="85" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">[0]</text>
  <text x="77"  y="85" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">[1]</text>
  <text x="122" y="85" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">[2]</text>
  <text x="167" y="85" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">[3]</text>
  <text x="212" y="85" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">[4]</text>
  <text x="257" y="85" font-family="monospace" font-size="9" fill="#c07000" text-anchor="middle">[5]</text>
  <!-- strlen arrow -->
  <line x1="257" y1="77" x2="257" y2="100" stroke="#c07000" stroke-width="1.5" marker-end="url(#arr-12)"/>
  <text x="310" y="105" font-family="sans-serif" font-size="10" fill="#c07000">strlen(name) = 5  (stops at '\0')</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 12.2.</strong> A C string and its null terminator.</em></p>

```c
char name[10] = "Alice";   /* stored: 'A','l','i','c','e','\0', garbage... */
char word[]   = "Hi";      /* size = 3: 'H','i','\0' */
```

**Always allocate room for `\0`.**
A string of 5 characters needs at least 6 bytes.

### Common `<string.h>` Functions

```c
#include <string.h>

strlen(s)           /* number of chars before '\0' */
strcpy(dst, src)    /* copy src into dst (dst must be large enough) */
strcat(dst, src)    /* append src to dst */
strcmp(s1, s2)      /* 0 if equal; negative if s1 < s2; positive if s1 > s2 */
```

> **Under the Hood: chars are bytes**
>
> Each `char` is stored as one byte: its ASCII code.
> `'A'` = 65, `'a'` = 97, `'0'` = 48, `'\0'` = 0.
> String functions work by walking the array byte by byte until they find 0.
> Missing the null terminator causes string functions to read past the array: a common bug.

---

## Worked Examples

### Example 1: Matrix row/column sums

```c
/* lab12_matrix.c (outline) */
/* Reads a 3x3 matrix, prints it, then prints row sums and column sums */
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
    for (int c = 0; c < C; c++) {
        int csum = 0;
        for (int r = 0; r < R; r++) csum += m[r][c];
        printf("%4d", csum);
    }
    printf("\n");
    return 0;
}
```

### Example 2: Palindrome check (string)

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

### Line by line: palindrome check

| Line | What it does |
|------|-------------|
| `int is_palindrome(const char s[])` | Takes a string `s` as a `const char[]`. The `const` keyword promises: "I will not modify the string." The return type `int` means 1 = yes (palindrome), 0 = no. |
| `int len = strlen(s);` | Get the number of characters (not counting `'\0'`). `strlen` walks the array until it finds `'\0'` and counts the steps. |
| `for (int i = 0; i < len / 2; i++)` | Only need to check the first half. For a 5-character string, `len/2 = 2` so we check indices 0 and 1. The middle character (index 2) has no mirror. |
| `if (s[i] != s[len - 1 - i]) return 0;` | Compare the character at position `i` from the left with the character at position `i` from the right. If they differ, it is not a palindrome: return 0 immediately. For `"level"`: compare s[0]='l' with s[4]='l' (match), s[1]='e' with s[3]='e' (match). Done. |
| `return 1;` | If the loop finished without finding a mismatch, every character matched its mirror: it is a palindrome. Return 1. |

**Examples:**
```
"level"  -> len=5, check i=0: 'l'=='l', i=1: 'e'=='e' -> return 1 (palindrome)
"hello"  -> len=5, check i=0: 'h' != 'o' -> return 0 (not palindrome)
"racecar"-> len=7, check 3 pairs, all match -> return 1
```

---

## Guided In-Lab Exercises

### Exercise 1: Matrix operations (Part A to C)

Write a program that:
1. Reads a 3x4 integer matrix from the user.
2. Prints the matrix formatted with field width 5.
3. Prints the sum of each row.
4. Prints the sum of each column.
5. Prints the overall total.

File: `lab12_matrix.c`

### Exercise 2: String statistics (Part B to C)

Write a program that reads a word (no spaces) and prints:
- Its length
- Whether it is a palindrome (yes/no)
- How many vowels it contains
- The word in uppercase (using `toupper` from `<ctype.h>`)

File: `lab12_text.c`

### Exercise 3: Name sorter (Part C)

Read 5 names into a `char` array-of-strings (`char names[5][30]`).
Sort them alphabetically using `strcmp` in a simple bubble sort.
Print the sorted list.

File: `lab12_names.c`

---

## Challenge Problem

Write a function `void transpose(int m[][N], int n)` that transposes a square matrix in-place
(swaps element [r][c] with element [c][r]).

File: `lab12_transpose.c`

---

## Practice Problems

These are ungraded: extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Word reversal

Write a program that reads a single word (no spaces) and prints it reversed. Reverse the characters in place by swapping the first and last, then the second and second-to-last, and so on; do not use a library reverse function.

File: `lab12_practice1_reverse.c`

**Sample run:**
```
Enter a word: hello
Reversed: olleh
```

### Practice 2: Letter counter

Write a program that reads a sentence (use `fgets`, up to 99 characters) and a single letter, then counts how many times that letter appears in the sentence, ignoring uppercase/lowercase differences (use `tolower`).

File: `lab12_practice2_letter_count.c`

**Sample run:**
```
Enter a sentence: The quick brown fox
Enter a letter to count: o
'o' appears 2 time(s)
```

### Practice 3: Classroom seating chart

A classroom has 3 rows of 4 seats, stored as a 2-D `char` array where `'X'` means occupied and `'.'` means empty. Read the grid one row at a time (each row entered as a 4-character string), print the grid back, then print how many empty seats are in each row.

File: `lab12_practice3_seating.c`

**Sample run:**
```
Row 1: X.X.
Row 2: ....
Row 3: XXXX

X.X.
....
XXXX
Row 1 empty seats: 2
Row 2 empty seats: 4
Row 3 empty seats: 0
```

### Practice 4: Tic-tac-toe winner check

Read a 3x3 tic-tac-toe board into a 2-D `char` array, one row at a time as a 3-character string of `'X'`, `'O'`, or `'.'`. Write a function that checks every row, every column, and both diagonals for three matching non-`'.'` characters, and print the winner (`"X"` or `"O"`), or `"No winner"` if nobody has three in a row.

File: `lab12_practice4_tictactoe.c`

**Sample run:**
```
Row 1: XXX
Row 2: OO.
Row 3: O..
Winner: X
```

### Practice 5: Caesar cipher encoder

Write a program that reads a lowercase word (letters only) and an integer shift amount, then prints the word encoded with a Caesar cipher: each letter is shifted forward in the alphabet by the shift amount, wrapping around from `'z'` back to `'a'`.

File: `lab12_practice5_caesar.c`

**Sample run:**
```
Enter a lowercase word: xyz
Enter shift amount: 3
Encoded: abc
```

### Practice 6: Longest word finder

Read 5 words into an array of strings (`char words[5][20]`). Write a function that finds the index of the longest word using `strlen` (on a tie, keep the first one found), then print that word together with its length.

File: `lab12_practice6_longest_word.c`

**Sample run:**
```
Word 1: cat
Word 2: elephant
Word 3: dog
Word 4: hippopotamus
Word 5: ox
Longest word: hippopotamus (12 letters)
```

### Practice 7: Magic square checker

Read a 3x3 integer grid. Write a function `is_magic_square` that returns 1 if every row sum, every column sum, and both diagonal sums are all equal to each other, and 0 otherwise. Print whether the entered grid is a magic square.

File: `lab12_practice7_magic_square.c`

**Sample run:**
```
Enter 9 integers for a 3x3 grid (row by row):
2 7 6 9 5 1 4 3 8
This grid IS a magic square.
```

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Not leaving room for `\0` | String functions corrupt memory | Size = characters + 1 |
| Comparing strings with `==` | Always compares pointer addresses, not content | Use `strcmp(s1, s2) == 0` |
| `strcpy` into a small buffer | Buffer overflow / crash | Ensure `dst` is large enough; use `strncpy` if unsure |
| Wrong column size in 2-D function param | Compiler error | The innermost dimension must be specified in the parameter |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Matrix operations | `lab12_matrix.c` | 5 |
| String statistics | `lab12_text.c` | 3 |
| Name sorter | `lab12_names.c` | 2 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 8 "Arrays"
- King, Ch. 13 "Strings"
- K&R, Ch. 5 "Pointers and Arrays", Ch. 6 §6.4
