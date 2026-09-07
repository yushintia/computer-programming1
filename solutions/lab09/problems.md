# Lab 09: Functions I - Basics - Guided Exercises and Challenge

Prompts only, adapted from the lab text. See `answer-key/` for reference solutions.

## Guided In-Lab Exercises

### Exercise 1: Extend the math library

Add these functions to the mini math library example (which already provides
`max`, `min`, and `is_prime`):
- `int gcd(int a, int b)` - greatest common divisor using Euclid's algorithm.
- `double power(double base, int exp)` - base raised to the integer exponent,
  without `<math.h>`.

Test each function from `main` with at least two inputs.

File: `lab09_mathlib.c`

### Exercise 2: Input validator as a function

Write a function `int read_positive(void)` that:
1. Prompts "Enter a positive integer: "
2. Reads an integer
3. If it is 0 or negative, prints "Invalid, try again." and loops
4. Returns the valid positive integer

Use this function from `main` to read two values, then print their sum.

File: `lab09_validator.c`

### Exercise 3: Modular grade printer

Write three functions:
- `double read_score(const char* label)` prints `label`, reads a double 0 to 100.
- `char grade_letter(double score)` returns the letter grade ('A' to 'F').
- `void print_report(double s1, double s2, double s3)` prints each score with
  its grade and the average.

File: `lab09_grades.c`

## Challenge Problem

Write a function `int count_digits(int n)` that counts how many digits the
integer `n` has.
Write a function `int reverse_num(int n)` that reverses the digits of `n`.
Test both with several inputs including 0 and negative numbers.

File: `lab09_digits.c`

## Practice Problems

These are ungraded — extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Road trip distance converter

Write two functions that convert between kilometers and miles for a road trip planner:
`double km_to_miles(double km)` and `double miles_to_km(double miles)`. Test each
function with at least two distances and print the results with two decimal places.

File: `lab09_practice1_distance.c`

Sample run:
```
10.0 km = 6.21 miles
100.0 km = 62.14 miles
50.0 miles = 80.47 km
26.2 miles = 42.16 km
```

### Practice 2: Square and cube reporter

Write two functions `int square(int n)` and `int cube(int n)` that return the square and
cube of an integer. Call both functions from `main` for at least three different
integers, including a negative one, and print the results.

File: `lab09_practice2_squarecube.c`

Sample run:
```
square(3) = 9, cube(3) = 27
square(5) = 25, cube(5) = 125
square(-2) = 4, cube(-2) = -8
```

### Practice 3: Triangular garden plot calculator

Write `double triangle_area(double base, double height)` and
`double triangle_perimeter(double side_a, double side_b, double side_c)` for a
landscaper laying out triangular garden plots. Test both functions on two different
plots and print the area and perimeter for each, with two decimal places.

File: `lab09_practice3_triangle.c`

Sample run:
```
Plot 1: area = 24.00 (base 6.0, height 8.0)
Plot 1: perimeter = 24.00 (sides 6.0, 8.0, 10.0)
Plot 2: area = 54.00 (base 9.0, height 12.0)
Plot 2: perimeter = 36.00 (sides 9.0, 12.0, 15.0)
```

### Practice 4: Book reading pace estimator

Write `double pages_per_day(int total_pages, int days)` that computes a reader's average
pace, and `int days_to_finish(int total_pages, double pace)` that computes how many
whole days are needed to finish a book at a given pace, rounding any partial day up.
Test both functions with at least two scenarios.

File: `lab09_practice4_reading.c`

Sample run:
```
pages_per_day(300, 10) = 30.0 pages/day
days_to_finish(300, 30.0) = 10 days
days_to_finish(250, 40.0) = 7 days
```

### Practice 5: Parking garage fee calculator

Write `double parking_fee(int hours)` for a parking garage that charges a flat rate for
the first hour, an hourly rate for each additional hour, and never charges more than a
fixed daily maximum. Test the function with a short stay, a medium stay, and a stay long
enough to hit the maximum.

File: `lab09_practice5_parking.c`

Sample run:
```
parking_fee(1) = 5.00
parking_fee(4) = 11.00
parking_fee(10) = 20.00
```

### Practice 6: Recipe ingredient scaler

Write `double scaled_liquid(double base_amount, int base_servings, int target_servings)`
to scale a liquid ingredient to a new serving size, and
`int scaled_whole_items(int base_amount, int base_servings, int target_servings)` to
scale a whole-count ingredient (such as eggs), rounding to the nearest whole number.
Test both functions by scaling a 4-serving recipe up to two different serving sizes.

File: `lab09_practice6_recipe.c`

Sample run:
```
Scaling recipe from 4 to 6 servings:
Milk: 3.00 cups
Eggs: 5

Scaling recipe from 4 to 10 servings:
Milk: 5.00 cups
Eggs: 8
```

### Practice 7: Clock hour advancer

Write `int advance_hour(int start_hour, int hours_to_add)` that advances an hour on a
12-hour clock (hours numbered 1 to 12), wrapping from 12 back to 1. Support negative
shifts too, so the function can also rewind the clock, wrapping from 1 back to 12. Test
it with a shift that wraps forward, one that lands exactly on 12, and one negative
shift.

File: `lab09_practice7_clock.c`

Sample run:
```
advance_hour(10, 5) = 3
advance_hour(11, 3) = 2
advance_hour(5, -7) = 10
```
