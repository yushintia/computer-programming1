# Lab 12: Arrays II (2-D Arrays & Strings) — Problem Set

Adapted from `src/labs/lab12-arrays-2d-strings.md`. These are the problem
statements only; see `answer-key/` for reference solutions.

## Guided In-Lab Exercises

### Exercise 1: Matrix operations

Write a program that:
1. Reads a 3x4 integer matrix from the user.
2. Prints the matrix formatted with field width 5.
3. Prints the sum of each row.
4. Prints the sum of each column.
5. Prints the overall total.

File: `lab12_matrix.c`

### Exercise 2: String statistics

Write a program that reads a word (no spaces) and prints:
- Its length
- Whether it is a palindrome (yes/no)
- How many vowels it contains
- The word in uppercase (using `toupper` from `<ctype.h>`)

File: `lab12_text.c`

### Exercise 3: Name sorter

Read 5 names into a `char` array-of-strings (`char names[5][30]`).
Sort them alphabetically using `strcmp` in a simple bubble sort.
Print the sorted list.

File: `lab12_names.c`

## Challenge Problem

Write a function `void transpose(int m[][N], int n)` that transposes a square
matrix in-place (swaps element `[r][c]` with element `[c][r]`).

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Matrix operations | `lab12_matrix.c` | 5 |
| String statistics | `lab12_text.c` | 3 |
| Name sorter | `lab12_names.c` | 2 |

**Total: 10 points**
