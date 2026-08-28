# C Style Guide

Consistent code style makes programs easier to read, debug, and grade.
Follow these conventions in all submitted work.

---

## File Header Block

Every `.c` file must begin with a comment block:

```c
/*
 * Course   : 400521-004 Computer Programming I
 * Professor: Yushintia Pramitarini
 * Name     : [Your Name]
 * Student ID: [Your ID]
 * Date     : [YYYY-MM-DD]
 * Lab      : [Lab 0X: Topic Name]
 * Filename : [filename.c]
 * Description: [one sentence about what this program does]
 */
```

---

## Naming Conventions

| Element | Style | Example |
|---------|-------|---------|
| Variables | `snake_case` | `total_score`, `num_students` |
| Constants (`#define`, `const`) | `SCREAMING_SNAKE` | `MAX_SIZE`, `PI` |
| Functions | `snake_case` | `compute_average()`, `print_menu()` |
| Types (`typedef struct`) | `PascalCase` | `Student`, `ContactEntry` |
| Loop counters | short is fine | `i`, `j`, `r`, `c` |

Use **descriptive names**: `score` is better than `x`; `num_items` is better than `n` unless `n` is conventional in a mathematical context.

---

## Indentation and Spacing

- Use **4 spaces** per indentation level (or tabs set to 4).
- Do **not** mix spaces and tabs.
- Opening brace `{` on the **same line** as the control statement.
- Closing brace `}` on its **own line**.

```c
/* Good */
if (score >= 90) {
    printf("A\n");
} else {
    printf("Below A\n");
}

/* Bad: no braces, inconsistent spacing */
if(score>=90) printf("A\n");
else printf("Below A\n");
```

Always use braces `{ }` even for single-statement bodies.

---

## Comments

- Write a comment for every function explaining what it does, its parameters, and its return value.
- Inside functions, comment non-obvious logic (not every line).
- Do not comment what the code obviously says (`i++; /* increment i */` is noise).

```c
/*
 * compute_average: returns the average of the first n elements of array a.
 * Parameters: a - integer array, n - number of elements (n > 0)
 * Returns: average as a double
 */
double compute_average(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return (double)sum / n;
}
```

---

## Functions

- **One function = one job.** If a function does two things, split it.
- Keep `main` short; call functions for each major task.
- Declare prototypes at the top of the file.
- Avoid global variables; pass data as parameters and return results.

---

## Constants

```c
/* Good */
#define MAX_STUDENTS 30
const double TAX_RATE = 0.10;

/* Bad: magic numbers */
if (count > 30) ...       /* what is 30? */
total = price * 1.10;     /* why 1.10? */
```

Name every non-obvious constant.

---

## Submission Filename Conventions

| Lab | Filename |
|-----|----------|
| Lab 02 card | `lab02_card.c` |
| Lab 06 guess | `lab06_guess.c` |
| Project | `project/main.c` + `project/README.txt` |

Use **lowercase with underscores**. Do not use spaces in filenames.

---

## Quick Checklist Before Submission

- [ ] File header block present and filled in
- [ ] Compiles with `gcc -Wall -Wextra -std=c99` without errors or warnings
- [ ] No debug `printf` statements left in
- [ ] Descriptive variable and function names
- [ ] Consistent 4-space indentation
- [ ] All functions have a comment explaining their purpose
- [ ] Correct filename format
