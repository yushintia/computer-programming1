# Pseudocode & Flowcharts

This reference page explains the two algorithm-design tools used throughout this course.
Use it alongside Lab 01 (where pseudocode first appears) and Labs 05-07 (where flowcharts
accompany each control-flow concept).

---

## Why Design Before You Code?

Writing code before thinking through the logic is like building a house before drawing the
floor plan. You discover the problems too late. Pseudocode and flowcharts let you check your
logic in minutes, before you have spent an hour fighting the compiler.

Both tools describe *what* a program does, not *how* the compiler does it.
They are language-agnostic: the same pseudocode can be translated into C, Python, or Java.

---

## Flowchart Symbols

Standard flowcharts use five shapes. Every flowchart in this manual uses these same symbols.

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 580 290" style="max-width:560px;display:block;margin:1.5em auto;">
  <title>Flowchart symbol legend showing five standard shapes with labels and meanings. An oval labeled Start or End is the terminal symbol. A rectangle labeled Process is for calculations and assignments. A parallelogram labeled Input or Output is for reading and printing. A diamond labeled Decision is for yes/no conditions. An arrow labeled Flow shows the direction of execution.</title>
  <defs>
    <marker id="arr-ap" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Row 1: Terminal (oval) -->
  <ellipse cx="80" cy="35" rx="60" ry="22" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="80" y="39" font-family="sans-serif" font-size="12" fill="#fff" text-anchor="middle" font-weight="bold">Start / End</text>
  <text x="180" y="30" font-family="sans-serif" font-size="13" fill="#0b3d66" font-weight="bold">Terminal</text>
  <text x="180" y="47" font-family="sans-serif" font-size="11" fill="#444">Marks where the algorithm begins or ends.</text>
  <text x="180" y="62" font-family="monospace" font-size="10" fill="#888">Always the first and last shape.</text>
  <!-- Row 2: Process (rect) -->
  <rect x="20" y="80" width="120" height="36" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="80" y="103" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle">sum = sum + i</text>
  <text x="180" y="92" font-family="sans-serif" font-size="13" fill="#0b3d66" font-weight="bold">Process</text>
  <text x="180" y="109" font-family="sans-serif" font-size="11" fill="#444">A calculation, assignment, or action step.</text>
  <text x="180" y="124" font-family="monospace" font-size="10" fill="#888">e.g. SET x = x + 1</text>
  <!-- Row 3: I/O (parallelogram) -->
  <polygon points="30,140 130,140 120,172 20,172" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="75" y="160" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">INPUT / OUTPUT</text>
  <text x="180" y="152" font-family="sans-serif" font-size="13" fill="#0b3d66" font-weight="bold">Input / Output</text>
  <text x="180" y="169" font-family="sans-serif" font-size="11" fill="#444">Reading from the user or printing to the screen.</text>
  <text x="180" y="184" font-family="monospace" font-size="10" fill="#888">e.g. INPUT n  or  OUTPUT result</text>
  <!-- Row 4: Decision (diamond) -->
  <polygon points="80,198 130,222 80,246 30,222" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="80" y="219" font-family="monospace" font-size="10" fill="#c07000" text-anchor="middle">x &gt; 0?</text>
  <text x="80" y="234" font-family="sans-serif" font-size="9" fill="#c07000" text-anchor="middle">YES / NO</text>
  <text x="180" y="210" font-family="sans-serif" font-size="13" fill="#0b3d66" font-weight="bold">Decision</text>
  <text x="180" y="227" font-family="sans-serif" font-size="11" fill="#444">A yes/no (true/false) branch point.</text>
  <text x="180" y="242" font-family="monospace" font-size="10" fill="#888">e.g. IF condition THEN ...</text>
  <!-- Row 5: Arrow (flow) -->
  <line x1="30" y1="268" x2="120" y2="268" stroke="#0b3d66" stroke-width="2" marker-end="url(#arr-ap)"/>
  <text x="180" y="263" font-family="sans-serif" font-size="13" fill="#0b3d66" font-weight="bold">Flow (arrow)</text>
  <text x="180" y="280" font-family="sans-serif" font-size="11" fill="#444">Shows the order of execution between shapes.</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure A.1.</strong> Standard flowchart symbols used in this manual.</em></p>

---

## Pseudocode Conventions

Pseudocode has no official standard. These conventions are used throughout this course:

| Keyword | Meaning |
|---------|---------|
| `INPUT x` | Read a value from the user into `x` |
| `OUTPUT x` | Print or display `x` |
| `SET x = expr` | Assign the value of `expr` to `x` |
| `IF ... THEN` / `ELSE IF` / `ELSE` / `END IF` | Conditional branch |
| `WHILE ... DO` / `END WHILE` | Loop that checks condition before each pass |
| `FOR i FROM a TO b DO` / `END FOR` | Counted loop |
| `RETURN x` | Return a value (used inside function pseudocode) |

**Style rules:**
- Keywords are written in CAPITALS.
- Indent the body of every `IF`, `WHILE`, and `FOR` block by one level.
- There is no semicolons, no curly braces, no `#include`.
- The goal is clarity, not compilability.

---

## Worked Example 1: Larger of Two Numbers

**Problem:** read two numbers, print the larger one.

**Pseudocode:**

```
INPUT a, b
IF a > b THEN
    OUTPUT a
ELSE
    OUTPUT b
END IF
```

**Flowchart:**

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 440 310" style="max-width:420px;display:block;margin:1.5em auto;">
  <title>Flowchart for finding the larger of two numbers. Start oval leads to an Input parallelogram for a and b, then a decision diamond asking a greater than b. If yes, an output parallelogram prints a. If no, an output parallelogram prints b. Both paths merge at an End oval.</title>
  <defs>
    <marker id="arr-ex1" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Start -->
  <ellipse cx="170" cy="16" rx="50" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="170" y="20" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">Start</text>
  <line x1="170" y1="30" x2="170" y2="48" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-ex1)"/>
  <!-- Input parallelogram -->
  <polygon points="85,50 255,50 245,80 75,80" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="165" y="70" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">INPUT a, b</text>
  <line x1="170" y1="80" x2="170" y2="100" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-ex1)"/>
  <!-- Decision diamond -->
  <polygon points="170,102 260,132 170,162 80,132" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="170" y="129" font-family="monospace" font-size="11" fill="#c07000" text-anchor="middle">a &gt; b?</text>
  <!-- YES: right branch, output a -->
  <line x1="260" y1="132" x2="340" y2="132" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-ex1)"/>
  <text x="290" y="124" font-family="sans-serif" font-size="10" fill="#2e7d32">YES</text>
  <polygon points="330,118 400,118 390,148 320,148" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="360" y="138" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">OUTPUT a</text>
  <!-- NO: down, output b -->
  <line x1="170" y1="162" x2="170" y2="192" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-ex1)"/>
  <text x="178" y="181" font-family="sans-serif" font-size="10" fill="#c00">NO</text>
  <polygon points="90,194 250,194 240,224 80,224" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="165" y="214" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">OUTPUT b</text>
  <!-- Merge from YES branch down -->
  <line x1="360" y1="148" x2="360" y2="270" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2"/>
  <line x1="360" y1="270" x2="230" y2="270" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2" marker-end="url(#arr-ex1)"/>
  <!-- From NO branch down -->
  <line x1="170" y1="224" x2="170" y2="270" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-ex1)"/>
  <!-- End -->
  <ellipse cx="170" cy="283" rx="50" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="170" y="287" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">End</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure A.2.</strong> Find the larger of two numbers.</em></p>

---

## Worked Example 2: Sum 1 to N (while loop)

**Problem:** read N, add up all integers from 1 to N, print the sum.

**Pseudocode:**

```
INPUT n
SET sum = 0
SET i = 1
WHILE i <= n DO
    SET sum = sum + i
    SET i = i + 1
END WHILE
OUTPUT sum
```

**Flowchart:**

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 420 390" style="max-width:400px;display:block;margin:1.5em auto;">
  <title>Flowchart for computing the sum of 1 to N using a while loop. Start oval leads to an input parallelogram for n, then a process box setting sum = 0 and i = 1, then a condition diamond asking i less than or equal to n. If false an output parallelogram prints sum, then End oval. If true a process box adds i to sum and increments i, then arrows back to the condition diamond.</title>
  <defs>
    <marker id="arr-ex2" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Start -->
  <ellipse cx="160" cy="16" rx="50" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="160" y="20" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">Start</text>
  <line x1="160" y1="30" x2="160" y2="48" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-ex2)"/>
  <!-- Input n -->
  <polygon points="80,50 240,50 230,78 70,78" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="155" y="69" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">INPUT n</text>
  <line x1="160" y1="78" x2="160" y2="96" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-ex2)"/>
  <!-- Init box -->
  <rect x="75" y="98" width="170" height="34" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="160" y="113" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle">SET sum = 0</text>
  <text x="160" y="127" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle">SET i = 1</text>
  <line x1="160" y1="132" x2="160" y2="150" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-ex2)"/>
  <!-- Condition diamond -->
  <polygon points="160,152 245,182 160,212 75,182" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <text x="160" y="179" font-family="monospace" font-size="11" fill="#c07000" text-anchor="middle">i &lt;= n?</text>
  <!-- FALSE: right to output -->
  <line x1="245" y1="182" x2="330" y2="182" stroke="#c00" stroke-width="1.5" marker-end="url(#arr-ex2)"/>
  <text x="272" y="174" font-family="sans-serif" font-size="10" fill="#c00">false</text>
  <polygon points="325,168 405,168 395,198 315,198" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="360" y="188" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">OUTPUT sum</text>
  <line x1="360" y1="198" x2="360" y2="360" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2"/>
  <line x1="360" y1="360" x2="220" y2="360" stroke="#0b3d66" stroke-width="1" stroke-dasharray="4,2" marker-end="url(#arr-ex2)"/>
  <!-- TRUE: down to body -->
  <line x1="160" y1="212" x2="160" y2="240" stroke="#2e7d32" stroke-width="1.5" marker-end="url(#arr-ex2)"/>
  <text x="168" y="230" font-family="sans-serif" font-size="10" fill="#2e7d32">true</text>
  <!-- Body box -->
  <rect x="70" y="242" width="180" height="44" rx="6" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <text x="160" y="260" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">SET sum = sum + i</text>
  <text x="160" y="278" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle">SET i = i + 1</text>
  <!-- Back arrow -->
  <path d="M70,264 Q20,264 20,182 Q20,152 75,152" fill="none" stroke="#0b3d66" stroke-width="1.5" stroke-dasharray="6,3" marker-end="url(#arr-ex2)"/>
  <text x="38" y="215" font-family="sans-serif" font-size="9" fill="#888" transform="rotate(-90,38,215)">back to top</text>
  <!-- End -->
  <ellipse cx="160" cy="373" rx="50" ry="14" fill="#0b3d66" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="160" y="377" font-family="sans-serif" font-size="11" fill="#fff" text-anchor="middle" font-weight="bold">End</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure A.3.</strong> Sum of 1 to N using a while loop.</em></p>

---

## Worked Example 3: Grade Classifier (if/else-if chain)

**Problem:** read a score (0-100), print the letter grade.

**Pseudocode:**

```
INPUT score
IF score < 0 OR score > 100 THEN
    OUTPUT "Invalid score"
ELSE IF score >= 90 THEN
    OUTPUT "Grade: A"
ELSE IF score >= 80 THEN
    OUTPUT "Grade: B"
ELSE IF score >= 70 THEN
    OUTPUT "Grade: C"
ELSE IF score >= 60 THEN
    OUTPUT "Grade: D"
ELSE
    OUTPUT "Grade: F"
END IF
```

See **Figure 5.1** in Lab 05 for the corresponding flowchart.

---

## Quick-Reference Card

| Situation | Flowchart shape | Pseudocode keyword |
|-----------|----------------|--------------------|
| Algorithm starts / ends | Oval (terminal) | (implicit - first/last line) |
| Read from user | Parallelogram | `INPUT x` |
| Print to screen | Parallelogram | `OUTPUT x` |
| Calculate or assign | Rectangle | `SET x = expr` |
| Branch (if/else) | Diamond | `IF ... THEN / ELSE / END IF` |
| Repeat while true | Diamond + back-arrow | `WHILE ... DO / END WHILE` |
| Count fixed times | Diamond + back-arrow | `FOR i FROM a TO b DO / END FOR` |

> **Tip:** always draw the flowchart (or write the pseudocode) before you start typing C.
> Fix the logic errors in the design; then fix the syntax errors in the code. Mixing the
> two tasks at once is slower and more confusing.
