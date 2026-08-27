# Lab 13: Basic Data Structures — Problem Set

Adapted from `src/labs/lab13-data-structures.md`. These are the problem
statements only; see `answer-key/` for reference solutions.

## Guided In-Lab Exercises

### Exercise 1: Contact book

Define a `struct Contact` with name, phone (string), and email (string).
Create an array of 3 contacts, read them from the user, then print a
formatted table.

File: `lab13_contacts.c`

### Exercise 2: Records program

Implement the Student roster from the worked example (an `id`, `name`, and
`score` per student, read into an array of structs, printed as a formatted
table, with a function that finds the top-scoring student).
Add a function that computes the class average score.

File: `lab13_records.c`

## Challenge Problem

Add a function `void sort_by_score(Student r[], int n)` that sorts the
roster in descending order of score using bubble sort.
Print the sorted roster.

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Contact book | `lab13_contacts.c` | 4 |
| Student records | `lab13_records.c` | 6 |

**Total: 10 points**
