# Lab 12: Arrays II: 2-D Arrays and Strings

Adapted from the Lab 12 lab page. These are the problem statements only.
Solutions are not distributed with this page.

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

### Exercise 4: Largest value and diagonal sum

Read a 4x4 grid of integers, one row at a time. Print the largest value, along with the
row and column where it first appears (counting rows and columns from 1). Then print the
sum of the main diagonal, the cells where the row number equals the column number.

File: `lab12_grid_max.c`

## Challenge Problem

Write a function `void transpose(int m[][N], int n)` that transposes a square
matrix in-place (swaps element `[r][c]` with element `[c][r]`).

File: `lab12_transpose.c`

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

Write a program that reads a single word (use `scanf("%s")`, as in Example 3) and a single letter, then counts how many times that letter appears in the word, ignoring uppercase/lowercase differences (use `tolower`).

File: `lab12_practice2_letter_count.c`

**Sample run:**
```
Enter a word: Mississippi
Enter a letter to count: s
's' appears 4 time(s)
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

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Matrix operations | `lab12_matrix.c` | 5 |
| String statistics | `lab12_text.c` | 3 |
| Name sorter | `lab12_names.c` | 2 |

**Total: 10 points**
