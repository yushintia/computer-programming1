# Lab 13: Basic Data Structures

| | |
|---|---|
| **Week** | 13 |
| **Duration** | 3 × 50 min (150 min); tightest week, each part covering one concept |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 12 (arrays, strings), Lab 09 to 10 (functions) |

**Why this lab matters:** A student record has an ID, a name, and a GPA, which are three different types that belong together. A contact has a name, a phone number, and an email. Real data is almost always mixed: it has fields of different types that describe one thing. The `struct` is C's way of grouping those fields into a single named unit, similar to a row in a database table. Structs are the building block for every more complex data structure, such as linked lists and trees, that you will meet in Data Structures and beyond.

**Time allocation (one topic per part)**

| Part | Min | Activity |
|--------|-----|----------|
| A | 50 | 5 recap · 30 `struct` definition and dot access · 15 struct demo |
| B | 50 | 5 transition · 20 array-of-structs lab (guided) · 20 pointer intro (~20 min awareness demo) · 5 debrief |
| C | 50 | 35 independent exercises (records program) · 10 challenge · 5 submit and Week 14 preview and project Q&A |

> "Combining arrays and structs" is the core in-class exercise.
> Deeper struct and pointer combination is take-home / project territory.

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Define a `struct` and declare variables of that type.
2. Access struct members with the dot operator.
3. Create and traverse an array of structs.
4. Recognize that `&x` gives the memory address of `x`, connecting back to `scanf`.

---

## Recap

In Weeks 11 to 12 you collected related values of the same type into arrays.
But what if the data belongs together but has different types?
A `struct` groups fields of *different* types under one name, like a row in a table.

---

## Key Terms

> **In plain words: struct**
> A `struct` (short for structure) is a way to group related variables of *different* types
> under one name. Think of a paper form with labeled fields: a student registration form
> has a field for ID number (integer), a field for name (text), and a field for GPA
> (decimal). All three pieces of data belong to the same person, so they should travel
> together. A `struct` is the C equivalent of that form.
>
> Without structs, you would need three separate arrays (`int ids[100]`,
> `char names[100][30]`, `double gpas[100]`) and have to keep them in sync manually.
> With a struct, `Student roster[100]` keeps all three fields together per student.

> **In plain words: field (member)**
> A *field* (also called a *member*) is one named slot inside a struct, just like one
> labeled box on a form. You access it with the dot operator: `s.gpa` reads the `gpa`
> field of the struct variable `s`. If you have a pointer to a struct, use the arrow
> operator: `p->gpa` is shorthand for `(*p).gpa`.

> **In plain words: pointer (awareness summary)**
> A *pointer* is a variable that stores a memory address rather than a data value.
> `int *p = &x;` means "p holds the address of x." You have been using `&` in
> `scanf(&score)` since Week 3; `&score` passes the address of `score` so `scanf`
> can write the value into it. `*p` (dereference) reads or writes the value *at* the
> address. Pointers are the gateway to dynamic memory and linked lists in later courses.

## Background: Part A: Structures

### Struct Record Layout

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 520 170" style="max-width:500px;display:block;margin:1.5em auto;">
  <title>A Student struct shown as a record with three fields laid out in memory. The first field id is an int taking 4 bytes. The second field name is a char array of 30 bytes. The third field gpa is a double taking 8 bytes. The total size is shown as 42 bytes. A sample value is shown below: id equals 2025001, name equals Alice, gpa equals 3.75.</title>
  <!-- Struct box -->
  <rect x="10" y="10" width="490" height="100" rx="8" fill="#f5f9fd" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="20" y="30" font-family="monospace" font-size="12" fill="#0b3d66" font-weight="bold">typedef struct {</text>
  <!-- id field -->
  <rect x="30" y="40" width="80" height="42" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.2"/>
  <text x="70" y="58" font-family="monospace" font-size="11" fill="#0b3d66" text-anchor="middle" font-weight="bold">id</text>
  <text x="70" y="72" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">int (4 B)</text>
  <!-- name field -->
  <rect x="120" y="40" width="210" height="42" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="1.2"/>
  <text x="225" y="58" font-family="monospace" font-size="11" fill="#c07000" text-anchor="middle" font-weight="bold">name[30]</text>
  <text x="225" y="72" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">char array (30 B)</text>
  <!-- gpa field -->
  <rect x="340" y="40" width="140" height="42" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.2"/>
  <text x="410" y="58" font-family="monospace" font-size="11" fill="#2e7d32" text-anchor="middle" font-weight="bold">gpa</text>
  <text x="410" y="72" font-family="sans-serif" font-size="9" fill="#888" text-anchor="middle">double (8 B)</text>
  <text x="20" y="100" font-family="monospace" font-size="12" fill="#0b3d66">} Student;</text>
  <!-- sample values -->
  <text x="10" y="128" font-family="sans-serif" font-size="11" fill="#555">Sample value:</text>
  <text x="10" y="148" font-family="monospace" font-size="12" fill="#2e7d32">Student s = { 2025001, "Alice", 3.75 };</text>
  <text x="10" y="165" font-family="sans-serif" font-size="10" fill="#888">Access with: s.id   s.name   s.gpa</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 13.1.</strong> Layout of a struct record.</em></p>

```c
typedef struct {
    int    id;
    char   name[30];
    double gpa;
} Student;

Student s1 = {2025001, "Alice", 3.75};
printf("%d  %s  %.2f\n", s1.id, s1.name, s1.gpa);
```

---

## Background: Part B: Pointer Awareness (~20 min)

> This is an **awareness demo only**: not assessed, not on the exam.
> The goal is to demystify `&` and prepare you for System Programming.

### Pointer Arrow Diagram

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 440 130" style="max-width:420px;display:block;margin:1.5em auto;">
  <title>Pointer diagram. On the left a box labeled int x contains the value 42 at memory address 0x2000. On the right a box labeled int star p contains 0x2000 (the address of x). An arrow from p points to the x box labeled dereference star p.</title>
  <defs>
    <marker id="arr-13" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- variable x -->
  <rect x="20" y="35" width="140" height="70" rx="6" fill="#eef4fa" stroke="#0b3d66" stroke-width="2"/>
  <text x="90" y="55" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">int x</text>
  <text x="90" y="75" font-family="monospace" font-size="20" fill="#0b3d66" text-anchor="middle">42</text>
  <text x="90" y="97" font-family="monospace" font-size="10" fill="#888" text-anchor="middle">address: 0x2000</text>
  <!-- pointer p -->
  <rect x="280" y="35" width="145" height="70" rx="6" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <text x="352" y="55" font-family="monospace" font-size="12" fill="#c07000" text-anchor="middle" font-weight="bold">int *p</text>
  <text x="352" y="75" font-family="monospace" font-size="14" fill="#c07000" text-anchor="middle">0x2000</text>
  <text x="352" y="95" font-family="sans-serif" font-size="10" fill="#888" text-anchor="middle">stores the address of x</text>
  <!-- dereference arrow -->
  <line x1="280" y1="70" x2="162" y2="70" stroke="#0b3d66" stroke-width="2" marker-end="url(#arr-13)"/>
  <text x="221" y="60" font-family="sans-serif" font-size="10" fill="#0b3d66" text-anchor="middle">*p dereferences</text>
  <text x="221" y="88" font-family="sans-serif" font-size="10" fill="#0b3d66" text-anchor="middle">(reads/writes x)</text>
  <!-- code -->
  <text x="20" y="125" font-family="monospace" font-size="11" fill="#555">int *p = &amp;x;   /* p holds the address of x */</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 13.2.</strong> A pointer holds the address of a variable.</em></p>

`&x` is the **address** of `x`, where it lives in memory.
You have been using `&` with `scanf` since Week 3; now you know what it means.

```c
int  x = 42;
int *p = &x;          /* p points to x */
printf("%d\n", *p);   /* dereference: read value at address p: prints 42 */
*p = 99;              /* modify x through p */
printf("%d\n", x);    /* prints 99 */
```

**This is the doorway to System Programming and Data Structures.**
In those courses you will use pointers to build linked lists, manage heap memory,
and interact with the operating system. For now, just recognize the pattern.

---

## Background: Part B continued: Array of Structs

```c
Student roster[3] = {
    {2025001, "Alice", 3.75},
    {2025002, "Bob",   3.20},
    {2025003, "Carol", 3.90}
};

for (int i = 0; i < 3; i++) {
    printf("%-10s GPA: %.2f\n", roster[i].name, roster[i].gpa);
}
```

---

## Worked Example: Student records

```c
/* lab13_records.c (outline) */
#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int    id;
    char   name[30];
    double score;
} Student;

void print_roster(Student r[], int n);
Student find_top(Student r[], int n);

int main(void) {
    Student roster[MAX];
    for (int i = 0; i < MAX; i++) {
        printf("Student %d ID: ", i + 1);
        scanf("%d", &roster[i].id);
        printf("Name: ");
        scanf("%29s", roster[i].name);
        printf("Score: ");
        scanf("%lf", &roster[i].score);
    }
    print_roster(roster, MAX);
    Student top = find_top(roster, MAX);
    printf("Top student: %s (%.2f)\n", top.name, top.score);
    return 0;
}

void print_roster(Student r[], int n) {
    printf("%-8s %-12s %6s\n", "ID", "Name", "Score");
    for (int i = 0; i < n; i++)
        printf("%-8d %-12s %6.2f\n", r[i].id, r[i].name, r[i].score);
}

Student find_top(Student r[], int n) {
    Student best = r[0];
    for (int i = 1; i < n; i++)
        if (r[i].score > best.score) best = r[i];
    return best;
}
```

### Line by line

| Line | What it does |
|------|-------------|
| `typedef struct { ... } Student;` | Defines a new type called `Student`. After this definition, `Student` can be used anywhere you would use `int` or `double` to declare a variable. `typedef` saves you from writing `struct Student` every time. |
| `void print_roster(Student r[], int n);` | Prototype: declares that the function exists. It takes an array of `Student` and a count, and returns nothing. |
| `Student roster[MAX];` | Creates an array of `MAX` Student records. Each element is a complete Student with all three fields. |
| `scanf("%d", &roster[i].id);` | Reads an integer and stores it in the `id` field of `roster[i]`. The `.id` selects the field; `&` gives `scanf` its address so it can write there. |
| `scanf("%29s", roster[i].name);` | Reads a word (up to 29 characters, leaving room for `'\0'`) into the `name` field. Note: `name` is a char array, so no `&` needed; the array name already acts as an address. The `29` prevents a buffer overflow. |
| `scanf("%lf", &roster[i].score);` | Reads a `double`. Must use `%lf` (lowercase L, not letter i) for `double` with `scanf`. |
| `Student top = find_top(roster, MAX);` | Calls `find_top`, which returns a `Student` value by copy. The whole struct is copied into `top`. |
| `Student best = r[0];` | Inside `find_top`: start by assuming the first student has the top score. |
| `if (r[i].score > best.score) best = r[i];` | If student `i` beats the current best, copy the entire Student struct into `best`. Structs can be assigned with `=`, unlike arrays. |
| `return best;` | Returns a copy of the best-scoring student record to the caller. |

**Sample interaction:**
```
Student 1 ID: 2025001
Name: Alice
Score: 88.5
Student 2 ID: 2025002
Name: Bob
Score: 92.0
...
ID       Name         Score
2025001  Alice        88.50
2025002  Bob          92.00
...
Top student: Bob (92.00)
```

---

## Guided In-Lab Exercises

### Exercise 1: Contact book (Part A and B)

Define a `struct Contact` with name, phone (string), and email (string).
Create an array of 3 contacts, read them from the user, then print a formatted table.

File: `lab13_contacts.c`

### Exercise 2: Records program (Part C)

Implement the Student roster from the worked example.
Add a function that computes the class average score.

File: `lab13_records.c`

### Exercise 3: Course grade book (Part C)

Define a `typedef struct` named `Course` with a `char name[20]`, an `int credits`, and a `double grade_points`
(for example 4.0 for an A, or 3.5 for a B+). Read 4 courses into an array, then write:
- `double weighted_gpa(Course c[], int n)`: returns the sum of `credits * grade_points`
  divided by the total credits.
- `Course most_credits(Course c[], int n)`: returns a copy of the course with the most credits.

Print the weighted GPA with 2 decimal places, then print the name and credits of the course
returned by `most_credits`.

Sample run:
```
Course 1 name: Math
Credits: 3
Grade points: 4.0
Course 2 name: Art
Credits: 2
Grade points: 3.5
Course 3 name: Physics
Credits: 4
Grade points: 3.0
Course 4 name: Music
Credits: 1
Grade points: 4.0
Weighted GPA: 3.50
Most credits: Physics (4)
```

Hint: the total credits is an `int`. Cast it to `double` before dividing, or the decimal
part of the GPA is lost.

File: `lab13_gradebook.c`

---

## Challenge Problem

Add a function `void sort_by_score(Student r[], int n)` that sorts the roster
in descending order of score using bubble sort.
Print the sorted roster.

File: `lab13_sort_challenge.c`

---

## Practice Problems

These are ungraded: extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Rectangle catalog

Define a `struct Rectangle` with a `char label[10]`, `double width`, and `double height`. Read 3 rectangles (label, width, height) into an array, then print a table with each rectangle's label, width, height, and computed area (`width * height`).

File: `lab13_practice1_rectangles.c`

**Sample run:**
```
Rectangle 1 label: A
Width: 4
Height: 5
...
Label         Width   Height     Area
A              4.00     5.00    20.00
```

### Practice 2: Weather extremes

Define a `struct Reading` with a `char day[10]` and `double celsius`. Read 5 daily readings into an array. Write two functions, `hottest_day` and `coldest_day`, each returning a copy of the `Reading` with the highest and lowest temperature, and print both.

File: `lab13_practice2_weather.c`

**Sample run:**
```
Hottest day: Tue (26.0 C)
Coldest day: Wed (19.0 C)
```

### Practice 3: Library catalog search

Define a `struct Book` with `char title[40]`, `char author[30]`, and `int year`. Read 4 books into an array, then read a search title from the user and search for it linearly using `strcmp`. Print the matching book's author and year, or `"Not found"` if no title matches.

File: `lab13_practice3_library.c`

**Sample run:**
```
Search for title: It
Found: King (1986)
```

### Practice 4: Inventory value

Define a `struct Product` with `char name[20]`, `int quantity`, and `double unit_price`. Read 4 products into an array. Compute and print the total inventory value (the sum of `quantity * unit_price` over all products), then identify and print the product that contributes the highest total value.

File: `lab13_practice4_inventory.c`

**Sample run:**
```
Total inventory value: 208.00
Highest value product: Notebook (90.00)
```

### Practice 5: Movie ratings tally

Define a `struct Movie` with `char title[30]` and `double rating`. Read 5 movies into an array, then read a rating threshold from the user. Print the title of every movie rated at or above that threshold, and print the total count of matches.

File: `lab13_practice5_movies.c`

**Sample run:**
```
Rating threshold: 8.0
Movies rated >= 8.0:
  Nova (8.2)
  Dunes (9.0)
  Relic (8.5)
Total: 3 movie(s)
```

### Practice 6: Employee payroll sort

Define a `struct Employee` with `char name[20]` and `double salary`. Read 5 employees into an array. Sort them into ascending order of salary with a bubble sort (swap whole structs, not individual fields), print the sorted list, and print the total payroll.

File: `lab13_practice6_payroll.c`

**Sample run:**
```
Sorted by salary (ascending):
Eve               47000.00
Bob               48000.00
...
Total payroll: 263000.00
```

### Practice 7: Game leaderboard

Define a `struct Player` with `char name[20]`, `int score`, and `int level`. Read 5 players into an array. Print the player with the highest score, compute and print the average score across all players, then read a minimum level from the user and print how many players reached at least that level.

File: `lab13_practice7_leaderboard.c`

**Sample run:**
```
Top scorer: Dee (1700)
Average score: 1280.00
Minimum level to check: 6
Players at level 6 or above: 2
```

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| `s1 == s2` to compare structs | Compilation error | Compare field by field |
| Forgetting `&` for struct scalar fields in `scanf` | Crash | `scanf("%d", &s.id)` |
| Using `&` for char array fields in `scanf` | Unnecessary but harmless (or wrong) | `scanf("%29s", s.name)` with no `&` for array fields |
| `printf("%s\n", &s.name)` | Extra `&` is noisy | Use `s.name` directly |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Contact book | `lab13_contacts.c` | 3 |
| Student records | `lab13_records.c` | 4 |
| Course grade book | `lab13_gradebook.c` | 3 |

**Total: 10 points**

---

## Further Reading

- King, Ch. 16 "Structures, Unions, and Enumerations"
- K&R, Ch. 6 "Structures"
- [Bonus: Dynamic Memory](../appendix/bonus/dynamic-memory.md)
