# Bonus: File I/O

> **This is optional enrichment**, beyond the CS1 curriculum.
> File I/O is not assessed in this course.
> It is introduced here for students who want their projects to save data between runs.
> You will study file I/O thoroughly in **System Programming**.

---

## Why File I/O?

All programs so far read from the keyboard and print to the screen.
When the program exits, all data is lost.
File I/O lets you **persist data**: save it to a file and read it back later.

---

## Opening and Closing Files

```c
#include <stdio.h>

FILE *fp;
fp = fopen("data.txt", "w");  /* open for writing (creates or overwrites) */
if (fp == NULL) {
    printf("Error: cannot open file.\n");
    return 1;
}
/* ... use fp ... */
fclose(fp);
```

| Mode | Meaning |
|------|---------|
| `"r"` | Open for reading (file must exist) |
| `"w"` | Open for writing (creates or overwrites) |
| `"a"` | Open for appending (adds to end) |
| `"r+"` | Open for reading and writing |

**Always check that `fopen` did not return `NULL`**: the file might not exist or might not be writable.
**Always call `fclose`**: this flushes buffered data to disk.

---

## Writing to a File

```c
FILE *fp = fopen("output.txt", "w");
if (fp == NULL) { perror("fopen"); return 1; }

fprintf(fp, "Name: %s\n", "Alice");      /* like printf, but to a file */
fprintf(fp, "Score: %d\n", 95);
fputs("Goodbye!\n", fp);                 /* write a string */

fclose(fp);
```

---

## Reading from a File

```c
FILE *fp = fopen("data.txt", "r");
if (fp == NULL) { perror("fopen"); return 1; }

char line[100];
while (fgets(line, sizeof(line), fp) != NULL) {  /* read one line */
    printf("%s", line);                           /* line includes '\n' */
}

fclose(fp);
```

Or read formatted values:

```c
int id;
char name[30];
double score;
while (fscanf(fp, "%d %29s %lf", &id, name, &score) == 3) {
    printf("%-8d %-12s %.2f\n", id, name, score);
}
```

---

## A Complete Example: Save and Load a Contact List

```c
/* contacts_file.c (outline) */
#include <stdio.h>
#include <string.h>

typedef struct { char name[30]; char phone[15]; } Contact;

void save(Contact c[], int n, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) { perror("save"); return; }
    for (int i = 0; i < n; i++)
        fprintf(fp, "%s %s\n", c[i].name, c[i].phone);
    fclose(fp);
}

int load(Contact c[], int max, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;   /* file does not exist yet */
    int n = 0;
    while (n < max && fscanf(fp, "%29s %14s", c[n].name, c[n].phone) == 2)
        n++;
    fclose(fp);
    return n;
}
```

---

## Where You Will See This Again

- **System Programming:** `open()`, `read()`, `write()` (low-level POSIX file API).
- **Databases:** file-backed storage, indexing, transactions.
- **Any real project:** configuration files, logs, data persistence.
