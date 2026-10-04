# Lab 02: Program Structure and Basic I/O - Problems (Guided Exercises and Challenge)

## Exercise 1: Your name card

Write a program that prints a name card in this format:

```
+---------------------------+
| Name : [your name]        |
| ID   : [your student ID]  |
| Lab  : Computer Prog. I   |
+---------------------------+
```

File: `lab02_card.c`

## Exercise 2: Break it and read the error

Take your `lab02_card.c` and:

1. Remove the semicolon from one line. Compile. Read the error. Put it back.
2. Remove the `#include <stdio.h>` line. Compile. Read the error. Put it back.
3. Change `main` to `Main`. Compile. Read the error. Put it back.
   (This demos case sensitivity: `Main` and `main` are different names to C.)

For each case, write a comment at the top of your file recording what the
error message said.

## Exercise 3: ASCII banner

Write a program that prints a simple ASCII banner of your choice
(for example, your initials drawn with `*` characters) using `printf`.
Use at least 5 `printf` calls and at least one escape sequence other than `\n`.

File: `lab02_banner.c`

## Challenge Problem: 5-times table

Write a program that prints a multiplication table for the 5-times table:

```
5 x 1 = 5
5 x 2 = 10
...
5 x 10 = 50
```

Write out all 10 `printf` calls by hand (loops arrive in Week 6).

File: `lab02_challenge_times_table.c`

## Practice Problems

These are ungraded - extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Bus ticket stub

Write a program that prints a fixed bus ticket stub inside an ASCII box using
`printf`, showing a route, a seat number, and a price. Everything is
hard-coded text and numbers; you do not need variables or input yet.

File: `lab02_practice1_ticket.c`

Sample run:
```
*****************************
*        BUS TICKET         *
*****************************
* Route: Seoul -> Busan     *
* Seat : 14A                *
* Price: 59000 KRW          *
*****************************
```

### Practice 2: Launch countdown

Write a program that prints a rocket-launch countdown, one line per `printf`
call, counting down from 5 to "Liftoff!". Use a separate `printf` for every
line.

File: `lab02_practice2_countdown.c`

Sample run:
```
Launch sequence starting...
5...
4...
3...
2...
1...
Liftoff!
```

### Practice 3: Weekly study timetable

Write a program that prints a two-column weekly study timetable (day and
subject) using the `\t` escape sequence to line up the columns. Include a
header row and one row for each weekday.

File: `lab02_practice3_timetable.c`

Sample run:
```
Day	Subject
Mon	Math
Tue	Physics
```
(five weekday rows total)

### Practice 4: Grocery receipt header

Write a program that prints a small fixed grocery receipt: a shop-name
header line, three hard-coded item/price lines, a separator line, and a
closing "thank you" message. No computation is required yet; every value is
a literal you type directly into the `printf` calls.

File: `lab02_practice4_receipt.c`

Sample run:
```
===== CORNER GROCERY =====
Bread        2500
Milk         3200
Eggs         4100
===========================
Thank you for shopping!
```

### Practice 5: ASCII postcard

Write a program that draws a small ASCII picture (for example, a house)
using at least five `printf` calls, including at least one escape sequence
other than `\n` (such as `\t`) somewhere in the drawing.

File: `lab02_practice5_postcard.c`

Sample run:
```
    /\
   /  \
  /____\
  |    |
  |[]  |	Greetings from my house!
  |____|
```

### Practice 6: Cafe menu board

Write a program that prints a boxed cafe menu with a title, a header row,
four tab-aligned item/price rows, and a closing message, using ten `printf`
calls written out by hand (loops arrive in Week 6).

File: `lab02_practice6_menu.c`

Sample run:
```
+-----------------------------+
|         CAFE MENU           |
+-----------------------------+
| Item		Price (KRW)     |
| Coffee	3000            |
```
(plus Tea, Sandwich, and Cake rows, then a closing border and message)

### Practice 7: Escape sequence notice board

Write a program that prints a short "notice board" announcement that must
include, somewhere in its output: a literal backslash (as part of a file
path), a literal double quote (around a short quoted phrase), and at least
one tab character used to separate words on a line.

File: `lab02_practice7_notice.c`

Sample run:
```
NOTICE BOARD
Backup path: C:\Lab02\backup
Today's quote: "Practice makes progress."
Office	hours	are	9-5.
```
