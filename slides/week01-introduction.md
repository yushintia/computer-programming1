---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 1: Introduction

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Welcome the class. This session is the course contract: what this
course covers, how it's graded, what's expected of you, and how the
semester runs. No code yet - that starts next week.
-->

---

<!-- SLOT 2: Where we are (Act 0 / LOCATE) -->

# Where We Are

<div class="roadmap">
<div class="wk now"><div class="n">Wk 1</div><div class="t">Introduction</div></div>
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
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

<!-- notes: Point at the row. Say: "Fifteen weeks. Today's the odd one
out - it's about how this course works, not code. Week 8 is the
midterm, Week 15 is your final project defense. The other thirteen
each add one real skill." -->

---

<!-- Course intro: why this course, briefly, before the contract -->

# Why This Course

<div class="thread">One idea, plain and simple.</div>

<div class="why">
Every app, website, and tool you will ever use is built out of
programs. This course teaches you to write your own, in C - one of
the languages closest to how the computer actually works.
</div>

That is not a sales pitch. Programming is a skill you build with your
hands, not one you memorize from a book. This course gives you fifteen
weeks of small, real programs, each one teaching exactly one new idea.

By the end, you will read a program and understand it, and write a
program from a plain description of what it should do.

---

<!-- Running-example tease: premise only, no code, no teaching -->

# A Program That Isn't There Yet

<div class="pain">

You want a program that checks three exam scores and decides: did this
student pass?

Right now, you have no way to write that. Not because it's hard - you
already know the rule ("average 60 or higher passes"). You simply
don't have a way to say it to a computer yet.

</div>

<!-- notes: Ask: "How would YOU decide, by hand, given three scores?"
Let two or three students answer in plain English. Do not write any
code yet - this is a premise, not a lesson. -->

---

<!-- Teaser / discussion prompt, framed as a question not answered today -->

# A Question We Will Not Answer Today

<div class="thread">Sit with this question. Week 2 starts to answer it.</div>

You already know the rule for the pass/fail check. A computer does
not - it can only follow instructions written in a language it
understands.

- What does a computer actually need, to run *any* set of instructions?
- Is C hard to learn, or just unfamiliar?

<!--
notes: A discussion prompt, not a lesson - do not answer it today. Let
the class sit with the question. This course spends the rest of the
semester answering it, one small program at a time, starting with
what a C program actually looks like in Week 2.
-->

---

<!-- SLOT 6: Driving question -->

<!-- _class: section -->

# This Course's Question

<div class="driving-q">"Given a plain description of a task, can you write a correct, working C program that does it?"</div>

---

# This Course's Six Objectives

<div class="thread">Not just today's goals. This is the whole course, in six lines.</div>

| # | Objective (from the syllabus) | Where |
|---|---|---|
| 1 | Understand core programming principles and problem-solving | All semester |
| 2 | Read and write syntactically correct C code | Weeks 2-4 |
| 3 | Use variables, data types, and expressions correctly | Weeks 3-4 |
| 4 | Apply control structures (if/else, switch, while, for) | Weeks 5-7 |
| 5 | Design modular programs using functions | Weeks 9-10 |
| 6 | Work with 1-D/2-D arrays and C strings | Weeks 11-12 |

Every one of these six objectives is built, one small program at a
time, starting with the exam-score checker you just heard about.

---

<!-- _class: section -->

# End of 차시 1
<div class="driving-q">Short break. Next: the course contract - what's covered, how you're graded, and what's expected of you.</div>

---

# Course Description

<div class="thread">From the official syllabus.</div>

This course introduces the fundamentals of programming using the C
language: variables, control structures, functions, and arrays. You
learn to think through a problem step by step, then express that
thinking as a correct, working program - a skill every later course in
this major builds on.

---

# Learning Objectives

<div class="thread">The official course objectives, from the syllabus - what you'll be able to do by Week 15.</div>

By the end of this course, you can:

1. Explain core programming principles and problem-solving steps.
2. Read and write syntactically correct C (C99) code.
3. Use variables, data types, and expressions correctly.
4. Apply control structures: if/else, switch, while, do-while, for.
5. Design modular programs using functions.
6. Work with one- and two-dimensional arrays and C strings.

---

# Prerequisites

<div class="thread">What this course assumes you already have.</div>

No prior programming course is required. Here is why:

- **You already follow instructions.** A recipe, a set of directions,
  an assembly manual - all step-by-step processes, like a program.
- **You already spot patterns.** "Do this for every item in the list"
  is a loop, even before you have a word for it.
- **You are willing to be precise.** A computer runs exactly what you
  write, not what you meant. That habit is the one real prerequisite.

---

# Textbooks

<div class="thread">One primary text. One reference.</div>

- **Primary:** K. N. King, *C Programming: A Modern Approach*, 2nd ed.
- **Reference:** Kernighan &amp; Ritchie, *The C Programming Language*, 2nd ed.
- **Also:** the lab manual (this course's own book) is a listed course
  reference, with a guided exercise and challenge problem every week

---

# How This Course Runs

<div class="thread">What to expect from a 3-period block, every week.</div>

Each week has three class periods (차시), about 50 minutes each:

<div class="cardlist">
<div class="card"><div class="h">Part A: Lecture</div><div class="d">New concept, explained simply, always starting from a real short program</div></div>
<div class="card"><div class="h">Part B: Guided Lab</div><div class="d">Work through exercises with your instructor, in the course lab manual</div></div>
<div class="card"><div class="h">Part C: Independent Work</div><div class="d">A challenge problem you solve on your own, with the week's deliverable</div></div>
<div class="card"><div class="h">Every Week, a Deliverable</div><div class="d">Weeks 2-13 each have a small graded assignment - see the lab manual's submission rubric</div></div>
</div>

---

# Weekly Schedule

<div class="thread">One line per week - the full walkthrough.</div>

| Wk | Topic | Wk | Topic |
|---|---|---|---|
| 1 | Introduction (today) | 9 | Functions I |
| 2 | Program Structure &amp; I/O | 10 | Functions II: Recursion |
| 3 | Variables &amp; Data Types | 11 | Arrays I: 1-D |
| 4 | I/O &amp; Operators | 12 | Arrays II: 2-D &amp; Strings |
| 5 | Conditionals | 13 | Data Structures |
| 6 | Loops I: while | 14 | Debugging &amp; Project |
| 7 | Loops II: for | 15 | **Final Exam** |
| 8 | **Midterm Exam** | | |

---

<!-- _class: section -->

# End of 차시 2
<div class="driving-q">Short break. Next: grading, assignments, and policy.</div>

---

# Grading &amp; Materials

<div class="thread">Five components, 100% total.</div>

| Item | Weight |
|---|---|
| Attendance | 10% |
| Assignments (Weeks 2-13) | 10% |
| Midterm (Week 8, live in-lab coding) | 20% |
| Project (artifact, due Week 14) | 30% |
| Final (Week 15, demo + oral defense) | 30% |

<div class="why">
<strong>Grade distribution guideline:</strong> A ≤40%, B ≤40%, C-F
≤20% of the class. This may shift after the add/drop period, based on
final enrollment.
</div>

---

# Assignments &amp; the Project

<div class="thread">Two different kinds of deliverable.</div>

- **Weekly assignments (Weeks 2-13):** a small program each week,
  matching that week's lab exercises - see the lab manual's submission
  rubric for exact requirements
- **The project (announced Week 11, due Week 14):** one larger program
  you design yourself, from four options (contact book, grade manager,
  guessing game, calculator suite) or your own idea
- **Week 15:** you defend the project live - explain your own code,
  answer questions, make a small live modification

---

# Feedback Policy

<div class="thread">From the syllabus, in plain terms.</div>

<div class="why">
Assignments are graded and returned within one week, with specific
feedback on what worked and what didn't. Midterm results include an
item-by-item breakdown so you know exactly where points were lost.
</div>

In plain terms: you will know what you got wrong, and why, quickly
enough for it to still matter for the next assignment.

---

# Academic Integrity

<div class="thread">From the syllabus, verbatim in spirit.</div>

- **Weekly assignments:** discussing ideas with classmates is fine;
  the code you submit must be your own, never a shared file
- **The project:** strictly individual - you must be able to explain
  every line at your Week 15 oral defense
- **Midterm:** closed collaboration, restricted network access,
  open-book (compiler and your own reference sheets allowed)
- **When in doubt, ask before submitting** - it is always better to
  ask than to guess wrong

<div class="why">
Unattributed AI-generated code submitted as your own work is an
academic integrity violation, same as copying from another student.
</div>

---

# Attendance &amp; Late Work

<div class="thread">Department-standard policy.</div>

<div class="cardlist">
<div class="card"><div class="h">Attendance</div><div class="d">10% of the final grade, tracked every session</div></div>
<div class="card"><div class="h">Late Arrival</div><div class="d">Arriving more than 15 minutes late counts as late; three lates equal one absence</div></div>
<div class="card"><div class="h">Can't Attend?</div><div class="d">Email the instructor before class with your reason for an excused absence</div></div>
<div class="card"><div class="h">Late Work</div><div class="d">Loses 10% of that assignment's points per day late, up to 3 days</div></div>
</div>

---

# Support for Students with Disabilities

<div class="thread">From the syllabus's accommodations section.</div>

- **Extended time:** available for exams and timed in-class work
- **Materials in advance:** lecture materials provided ahead of class
  where possible
- **Other documented conditions:** reasonable accommodation based on
  need, arranged individually

Contact the instructor early, and the Disability Student Support
Center or Academic Affairs Team, so accommodations are ready before
you need them.

---

# Contact

<div class="thread">How to reach the instructor.</div>

- **Instructor:** Yushintia Pramitarini, Ph.D
- **Office hours:** by appointment
- **Course communication:** announcements and materials via the LMS

---

<!-- SLOT N+1: Limits -->

# What Today Doesn't Give You Yet

<div class="limits">
You know how this course runs, how you're graded, and what's expected
of you. You still don't have a way to write your own program - not
because it's hard, but because you haven't seen what a C program
actually looks like yet.
</div>

<!-- notes: Ask students which topic feels hardest or most unfamiliar
right now. That's fine - Week 2 starts from zero. -->

---

<!-- SLOT N+2: Bridge -->

# Next Week

Week 1 leaves **what a real C program looks like, and how to run one**
unsolved. **Week 2** addresses it: Program Structure &amp; Basic I/O.

---

<!-- SLOT N+3: Summary -->

# Summary

- This course teaches you to write correct, working C programs, one
  small idea at a time, over fifteen weeks.
- **Grading:** Attendance 10%, Assignments 10%, Midterm 20%, Project
  30%, Final 30%.
- **Textbook:** K. N. King, *C Programming: A Modern Approach*, 2nd ed.
- **Prepare:** install your C toolchain before Week 2 - see the lab
  manual's Setup section (`book/src/setup/toolchain.md`).

---

<!-- SLOT N+4: Thank You -->
<!-- _class: end -->

# Thank You
