# Lab 13: Basic Data Structures

Adapted from the Lab 13 lab page. These are the problem statements only.
Solutions are not distributed with this page.

## Guided In-Lab Exercises

### Exercise 1: Contact book

Define a `struct Contact` with name, phone (string), and email (string).
Create an array of 3 contacts, read them from the user, then print a
formatted table.

File: `lab13_contacts.c`

### Exercise 2: Records program

Implement the Student roster from the worked example.
Add a function that computes the class average score.

File: `lab13_records.c`

### Exercise 3: Course grade book

Define a `typedef struct` named `Course` with a `char name[20]`, an `int credits`, and a
`double grade_points` (for example 4.0 for an A, or 3.5 for a B+). Read 4 courses into an
array, then write:
- `double weighted_gpa(Course c[], int n)`: returns the sum of `credits * grade_points`
  divided by the total credits.
- `Course most_credits(Course c[], int n)`: returns a copy of the course with the most credits.

Print the weighted GPA with 2 decimal places, then print the name and credits of the course
returned by `most_credits`.

File: `lab13_gradebook.c`

## Challenge Problem

Add a function `void sort_by_score(Student r[], int n)` that sorts the
roster in descending order of score using bubble sort.
Print the sorted roster.

File: `lab13_sort_challenge.c`

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

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Contact book | `lab13_contacts.c` | 4 |
| Student records | `lab13_records.c` | 6 |

**Total: 10 points**
