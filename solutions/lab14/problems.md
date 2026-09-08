# Lab 14: Debugging, Analysis and Project Build — Problem Set

Adapted from `src/labs/lab14-debugging-project.md`. These are the problem
statements only; see `answer-key/` for reference solutions. Bug locations
and trace answers are intentionally NOT revealed here.

## Guided In-Lab Exercises

### Exercise 1: Bug hunt

The professor provides `buggy.c`, a program with 3 deliberate bugs (at
least one compile-time, at least one logic bug). Your task:
1. Compile and read the errors.
2. Use `printf`-tracing to find the logic bug(s).
3. Fix all bugs. Write a comment near each fix: `/* BUG FIX: ... */`

File: submit the corrected `lab14_buggy.c`

### Exercise 2: Trace the program

Given `mystery.c` (provided — a function that sums up some subset of the
integers from 1 to n), predict the output for inputs 5, 10, and 0.
Write your predictions in a comment at the top, then run and compare.

File: `lab14_trace.c` (add your comment block)

### Exercise 3: Project finalization and submission

Use this time to:
- Run your project on several test inputs.
- Fix any remaining bugs.
- Write or complete your README.
- Submit to LMS before the session ends.

(No standalone solution file — this exercise is about each student's own
individual semester project, not a generic coding problem.)

## Practice Problems

These are ungraded: extra practice for the concepts in this lab. Solutions are not distributed with this page. Each problem below shows a short buggy snippet; find and fix every bug, add a `/* BUG FIX: ... */` comment next to each change (as in Exercise 1), and submit the corrected, complete program under the given filename.

### Practice 1: Fix the temperature converter

```c
int fahrenheit;
scanf("%d", &fahrenheit);
int celsius = (fahrenheit - 32) / 9 * 5;  /* wrong order + integer division */
printf("%d F = %d C\n", fahrenheit, celsius);
```

This is supposed to convert a Fahrenheit temperature to Celsius, but dividing before multiplying (and staying in `int` the whole way) truncates the result and gives the wrong answer. Fix it so the conversion is correct and reports one decimal place.

File: `lab14_practice1_temp_convert.c`

**Sample run:**
```
Enter Fahrenheit temperature: 98
98 F = 36.7 C
```

### Practice 2: Fix the vowel counter

```c
int count_vowels(const char word[]) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];
        if (c == 'a' && c == 'e' && c == 'i' && c == 'o' && c == 'u') {
            count++;
        }
    }
    return count;
}
```

This is supposed to count the vowels in `word`, but no single character can equal five different letters at the same time, so it never counts anything. Fix the condition and write a complete program that reads a word and prints its vowel count.

File: `lab14_practice2_vowel_count.c`

**Sample run:**
```
Enter a word: banana
Vowel count: 3
```

### Practice 3: Fix the grid border painter

```c
void paint_border(char grid[][SIZE], int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (r == 0 || r == size || c == 0 || c == size) {
                grid[r][c] = '*';
            } else {
                grid[r][c] = '.';
            }
        }
    }
}
```

This is supposed to paint `'*'` around the border of a `SIZE x SIZE` grid and `'.'` everywhere inside, but valid indices only go up to `size - 1`, so the bottom row and right column never get painted. Fix the bounds and write a complete program (`SIZE` 4) that paints and prints the grid.

File: `lab14_practice3_border.c`

**Sample run:**
```
****
*..*
*..*
****
```

### Practice 4: Fix the word reverser

```c
void reverse_string(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
```

This is supposed to reverse `s` in place, but looping all the way to `len` swaps every pair once on the way in and then swaps each pair right back on the way out, leaving the string unchanged. Fix the loop bound and write a complete program that reads a word and prints it reversed.

File: `lab14_practice4_reverse_fix.c`

**Sample run:**
```
Enter a word: coding
Reversed: gnidoc
```

### Practice 5: Fix the cheapest item finder

```c
int find_cheapest(const Item items[], int count) {
    int cheapest_index = 0;
    double best_price = 0.0;
    for (int i = 0; i < count; i++) {
        if (items[i].price < best_price) {
            cheapest_index = i;
            best_price = items[i].price;
        }
    }
    return cheapest_index;
}
```

`Item` has a `char name[20]` and a `double price`. This is supposed to find the cheapest item in the array, but starting `best_price` at `0.0` means no real (positive) price is ever less than it, so it always reports index 0 no matter what. Fix the starting value and write a complete program that reads 4 items and prints the cheapest one.

File: `lab14_practice5_cheapest.c`

**Sample run:**
```
Cheapest item: Milk ($0.99)
```

### Practice 6: Trace and fix a recursive sum

```c
int sum_down(int n) {
    return n + sum_down(n - 1);
}
```

This is supposed to recursively sum the integers from `n` down to 0, but it has no base case, so it keeps calling itself with a smaller `n` forever and crashes with a stack overflow. Add the missing base case, then write your predictions for `sum_down(5)`, `sum_down(10)`, and `sum_down(0)` in a comment at the top of your file (as in the Worked Example), and verify them by running the program.

File: `lab14_practice6_recursive_sum.c`

**Sample run:**
```
sum_down(5)  = 15
sum_down(10) = 55
sum_down(0)  = 0
```

### Practice 7: Fix the attendance tracker

```c
#define NUM_STUDENTS 4
#define TOTAL_DAYS 10

typedef struct {
    char name[20];
    int days_present;
} Student;

int main(void) {
    Student roster[NUM_STUDENTS];
    int total_present = 0
    int perfect_count = 0;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        scanf("%19s", roster[i].name);
        scanf("%d", &roster[i].days_present);
        total_present += roster[i].days_present;
        if (roster[i].days_present = TOTAL_DAYS) {
            perfect_count++;
        }
    }

    int lowest_index = 0;
    for (int i = 0; i <= NUM_STUDENTS; i++) {
        if (roster[i].days_present < roster[lowest_index].days_present) {
            lowest_index = i;
        }
    }

    printf("Total attendance: %d\n", total_present);
    printf("Perfect attendance: %d\n", perfect_count);
    printf("Lowest attendance: %s (%d days)\n",
           roster[lowest_index].name, roster[lowest_index].days_present);

    return 0;
}
```

This attendance tracker (out of `TOTAL_DAYS` = 10 days) has 3 deliberate bugs: one compile-time bug and two logic bugs (one that corrupts data and one that reads past the end of the array). Find and fix all three, marking each with a `/* BUG FIX: ... */` comment.

File: `lab14_practice7_attendance.c`

**Sample run:**
```
Total attendance: 34
Perfect attendance: 2
Lowest attendance: Cid (6 days)
```

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Corrected buggy program | `lab14_buggy.c` | 4 |
| Trace exercise with predictions | `lab14_trace.c` | 2 |
| **Project artifact + README** | `project/` folder | **30% of final grade** |
