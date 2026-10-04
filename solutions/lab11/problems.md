# Lab 11: Arrays I: One-Dimensional Arrays

Prompts only, adapted from the Lab 11 lab page. Solutions are not distributed with this page.

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

### Exercise 4: Count values in a range

Write `int count_in_range(int a[], int n, int low, int high)` that returns how many
elements satisfy `low <= a[i] <= high`. In `main`, read 8 integers into an array, read
`low` and `high`, call the function, and print the count and the matching values on one
line, in the order they were entered.

File: `lab11_range.c`

## Challenge Problem

Write a function that checks whether an array is a **palindrome**
(reads the same forwards and backwards). Return 1 if yes, 0 if no.

File: `lab11_palindrome.c`

## Practice Problems

These are ungraded: extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Class attendance counter

Write a program that stores 10 days of attendance for one student in an array of `int`
(1 = present, 0 = absent), prints a day-by-day report ("Day 1: Present", etc.), and
uses a function `int count_present(int attendance[], int n)` to count and print the
total number of present days.

File: `lab11_practice1_attendance.c`

Sample run:
```
Day 1: Present
Day 2: Present
Day 3: Absent
Day 4: Present
Day 5: Present
Day 6: Present
Day 7: Absent
Day 8: Present
Day 9: Present
Day 10: Present
Total present days: 8
```

### Practice 2: Highest temperature day finder

Write a program that stores a week of daily temperatures in an array of `double`,
prints each day's reading, and uses a function `int index_of_max(double a[], int n)` to
find and report which day had the highest temperature.

File: `lab11_practice2_hottemp.c`

Sample run:
```
Day 1: 68.5
Day 2: 72.0
Day 3: 75.3
Day 4: 90.1
Day 5: 81.4
Day 6: 77.7
Day 7: 74.2
Highest temperature: 90.1 on Day 4
```

### Practice 3: Dice roll frequency counter

Write a function `int count_occurrences(int a[], int n, int target)`. Using a fixed
array of 12 dice roll results, prompt the user for a value from 1 to 6 and print how
many times that value appears in the array.

File: `lab11_practice3_dice.c`

Sample run:
```
Enter the value to count (1-6): 5
The value 5 appears 5 times.
```

### Practice 4: Daily sales excluding refunds

Write a function `double net_sales(double a[], int n)` that sums only the non-negative
entries of a sales array (negative entries represent refunds) and a function
`int count_refunds(double a[], int n)` that counts the negative entries. Test both on a
fixed array of 8 sales entries.

File: `lab11_practice4_sales.c`

Sample run:
```
Net sales (excluding refunds): 326.85
Number of refunds: 3
```

### Practice 5: Runner-up score finder

Write a function `int find_highest(int a[], int n)` and a function
`int find_runner_up(int a[], int n, int highest)` that finds the largest value strictly
less than `highest` (so a duplicate of the highest score is skipped). Test both on a
fixed array of 6 scores that contains a tie for first place.

File: `lab11_practice5_runnerup.c`

Sample run:
```
Highest score: 95
Runner-up score: 91
```

### Practice 6: Sort ticket prices ascending

Write a function `void bubble_sort_prices(double a[], int n)` that sorts an array of
concert ticket prices into ascending order using bubble sort. Print the array before
and after sorting.

File: `lab11_practice6_tickets.c`

Sample run:
```
Before sorting: 49.99 12.50 75.00 8.25 33.10 60.00 
After sorting: 8.25 12.50 33.10 49.99 60.00 75.00 
```

### Practice 7: Sorted locker number finder

Write a function `int binary_search_verbose(int a[], int n, int target)` that performs
binary search on a sorted array of 8 locker numbers, printing the index and value it
checks at every step, and returns the index of `target` or -1 if not found. Search for
two different locker numbers: one that exists and one that does not.

File: `lab11_practice7_lockers.c`

Sample run:
```
Searching for locker 124:
Step 1: checking index 3 (value 118)
Step 2: checking index 5 (value 130)
Step 3: checking index 4 (value 124)
Locker 124 found at index 4.

Searching for locker 115:
Step 1: checking index 3 (value 118)
Step 2: checking index 1 (value 105)
Step 3: checking index 2 (value 110)
Locker 115 not found.
```
