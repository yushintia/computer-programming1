# Lab 01: Course Introduction & Programming Concepts

| | |
|---|---|
| **Week** | 1 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture (no code submission this week) |
| **Prerequisites** | None |

**Why this lab matters:** Every digital device runs on programs: your phone, your car's navigation system, your bank's ATM. This lab shows you where programs come from and how a human idea becomes instructions a computer can follow. Understanding the programming mindset of breaking a problem into small, ordered steps is a skill you will apply in every role that involves computing, whether you end up writing software, analyzing data, or managing systems.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A | 50 | 30 min course overview and policies · 20 min programming concepts (problem to algorithm to code, pseudocode) |
| B | 50 | 30 min environment setup walkthrough (compiler/editor and online-compiler fallback) · 20 min start hands-on |
| C | 50 | 40 min hands-on: everyone types and runs a provided program · 10 min wrap-up and Week 2 preview |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. State what a program is and describe the problem-to-algorithm-to-code pipeline.
2. Write a simple pseudocode or flowchart for an everyday problem.
3. Open your text editor, create a `.c` file, and run it with a compiler (or online).
4. Locate and describe the course assessment model (Midterm 20%, Project 30%, Final 30%, Attendance 10%, Assignments 10%).

---

## Recap

This is the first meeting; there is no prior week to recap.

---

## Background

### What Is Programming?

A **program** is a set of instructions that tells a computer what to do.
You, the programmer, write those instructions in a **programming language** (C in this course).
The computer does exactly what you wrote: nothing more, nothing less.

> **In plain words: programming language**
> A programming language is a precise, structured way of writing instructions that both
> a human can read and a compiler can translate into machine code. English is too
> ambiguous for a computer (what does "make it bigger" mean exactly?). C uses strict
> grammar rules so there is only one possible interpretation of every instruction.
>
> Think of it like the difference between telling a friend "make the text bigger" and
> writing in a legal contract "increase the font size to 14 points in Helvetica Bold."
> The computer needs the contract version.

> **In plain words: algorithm**
> An algorithm is a step-by-step plan for solving a problem. Every step must be clear
> and unambiguous. An algorithm is language-independent: the tea-making steps below
> could be translated into C, Python, or carried out by a robot.

### From Problem to Code

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 600 130" style="max-width:580px;display:block;margin:1.5em auto;">
  <title>Four-step pipeline: Real-world problem goes to Understand and decompose, then to Design algorithm, then to Write C code, then to Compile and test. An arrow from the last step loops back to Understand to represent iteration.</title>
  <defs>
    <marker id="arr-01" markerWidth="8" markerHeight="8" refX="6" refY="3" orient="auto">
      <path d="M0,0 L0,6 L8,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Step 1 -->
  <rect x="10" y="30" width="120" height="50" rx="8" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="70" y="53" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Real-world</text>
  <text x="70" y="68" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Problem</text>
  <!-- arrow -->
  <line x1="130" y1="55" x2="152" y2="55" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-01)"/>
  <!-- Step 2 -->
  <rect x="155" y="30" width="120" height="50" rx="8" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="215" y="53" font-family="sans-serif" font-size="10" font-weight="bold" fill="#0b3d66" text-anchor="middle">Understand</text>
  <text x="215" y="66" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">Break into steps</text>
  <!-- arrow -->
  <line x1="275" y1="55" x2="297" y2="55" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-01)"/>
  <!-- Step 3 -->
  <rect x="300" y="30" width="120" height="50" rx="8" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="360" y="53" font-family="sans-serif" font-size="10" font-weight="bold" fill="#0b3d66" text-anchor="middle">Design Algorithm</text>
  <text x="360" y="66" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">Pseudocode / flowchart</text>
  <!-- arrow -->
  <line x1="420" y1="55" x2="442" y2="55" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-01)"/>
  <!-- Step 4 -->
  <rect x="445" y="30" width="130" height="50" rx="8" fill="#ddeeff" stroke="#0b3d66" stroke-width="2"/>
  <text x="510" y="53" font-family="sans-serif" font-size="10" font-weight="bold" fill="#0b3d66" text-anchor="middle">Write C Code</text>
  <text x="510" y="66" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">Compile and test</text>
  <!-- feedback loop arrow -->
  <path d="M510,80 Q510,115 360,115 Q215,115 215,80" fill="none" stroke="#0b3d66" stroke-width="1.2" stroke-dasharray="5,3" marker-end="url(#arr-01)"/>
  <text x="360" y="128" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">iterate until correct</text>
</svg>
<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 1.1.</strong> From problem to working code.</em></p>

Before writing any code, you should be able to describe your algorithm in plain language or pseudocode.

### What Is an Algorithm?

An algorithm is a precise, finite sequence of steps that solves a problem.

**Example: make tea**
```
1. Fill kettle with water.
2. Boil water.
3. Place tea bag in cup.
4. Pour boiling water into cup.
5. Wait 3 minutes.
6. Remove tea bag.
7. Add milk and sugar if desired.
```

Good programs come from good algorithms, not the other way around.

### Pseudocode

Pseudocode is informal, algorithm-level writing that looks like code but is not tied to any language.
There is no single correct pseudocode syntax; clarity is what matters.
Its purpose is to think through the logic before worrying about C syntax.
You cannot run pseudocode through a compiler; it is a planning tool, like a rough sketch before a final drawing.

**Example: find the larger of two numbers**
```
INPUT a, b
IF a > b THEN
    OUTPUT a
ELSE
    OUTPUT b
END IF
```

> **Under the Hood: what is a computer?**
>
> At its core, a computer is a machine that can store data (in RAM) and run instructions (in the CPU).
> The CPU performs a few billion simple operations per second: add, subtract, compare, jump, load, store.
> Everything a program does (printing text, sorting a list, playing a video) is built from combinations of these primitives.
> In this course you will write programs in C, which is close enough to the machine that you will start to see this.

---

## Worked Examples

### Example 1: The provided "first program" (run, do not write yet)

This program will be provided as a file. Read it, then run it:

```c
/* first.c */
#include <stdio.h>

int main(void) {
    printf("Hello, Computer Programming I!\n");
    printf("Instructor: Yushintia Pramitarini\n");
    return 0;
}
```

Expected output:
```
Hello, Computer Programming I!
Instructor: Yushintia Pramitarini
```

You do not need to understand every line yet; that is Week 2's job.
The goal right now is: does it compile and run on *your* machine?

---

## Guided In-Lab Exercises

### Exercise 1: Verify your toolchain (Part B)

- Follow [Setup: Toolchain](../setup/toolchain.md) to install gcc and an editor.
- Alternatively, open OnlineGDB or Programiz in a browser.
- Type (do not copy-paste) the example above, compile, and run it.
- Raise your hand if you see an error you cannot resolve.

### Exercise 2: Pseudocode for a vending machine (Part B and C)

Write pseudocode (not code) for the following problem:

> A vending machine sells drinks for 1,500 won each.
> A customer inserts coins. The machine should dispense a drink
> and return change when the customer has inserted enough coins.

Your pseudocode should handle:
- Accumulating the total inserted so far
- Checking when the total is at least 1,500
- Computing and dispensing change

There is no single correct answer. Discuss your solution with the person next to you.

### Exercise 3: Run the provided program (Part C)

- Open `first.c` (provided by the instructor).
- Compile it: `gcc first.c -o first`
- Run it: `./first`
- Take a screenshot of the terminal showing the output.

---

## Challenge Problem

Design a flowchart (on paper or a drawing tool) for the following:

> A student wants a program that reads their scores for three exams
> and prints their average, and whether they passed (average at least 60) or failed.

You will implement this as actual C code in Week 5.

---

## Common Pitfalls

- **"I cannot find the terminal."** On Windows: search for "Command Prompt", "PowerShell", or "WSL". On macOS: search for "Terminal". On Linux: right-click the desktop and look for Terminal.
- **"The compiler says 'command not found'."** gcc is not installed or not on your PATH. Use the online compiler today and fix the install before Week 2.
- **Pseudocode is not code.** Do not worry about semicolons or exact syntax. Write it so a classmate could follow the steps.

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Screenshot of `first.c` running on your machine (or online compiler) | `lab01_screenshot.png` (or `.jpg`) | 5 |
| Pseudocode for the vending machine problem (handwritten or typed) | `lab01_pseudo.txt` (or photo) | 5 |

**Total: 10 points** (graded per [Assignments rubric](../appendix/grading-rubric.md))

> No code to compile this week; the screenshot proves your environment works.

---

## Further Reading

- K. N. King, *C Programming: A Modern Approach*, Ch. 1 "Introducing C"
- [Setup: Toolchain](../setup/toolchain.md)
- [Setup: How a Program Runs](../setup/how-a-program-runs.md)
- [Pseudocode & Flowcharts](../appendix/pseudocode-flowchart.md) - symbol reference and worked examples
