# References & Further Reading

---

## Primary Textbooks

1. **K. N. King**, *C Programming: A Modern Approach*, 2nd ed., W. W. Norton & Company.
   The primary textbook for this course. Beginner-friendly, comprehensive, with extensive exercises.

2. **Brian W. Kernighan & Dennis M. Ritchie**, *The C Programming Language*, 2nd ed., Prentice Hall.
   The canonical reference written by C's creators. Concise and authoritative; used for chapter mapping below.

## Supplementary Textbooks

3. **Stephen Prata**, *C Primer Plus*, 6th ed., Addison-Wesley.
   Very gentle introduction; ideal for absolute beginners who want more worked examples and explanation.

4. **Paul Deitel & Harvey Deitel**, *C How to Program*, 8th ed., Pearson.
   Extensive examples and exercises; strong on I/O and structured programming.

---

## Week-by-Week Chapter Map

| Week | Topic | King (K) | K&R |
|------|-------|----------|-----|
| 1 | Introduction to programming | K Ch. 1 | Ch. 1 |
| 2 | Program structure, printf | K Ch. 2 | Ch. 1 |
| 3 | Variables, types, scanf | K Ch. 3–4, 7 | Ch. 1–2 |
| 4 | I/O formatting, operators | K Ch. 3–4 | Ch. 2 |
| 5 | Conditionals | K Ch. 5 | Ch. 3 |
| 6 | while / do-while loops | K Ch. 6 | Ch. 3 |
| 7 | for / nested loops | K Ch. 6 | Ch. 3 |
| 8 | Midterm | n/a | n/a |
| 9 | Functions I | K Ch. 9 | Ch. 4 |
| 10 | Functions II, scope, recursion | K Ch. 9 | Ch. 4 |
| 11 | 1-D Arrays | K Ch. 8 | Ch. 5.1–5.3 |
| 12 | 2-D Arrays & Strings | K Ch. 8, 13 | Ch. 5–6 |
| 13 | Structs, pointer intro | K Ch. 16 | Ch. 6 |
| 14 | Debugging, project | n/a | n/a |
| 15 | Final | n/a | n/a |

---

## Online Resources

| Resource | URL | Use |
|----------|-----|-----|
| cppreference.com | <https://en.cppreference.com/w/c> | Standard library reference |
| OnlineGDB | <https://www.onlinegdb.com/online_c_compiler> | Browser C compiler (no install) |
| Programiz online C | <https://www.programiz.com/c-programming/online-compiler/> | Alternate browser compiler |
| GNU GDB manual | <https://sourceware.org/gdb/current/onlinedocs/gdb/> | Full gdb reference |

---

## Where to Go Next

After completing this course, you have several paths forward:

### System Programming
**Topics you will study:** pointers in depth, dynamic memory (`malloc`/`free`), file I/O,
processes and threads, system calls, the Unix API.
**Recommended reading:** K&R Chapters 5–7; *The Linux Programming Interface* (Kerrisk).
**Preview in this course:** [Bonus: Dynamic Memory](bonus/dynamic-memory.md), [Bonus: File I/O](bonus/file-io.md).

### Data Structures & Algorithms
**Topics you will study:** linked lists, stacks, queues, binary trees, hash tables,
sorting and searching algorithms, complexity analysis (Big-O).
**Recommended reading:** *Data Structures in C* (Tenenbaum); *Introduction to Algorithms* (CLRS).
**Preview in this course:** the pointer intro in Lab 13.

### Computer Architecture
**Topics you will study:** the CPU instruction set, memory hierarchy (cache, RAM, disk),
pipelining, assembly language.
**Connection to this course:** every "Under the Hood" box in the lab pages.

### Operating Systems
**Topics you will study:** process management, scheduling, virtual memory, file systems, I/O.
**Prerequisites:** System Programming, Computer Architecture.
