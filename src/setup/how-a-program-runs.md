# How a Program Runs

This page gives you a **mental model**: a short, accurate picture of what happens
between typing your code and seeing output. You do not need to memorize this;
you need to *believe it*, because it explains many things that would otherwise seem like magic.

---

## The Big Picture: Write, Compile, Run

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 680 110" style="max-width:660px;display:block;margin:1.5em auto;">
  <title>Compilation pipeline: C source file goes into gcc compiler, which produces an executable binary, which the user runs to produce program output</title>
  <defs>
    <marker id="arr-p" markerWidth="8" markerHeight="8" refX="6" refY="3" orient="auto">
      <path d="M0,0 L0,6 L8,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Step 1: Source file -->
  <rect x="10" y="25" width="130" height="60" rx="8" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="75" y="49" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">hello.c</text>
  <text x="75" y="67" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">C source code</text>
  <text x="75" y="80" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">(text you write)</text>
  <!-- arrow -->
  <line x1="140" y1="55" x2="178" y2="55" stroke="#0b3d66" stroke-width="2" marker-end="url(#arr-p)"/>
  <!-- Step 2: gcc -->
  <rect x="180" y="25" width="130" height="60" rx="8" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="245" y="49" font-family="monospace" font-size="12" fill="#c07000" text-anchor="middle" font-weight="bold">gcc</text>
  <text x="245" y="66" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">compiler</text>
  <text x="245" y="80" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">(translates)</text>
  <!-- arrow -->
  <line x1="310" y1="55" x2="348" y2="55" stroke="#0b3d66" stroke-width="2" marker-end="url(#arr-p)"/>
  <!-- Step 3: Executable -->
  <rect x="350" y="25" width="130" height="60" rx="8" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="415" y="49" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">./hello</text>
  <text x="415" y="66" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">executable</text>
  <text x="415" y="80" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">(machine code)</text>
  <!-- arrow: "you run it" -->
  <line x1="480" y1="55" x2="518" y2="55" stroke="#0b3d66" stroke-width="2" marker-end="url(#arr-p)"/>
  <text x="499" y="43" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">you run it</text>
  <!-- Step 4: Output -->
  <rect x="520" y="25" width="140" height="60" rx="8" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="590" y="49" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle" font-weight="bold">Hello, world!</text>
  <text x="590" y="66" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">output on screen</text>
  <text x="590" y="80" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">(CPU ran the code)</text>
</svg>
<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure S.1.</strong> From source code to a running program.</em></p>

That is it. Three stages: **write, compile, run**.

Think of it like a recipe: you write the recipe (source code), a translator reads it and
turns it into precise kitchen instructions any chef can follow (machine code), and
then the chef (CPU) follows those instructions and produces the dish (output).

---

## Stage 1: Write

You write **C source code** in a text file (`hello.c`).
This is just text; the computer cannot run it yet.
C is called a *high-level* language because it is close to how humans think,
not how the CPU thinks.

---

## Stage 2: Compile

When you run `gcc hello.c -o hello`, the compiler does four things in order:

1. **Reads and checks your text** for grammar mistakes (missing `;`, typos in keywords, etc.).
2. **Translates it** into **machine code**: the tiny numeric instructions the CPU understands.
   Machine code looks like `01001000 10001001 11000001 ...` (not human-readable, but exactly what the chip needs).
3. **Links in standard library code.** When you write `printf(...)`, the compiler does not invent `printf` from scratch; it copies the ready-made `printf` code from the standard library into your executable.
4. **Writes the executable file** (`hello`). This is the file you distribute or run.

> **In plain words: standard library**
> The C standard library is a collection of pre-written, tested functions that come with
> every C compiler. `printf`, `scanf`, `strlen`, `sqrt` are all in it. You tell the compiler
> which part you need with `#include <stdio.h>` (for input/output functions) or
> `#include <math.h>` (for math functions). Think of the library as a toolbox that comes
> pre-packed with the compiler; `#include` picks up the tools you need for that project.

If there is a syntax error, the compiler prints an error message and does *not* produce an executable.
**This is good.** It means the bug is caught before the program ever runs.

---

## Stage 3: Run

When you type `./hello`, the operating system:

1. Loads the executable into **RAM (main memory)**.
2. Hands the first instruction to the **CPU**.
3. The CPU runs instructions one at a time, mostly top to bottom.

---

## CPU and Memory: The Hardware Picture

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 540 200" style="max-width:520px;display:block;margin:1.5em auto;">
  <title>Hardware schematic showing the CPU on the left connected by arrows to RAM on the right. RAM contains labeled cells for variables and code.</title>
  <defs>
    <marker id="arr-hw" markerWidth="8" markerHeight="8" refX="6" refY="3" orient="auto">
      <path d="M0,0 L0,6 L8,3 z" fill="#0b3d66"/>
    </marker>
    <marker id="arr-hw-rev" markerWidth="8" markerHeight="8" refX="2" refY="3" orient="auto">
      <path d="M8,0 L8,6 L0,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- CPU box -->
  <rect x="20" y="40" width="160" height="120" rx="10" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <text x="100" y="65" font-family="sans-serif" font-size="13" font-weight="bold" fill="#c07000" text-anchor="middle">CPU</text>
  <text x="100" y="88" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">Executes instructions</text>
  <text x="100" y="104" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">ADD, COMPARE, JUMP</text>
  <text x="100" y="122" font-family="sans-serif" font-size="10" fill="#555" text-anchor="middle">Billions per second</text>
  <text x="100" y="148" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">(your for-loops run here)</text>
  <!-- bidirectional arrows: CPU <-> RAM -->
  <line x1="180" y1="85" x2="258" y2="85" stroke="#0b3d66" stroke-width="2" marker-end="url(#arr-hw)"/>
  <line x1="258" y1="105" x2="180" y2="105" stroke="#0b3d66" stroke-width="2" marker-end="url(#arr-hw)"/>
  <text x="219" y="79" font-family="sans-serif" font-size="9" fill="#0b3d66" text-anchor="middle">fetch code</text>
  <text x="219" y="120" font-family="sans-serif" font-size="9" fill="#0b3d66" text-anchor="middle">load/store data</text>
  <!-- RAM box -->
  <rect x="260" y="20" width="250" height="168" rx="10" fill="#eef4fa" stroke="#0b3d66" stroke-width="2"/>
  <text x="385" y="45" font-family="sans-serif" font-size="13" font-weight="bold" fill="#0b3d66" text-anchor="middle">RAM (Memory)</text>
  <!-- memory cells -->
  <!-- code section -->
  <rect x="278" y="58" width="100" height="36" rx="4" fill="#ddeeff" stroke="#0b3d66" stroke-width="1"/>
  <text x="328" y="74" font-family="monospace" font-size="10" fill="#0b3d66" text-anchor="middle">machine code</text>
  <text x="328" y="88" font-family="sans-serif" font-size="9" fill="#555" text-anchor="middle">(your compiled program)</text>
  <!-- variable cells -->
  <rect x="278" y="112" width="44" height="30" rx="4" fill="#fff" stroke="#0b3d66" stroke-width="1"/>
  <text x="300" y="129" font-family="monospace" font-size="10" fill="#0b3d66" text-anchor="middle">age</text>
  <text x="300" y="141" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">4 B</text>
  <rect x="328" y="112" width="44" height="30" rx="4" fill="#fff" stroke="#0b3d66" stroke-width="1"/>
  <text x="350" y="129" font-family="monospace" font-size="10" fill="#0b3d66" text-anchor="middle">score</text>
  <text x="350" y="141" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">4 B</text>
  <rect x="378" y="112" width="44" height="30" rx="4" fill="#fff" stroke="#0b3d66" stroke-width="1"/>
  <text x="400" y="129" font-family="monospace" font-size="10" fill="#0b3d66" text-anchor="middle">total</text>
  <text x="400" y="141" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">8 B</text>
  <text x="328" y="163" font-family="sans-serif" font-size="9" fill="#555" text-anchor="middle">(your variables live here while the program runs)</text>
  <!-- labels -->
  <text x="328" y="106" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">variables (stack)</text>
</svg>
<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure S.2.</strong> How the CPU and RAM work together.</em></p>

Think of RAM as a giant wall of numbered post-it notes. Each note holds a tiny piece
of data. When your program declares a variable, the OS hands it a note (or several
adjacent notes) and writes the value there. The CPU reads and writes those notes at
billions of operations per second. When the program finishes, all the notes are erased.

Variables live in RAM while your program runs.
When the program ends, their memory is freed.

---

> **Under the Hood: what the CPU actually does**
>
> Your CPU is just a chip that can do a handful of things very fast:
> load a value from memory, store a value to memory, add two numbers,
> compare two numbers, and jump to a different instruction.
> Everything your program does (printf, if, for) is compiled down
> to combinations of these primitive operations.
>
> This is why learning C is useful: you are close enough to the hardware
> to see the machine, but far enough away to think in human terms.
> In **Computer Architecture** you will study the CPU itself.
> In **System Programming** you will control memory and processes directly.

---

## What Happens on a Runtime Error?

Some bugs are not caught by the compiler; they only appear when the program runs.
For example, dividing by zero, or writing past the end of an array.
These cause the program to crash, often with a message like `Segmentation fault`.

This is the second kind of bug you will learn to find and fix in this course.

---

## Key Vocabulary

| Term | Meaning |
|------|---------|
| Source code | The C text you write (`.c` files) |
| Compiler | The tool (`gcc`) that translates source to machine code |
| Executable / binary | The machine-code file you run (`./hello`) |
| RAM | Memory where variables and code live while the program runs |
| Runtime error | A bug that crashes the running program, not caught at compile time |
| Syntax error | A grammar mistake the compiler catches before running |
