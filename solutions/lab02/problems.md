# Lab 02 — Problems (Guided Exercises & Challenge)

## Exercise 1: Your name card

Write a program that prints a name card in this format:

```
+---------------------------+
| Name : [your name]        |
| ID   : [your student ID]  |
| Lab  : Computer Prog. I   |
+---------------------------+
```

File: `lab02_card.c`

## Exercise 2: Break it and read the error

Take your `lab02_card.c` and:

1. Remove the semicolon from one line. Compile. Read the error. Put it back.
2. Remove the `#include <stdio.h>` line. Compile. Read the error. Put it back.
3. Change `main` to `Main`. Compile. Read the error. Put it back.
   (This demos case sensitivity: `Main` and `main` are different names to C.)

For each case, write a comment at the top of your file recording what the
error message said.

## Exercise 3: ASCII banner

Write a program that prints a simple ASCII banner of your choice
(for example, your initials drawn with `*` characters) using `printf`.
Use at least 5 `printf` calls and at least one escape sequence other than `\n`.

File: `lab02_banner.c`

## Challenge Problem: 5-times table

Write a program that prints a multiplication table for the 5-times table:

```
5 x 1 = 5
5 x 2 = 10
...
5 x 10 = 50
```

Write out all 10 `printf` calls by hand (loops arrive in Week 6).
