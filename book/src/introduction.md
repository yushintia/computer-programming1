# Introduction

**Course:** 400521-004 컴퓨터프로그래밍 I · Computer Programming I  
**Instructor:** Yushintia Pramitarini  
**Year / Semester:** 2025 · Semester 1  
**Format:** 15 meetings × 3 × 50 min · Language: C (C99)

---

## Who This Manual Is For

This manual is for complete beginners. Have you never written a single line of code? Then this manual is for you. You do not need any programming background. You do not need to see yourself as a "math person" or a "computer person" to succeed here.

Programming is a skill. Like any skill, it grows with practice. Every professional developer once stared at their first error message. They had no idea what it meant, just like you might feel today. This course walks you through that journey. We take one small step at a time.

Our goal is not to race through every feature of the C language. Our goal is to build your real problem-solving confidence. This means you can look at a problem, break it into steps, and turn those steps into working code. You will carry this way of thinking into every advanced course. You will carry it into every program you ever write.

---

## Why C?

C is a high-level language. It still stays close to the machine.
Learning C teaches you:

- How variables and data are stored in memory
- How the CPU runs instructions one at a time
- Why bugs like buffer overflows and off-by-one errors happen

These lessons prepare you for later courses. They build the base for **System Programming**, **Computer Architecture**, and **Operating Systems**.

---

## Course Objectives

By the end of this course you will be able to:

1. Understand the basic principles of programming and problem-solving.
2. Read and write syntactically correct C programs.
3. Use variables, data types, and expressions correctly.
4. Apply `if`/`else`, `switch`, `while`, `do-while`, and `for` control structures.
5. Design and call functions; organize code into reusable modules.
6. Declare, initialize, and traverse one-dimensional and two-dimensional arrays; handle C strings.

---

## Course Journey: 15 Weeks at a Glance

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 720 200" style="max-width:700px;display:block;margin:1.5em auto;">
  <title>15-week course roadmap showing six phases: Foundations (Wk 1-2), Data (Wk 3-4), Control Flow (Wk 5-7), Functions (Wk 9-10), Arrays and Strings (Wk 11-12), Project (Wk 13-15), with Midterm at Week 8</title>
  <defs>
    <marker id="arr-i" markerWidth="8" markerHeight="8" refX="6" refY="3" orient="auto">
      <path d="M0,0 L0,6 L8,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Phase boxes -->
  <!-- Foundations Wk1-2 -->
  <rect x="10" y="40" width="100" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="60" y="63" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Foundations</text>
  <text x="60" y="79" font-family="sans-serif" font-size="10" fill="#444" text-anchor="middle">Weeks 1–2</text>
  <!-- arrow -->
  <line x1="110" y1="65" x2="128" y2="65" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-i)"/>
  <!-- Data Wk3-4 -->
  <rect x="130" y="40" width="100" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="180" y="63" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Data &amp; I/O</text>
  <text x="180" y="79" font-family="sans-serif" font-size="10" fill="#444" text-anchor="middle">Weeks 3–4</text>
  <!-- arrow -->
  <line x1="230" y1="65" x2="248" y2="65" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-i)"/>
  <!-- Control Flow Wk5-7 -->
  <rect x="250" y="40" width="110" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="305" y="63" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Control Flow</text>
  <text x="305" y="79" font-family="sans-serif" font-size="10" fill="#444" text-anchor="middle">Weeks 5–7</text>
  <!-- Midterm badge -->
  <rect x="266" y="104" width="84" height="24" rx="5" fill="#0b3d66"/>
  <text x="308" y="120" font-family="sans-serif" font-size="10" fill="#fff" text-anchor="middle">Midterm Wk 8</text>
  <!-- arrow -->
  <line x1="360" y1="65" x2="378" y2="65" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-i)"/>
  <!-- Functions Wk9-10 -->
  <rect x="380" y="40" width="100" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="430" y="63" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Functions</text>
  <text x="430" y="79" font-family="sans-serif" font-size="10" fill="#444" text-anchor="middle">Weeks 9–10</text>
  <!-- arrow -->
  <line x1="480" y1="65" x2="498" y2="65" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-i)"/>
  <!-- Arrays+Strings Wk11-12 -->
  <rect x="500" y="40" width="100" height="50" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="550" y="59" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Arrays &amp;</text>
  <text x="550" y="72" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Strings</text>
  <text x="550" y="85" font-family="sans-serif" font-size="10" fill="#444" text-anchor="middle">Weeks 11–12</text>
  <!-- arrow -->
  <line x1="600" y1="65" x2="618" y2="65" stroke="#0b3d66" stroke-width="1.5" marker-end="url(#arr-i)"/>
  <!-- Project Wk13-15 -->
  <rect x="620" y="40" width="90" height="50" rx="6" fill="#ddeeff" stroke="#0b3d66" stroke-width="2"/>
  <text x="665" y="59" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">Structures</text>
  <text x="665" y="72" font-family="sans-serif" font-size="11" font-weight="bold" fill="#0b3d66" text-anchor="middle">&amp; Project</text>
  <text x="665" y="85" font-family="sans-serif" font-size="10" fill="#444" text-anchor="middle">Weeks 13–15</text>
  <!-- Final badge -->
  <rect x="628" y="104" width="76" height="24" rx="5" fill="#0b3d66"/>
  <text x="666" y="120" font-family="sans-serif" font-size="10" fill="#fff" text-anchor="middle">Final Wk 15</text>
  <!-- Timeline baseline -->
  <line x1="10" y1="155" x2="710" y2="155" stroke="#ccd" stroke-width="1"/>
  <text x="60" y="170" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">Wk 1–2</text>
  <text x="180" y="170" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">Wk 3–4</text>
  <text x="305" y="170" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">Wk 5–8</text>
  <text x="430" y="170" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">Wk 9–10</text>
  <text x="550" y="170" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">Wk 11–12</text>
  <text x="665" y="170" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">Wk 13–15</text>
</svg>
<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure I.1.</strong> Course roadmap: six phases across 15 weeks.</em></p>

| Weeks | Theme | Objectives covered |
|-------|-------|--------------------|
| 1–2   | Foundations: what programming is, first program | 1–2 |
| 3–4   | Data: variables, types, expressions, I/O | 3 |
| 5–7   | Control flow: conditionals, loops | 4 |
| 8     | **Midterm** (live coding, weeks 1–7) | 1–4 |
| 9–10  | Functions and modular design | 5 |
| 11–12 | Arrays and strings | 6 |
| 13    | Basic data structures (struct, intro pointers) | 6 + awareness |
| 14    | Systematic debugging and project finalization | 1–6 |
| 15    | **Final** (project demo + individual oral defense) | 1–6 |

---

## How to Use a Lab

Each lab page follows the same ten-section template:

1. **Header:** week, topic, duration, prerequisites, method
2. **Learning outcomes:** what you will be able to do by the end
3. **Recap:** one paragraph connecting to the prior week
4. **Background:** concise theory (with optional *Under the Hood* box)
5. **Worked examples:** annotated programs with expected output
6. **Guided exercises:** type-along coding tasks (Part B)
7. **Challenge problems:** optional harder tasks
8. **Common pitfalls:** the errors everyone makes on this topic
9. **Submission and rubric:** what to submit, filename, points
10. **Further reading:** mapped textbook sections

> **Under the Hood** boxes are short curiosity notes about how hardware
> relates to the concept you just learned. They are **never assessed.**
> They exist to build intuition, and they signpost deeper material you
> will study in later courses.

---

## Assessment Summary

| Component | Weight | When |
|-----------|:------:|------|
| Midterm (live in-lab coding) | 20% | Week 8 |
| Project (artifact: code + README) | 30% | Submitted Week 14 |
| Final (project demo + oral defense) | 30% | Week 15 |
| Attendance | 10% | Ongoing |
| Assignments (weekly deliverables) | 10% | Weeks 2–13 |

Full rubrics are in [Appendix: Grading Rubrics](appendix/grading-rubric.md).

---

## Academic Integrity and Collaboration Policy

- **Weekly assignments:** you may discuss ideas with classmates but must write your own code. Sharing source files or copying code is not permitted.
- **Take-home project:** the project is strictly individual. You must be able to explain every line in the Week-15 oral defense. Submitting code you did not write and cannot explain is an academic integrity violation.
- **Midterm:** closed collaboration, restricted network; open-book (compiler and reference sheets allowed).
- When in doubt, ask the instructor before submitting, not after.

---

## Course Resources

- **Primary:** K. N. King, *C Programming: A Modern Approach*, 2nd ed.
- **Reference:** Kernighan and Ritchie, *The C Programming Language*, 2nd ed.
- **Online:** cppreference.com, OnlineGDB (browser C compiler)
- **Full reference list:** [Appendix: References](appendix/references.md)
