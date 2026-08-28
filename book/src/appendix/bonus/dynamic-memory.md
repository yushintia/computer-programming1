# Bonus: Dynamic Memory (malloc / free)

> **This is optional enrichment**, beyond the CS1 curriculum.
> Dynamic memory allocation is not assessed in this course.
> It is the first topic of **System Programming** and **Data Structures**.
> This page is a teaser.

---

## The Problem with Fixed-Size Arrays

All arrays in this course have a size fixed at **compile time**:

```c
int scores[100];   /* must decide at compile time; what if there are 200 students? */
```

What if you do not know the size until the program runs?
Dynamic memory allocation solves this.

---

## Stack vs Heap

| Memory region | What lives there | Lifetime |
|---------------|-----------------|----------|
| **Stack** | Local variables, function call frames | Freed automatically when function returns |
| **Heap** | Memory you allocate with `malloc` | Lives until you call `free` |

Local arrays are on the stack (limited size, typically 1–8 MB).
Dynamic arrays are on the heap (limited only by available RAM).

---

## `malloc` and `free`

```c
#include <stdlib.h>

/* Allocate an array of n ints */
int *scores = malloc(n * sizeof(int));
if (scores == NULL) {
    printf("Out of memory!\n");
    return 1;
}

/* Use it exactly like a regular array */
for (int i = 0; i < n; i++) scores[i] = 0;

/* Free when done - required! */
free(scores);
scores = NULL;   /* prevent accidental use after free */
```

`malloc(size)` returns a pointer to the newly allocated block, or `NULL` on failure.
`free(ptr)` returns the memory to the system.

---

## A Concrete Example: Read N scores at runtime

```c
/* dynamic_scores.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("How many scores? ");
    scanf("%d", &n);

    int *scores = malloc(n * sizeof(int));
    if (!scores) { fprintf(stderr, "malloc failed\n"); return 1; }

    for (int i = 0; i < n; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += scores[i];
    printf("Average: %.2f\n", (double)sum / n);

    free(scores);
    return 0;
}
```

---

## Common Dynamic Memory Bugs

| Bug | Description |
|-----|-------------|
| **Memory leak** | `malloc` without `free`: memory is never returned; program grows until it crashes |
| **Use after free** | Accessing memory after `free`: undefined behaviour |
| **Double free** | Calling `free` twice on the same pointer: corrupts the heap |
| **Buffer overflow** | Writing past the end of allocated memory: overwrites other data |

These bugs are hard to debug and are the source of many real-world security vulnerabilities.
**System Programming** teaches tools (Valgrind, AddressSanitizer) to detect them.

---

## Where You Will See This Again

- **System Programming:** `malloc`, `calloc`, `realloc`, `free`; the heap; memory-safe patterns.
- **Data Structures:** every linked list, tree, and hash table uses dynamic allocation for each node.
- **C++ / Modern Languages:** `new`/`delete` in C++; garbage collectors in Java/Python do this automatically.
