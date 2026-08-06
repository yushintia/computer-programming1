# 강의계획서 · Course Syllabus — 기본관리(학부)

> Text version of `docs/silabus.jpg`, updated to the current course plan.
> Course code `Uc00504a_2019`.

---

## 1. 교과목 기본정보 · Course Basic Information

| 항목 (Field) | 내용 (Content) |
|---|---|
| 년도 (Year) | 2025 |
| 학기 (Semester) | 1학기 · Semester 1 |
| 교원번호 (Faculty No.) | 15848 |
| 교원명 (Instructor) | **Yushintia Pramitarini** |
| 담당교목 (Course) | 400521-004 컴퓨터프로그래밍 I · Computer Programming I |
| 학점/이론/실습 (Credits / Theory / Lab) | 3 · Lecture & Lab (강의 및 실습) |
| 학습유형 (Learning type) | 06 플립러닝형 · Blended / Flipped |
| 상담시간 (Office hours) | TBA |

---

## 2. 교과목개요 · Course Overview

This course introduces the fundamental concepts of computer programming using a high-level programming language (**C**). Students will learn problem-solving techniques, algorithm development, and structured programming principles. The course covers variables, control structures, functions, arrays, and basic input/output operations. By the end of the course, students will be able to write, debug, and analyze simple programs. Emphasis is placed on problem-solving and logical thinking, with hands-on coding exercises that illustrate how software interacts closely with hardware.

---

## 3. 교과교육목표 · Course Objectives

Upon completing this course, students are expected to:

1. Understand the basic principles of programming and problem-solving.
2. Learn the syntax and semantics of a high-level programming language.
3. Utilize variables, data types, and expressions effectively.
4. Apply control structures such as loops and conditional statements.
5. Understand and implement functions and modular programming.
6. Work with arrays and basic data structures.

---

## 4. 성적평가 · Assessment

**성적평가비율 (Grade distribution):** A: 40% 이하 · B: 40% 이하 · C: 20% 이하 (수강인원에 따라 비율 변경 가능; A 이하 절대평가 적용)

**평가방법 (Evaluation):**

| 중간시험 Midterm | 기말시험 Final | 출석 Attendance | 과제물 Assignments | 발표 Presentation | 프로젝트 Project | 합계 Total |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 20% | 30% | 10% | 10% | 0% | 30% | **100%** |

- **중간시험 (Midterm) 20%:** Week 8 — **live in-lab coding** exam (open-book, own machine, several small tasks with partial credit), covering Weeks 1–7.
- **프로젝트 (Project) 30%:** individual take-home program (artifact) assigned mid-term, **submitted in Week 14** — graded on features, correctness, code quality, and README/report.
- **기말시험 (Final) 30%:** Week 15 — **project demo + individual oral defense** (live demo, explain-your-code Q&A, one live modification), assessing Weeks 9–14 through the project.
- **출석 (Attendance) 10%** · **과제물 (Assignment) 10%:** weekly lab deliverables (Weeks 2–13).

---

## 5. 참고문헌 및 인터넷 사이트 · References

**주교재 (Primary textbooks)**

1. K. N. King, *C Programming: A Modern Approach*, 2nd ed., W. W. Norton & Company. — beginner-friendly, structured coverage of C that matches this course's topic sequence.
2. Brian W. Kernighan & Dennis M. Ritchie, *The C Programming Language*, 2nd ed., Prentice Hall. — the canonical C reference (used for the per-week chapter map).

**부교재 (Supplementary)**

3. Stephen Prata, *C Primer Plus*, 6th ed., Addison-Wesley. — gentle, example-driven introduction for absolute beginners.
4. Paul Deitel & Harvey Deitel, *C How to Program*, 8th ed., Pearson. — extensive worked examples and exercises.

**인터넷 사이트 (Online resources)**

- cppreference.com — C standard library reference.
- OnlineGDB / Programiz online C compiler — browser-based fallback for the Week-1 environment setup.
- GNU GDB documentation — for the Week-14 systematic-debugging capstone.

---

## 6. 수업의 질 관리 · Course Quality Management

- **수업 피드백 (Feedback):** A Kakao chatroom is created to facilitate communication with students; lecture slides and class materials are uploaded to the LMS.
- **수업 개선방안 (Improvement):** Week-5 diagnostic assessment (5주차 진단평가) results are reflected in subsequent adjustments.

---

## 7. 주차별 강의계획 · Weekly Lecture Plan

Each meeting = **3×50 min (150 min)**, delivered in three 50-minute parts (A: concept + demo · B: guided lab · C: independent exercises + wrap-up). Debugging is threaded across the term rather than taught as a single week.

---

### [Week 1]
- **강의주제 (Topic):** Course Introduction and Programming Concepts
- **강의내용 (Content):**
  - Course overview, objectives, evaluation method, and academic-integrity/collaboration policy
  - Principles of programming, problem-solving, and algorithm development (pseudocode/flowchart)
  - Setting up the development environment (compiler/IDE) + online-compiler fallback
  - Hands-on: type and run a first provided program to verify every setup works
- **시간배분 (Time):** A(50) overview & policies · B(50) concepts + setup walkthrough · C(50) hands-on run + Week 2 preview
- **강의방법 (Method):** 강의 (Lecture)

### [Week 2]
- **강의주제:** Program Structure and Basic Input/Output
- **강의내용:**
  - Structure of a program; "your code → gcc → a program you run" (compilation in one line)
  - Writing, compiling, and running a first program; basic output and program flow
  - Reading error messages primer: find the line, fix the first error first, recompile
- **시간배분:** A(50) program structure + demo · B(50) guided `printf` coding + reading errors · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 3]
- **강의주제:** Variables, Data Types, and Expressions
- **강의내용:**
  - Integer, floating-point, and character data types
  - Variable declaration, initialization, and constants
  - Expressions; **basic `scanf` input** → first interactive program
  - How data is stored in memory (a variable = a labeled box of bytes)
- **시간배분:** A(50) types & expressions · B(50) guided interactive I/O · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 4]
- **강의주제:** Input/Output and Operators
- **강의내용:**
  - Formatted input and output
  - Arithmetic, relational, and logical operators
  - Operator precedence and type conversion
  - (Optional enrichment: bitwise operators)
- **시간배분:** A(50) operators & precedence · B(50) guided calculator lab · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 5]
- **강의주제:** Conditional Statements
- **강의내용:**
  - if, if-else, and nested if statements
  - switch-case structure
  - Diagnostic assessment and feedback (진단평가)
  - Common pitfall: `=` vs `==`
- **시간배분:** A(50) conditionals · B(50) guided lab + diagnostic · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 6]
- **강의주제:** Loops I — while and do-while
- **강의내용:**
  - while and do-while loops
  - Loop conditions and avoiding infinite loops
  - Counting and accumulation problems
  - Runtime-debugging moment: `printf`-tracing a loop that gives the wrong result
- **시간배분:** A(50) loop concepts · B(50) guided lab + runtime debugging · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 7]
- **강의주제:** Loops II — for and Nested Loops
- **강의내용:**
  - for loop structure
  - Nested loops and pattern problems
  - break and continue statements
  - Pre-midterm mixed review
- **시간배분:** A(50) for & nested loops · B(50) guided pattern lab · C(50) review + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 8]
- **강의주제:** Midterm — Live In-Lab Coding
- **강의내용:**
  - Live-coding practical exam covering Weeks 1–7 (variables, data types, I/O, operators, conditionals, loops)
  - Open-book (compiler + reference sheets), own lab machine, restricted network, invigilated
  - Several small tasks with partial credit per task
- **시간배분:** 10 rules/setup · 120 live coding · 20 submission + buffer
- **강의방법:** 시험 (Examination — live coding)

### [Week 9]
- **강의주제:** Functions I
- **강의내용:**
  - Function definition, declaration, and call
  - Parameters and return values
  - Structured, modular program design
- **시간배분:** A(50) functions concept · B(50) guided mini-library lab · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 10]
- **강의주제:** Functions II
- **강의내용:**
  - Variable scope and storage classes
  - Basics of recursion (simple examples)
  - Function-based problem solving
- **시간배분:** A(50) scope & recursion · B(50) guided lab · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 11]
- **강의주제:** Arrays I — One-Dimensional Arrays
- **강의내용:**
  - Array declaration, indexing, and traversal
  - Common array operations (sum, search, min/max)
  - Array-based exercises
  - Common pitfall: off-by-one / out-of-bounds
  - First look at strings: a string is a one-dimensional `char` array ending in `\0` (full treatment in Week 12)
  - Sorting an array into order with bubble sort (first look; faster sorting algorithms and Big-O in a later course)
- **시간배분:** A(50) arrays concept · B(50) guided stats lab · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 12]
- **강의주제:** Arrays II — Multi-Dimensional Arrays and Strings
- **강의내용:**
  - Two-dimensional arrays (Part A)
  - Character arrays and strings; the `\0` terminator (Part B)
  - Text-processing exercises (Part C); heavier `<string.h>` work as take-home
- **시간배분:** A(50) 2-D arrays · B(50) strings · C(50) text exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 13]
- **강의주제:** Basic Data Structures
- **강의내용:**
  - Structures (struct) and grouping related data (Part A, in-class core)
  - Introduction to pointers and memory addresses — awareness demo (~20 min); connects to the `&` in `scanf`; depth deferred to System Programming
  - Combining arrays and structures (array of structs; "combining" extended as take-home)
- **시간배분:** A(50) structs · B(50) array-of-structs + pointer intro · C(50) exercises + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 14]
- **강의주제:** Debugging, Program Analysis, and Project Build
- **강의내용:**
  - Systematic debugging (printf-tracing, rubber-duck, intro gdb) — capstone, not first exposure
  - Reading and analyzing simple/unfamiliar programs
  - Integrative project: **artifact submission** (code + README); demo/defense follows in Week 15
- **시간배분:** A(50) systematic debugging · B(50) program analysis · C(50) project finalize + submit
- **강의방법:** 강의 및 실습 (Lecture & Lab)

### [Week 15]
- **강의주제:** Final: Project Demo + Individual Oral Defense
- **강의내용:**
  - Live demo of the take-home project + explain-your-code Q&A + one live modification
  - Assesses Weeks 9–14 (functions, arrays, strings, basic data structures) through the project
  - Rubric: runs & meets spec · code understanding · live-modification · presentation clarity
- **시간배분:** ~10–12 min per student (demo · Q&A · live modification); parallel stations if class is large
- **강의방법:** 시험 (Examination — demo/oral defense)
