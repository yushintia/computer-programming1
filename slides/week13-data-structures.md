---
marp: true
theme: shintia
paginate: true
footer: 'Department of Intelligent Computing'
---

<!-- SLOT 1: Title -->
<!-- _class: title -->

# Week 13: Basic Data Structures

<span class="subtitle">Computer Programming I (400521-004)</span>

<div class="meta">
Yushintia Pramitarini, Ph.D · Dept. of Intelligent Computing
</div>

<!--
notes: Week 13. Last week: arrays hold many values, but all of the SAME
type. This week: a way to group different types together, into one
record - the struct. We also take a first, non-assessed look at pointers.
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
<div class="wk now"><div class="n">Wk 13</div><div class="t">Data Structures</div></div>
<div class="wk"><div class="n">Wk 14</div><div class="t">Debugging &amp; Project</div></div>
<div class="wk review"><div class="n">Wk 15</div><div class="t">Final Exam</div></div>
</div>

<!-- notes: Point at Week 13. Tightest week of the semester - one concept
per class period: structs, then pointer awareness, then array-of-structs
practice. -->

---

<!-- SLOT 3: Recap + open wound (Act 0 / LOCATE) -->

# Last Week, This Week

- **Last week delivered:** 2-D arrays for tables of numbers, and C
  strings for text - both arrays, just of different shapes.
- **Last week left broken:** arrays hold many values of ONE type, but a
  single real-world record - a student: id + name + GPA - mixes
  several types together.

---

<!-- SLOT 4: The pain (Act 1 / MOTIVATE), ZERO jargon -->

# One Student, Three Separate Lists

<div class="pain">

You want to store 100 students, each with an ID number, a name, and a
GPA. Right now, the only tool you have is a plain list - and a plain
list holds ONE kind of item. So you would need three separate lists:
one for IDs, one for names, one for GPAs.

Now imagine you delete student #42. You must remove their ID AND their
name AND their GPA - from three different lists, at the same
position, every single time, forever, without ever making a mistake.

</div>

<!-- notes: Ask: "What goes wrong if you update the ID array but forget
to update the name array at the same index?" Let students notice the
records silently fall out of sync. -->

---

<!-- SLOT 5: Cost of not knowing (Act 1 / MOTIVATE) -->

# What This Actually Costs

- Three parallel arrays are easy to get out of sync: one update, one
  missed array, and every record after that point is silently wrong.
- Passing "one student" to a function means passing three separate
  arguments, every time, instead of one clean unit.

<div class="why">
<strong>In industry:</strong> almost every real system models the world
as records - a row in a database table, a JSON object, a class in
another language. C's `struct` is the direct ancestor of all of them,
and understanding it is expected before any database or systems course.
</div>

---

<!-- SLOT 6: Driving question (Act 1 / MOTIVATE) -->

<!-- _class: section -->

# This Week's Question

<div class="driving-q">"How do you group different types of data about ONE thing into a single unit?"</div>

---

<!-- SLOT 7: Learning outcomes (Act 1 / MOTIVATE) -->

# By the End of This Week, You Can

1. Define a record type that groups related fields of different types,
   and declare variables of that type.
2. Read and change one field of a record by name.
3. Create and walk through a list of records.
4. Recognize that every variable has a memory address, and that the
   address is what input functions need to store a value.

---

<!-- SLOT 8: Origin (Act 2 / GROUND) -->

# Where This Idea Came From

Think of a paper form: a student registration form has a field for ID
number, a field for name, a field for GPA. All three pieces of data
belong to the same person, so on the form they travel together, as one
sheet of paper - not three separate stacks sorted by field.

A `struct` is C's version of that form: a way to group related
variables of *different* types under one name, so the language itself
keeps them together, instead of relying on you to keep three arrays in
sync by hand.

---

<!-- SLOT 9: Core concept (Act 2 / GROUND) -->

# `struct`: Definition

> A **struct** groups related variables of different types under one
> name, like a row in a table. A **field** (or **member**) is one named
> slot inside it, accessed with the dot operator: `s.gpa`.

```c
struct Student {
    int    id;
    char   name[30];
    double gpa;
};

struct Student s1 = {2025001, "Alice", 3.75};
printf("%d  %s  %.2f\n", s1.id, s1.name, s1.gpa);
```

---

<!-- SLOT 10: Mechanics - defining and using a struct -->

# Defining and Using a `struct`

- `struct Student { ... };` describes one record: a group of fields
  with names, of different types. Every variable of this kind is
  declared as `struct Student`, the same way `int` or `double` is
  used to declare a variable.
- `struct Student s1 = {2025001, "Alice", 3.75};` creates one variable with
  all three fields filled in, in field order.
- `s1.id`, `s1.name`, `s1.gpa` read or write one field, using the
  **dot operator**.
- Unlike arrays, whole structs CAN be assigned with `=`:
  `struct Student copy = s1;` copies every field at once.

---

<!-- SLOT 11: Mechanics - array of structs -->

# Array of Structs: Many Records, One Type

```c
struct Student roster[3] = {
    {2025001, "Alice", 3.75},
    {2025002, "Bob",   3.20},
    {2025003, "Carol", 3.90}
};

for (int i = 0; i < 3; i++) {
    printf("%-10s GPA: %.2f\n", roster[i].name, roster[i].gpa);
}
```

- `roster` is an array, exactly like Week 11's arrays - except each
  element is now a whole `struct Student`, not a single number.
- `roster[i].gpa` reads field `gpa` of element `i`: index first with
  `[]`, then select the field with `.`.
- This solves last week's pain directly: one array, ID + name + GPA
  always travel together, never falls out of sync.

---

<!-- SLOT 12: Mechanics - pointer awareness -->

# Pointer Awareness (Not Assessed - Just a Preview)

- A **pointer** is a variable that stores a memory *address* instead
  of a value: `int *p = &x;` means "`p` holds the address of `x`."
- You have used `&` since Week 3, inside `scanf("%d", &score)` -
  `&score` hands `scanf` the address so it can write the value there.
  Now you know what that `&` actually means.
- `*p` (**dereference**) reads or writes the value *at* that address:

```c
int  x = 42;
int *p = &x;          /* p points to x */
printf("%d\n", *p);   /* prints 42 */
*p = 99;               /* modify x through p */
printf("%d\n", x);    /* prints 99 */
```

This is a first look only - pointers return in depth in System
Programming and Data Structures.

---

<!-- SLOT 13: Worked example -->

# Worked Example: Student Records (1/3)

```c
#include <stdio.h>
#include <string.h>
#define MAX 5

struct Student {
    int    id;
    char   name[30];
    double score;
};

void print_roster(struct Student r[], int n);
struct Student find_top(struct Student r[], int n);
```

One `struct Student` type, and two function prototypes that take an array of
`struct Student` plus a count - the same pattern as any array-processing
function since Week 11, just with a struct element type.

---

# Worked Example: Student Records (2/3)

```c
int main(void) {
    struct Student roster[MAX];
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &roster[i].id);
        scanf("%29s", roster[i].name);
        scanf("%lf", &roster[i].score);
    }
    print_roster(roster, MAX);
    struct Student top = find_top(roster, MAX);
    printf("Top student: %s (%.2f)\n", top.name, top.score);
    return 0;
}
```

- `scanf("%d", &roster[i].id)`: a scalar field still needs `&`.
- `scanf("%29s", roster[i].name)`: `name` is already a `char` array,
  so no `&` here - the `29` leaves room for `'\0'`.

---

# Worked Example: Student Records (3/3)

```c
void print_roster(struct Student r[], int n) {
    printf("%-8s %-12s %6s\n", "ID", "Name", "Score");
    for (int i = 0; i < n; i++)
        printf("%-8d %-12s %6.2f\n", r[i].id, r[i].name, r[i].score);
}

struct Student find_top(struct Student r[], int n) {
    struct Student best = r[0];
    for (int i = 1; i < n; i++)
        if (r[i].score > best.score) best = r[i];
    return best;
}
```

`best = r[i]` is whole-struct assignment: it copies all three fields
at once, the same way `struct Student top = find_top(...)` copies the whole
returned record into `top`.

---

<!-- SLOT 14: Common mistakes -->

# Common Mistakes

<div class="cardlist">
<div class="card"><div class="h">Comparing structs with ==</div><div class="d">s1 == s2 does not compile. C has no built-in struct comparison - compare the fields you care about, one at a time.</div></div>
<div class="card"><div class="h">Forgetting & for scalar fields</div><div class="d">scanf("%d", &s.id) still needs the & - a struct's int or double field is scanned exactly like a plain variable.</div></div>
<div class="card"><div class="h">Adding & for char array fields</div><div class="d">scanf("%29s", s.name) needs NO & - name is already an array, which acts as an address on its own.</div></div>
<div class="card"><div class="h">Printing &s.name</div><div class="d">printf("%s", &s.name) adds a noisy, unnecessary &. Just use s.name directly with %s.</div></div>
</div>

---

<!-- SLOT 15: Sample questions -->

# Sample Question 1

**Question:** Given `struct Student s;`, how do you read its `id` field with `scanf`?
How do you read its `name` field?

---

# Sample Question 1: Answer

**Answer:** `scanf("%d", &s.id)` (needs `&`, it's a scalar); `scanf("%29s",
s.name)` (no `&`, it's already an array).

---

# Sample Question 2

**Question:** What does `struct Student best = r[0];` copy - just one field, or all of
them?

---

# Sample Question 2: Answer

**Answer:** All of them - a struct assignment copies every field at once.

---

# Sample Question 3

**Question:** Why can't three separate arrays (`ids`, `names`, `gpas`) replace a
single `struct Student roster[]` safely?

---

# Sample Question 3: Answer

**Answer:** The three arrays can silently drift out of sync (one updated,
others not); a struct keeps every field of one record together by
construction, so that can't happen.

---

<!-- SLOT N+1: Limits (Act 4 / CLOSE) -->

# What `struct` Cannot Do Yet

<div class="limits">
`struct` models one real record cleanly. But nothing yet in this course
catches the bugs that slip into a growing program - a wrong index, a
missing `&`, a logic mistake that only shows up on some inputs. As
programs get bigger (like the project you are about to build), finding
those bugs by luck stops working.
</div>

<!-- notes: This is SPINE.md's Week 13 chain text verbatim - it becomes
Week 14's slot 4 pain, framed instead as: "nothing yet catches the bugs
that slip into a growing program." -->

---

<!-- SLOT N+2: Bridge (Act 4 / CLOSE) -->

# Next Week

Week 13 leaves **catching the bugs that slip into a growing program**
unsolved. **Week 14** addresses it: systematic debugging, plus building
and finalizing your semester project.

---

<!-- SLOT N+3: Summary (Act 4 / CLOSE) -->

# Summary

- A `struct` groups fields of different types under one name, accessed
  with the dot operator (`s.field`).
- An array of structs (`struct Student roster[N]`) keeps many complete
  records in sync automatically.
- `&x` is the address of `x` - the idea behind `scanf`'s `&`, and the
  doorway to pointers in later courses.
- **Lab page:** [Lab 13: Basic Data Structures](../book/labs/lab13-data-structures.html), for the
  contact-book and student-records exercises, plus the sort-by-score
  challenge.
- **Prepare:** think about which of the four project options (contact
  book, grade manager, guessing game, calculator suite) fits your idea
  - Week 14 finalizes and submits your project.

---

<!-- SLOT N+4: Thank You (Act 4 / CLOSE) -->
<!-- _class: end -->

# Thank You
