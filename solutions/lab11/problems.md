# Lab 11: Arrays I - One-Dimensional Arrays - Guided Exercises and Challenge

Prompts only, adapted from the lab text. See `answer-key/` for reference solutions.

## Guided In-Lab Exercises

### Exercise 1: Read and summarize

Write a program that:
1. Reads N (max 20) integers from the user.
2. Prints sum, average, min, max.
3. Counts how many values are above the average.

File: `lab11_stats.c`

### Exercise 2: Linear search

Write a function `int search(int a[], int n, int target)`.
Read an array of 10 integers, then repeatedly prompt "Search for: "
until the user enters -1. Print the index if found or "Not found".

File: `lab11_search.c`

### Exercise 3: Rotate left

Write a function `void rotate_left(int a[], int n)` that shifts each element
one position to the left, wrapping the first element to the end.
For example: `{1, 2, 3, 4, 5}` becomes `{2, 3, 4, 5, 1}`.

File: `lab11_rotate.c`

## Challenge Problem

Write a function that checks whether an array is a **palindrome**
(reads the same forwards and backwards). Return 1 if yes, 0 if no.
