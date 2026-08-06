# Debugging Tips & Common Errors

This appendix is your reference for the two categories of bugs you will encounter:
**compile-time errors** (the program won't build) and **runtime bugs** (the program builds but misbehaves).

---

## Part 1: Reading Compiler Error Messages

### Anatomy of a GCC Error

```
hello.c:5:18: error: expected ';' before 'return'
```

| Part | Meaning |
|------|---------|
| `hello.c` | Which file |
| `5` | Which line |
| `18` | Which column (character position) |
| `error:` | Fatal: program won't compile |
| `warning:` | Non-fatal but dangerous; treat as errors |
| Message text | What went wrong |

**Rule:** Fix the **first** error first. Later errors are often caused by the first one.
After each fix, recompile before fixing the next.

---

## Part 2: Common Compile-Time Errors

| Error message | Likely cause | Fix |
|---------------|--------------|-----|
| `expected ';' before ...` | Missing semicolon | Add `;` at the end of the previous statement |
| `implicit declaration of function 'printf'` | Missing `#include <stdio.h>` | Add the include |
| `undeclared identifier 'x'` | Variable used before declared | Declare `int x;` before first use |
| `too few arguments to function` | Wrong number of arguments in a call | Check the function prototype |
| `expected expression` | Missing value where one is needed | Check for typos, missing operand |
| `lvalue required as left operand of assignment` | `5 = x;` (cannot assign to a literal) | Flip to `x = 5;` |
| `incompatible types` | Assigning wrong type | Check that types match, or cast explicitly |
| `redefinition of ...` | Variable or function declared twice | Remove the duplicate |

---

## Part 3: Common Logic (Runtime) Bugs

These compile fine but produce wrong results or crashes.

### Off-by-one Errors

```c
int a[5];
for (int i = 0; i <= 5; i++) a[i] = 0;  /* Bug: i=5 accesses a[5] - out of bounds! */
for (int i = 0; i < 5;  i++) a[i] = 0;  /* Correct */
```

**How to find:** trace the first and last iterations manually.

### Infinite Loop

```c
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    /* forgot i++ */
}
```

**How to find:** add `printf("DEBUG i=%d\n", i);` inside the loop. If the same value
prints forever, you have a missing update.

### Using `=` Instead of `==`

```c
if (x = 5) { ... }   /* Bug: assigns 5 to x, condition is always true */
if (x == 5) { ... }  /* Correct */
```

Compile with `-Wall`; GCC warns about this pattern.

### Integer Division Giving 0

```c
double rate = 1 / 3;    /* Bug: integer division → 0; then stored as 0.0 */
double rate = 1.0 / 3;  /* Correct: 0.333... */
```

### Forgetting `&` in `scanf`

```c
int x;
scanf("%d", x);    /* Bug: passes the value of x, not its address */
scanf("%d", &x);   /* Correct */
```

Often causes a segmentation fault.

### Not Null-Terminating a String

```c
char s[3] = {'H', 'i'};   /* s[2] is garbage, not '\0' */
printf("%s\n", s);         /* undefined: reads past end */

char s[3] = {'H', 'i', '\0'};  /* Correct */
/* or simply: */
char s[] = "Hi";
```

### Uninitialized Variable

```c
int total;
printf("%d\n", total);   /* garbage: value is undefined */

int total = 0;           /* always initialize */
```

---

## Part 4: printf-Tracing Recipe

When a program compiles but gives wrong results:

1. **Identify the suspected region:** narrow down which function or loop has the bug.
2. **Add `DEBUG:` printf statements** before and after key operations:
   ```c
   printf("DEBUG: entering loop, i=%d, sum=%d\n", i, sum);
   ```
3. **Run and read the output:** find where values deviate from what you expect.
4. **Fix the root cause,** not just the symptom.
5. **Remove all `DEBUG:` lines** before submitting.

To complement `printf`-tracing with a structured hand trace, see
[Reading and Tracing a Program](tracing-a-program.md).

---

## Part 5: gdb Quick Reference

Compile with debug info: `gcc -g file.c -o prog`

| Command | Effect |
|---------|--------|
| `gdb ./prog` | Start debugger |
| `break main` | Set breakpoint at the start of `main` |
| `break 42` | Set breakpoint at line 42 |
| `run` | Start program; stops at first breakpoint |
| `next` | Execute next line (step over function calls) |
| `step` | Execute next line (step into function calls) |
| `print x` | Print value of variable `x` |
| `print *p` | Dereference pointer `p` |
| `continue` | Run until next breakpoint |
| `quit` | Exit gdb |

---

## Part 6: Debugging Checklist

Before asking for help, go through this checklist:

- [ ] Compile with `-Wall -Wextra`: have you read all warnings?
- [ ] Is the first error fixed first?
- [ ] Did you add `printf`-tracing to narrow down the bad region?
- [ ] Did you trace the loop (first and last iteration) on paper?
- [ ] Did you check `=` vs `==` in every condition?
- [ ] Are all arrays indexed from 0 to n−1?
- [ ] Is every `scanf` call using `&`?
- [ ] Are all variables initialized before use?
- [ ] Are all strings null-terminated?
