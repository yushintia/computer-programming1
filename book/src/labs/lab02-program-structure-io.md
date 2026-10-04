# Lab 02: Program Structure & Basic I/O

| | |
|---|---|
| **Week** | 2 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 01 (working toolchain) |

**Why this lab matters:** A program that cannot receive input or display output is like a calculator with no buttons and no screen. This lab gives your programs the ability to communicate: to ask the user for data and to report results back. Every interactive application you have ever used, from a login screen to a search box to a form on a website, depends on exactly these operations, which makes this lab the foundation for everything you will build in this course.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap · 30 program anatomy and compilation model · 15 live demo |
| B (Guided practice) | 50 | 40 guided `printf` coding and reading errors · 10 debrief and pitfalls |
| C (Independent and wrap) | 50 | 35 independent exercises · 10 challenge · 5 submit and Week 3 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Identify the parts of a minimal C program: preprocessor directives, `main`, statements, `return`.
2. Use `printf` to print text, numbers, and escape sequences (`\n`, `\t`).
3. Compile a program with `gcc` and read the first error message when it fails.
4. Deliberately introduce a common error, read the message, and fix it.
5. Read a C program's layout: recognise comments, string literals, indentation, and code blocks, and explain that whitespace and comments are for human readers, not the compiler.

---

## Recap

In Week 1 you ran a program someone else wrote and verified that your toolchain works.
This week you write your first programs from scratch and learn what each part does.

---

## Background

### Anatomy of a C Program

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 620 280" style="max-width:600px;display:block;margin:1.5em auto;">
  <title>Anatomy of a C program showing four numbered parts: 1 preprocessor directive include stdio.h, 2 main function header, 3 a printf statement, and 4 return 0. Each part has a callout label explaining its purpose.</title>
  <defs>
    <marker id="arr-02" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Code block background -->
  <rect x="10" y="10" width="340" height="260" rx="8" fill="#f5f9fd" stroke="#ccd" stroke-width="1.5"/>
  <!-- Line numbers and code -->
  <text x="25" y="42"  font-family="monospace" font-size="13" fill="#888">1</text>
  <text x="45" y="42"  font-family="monospace" font-size="13" fill="#2e7d32">#include &lt;stdio.h&gt;</text>
  <text x="25" y="68"  font-family="monospace" font-size="13" fill="#888">2</text>
  <text x="25" y="95"  font-family="monospace" font-size="13" fill="#888">3</text>
  <text x="45" y="95"  font-family="monospace" font-size="13" fill="#0b3d66">int main(void) {</text>
  <text x="25" y="122" font-family="monospace" font-size="13" fill="#888">4</text>
  <text x="45" y="122" font-family="monospace" font-size="13" fill="#333">    printf("Hi!\n");</text>
  <text x="25" y="149" font-family="monospace" font-size="13" fill="#888">5</text>
  <text x="25" y="176" font-family="monospace" font-size="13" fill="#888">6</text>
  <text x="45" y="176" font-family="monospace" font-size="13" fill="#c07000">    return 0;</text>
  <text x="25" y="203" font-family="monospace" font-size="13" fill="#888">7</text>
  <text x="45" y="203" font-family="monospace" font-size="13" fill="#0b3d66">}</text>
  <!-- Callout 1: #include -->
  <line x1="190" y1="38" x2="360" y2="55" stroke="#0b3d66" stroke-width="1.2" marker-end="url(#arr-02)"/>
  <rect x="360" y="20" width="240" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="370" y="37" font-family="sans-serif" font-size="10" font-weight="bold" fill="#0b3d66">① Preprocessor directive</text>
  <text x="370" y="52" font-family="sans-serif" font-size="10" fill="#444">Includes the I/O library so you</text>
  <text x="370" y="64" font-family="sans-serif" font-size="10" fill="#444">can use printf and scanf.</text>
  <!-- Callout 2: main -->
  <line x1="175" y1="93" x2="360" y2="100" stroke="#0b3d66" stroke-width="1.2" marker-end="url(#arr-02)"/>
  <rect x="360" y="80" width="240" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="370" y="97" font-family="sans-serif" font-size="10" font-weight="bold" fill="#0b3d66">② main function</text>
  <text x="370" y="112" font-family="sans-serif" font-size="10" fill="#444">The entry point. Every C program</text>
  <text x="370" y="124" font-family="sans-serif" font-size="10" fill="#444">starts executing here.</text>
  <!-- Callout 3: printf -->
  <line x1="215" y1="120" x2="360" y2="148" stroke="#0b3d66" stroke-width="1.2" marker-end="url(#arr-02)"/>
  <rect x="360" y="138" width="240" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="370" y="155" font-family="sans-serif" font-size="10" font-weight="bold" fill="#0b3d66">③ Statement</text>
  <text x="370" y="170" font-family="sans-serif" font-size="10" fill="#444">Calls printf to print text. Every</text>
  <text x="370" y="182" font-family="sans-serif" font-size="10" fill="#444">statement ends with a semicolon.</text>
  <!-- Callout 4: return -->
  <line x1="125" y1="174" x2="360" y2="208" stroke="#0b3d66" stroke-width="1.2" marker-end="url(#arr-02)"/>
  <rect x="360" y="198" width="240" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1"/>
  <text x="370" y="215" font-family="sans-serif" font-size="10" font-weight="bold" fill="#0b3d66">④ return 0</text>
  <text x="370" y="230" font-family="sans-serif" font-size="10" fill="#444">Tells the OS the program finished</text>
  <text x="370" y="242" font-family="sans-serif" font-size="10" fill="#444">successfully (0 = no error).</text>
</svg>
<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 2.1.</strong> Anatomy of a C program.</em></p>

| Part | What it does |
|------|-------------|
| `#include <stdio.h>` | Includes the standard input/output library so you can use `printf` and `scanf`. |
| `int main(void)` | The entry point. Every C program starts here. `int` means main returns an integer; `void` means it takes no arguments. |
| `{ ... }` | Curly braces group the body of `main`. Everything between `{` and `}` belongs to main. |
| `printf("Hi!\n");` | Calls `printf` to print text. `\n` is a newline (moves to the next line). Every statement ends with `;`. |
| `return 0;` | Tells the operating system the program finished successfully. 0 means "no error"; any other number signals a problem. |

> **In plain words: library**
> A library is a collection of pre-written, pre-tested functions that come with the compiler.
> Instead of writing your own code to talk to the screen, you use `printf`, which was
> written by experts and works on every platform. `#include <stdio.h>` is the instruction
> that brings the input/output library (standard I/O) into your program. Think of it
> like borrowing a professional toolkit from a shelf rather than building every tool yourself.

> **In plain words: `main` function**
> Every C program must have exactly one function named `main`. When you run the program,
> the operating system starts executing from the first line inside `main`. It is the
> front door of your program. There can only be one front door.

> **In plain words: statement and semicolon**
> A statement is one complete instruction, like one sentence in English.
> In C, every statement ends with a semicolon (`;`). The semicolon is the full stop.
> Forgetting it is the single most common compile error you will make, and the compiler
> will tell you exactly where the missing one is.

### Reading C Code

Before writing your own programs, practice *reading* existing ones.
A C source file is just text, but it contains several kinds of writing mixed together:
executable statements, notes for human readers, and formatting that makes the structure visible.
Understanding each kind is the first step to reading code confidently.

> **In plain words: syntax and keywords**
> *Syntax* is the grammar of C: the rules that say where semicolons go, how braces must be
> paired, and in what order words are allowed to appear. When you break a grammar rule you get
> a *syntax error*. Think of it like spelling or punctuation rules in written English: the
> sentence is invalid if the rules are violated, even if the meaning seems obvious.
>
> A *keyword* is a word that C has reserved for its own grammar and that you cannot use as a
> variable or function name. Examples: `int`, `return`, `void`, `if`, `while`, `for`.
> The compiler knows every keyword and treats it specially. If you try to name a variable
> `return`, the compiler refuses because `return` already means something.

> **In plain words: string literal**
> Any text between double quotes `"..."` is called a *string literal*: the characters inside
> are printed exactly as written, character by character. The opening and closing `"` marks
> are not printed; they just tell the compiler where the text starts and ends.
>
> ```c
> printf("Hello!");   /* "Hello!" is a string literal; the quotes are not printed */
> ```
>
> String literals can contain escape sequences (like `\n` for newline) - those are covered
> in the next section. Any other character inside the quotes is printed as-is.

> **In plain words: comment**
> A comment is text the compiler ignores completely. It is written for humans: to explain
> what the code does, why a choice was made, or to leave a note for yourself later.
> C has two comment styles:
>
> ```c
> /* This is a block comment.
>    It can span multiple lines.
>    The compiler ignores everything between the slash-star and star-slash. */
>
> printf("Hi!\n");    // This is a line comment. It ends at the end of this line.
> ```
>
> Both styles appear throughout this manual. Use block comments for file headers and
> multi-sentence explanations; use line comments for brief notes next to a statement.
> A common beginner mistake: forgetting the closing `*/` on a block comment, which causes
> the compiler to ignore everything from that point on.

> **In plain words: whitespace and indentation**
> Whitespace means spaces, tabs, and blank lines. **C ignores extra whitespace** - the
> following two programs are identical to the compiler:
>
> ```c
> /* unindented - valid C, but hard to read */
> int main(void){printf("Hi!\n");return 0;}
> ```
>
> ```c
> /* indented - same program, much easier to read */
> int main(void) {
>     printf("Hi!\n");
>     return 0;
> }
> ```
>
> *Indentation* is the leading whitespace that pushes a line to the right to show that it
> sits *inside* a block (between `{` and `}`). We use **4 spaces per level** of nesting
> in this course. The rule: everything inside `{` ... `}` is indented one extra level.
> When you open a second `{` inside the first, indent one more level, and so on.
>
> Indentation is not optional in a team or a course: unindented code is extremely hard to
> debug. The compiler does not care; your reader - and your professor - does.

> **In plain words: block (curly braces)**
> A *block* is a group of one or more statements enclosed between `{` and `}` and treated
> by the compiler as a single unit. `main`'s body is a block. Later, when you write `if`,
> `while`, and `for`, each one controls exactly one statement or one block:
>
> ```c
> if (score >= 90) {
>     printf("A\n");   /* these two statements are ONE block */
>     printf("Well done!\n");
> }
> ```
>
> Without the braces, only the very next statement would belong to the `if`. The braces
> are what group multiple statements into one unit. Forgetting braces when you need them
> is one of the most common sources of logic bugs in early C programs.

> **In plain words: case sensitivity**
> C treats uppercase and lowercase letters as completely different. `main`, `Main`,
> and `MAIN` are three separate, unrelated names. Only `main` (all lowercase) is
> recognized as the program's entry point.
>
> ```c
> int Main(void) {   /* wrong: 'Main' is not the entry point */
>     return 0;
> }
> ```
>
> This applies to everything: variable names, function names, and keywords. `INT` is not
> the same as `int`; `Printf` is not the same as `printf`. When a program compiles but
> does nothing, or produces a "undefined reference to `main`" error, a wrong-case
> identifier is a common culprit.

For the full set of formatting rules (brace placement, 4-space indent, naming conventions),
see the [C Style Guide](../appendix/style-guide.md).

### Compile and Run: in One Sentence

**Your code goes into `gcc`, which produces a program you run.**

```bash
gcc hello.c -o hello -Wall    # compile
./hello                        # run
```

### `printf` and Escape Sequences

> **In plain words: escape sequence**
> Inside a string, the backslash `\` is a special signal to the compiler: the next
> character together with the backslash form an *escape sequence*, a two-character
> code that stands for something you cannot type literally in source code.
> For example, you cannot press Enter inside a string literal to get a newline;
> instead you write `\n` and the compiler replaces it with a single newline character
> when the program runs. The backslash "escapes" from the normal meaning of the
> following character.

| Escape sequence | Meaning | Common use |
|-----------------|---------|------------|
| `\n` | Newline (move to next line) | End every printed line |
| `\t` | Horizontal tab | Align columns |
| `\\` | Literal backslash | Print a `\` character |
| `\"` | Literal double-quote | Print `"` inside a string |
| `\'` | Literal single-quote | Print `'` inside a char literal |
| `\r` | Carriage return | Overwrite the current line (terminal tricks) |
| `\0` | Null character (value 0) | Marks the end of a C string |
| `\a` | Alert / bell | Beep the terminal speaker |
| `\b` | Backspace | Move cursor one position left |

```c
printf("Line one\n");       // \n  means newline
printf("A\tB\tC\n");        // \t  means tab
printf("Quote: \"Hi\"\n");  // \"  means a literal double-quote
```

### Reading Error Messages

When `gcc` refuses to compile, it prints something like:

```
hello.c:5:5: error: expected ';' before 'return'
```

Read it as: **file `hello.c`, line 5, column 5: missing semicolon before `return`**.

Rules:
1. Find the **line number** and look at that line first.
2. Fix the **first** error; recompile. Later errors often disappear.
3. Read the message literally; it usually tells you exactly what is wrong.

> **Under the Hood: compilation**
>
> When you run `gcc`, it translates your human-readable C text into
> machine code: numbers the CPU can execute directly.
> The resulting executable file is entirely different from your source.
> If your source has a syntax error, the compiler stops and produces nothing.
> It cannot translate something it does not understand.

---

## Worked Examples

### Example 1: Hello, World with formatting

```c
/* lab02_hello.c */
#include <stdio.h>

int main(void) {
    printf("========================================\n");
    printf("  Computer Programming I\n");
    printf("  Professor: Yushintia Pramitarini\n");
    printf("========================================\n");
    return 0;
}
```

Expected output:
```
========================================
  Computer Programming I
  Professor: Yushintia Pramitarini
========================================
```

### Example 2: Printing numbers and mixing text

```c
/* lab02_numbers.c */
#include <stdio.h>

int main(void) {
    printf("My favourite number is %d\n", 42);
    printf("Pi is approximately %.2f\n", 3.14159);
    printf("Twice my number is %d\n", 2 * 42);
    return 0;
}
```

Expected output:
```
My favourite number is 42
Pi is approximately 3.14
Twice my number is 84
```

> **`%d`** is a *format specifier*: a placeholder that tells `printf` what type of value
> to insert and how to display it. `%d` means "insert an integer here in decimal."
> `%.2f` means "insert a decimal number here, showing 2 digits after the decimal point."
> You will use these every week; Week 4 covers all the options in detail.

---

## Guided In-Lab Exercises

### Exercise 1: Your name card (Part B)

Write a program that prints a name card in this format:
```
+---------------------------+
| Name : [your name]        |
| ID   : [your student ID]  |
| Lab  : Computer Prog. I   |
+---------------------------+
```

File: `lab02_card.c`

### Exercise 2: Break it and read the error (Part B)

Take your `lab02_card.c` and:
1. Remove the semicolon from one line. Compile. Read the error. Put it back.
2. Remove the `#include <stdio.h>` line. Compile. Read the error. Put it back.
3. Change `main` to `Main`. Compile. Read the error. Put it back. (This demos case sensitivity: `Main` and `main` are different names to C.)

For each case, write a comment at the top of your file recording what the error message said.

### Exercise 3: ASCII banner (Part C)

Write a program that prints a simple ASCII banner of your choice
(for example, your initials drawn with `*` characters) using `printf`.
Use at least 5 `printf` calls and at least one escape sequence other than `\n`.

File: `lab02_banner.c`

---

## Challenge Problem

Write a program that prints a multiplication table header for the 5-times table:
```
5 x 1 = 5
5 x 2 = 10
...
5 x 10 = 50
```
Write out all 10 `printf` calls by hand (we will use loops starting Week 6).

File: `lab02_challenge_times_table.c`

---

## Practice Problems

These are ungraded - extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Bus ticket stub

Write a program that prints a fixed bus ticket stub inside an ASCII box using `printf`, showing a route, a seat number, and a price. Everything is hard-coded text and numbers; you do not need variables or input yet.

File: `lab02_practice1_ticket.c`

Sample run:
```
*****************************
*        BUS TICKET         *
*****************************
* Route: Seoul -> Busan     *
* Seat : 14A                *
* Price: 59000 KRW          *
*****************************
```

### Practice 2: Launch countdown

Write a program that prints a rocket-launch countdown, one line per `printf` call, counting down from 5 to "Liftoff!". Use a separate `printf` for every line.

File: `lab02_practice2_countdown.c`

Sample run:
```
Launch sequence starting...
5...
4...
3...
2...
1...
Liftoff!
```

### Practice 3: Weekly study timetable

Write a program that prints a two-column weekly study timetable (day and subject) using the `\t` escape sequence to line up the columns. Include a header row and one row for each weekday.

File: `lab02_practice3_timetable.c`

Sample run:
```
Day	Subject
Mon	Math
Tue	Physics
```
(five weekday rows total)

### Practice 4: Grocery receipt header

Write a program that prints a small fixed grocery receipt: a shop-name header line, three hard-coded item/price lines, a separator line, and a closing "thank you" message. No computation is required yet; every value is a literal you type directly into the `printf` calls.

File: `lab02_practice4_receipt.c`

Sample run:
```
===== CORNER GROCERY =====
Bread        2500
Milk         3200
Eggs         4100
===========================
Thank you for shopping!
```

### Practice 5: ASCII postcard

Write a program that draws a small ASCII picture (for example, a house) using at least five `printf` calls, including at least one escape sequence other than `\n` (such as `\t`) somewhere in the drawing.

File: `lab02_practice5_postcard.c`

Sample run:
```
    /\
   /  \
  /____\
  |    |
  |[]  |	Greetings from my house!
  |____|
```

### Practice 6: Cafe menu board

Write a program that prints a boxed cafe menu with a title, a header row, four tab-aligned item/price rows, and a closing message, using ten `printf` calls written out by hand (loops arrive in Week 6).

File: `lab02_practice6_menu.c`

Sample run:
```
+-----------------------------+
|         CAFE MENU           |
+-----------------------------+
| Item		Price (KRW)     |
| Coffee	3000            |
```
(plus Tea, Sandwich, and Cake rows, then a closing border and message)

### Practice 7: Escape sequence notice board

Write a program that prints a short "notice board" announcement that must include, somewhere in its output: a literal backslash (as part of a file path), a literal double quote (around a short quoted phrase), and at least one tab character used to separate words on a line.

File: `lab02_practice7_notice.c`

Sample run:
```
NOTICE BOARD
Backup path: C:\Lab02\backup
Today's quote: "Practice makes progress."
Office	hours	are	9-5.
```

---

## Common Pitfalls

| Mistake | Error message (approx.) | Fix |
|---------|------------------------|-----|
| Missing `;` at end of statement | `error: expected ';'` | Add the semicolon |
| Missing `#include <stdio.h>` | `warning: implicit declaration of 'printf'` or link error | Add the include |
| Using `'` instead of `"` around strings | `error: expected expression` | Use double quotes for strings |
| Unclosed `{` or `}` | `error: expected declaration` at end of file | Count your braces |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Name card program | `lab02_card.c` | 5 |
| ASCII banner | `lab02_banner.c` | 5 |

**Total: 10 points** (graded per [Assignments rubric](../appendix/grading-rubric.md))

---

## Further Reading

- King, Ch. 2 "C Fundamentals"
- [Debugging Tips](../appendix/debugging-tips.md)
- [C Style Guide](../appendix/style-guide.md) - formatting rules for indentation, braces, comments, and naming
