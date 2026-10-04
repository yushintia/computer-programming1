---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 15: Final Exam - Project Demo & Oral Defense

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: This is the final week. No new concept today - this session
covers the oral defense format, what is assessed, and how to prepare.
This is the last graded activity of the semester.
-->

---

<!-- SLOT 2: Where we are (Act 0 / LOCATE) -->

# Where We Are

<div class="roadmap">
<div class="wk"><div class="n">Wk 1</div><div class="t">Introduction</div></div>
<div class="wk"><div class="n">Wk 2</div><div class="t">Program Structure &amp; I/O</div></div>
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
<div class="wk review now"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

<!-- notes: Fourteen weeks of material behind you, and a project built in
Week 14. Today is where you prove it's yours. -->

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Week 14 delivered:** a working capstone project, debugged, analyzed,
  and submitted - the synthesis of everything from Weeks 1-13.
- **Today is not a new lesson.** It is the final checkpoint: can you
  demonstrate, explain, and extend the program you built, live, in
  front of an examiner?

---

# Today: The Final Exam

<div class="why">
<strong>150 minutes, individual oral defense, worth 30% of your final grade.</strong>
Not a written test or a timed coding sprint - you present YOUR project
and answer questions about it live.
</div>

<div class="cardlist">
<div class="card"><div class="h">Setup - 5 min</div><div class="d">Confirm your project runs on the lab machine</div></div>
<div class="card"><div class="h">Student rotations - ~135 min</div><div class="d">~10-12 min per student: demo, Q&amp;A, live modification</div></div>
<div class="card"><div class="h">Buffer - 10 min</div><div class="d">Technical issues; parallel stations if class is large</div></div>
</div>

---

# The 10-12 Minute Defense

<div class="cardlist">
<div class="card"><div class="h">Live demo - 2-3 min</div><div class="d">Run your program, show it works for a sample scenario</div></div>
<div class="card"><div class="h">Explain-your-code Q&amp;A - 5-6 min</div><div class="d">"What does this function do?" "Why a struct here?" "Walk me through input X."</div></div>
<div class="card"><div class="h">Live modification - 3-4 min</div><div class="d">Add or change a small feature during the session - proves authorship</div></div>
</div>

- This validates authorship and measures understanding beyond
  memorization - you are not expected to redesign the program.

---

# What Is Being Assessed

The defense assesses Weeks 9-14 **through your project**:

| Topic | How it shows up |
|-------|----------------|
| Functions (Wk 9-10) | Explain what each function does, and why split this way |
| Arrays (Wk 11-12) | Trace array indexing, explain loop bounds |
| Strings (Wk 12) | Explain the `\0` terminator, if your project processes strings |
| Structs (Wk 13) | Explain why you grouped data into a struct |
| Debugging (Wk 14) | Find and fix a bug in your own code in real time |

---

# Oral Defense Rubric (30%)

| Criterion | Weight |
|-----------|:------:|
| Runs & meets spec (no crashes, README features work) | 8% |
| Code understanding (explain any part accurately) | 10% |
| Live modification (correct, partial credit for approach) | 8% |
| Presentation clarity | 4% |

<div class="why">
<strong>In industry:</strong> this IS the technical interview format -
explaining your own code and extending it live under a reviewer's
questions is exactly what a whiteboard or take-home-defense interview
looks like.
</div>

---

# How to Prepare

- **Know your own code:** read every line before the defense; be ready
  to explain each function, each data-structure choice, each loop's
  termination, and every invalid-input path.
- **If you copied a snippet, understand it** - you will be asked about it.
- **Practice typical questions:** "What does `main` do first?" "Why
  `while` here instead of `for`?" "What happens on negative input?"
  "Walk me through the output for this input: ..."

---

# Preparing for the Live Modification

Past modifications have included:

- "Add a feature that prints the total number of items."
- "Make the program reject negative input."
- "Add a function that returns the average of your array."

<div class="why">
These are deliberate small changes in scope, not a redesign. Writing
clean, modular code in Week 14 makes Week 15 easier.
</div>

---

# Logistics

- Bring your project files on the lab machine (or a USB drive as backup).
- Have a terminal open with the project directory ready.
- Compile fresh at the start of the session:
  `gcc *.c -o project -Wall -std=c99`
- If multiple lab machines are available, the class splits into
  parallel stations to minimize wait time.

---

# Scoring Guide

| Score band | Meaning |
|------------|---------|
| 90-100% | Explains all code fluently; modification complete and correct |
| 75-89% | Minor gaps in explanation; modification mostly correct |
| 60-74% | Explains core features; modification partial |
| Below 60% | Cannot explain key parts; modification not attempted |

---

<!-- SLOT N+1: Where to go next (replaces Limits for exam week) -->

# Where to Go Next

<div class="limits">
You can now write, compile, debug, and explain C programs that use
variables, control flow, functions, arrays, strings, and basic data
structures. From here:

- **Computer Programming II / System Programming:** pointers in depth,
  memory management, file I/O, processes
- **Data Structures:** linked lists, stacks, queues, trees, sorting
- **Computer Architecture:** what the CPU and memory really do
- **Operating Systems:** how programs interact with the OS kernel
</div>

---

<!-- SLOT N+2: closing note (no "Next Week" bridge - final week) -->

# This Is the Last Graded Activity

| Component | Weight |
|-----------|:------:|
| Midterm (Week 8) | 20% |
| Project artifact (submitted Week 14) | 30% |
| Final: demo + oral defense (today) | 30% |
| Attendance | 10% |
| Assignments (Weeks 2-13) | 10% |

---

<!-- SLOT N+3: Summary -->

# Summary

- Final: 150 minutes, individual oral defense, 30% of your grade,
  assesses Weeks 9-14 through your own project.
- Three parts: live demo, explain-your-code Q&A, live modification.
- **Lab page:** [Lab 15: Final: Project Demo + Individual Oral Defense](../book/labs/lab15-final-exam.html) for the full rubric and scoring
  guide.
- **Prepare:** know every line of your project; practice explaining it
  out loud; review the Debugging Tips appendix.

---

<!-- SLOT N+4: Congratulations / Thank You -->
<!-- _class: end -->

# Congratulations - You've Completed Computer Programming I

Thank You
