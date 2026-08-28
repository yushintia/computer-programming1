# The Spine: Standard Structure for Every Lecture Week

Computer Programming I (400521-004), 2025-1. This document is the
standard. Every week's deck (`slides/weekNN-*.md`) must follow it. If a
deck and this document disagree, fix the deck.

Content source: each week's slide deck teaches that week's lab's Part A
(concept + demo, ~50 min) content — see `book/src/labs/labNN-*.md` for
the full lab (Part A lecture scope, Part B/C guided exercises, challenge
problem, submission rubric). The slide deck is the lecture; the lab page
is the full take-home reference (this mirrors the sibling courses'
handout/worksheet split, done here as slides/lab-page instead).

## Principle

**Motivation always precedes definition.** A student should never meet a
concept before meeting the concrete problem that forced someone to need
it. Every week opens with a broken scenario in plain language, not a
formal statement.

**Weeks chain.** The "Limits" slide that closes week N is, almost
verbatim, the "Pain" slide that opens week N+1. The semester should read
as one argument, not fifteen independent talks.

**No single running case study.** Unlike the sibling courses (which
follow one case study — e.g. a registration system — across the whole
semester), this course's labs are deliberately example-diverse: a name
card, a temperature converter, a grade classifier, a guessing game, a
student-records program, and so on, each chosen to fit that week's C
concept. Slot 10..N-2 (worked example) draws on THAT week's own lab
example, not a shared thread — do not invent a unifying story that isn't
in the source lab.

## The 17 slots

Acts 0, 1, 2, 4 are **mandatory and fixed**: same slot numbers, same
order, every full-spine week. Act 3 (Build) expands or contracts to fit
the topic.

### Act 0: LOCATE

| # | Slide | Rule |
|---|---|---|
| 1 | Title | Week #, topic, course code, professor, date |
| 2 | Where we are | Shared roadmap graphic (`_shared/roadmap.md`), current week highlighted |
| 3 | Recap + open wound | One sentence on what last week delivered, one sentence on what it left broken |

### Act 1: MOTIVATE

| # | Slide | Rule |
|---|---|---|
| 4 | The pain | Concrete broken scenario, drawn from that week's lab's own hook/analogy. **Zero jargon.** If a technical term appears here, the slide is wrong |
| 5 | Cost of not knowing | What breaks downstream (wrong output, wasted rewrites, unreadable code) *and* where this bites in industry (interviews, real bugs, job requirements) |
| 6 | Driving question | One sentence the week must answer. Repeat it verbatim on any section-divider slide inside Act 3 |
| 7 | Learning outcomes | 3–4 verbs, each traceable to the lab's own learning outcomes |

**Hard rule:** no formal definition or C syntax before slot 8. If you
need one earlier, the pain slide (4) is too abstract, so fix it instead
of breaking the rule.

### Act 2: GROUND

| # | Slide | Rule |
|---|---|---|
| 8 | Origin | The lab's "Under the Hood" hardware/history note, or a plain-language history of the concept, if the lab provides one; otherwise a short "why C works this way" framing |
| 9 | Core concept | First formal definition/syntax of the week |

### Act 3: BUILD (flexible)

| # | Slide | Rule |
|---|---|---|
| 10..N-3 | Mechanics | Stepwise, as many slides as the topic needs — draw on the lab's "In plain words" boxes and SVG figure descriptions |
| N-2 | Worked example | That week's lab's own worked example, with full line-by-line explanation where the lab provides one |
| N-1 | Common mistakes | The lab's own Common Pitfalls table, restated as slides |
| N | Check yourself | 2–3 questions; put the answers on the slide immediately after, not the same slide |

### Act 4: CLOSE

| # | Slide | Rule |
|---|---|---|
| N+1 | Limits | What this week's technique cannot do yet. **This text becomes next week's slot 4** |
| N+2 | Bridge | "Week N leaves X unsolved → Week N+1 addresses it." Explicit, one sentence |
| N+3 | Summary | Takeaways + which lab page to open next + what to bring |
| N+4 | Thank You | Template end slide |

## The semester chain

| Wk | Lab | Topic | Limit (leads to next pain) |
|---|---|---|---|
| 1 | lab01 | Course Introduction & Programming Concepts | **Orientation variant** (contract-only: course policy, grading, schedule; no worksheet, no quiz; handout only — this course's "handout" is the lab page itself, no separate file needed). We don't yet know how to write a real program of our own, only run one someone else wrote → **W2** |
| 2 | lab02 | Program Structure & Basic I/O | We can print fixed text, but every value in a program is still typed by hand, never provided by the user → **W3** |
| 3 | lab03 | Variables, Data Types & Expressions | Variables and `scanf` bring in one raw value, but every program still runs exactly one path, no matter the input → **W4** |
| 4 | lab04 | Input/Output & Operators | Output can be formatted precisely, but there is still no way for a program to *decide* between two paths → **W5** |
| 5 | lab05 | Conditional Statements | A program can choose once, but any repeated task still needs the same lines pasted over and over → **W6** |
| 6 | lab06 | Loops I: while and do-while | `while` repeats until a condition changes, but counting a fixed number of times still takes extra bookkeeping lines → **W7** |
| 7 | lab07 | Loops II: for and Nested Loops | Loops can repeat and nest, but a whole block of related loop logic still can't be reused without copy-pasting it → **W8/W9** |
| 8 | lab08 | Midterm: Live In-Lab Coding | review only, no chain link |
| 9 | lab09 | Functions I: Basics | Functions package logic, but a function can't call itself, and every variable inside it disappears the moment it's needed again → **W10** |
| 10 | lab10 | Functions II: Scope & Recursion | Recursion and scope are solved, but every program so far holds only ONE value per variable — never a whole list of them → **W11** |
| 11 | lab11 | Arrays I: One-Dimensional Arrays | A single list of numbers works, but real data is a grid (rows and columns), and text itself has no dedicated type yet → **W12** |
| 12 | lab12 | Arrays II: 2-D Arrays & Strings | Arrays hold many values of ONE type, but a single real-world record (a student: id + name + gpa) mixes several types together → **W13** |
| 13 | lab13 | Basic Data Structures | `struct` models one real record, but nothing yet catches the bugs that slip into a growing program → **W14** |
| 14 | lab14 | Debugging, Analysis and Project Build | review/capstone, no new-concept chain link (this week is itself a synthesis of Weeks 1-13, feeding into the final defense) |
| 15 | lab15 | Final: Project Demo + Individual Oral Defense | review only, no chain link |

Weeks 8 and 15 use the **short review/exam variant**: Act 0 (slots 1-3)
+ exam logistics + sample practice problems (Week 8) or defense format
and rubric (Week 15) + Act 4 (slots N+1..N+4, "Limits" replaced by "What
to focus on next" or "Where to go next"). No Pain or Ground acts: there
is no new concept to motivate.

Week 1 uses the **orientation variant**: a pure course-contract session
(department standard, matching the sibling course decks). Course
description, objectives, prerequisites, textbook, schedule, grading,
assignments, and policy — near-zero technical content, a light
non-technical tease of "what a program actually is," and a
discussion-prompt slide (not answered) that Week 2 opens by answering.
It closes with the standard Limits → Next Week → Summary → Thank You,
same as every other week, so the chain into Week 2 still holds.

## Enforcement

- Copy `slides/_template/week-XX.md` for every new week. It carries all
  17 slots as HTML comments; fill them in, don't renumber them.
- `slides/_shared/roadmap.md`: single source for the Act 0 roadmap
  graphic.
- Every week's deck should stay close to its matching `book/src/labs/
  labNN-*.md` — slides are the LECTURE version of that lab's Part A,
  not new content; if a slide needs a fact the lab page doesn't have,
  check the lab page again before inventing one.
- Course logistics (grading, textbook, policies) are the entire content
  of Week 1 (the orientation variant above). For every other week, they
  must never appear at all — administrative content lives only in Week
  1.
