---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 2: Program Structure & Basic I/O

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Recap Week 1 in one line (we ran someone else's program, verified
the toolchain). Today we write our own program for the first time.
-->

---

<!-- SLOT 2: Where we are (Act 0 / LOCATE) -->

# Where We Are

<div class="roadmap">
<div class="wk"><div class="n">Wk 1</div><div class="t">Introduction</div></div>
<div class="wk now"><div class="n">Wk 2</div><div class="t">Program Structure &amp; I/O</div></div>
<div class="wk"><div class="n">Wk 3</div><div class="t">Variables &amp; Data Types</div></div>
<div class="wk"><div class="n">Wk 4</div><div class="t">I/O &amp; Operators</div></div>
<div class="wk"><div class="n">Wk 5</div><div class="t">Conditionals</div></div>
<div class="wk"><div class="n">Wk 6</div><div class="t">Loops I: while</div></div>
<div class="wk"><div class="n">Wk 7</div><div class="t">Loops II: for</div></div>
<div class="wk review"><div class="n">Wk 8</div><div class="t">Midterm Exam</div></div>
<div class="wk"><div class="n">Wk 9</div><div class="t">Functions I</div></div>
<div class="wk"><div class="n">Wk 10</div><div class="t">Functions II: Recursion</div></div>
<div class="wk"><div class="n">Wk 11</div><div class="t">Arrays I: 1-D</div></div>
<div class="wk"><div class="n">Wk 12</div><div class="t">Arrays II: 2-D &amp; Strings</div></div>
<div class="wk"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** a working toolchain - you ran a program
  someone else wrote and confirmed it compiles and runs on your
  machine.
- **Last week left broken:** we don't yet know how to write a real
  program of our own, only run one someone else wrote.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# A Machine That Can't Say Anything

<div class="pain">

Imagine a calculator with no buttons and no screen. You could plug it
in, but you could never tell it what to do, and it could never show
you an answer. It is powered on, but silent and useless.

Right now, that is exactly what you have. You know how to start a
program someone else wrote. But you still have no way to make a
program of your own display a single word, a number, or a result on
the screen.

</div>

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Without a way to display anything, you cannot build even the
  simplest useful program: no greeting, no receipt, no report, no
  result of any kind.
- Every interactive tool you have ever used - a login screen, a
  search box, a form on a website - depends on a program's ability to
  show text and respond. None of that is possible yet.

<div class="why">
<strong>In industry:</strong> reading a small, unfamiliar program and
explaining what it prints is one of the first screening questions in
any programming interview or course. If you can't trace what a
program displays, you can't debug it either.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"What are the parts of a C program, and how do you make one print something to the screen?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Identify the parts of a minimal C program: preprocessor directive,
   `main`, statements, and `return`.
2. Use `printf` to print text, numbers, and escape sequences (`\n`,
   `\t`).
3. Compile a program with `gcc` and read the first error message when
   it fails.
4. Read a C program's layout - comments, string literals, and
   indentation - and explain that this is for human readers, not the
   compiler.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

<div class="thread">Under the hood: compilation.</div>

When you run `gcc`, it translates your human-readable C text into
machine code: numbers the CPU can execute directly. The resulting
program file is entirely different from the text you typed.

If your source has a mistake in its grammar, the compiler stops and
produces nothing at all - it cannot translate something it does not
understand. This is why the very first thing you learn in C is not a
clever trick, but the exact shape a program must have before the
compiler will accept it.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# A C Program: Definition

> A C program is a plain text file containing instructions written in
> the grammar (*syntax*) of the C language. Every C program must have
> exactly one `main` function - the single entry point where the
> operating system starts running your code.

Everything you write this week lives inside that one `main` function.

---

<!-- Act 3 / BUILD -->

<!-- SLOT 10: Mechanics - anatomy code -->

# Anatomy of a C Program

```c
/* lab02_hello.c */
#include <stdio.h>

int main(void) {
    printf("Hi!\n");
    return 0;
}
```

Four parts, always in roughly this order: a preprocessor directive, a
`main` function header, one or more statements, and a `return`.

---

<!-- SLOT 11: Mechanics - anatomy parts -->

# Anatomy, Part by Part

<div class="cardlist">
<div class="card"><div class="h">#include &lt;stdio.h&gt;</div><div class="d">Includes the standard I/O library so you can use printf and scanf.</div></div>
<div class="card"><div class="h">int main(void)</div><div class="d">The entry point. Every C program starts here. There can only be one front door.</div></div>
<div class="card"><div class="h">{ ... }</div><div class="d">Curly braces group the body of main. Everything between them belongs to main.</div></div>
<div class="card"><div class="h">return 0;</div><div class="d">Tells the operating system the program finished successfully - 0 means no error.</div></div>
</div>

---

<!-- SLOT 12: Mechanics - library -->

# What Is a Library?

A library is a collection of pre-written, pre-tested functions that
come with the compiler. Instead of writing your own code to talk to
the screen, you use `printf`, written by experts, working on every
platform.

`#include <stdio.h>` is the instruction that brings the input/output
library into your program - like borrowing a professional toolkit
from a shelf rather than building every tool yourself.

---

<!-- SLOT 13: Mechanics - statements & string literals -->

# Statements and String Literals

A **statement** is one complete instruction, like one sentence in
English. In C, every statement ends with a semicolon `;` - the full
stop. Forgetting it is the single most common compile error you will
make.

Any text between double quotes `"..."` is a **string literal**: the
characters inside are printed exactly as written.

```c
printf("Hello!");   /* "Hello!" is a string literal; the quotes are not printed */
```

---

<!-- SLOT 14: Mechanics - comments -->

# Comments: Notes the Compiler Ignores

A comment is text the compiler ignores completely - written for
humans, to explain what the code does or why.

```c
/* This is a block comment.
   It can span multiple lines. */

printf("Hi!\n");    // This is a line comment. Ends at the line's end.
```

A common mistake: forgetting the closing `*/` on a block comment,
which makes the compiler ignore everything after it.

---

<!-- SLOT 15: Mechanics - whitespace & indentation -->

# Whitespace and Indentation

C ignores extra whitespace - these two programs are identical to the
compiler:

```c
int main(void){printf("Hi!\n");return 0;}
```

```c
int main(void) {
    printf("Hi!\n");
    return 0;
}
```

Indentation (4 spaces per level in this course) is only for the human
reader. The compiler does not care - your reader, and your
professor, do. Braces `{ }` group multiple statements into one
block: without them, only the very next line belongs to an `if` or
loop.

---

<!-- SLOT 16: Mechanics - case sensitivity -->

# Case Sensitivity

C treats uppercase and lowercase letters as completely different
names. `main`, `Main`, and `MAIN` are three unrelated identifiers.
Only lowercase `main` is recognized as the program's entry point.

```c
int Main(void) {   /* wrong: 'Main' is not the entry point */
    return 0;
}
```

A program that compiles but does nothing, or an "undefined reference
to `main`" error, is often a wrong-case name.

---

<!-- SLOT 17: Mechanics - compile and run -->

# Compile and Run: in One Sentence

**Your code goes into `gcc`, which produces a program you run.**

```bash
gcc hello.c -o hello -Wall    # compile
./hello                        # run
```

`-Wall` turns on extra warnings - always compile with it. A warning
does not stop compilation, but it usually points at a real mistake.

---

<!-- SLOT 18: Mechanics - printf & escape sequences -->

# `printf` and Escape Sequences

Inside a string, a backslash `\` starts an **escape sequence**: a
two-character code for something you cannot type literally, like a
newline.

| Escape | Meaning | Common use |
|--------|---------|------------|
| `\n` | Newline | End every printed line |
| `\t` | Horizontal tab | Align columns |
| `\\` | Literal backslash | Print a `\` character |
| `\"` | Literal double-quote | Print `"` inside a string |

```c
printf("Line one\n");       // \n means newline
printf("A\tB\tC\n");        // \t means tab
```

---

<!-- SLOT 19: Mechanics - reading error messages -->

# Reading Error Messages

When `gcc` refuses to compile, it prints something like:

```
hello.c:5:5: error: expected ';' before 'return'
```

Read it as: **file `hello.c`, line 5, column 5: missing semicolon
before `return`**.

1. Find the **line number** and look at that line first.
2. Fix the **first** error, then recompile - later errors often
   disappear on their own.
3. Read the message literally; it usually says exactly what is wrong.

---

<!-- SLOT N-2: Worked example -->

# Worked Example: Hello, World with Formatting

```c
/* lab02_hello.c */
#include <stdio.h>

int main(void) {
    printf("===========================\n");
    printf("  Computer Programming I  \n");
    printf("  Professor: Y. Pramitar \n");
    printf("===========================\n");
    return 0;
}
```

Four separate `printf` calls, each ending in `\n`, build up a banner
one line at a time.

---

# Worked Example: Printing Numbers

```c
/* lab02_numbers.c */
#include <stdio.h>

int main(void) {
    printf("My favourite number is %d\n", 42);
    printf("Pi is approximately %.2f\n", 3.14159);
    printf("The letter A has ASCII code %d\n", 'A');
    return 0;
}
```

`%d` is a **format specifier** - a placeholder telling `printf` what
type of value to insert. `%.2f` means "a decimal number, 2 digits
after the point." Week 4 covers all the options in detail.

---

<!-- SLOT N-1: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Missing ; at end of a statement</div><div class="d">error: expected ';'. Add the semicolon - the single most common beginner error.</div></div>
<div class="card"><div class="h">Missing #include &lt;stdio.h&gt;</div><div class="d">warning: implicit declaration of 'printf', or a link error. Add the include.</div></div>
<div class="card"><div class="h">Using ' instead of " around strings</div><div class="d">error: expected expression. Strings always use double quotes.</div></div>
<div class="card"><div class="h">Unclosed { or }</div><div class="d">error: expected declaration at end of file. Count your braces.</div></div>
</div>

---

<!-- SLOT N: Check yourself -->

# Check Yourself

1. You delete the `#include <stdio.h>` line and compile. What kind of
   error or warning would you expect, and why?
2. You rename `main` to `Main`. Does the program still run? Why or
   why not?
3. What is the difference between what the compiler sees in an
   indented program versus an unindented one - and who actually
   benefits from indentation?

---

# Answers

1. A warning or error about `printf` being undeclared (or a link
   error) - the standard I/O library was never brought in, so the
   compiler doesn't know what `printf` is.
2. No - `main` (all lowercase) is the only name C recognizes as the
   entry point. `Main` is just an unused, unrelated function.
3. Nothing - the compiler ignores whitespace completely; both
   versions are identical to it. Only the human reader benefits from
   indentation.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE), becomes next week's slot 4 -->

# What `printf`-Only Programs Cannot Do Yet

<div class="limits">
We can print fixed text, but every value in a program is still typed
by hand, never provided by the user.
</div>

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 2 leaves **every value hard-coded, never provided by the user**
unsolved. **Week 3** addresses it: Variables, Data Types & Expressions
- places to store data, and `scanf` to read it from the keyboard.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- A minimal C program has a preprocessor directive, one `main`
  function, statements ending in `;`, and a `return`.
- `printf` prints text, numbers (with format specifiers like `%d` and
  `%.2f`), and escape sequences like `\n` and `\t`.
- `gcc file.c -o file -Wall` compiles; read the first error's line
  number first, fix it, then recompile.
- **Lab page:** `book/src/labs/lab02-program-structure-io.md` for the
  name-card exercise, the deliberate-error exercise, and the challenge
  problem.
- **Prepare:** make sure your toolchain from Week 1 still compiles and
  runs a program before class.

---

<!-- SLOT N+4: Thank You -->
<!-- _class: end -->

# Thank You
