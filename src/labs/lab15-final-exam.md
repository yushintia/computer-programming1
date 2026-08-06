# Lab 15: Final: Project Demo + Individual Oral Defense

| | |
|---|---|
| **Week** | 15 |
| **Duration** | 150 min (single continuous block) |
| **Method** | Examination: demo and individual oral defense |
| **Scope** | Entire course; assessed through the project (emphasizes Weeks 9–14) |
| **Weight** | **30%** of final grade |

**Time allocation**

| Phase | Min | Activity |
|-------|-----|----------|
| Setup | 5 | Confirm project runs on the lab machine |
| Student rotations | ~135 | ~10–12 min per student: demo · Q&A · live modification |
| Buffer | 10 | Technical issues; parallel stations if class is large |

---

## What This Exam Is

The final is **not** a written test or a timed coding sprint from scratch.
It is an **individual oral defense**: you present your project and answer questions about it live.
You demonstrate that you wrote it, understand it, and can extend it on the spot.

Each student gets approximately **10–12 minutes**:

1. **Live demo (2–3 min):** run your program and show it works for a sample scenario.
2. **Explain-your-code Q&A (5–6 min):** the examiner asks about specific parts of your code.
   Typical questions: "What does this function do?", "Why did you use a struct here?",
   "Walk me through what happens when the user enters X."
3. **Live modification (3–4 min):** the examiner asks you to add or change a small feature
   *during the session*. This validates authorship and measures understanding beyond memorization.

---

## What Is Being Assessed

The oral defense assesses Weeks 9–14 *through your project*:

| Topic | How it shows up |
|-------|----------------|
| Functions (Wk 9–10) | Can you explain what each function does? Why split the code this way? |
| Arrays (Wk 11–12) | Can you trace array indexing? Explain the loop bounds? |
| Strings (Wk 12) | If your project processes strings, can you explain the `\0` terminator? |
| Structs (Wk 13) | Can you explain why you grouped data into a struct? |
| Debugging (Wk 14) | Can you find and fix a bug in your own code in real time? |

---

## Oral Defense Rubric (30%)

| Criterion | Description | Weight |
|-----------|-------------|--------|
| **Runs & meets spec** | Program runs without crashes; core features work as described in README | 8% |
| **Code understanding** | Student can explain any part of their code accurately | 10% |
| **Live modification** | Student successfully implements the requested change (partial credit for correct approach) | 8% |
| **Presentation clarity** | Clear communication; organized demo | 4% |

---

## Preparing for the Oral Defense

### Know Your Own Code

- Read every line of your project before the oral defense.
- Be ready to explain: what each function does, why you chose that data structure,
  how your loop terminates, what happens on invalid input.
- If you copied a snippet from an example, understand it. You will be asked about it.

### Practice Typical Questions

- "What does `main` do first?"
- "Why did you use a `while` loop here instead of `for`?"
- "What happens if the user enters a negative number?"
- "How does your struct store the data?"
- "Walk me through the output for this input: …"

### Prepare for the Live Modification

Past modifications have included:
- "Add a feature that prints the total number of items."
- "Make the program reject negative input."
- "Add a function that returns the average of your array."

These are deliberate small changes in scope. You are not expected to redesign the program.
Writing clean, modular code in Week 14 makes Week 15 easier.

---

## Oral Defense Scoring Guide

| Score band | Meaning |
|------------|---------|
| 90–100% | Explains all code fluently; live modification complete and correct |
| 75–89% | Explains most code with minor gaps; modification mostly correct |
| 60–74% | Explains core features; modification partial |
| Below 60% | Cannot explain key parts; modification not attempted |

---

## Logistics

- Bring your project files on the lab machine (or a USB drive as backup).
- Have a terminal open with the project directory ready.
- Compile your project fresh at the start of the session: `gcc *.c -o project -Wall -std=c99`
- If two or more lab machines are available, the class splits into parallel stations so wait time is minimal.

---

## After the Exam

This is the last graded activity of the semester.
Final grades are composed of:

| Component | Weight |
|-----------|:------:|
| Midterm (Week 8) | 20% |
| Project artifact (submitted Week 14) | 30% |
| Final: demo + oral defense (today) | 30% |
| Attendance | 10% |
| Assignments (Weeks 2–13) | 10% |

---

## Congratulations

You have completed **Computer Programming I**.
You can now write, compile, debug, and explain C programs that use variables,
control flow, functions, arrays, strings, and basic data structures.

**Where to go next:**

- **Computer Programming II / System Programming:** pointers in depth, memory management, file I/O, processes
- **Data Structures:** linked lists, stacks, queues, trees, sorting algorithms
- **Computer Architecture:** what the CPU and memory really do
- **Operating Systems:** how programs interact with the OS kernel

The [References appendix](../appendix/references.md) lists recommended resources for each path.

---

## Further Reading

- [Grading Rubrics](../appendix/grading-rubric.md): full scoring criteria
- [Debugging Tips](../appendix/debugging-tips.md): in case you need to fix a bug during the oral defense
