# Lab 11: Arrays I: One-Dimensional Arrays

| | |
|---|---|
| **Week** | 11 |
| **Duration** | 3 × 50 min (150 min) |
| **Method** | Lecture & Lab |
| **Prerequisites** | Lab 10 (functions, loops) |

**Why this lab matters:** Almost every meaningful program handles a collection of values: a list of exam scores, a series of temperature readings, a set of product prices. Without arrays, storing ten scores would require ten separate variable names; with an array, `int scores[10]` handles all ten at once and a loop processes them in two lines. Arrays are also the gateway to every data structure, such as strings, tables, and images, that you will meet in this and future courses.

**Time allocation**

| Part | Min | Activity |
|--------|-----|----------|
| A (Concept) | 50 | 5 recap · 30 array declaration, indexing, traversal · 15 live demo |
| B (Guided practice) | 50 | 40 guided stats lab · 10 debrief and pitfalls |
| C (Independent and wrap) | 50 | 35 independent exercises · 10 challenge · 5 submit and Week 12 preview and project announcement |

---

## Learning Outcomes

By the end of this lab, you will be able to:

1. Declare and initialize one-dimensional arrays.
2. Read and write array elements using index-based loops.
3. Implement common array operations: sum, average, minimum, maximum, linear search.
4. Explain why array indexing starts at 0 and what out-of-bounds access causes.
5. Recognize that a C string is a one-dimensional array of `char` ending in `'\0'`.
6. Put a one-dimensional array in order using bubble sort.
7. Read a step-by-step trace of a search or sort, and explain how binary search halves the range on a sorted array.

---

## Recap

Until now, your programs handled a fixed number of variables (`a`, `b`, `c`).
An array lets you store a **collection** of values of the same type
under one name and access them by position.

---

## Background

### What Is an Array?

> **In plain words: array**
> An array is a row of boxes in memory, all holding the same type, all sharing one name.
> You access each box by its position number, called the *index*.
> Think of a row of numbered lockers in a school corridor: all lockers have the same
> size (type), they are all in a row (contiguous memory), and you find any locker
> instantly by its number. Locker #0 is the first one, not locker #1.
>
> Without arrays, storing 100 exam scores would require 100 separate variable names.
> With an array: `int scores[100];` creates all 100 boxes at once.

> **In plain words: index**
> The *index* is the number you put inside the square brackets `[]` to pick one element.
> In C, arrays always start at index **0**, not 1. An array declared `int a[5]` has
> elements `a[0]`, `a[1]`, `a[2]`, `a[3]`, `a[4]`. The last valid index is always
> `size - 1`, which here is 4. Forgetting this and using `a[5]` is a very common bug.

> **In plain words: out-of-bounds access**
> Reading or writing `a[5]` when the array only has indices 0 to 4 is called an
> *out-of-bounds access*. The C compiler does NOT check for this automatically.
> The program reads (or writes) whatever bytes happen to be at that memory address,
> which could be another variable, a return address, or anything else. The result is
> unpredictable: the program might crash, produce garbage output, or appear to work
> fine until something worse happens. Always make sure your loop stops at `i < n`.

### Arrays as Contiguous Memory

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 580 160" style="max-width:560px;display:block;margin:1.5em auto;">
  <title>A one-dimensional array int a with 6 elements shown as contiguous boxes in memory. Each box is labeled with its index from 0 to 5, its value, and its memory address starting at 0x1000 incrementing by 4 bytes per element. The first element a[0] holds 34, then 17, 88, 5, 62, 41.</title>
  <defs>
    <marker id="arr-11" markerWidth="7" markerHeight="7" refX="5" refY="3" orient="auto">
      <path d="M0,0 L0,6 L7,3 z" fill="#0b3d66"/>
    </marker>
  </defs>
  <!-- Array label -->
  <text x="10" y="20" font-family="monospace" font-size="13" fill="#0b3d66" font-weight="bold">int a[6];</text>
  <!-- Boxes -->
  <rect x="10"  y="35" width="80" height="55" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="90"  y="35" width="80" height="55" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="170" y="35" width="80" height="55" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="250" y="35" width="80" height="55" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="330" y="35" width="80" height="55" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="410" y="35" width="80" height="55" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <!-- Out-of-bounds warning -->
  <rect x="490" y="35" width="80" height="55" rx="4" fill="#ffebee" stroke="#c62828" stroke-width="1.5" stroke-dasharray="5,3"/>
  <text x="530" y="60" font-family="sans-serif" font-size="9" fill="#c62828" text-anchor="middle">a[6]</text>
  <text x="530" y="72" font-family="sans-serif" font-size="9" fill="#c62828" text-anchor="middle">OUT OF</text>
  <text x="530" y="84" font-family="sans-serif" font-size="9" fill="#c62828" text-anchor="middle">BOUNDS!</text>
  <!-- Index labels -->
  <text x="50"  y="56" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">a[0]</text>
  <text x="130" y="56" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">a[1]</text>
  <text x="210" y="56" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">a[2]</text>
  <text x="290" y="56" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">a[3]</text>
  <text x="370" y="56" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">a[4]</text>
  <text x="450" y="56" font-family="monospace" font-size="12" fill="#0b3d66" text-anchor="middle" font-weight="bold">a[5]</text>
  <!-- Values -->
  <text x="50"  y="77" font-family="monospace" font-size="13" fill="#333" text-anchor="middle">34</text>
  <text x="130" y="77" font-family="monospace" font-size="13" fill="#333" text-anchor="middle">17</text>
  <text x="210" y="77" font-family="monospace" font-size="13" fill="#333" text-anchor="middle">88</text>
  <text x="290" y="77" font-family="monospace" font-size="13" fill="#333" text-anchor="middle">5</text>
  <text x="370" y="77" font-family="monospace" font-size="13" fill="#333" text-anchor="middle">62</text>
  <text x="450" y="77" font-family="monospace" font-size="13" fill="#333" text-anchor="middle">41</text>
  <!-- Address labels -->
  <text x="50"  y="100" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">0x1000</text>
  <text x="130" y="100" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">0x1004</text>
  <text x="210" y="100" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">0x1008</text>
  <text x="290" y="100" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">0x100C</text>
  <text x="370" y="100" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">0x1010</text>
  <text x="450" y="100" font-family="monospace" font-size="9" fill="#888" text-anchor="middle">0x1014</text>
  <!-- annotation -->
  <text x="10" y="125" font-family="sans-serif" font-size="10" fill="#555">Each element is 4 bytes (sizeof int). a[i] lives at address: start + i x 4.</text>
  <text x="10" y="143" font-family="sans-serif" font-size="10" fill="#c62828">a[6] reads random memory: the CPU does not check bounds for you!</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 11.1.</strong> A one-dimensional array in memory.</em></p>

### Declaring and Initializing Arrays

```c
int scores[5];                      /* uninitialized: values are garbage */
int primes[5] = {2, 3, 5, 7, 11};  /* initialized */
int zeros[10] = {0};                /* all elements set to 0 */
double data[] = {1.5, 2.5, 3.5};   /* compiler counts: size = 3 */
```

### Traversal with a Loop

```c
int a[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
    printf("a[%d] = %d\n", i, a[i]);
}
```

### Common Operations

```c
/* Sum and average */
int sum = 0;
for (int i = 0; i < n; i++) sum += a[i];
double avg = (double)sum / n;

/* Minimum */
int min = a[0];
for (int i = 1; i < n; i++)
    if (a[i] < min) min = a[i];

/* Linear search: returns index or -1 */
int search(int a[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (a[i] == target) return i;
    return -1;
}
```

### Arrays as Function Parameters

```c
void print_array(int a[], int n) {  /* array size is lost: pass n separately */
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
```

Always pass the **size** `n` as a separate parameter.

> **Under the Hood: contiguous memory**
>
> An array is a contiguous block of memory.
> `a[i]` is equivalent to `*(a + i)`: start of the array plus i times the element size.
> This is why `a[5]` in a 5-element array reads random memory: the CPU computes
> `start + 5 x 4 bytes` and fetches whatever bytes happen to be there.
> Out-of-bounds access is a very common source of crashes and security vulnerabilities.
> The computer does not check; you must.

### Strings: A First Look

Until now the arrays in your programs have held `int` or `double` values.
The same idea works with `char`: a 1-D array of characters.
C adds exactly one rule: the last real character must be followed by `'\0'`
(the null terminator, ASCII code 0), which marks where the text ends.

> **In plain words: string (first look)**
> A *string* in C is not a special type. It is a one-dimensional array of `char` with one
> rule: the last real character is followed by `'\0'` (the null terminator, ASCII 0), which
> marks "the text ends here." Because it is just an array, you index it like any other:
> `word[0]` is the first character. The full toolkit for strings (reading them, `strlen`,
> `strcpy`, `strcmp`, and arrays of strings) comes next week in Lab 12.

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 340 130" style="max-width:320px;display:block;margin:1.5em auto;">
  <title>The string Hi stored as a three-element char array. Cell index 0 holds the character H, cell 1 holds i, and cell 2 holds the null terminator backslash zero. A note reads three bytes: two letters plus the null terminator.</title>
  <text x="10" y="22" font-family="monospace" font-size="13" fill="#0b3d66" font-weight="bold">char word[] = "Hi";</text>
  <rect x="20"  y="34" width="60" height="50" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <rect x="80"  y="34" width="60" height="50" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="1.5"/>
  <rect x="140" y="34" width="60" height="50" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <text x="50"  y="65" font-family="monospace" font-size="16" fill="#2e7d32" text-anchor="middle">'H'</text>
  <text x="110" y="65" font-family="monospace" font-size="16" fill="#2e7d32" text-anchor="middle">'i'</text>
  <text x="170" y="65" font-family="monospace" font-size="14" fill="#c07000" text-anchor="middle" font-weight="bold">'\0'</text>
  <text x="50"  y="100" font-family="monospace" font-size="10" fill="#888" text-anchor="middle">[0]</text>
  <text x="110" y="100" font-family="monospace" font-size="10" fill="#888" text-anchor="middle">[1]</text>
  <text x="170" y="100" font-family="monospace" font-size="10" fill="#c07000" text-anchor="middle">[2]</text>
  <text x="20" y="120" font-family="sans-serif" font-size="10" fill="#555">3 bytes: 2 letters + the null terminator '\0'</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 11.2.</strong> A string is a one-dimensional char array ending in '\0'.</em></p>

Because a string is just a 1-D array, you can use it exactly like one:

```c
char word[] = "Hi";        /* a 1-D char array: 'H', 'i', '\0' */
printf("%s\n", word);      /* print the whole string: Hi        */
printf("%c\n", word[0]);   /* print one element:      H         */

for (int i = 0; word[i] != '\0'; i++)  /* walk it like any array */
    printf("%c ", word[i]);            /* H i                    */
printf("\n");
```

**Two rules to remember now:**
1. Index a string like any array: `word[0]` is the first character.
2. Always leave room for `'\0'`: a 5-letter word needs at least 6 bytes.

Full string coverage (reading strings, `<string.h>`, arrays of strings) is in
[Lab 12: Arrays II and Strings](lab12-arrays-2d-strings.md).

### Sorting: A First Look

Beyond *finding* a value (linear search above), another very common array task is
putting the values *in order*. The simplest method to learn first is bubble sort.

> **In plain words: sorting (bubble sort)**
> To *sort* an array is to rearrange its elements into order (smallest to largest here).
> The simplest method is *bubble sort*: walk left to right comparing each pair of
> neighbours, and swap them whenever they are out of order. After one full pass the
> largest value has "bubbled" to the end. Repeat over the shrinking front of the array
> until a pass makes no swaps. Bubble sort is slow on large arrays but easy to understand,
> which is why it is the first sort most people learn. Faster methods, and how to measure
> their speed (Big-O), come in a later Data Structures course.

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 360 170" style="max-width:340px;display:block;margin:1.5em auto;">
  <title>One pass of bubble sort on the array 5 2 4 1. Adjacent neighbours are compared and swapped when out of order. After the pass the largest value, 5, has moved to the last position, giving 2 4 1 5.</title>
  <text x="10" y="22" font-family="sans-serif" font-size="11" fill="#555">Compare neighbours; swap if out of order.</text>
  <!-- Before row -->
  <text x="10" y="62" font-family="sans-serif" font-size="11" fill="#0b3d66">Before:</text>
  <rect x="90"  y="40" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="145" y="40" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="200" y="40" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="255" y="40" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="115" y="66" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">5</text>
  <text x="170" y="66" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">2</text>
  <text x="225" y="66" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">4</text>
  <text x="280" y="66" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">1</text>
  <!-- swap annotation -->
  <text x="142" y="98" font-family="sans-serif" font-size="10" fill="#c07000" text-anchor="middle">5 &gt; 2 -&gt; swap</text>
  <!-- After row -->
  <text x="10" y="116" font-family="sans-serif" font-size="11" fill="#0b3d66">After 1 pass:</text>
  <rect x="90"  y="120" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="145" y="120" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="200" y="120" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="255" y="120" width="50" height="40" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <text x="115" y="146" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">2</text>
  <text x="170" y="146" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">4</text>
  <text x="225" y="146" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">1</text>
  <text x="280" y="146" font-family="monospace" font-size="16" fill="#c07000" text-anchor="middle" font-weight="bold">5</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 11.3.</strong> One pass of bubble sort moves the largest remaining value to the end.</em></p>

```c
/* Bubble sort: put a[0..n-1] in ascending order */
void bubble_sort(int a[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - 1 - pass; i++) {
            if (a[i] > a[i + 1]) {      /* out of order? swap the pair */
                int tmp  = a[i];
                a[i]     = a[i + 1];
                a[i + 1] = tmp;
            }
        }
    }
}
```

| Line | What it does |
|------|-------------|
| `for (int pass = 0; pass < n - 1; pass++)` | Outer loop: one pass per iteration. After each pass the next-largest value has settled at the end, so at most n-1 passes are needed for n elements. |
| `for (int i = 0; i < n - 1 - pass; i++)` | Inner loop: compare each neighbouring pair. The `- pass` shrinks the range each time because the last `pass` elements are already in their final place. |
| `if (a[i] > a[i + 1])` | If the left neighbour is bigger than the right one, they are out of order: swap them. |
| `int tmp = a[i]; a[i] = a[i+1]; a[i+1] = tmp;` | Classic three-step swap using a temporary variable. Writing `a[i] = a[i+1]; a[i+1] = a[i];` would overwrite `a[i]` before you copy it, so `tmp` is essential. |

**Trace of `bubble_sort` on `{5, 2, 4, 1}`:**

```
start:  5 2 4 1
pass 1: 2 4 1 5     (largest, 5, bubbles to the end)
pass 2: 2 1 4 5
pass 3: 1 2 4 5     (sorted)
```

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 320 250" style="max-width:310px;display:block;margin:1.5em auto;">
  <title>Full bubble sort showing four rows of boxes for array 5 2 4 1. Row labeled start shows 5 2 4 1 in plain blue boxes. Row labeled pass 1 shows 2 4 1 with 5 shaded amber at the end as settled in place. Row labeled pass 2 shows 2 1 with 4 and 5 both shaded amber as settled. Row labeled sorted shows 1 2 4 5 in green boxes indicating the array is fully sorted.</title>
  <!-- Row 1: start -->
  <text x="8" y="44" font-family="sans-serif" font-size="11" fill="#555">start:</text>
  <rect x="85"  y="20" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="143" y="20" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="201" y="20" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="259" y="20" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="110" y="46" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">5</text>
  <text x="168" y="46" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">2</text>
  <text x="226" y="46" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">4</text>
  <text x="284" y="46" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">1</text>
  <!-- Row 2: pass 1, 5 settles at end -->
  <text x="8" y="104" font-family="sans-serif" font-size="11" fill="#555">pass 1:</text>
  <rect x="85"  y="80" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="143" y="80" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="201" y="80" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="259" y="80" width="50" height="40" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <text x="110" y="106" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">2</text>
  <text x="168" y="106" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">4</text>
  <text x="226" y="106" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">1</text>
  <text x="284" y="106" font-family="monospace" font-size="18" fill="#c07000" text-anchor="middle" font-weight="bold">5</text>
  <!-- Row 3: pass 2, 4 and 5 settled -->
  <text x="8" y="164" font-family="sans-serif" font-size="11" fill="#555">pass 2:</text>
  <rect x="85"  y="140" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="143" y="140" width="50" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="201" y="140" width="50" height="40" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <rect x="259" y="140" width="50" height="40" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <text x="110" y="166" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">2</text>
  <text x="168" y="166" font-family="monospace" font-size="18" fill="#0b3d66" text-anchor="middle">1</text>
  <text x="226" y="166" font-family="monospace" font-size="18" fill="#c07000" text-anchor="middle" font-weight="bold">4</text>
  <text x="284" y="166" font-family="monospace" font-size="18" fill="#c07000" text-anchor="middle" font-weight="bold">5</text>
  <!-- Row 4: sorted, all green -->
  <text x="8" y="224" font-family="sans-serif" font-size="11" fill="#2e7d32" font-weight="bold">sorted:</text>
  <rect x="85"  y="200" width="50" height="40" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="2"/>
  <rect x="143" y="200" width="50" height="40" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="2"/>
  <rect x="201" y="200" width="50" height="40" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="2"/>
  <rect x="259" y="200" width="50" height="40" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="2"/>
  <text x="110" y="226" font-family="monospace" font-size="18" fill="#2e7d32" text-anchor="middle" font-weight="bold">1</text>
  <text x="168" y="226" font-family="monospace" font-size="18" fill="#2e7d32" text-anchor="middle" font-weight="bold">2</text>
  <text x="226" y="226" font-family="monospace" font-size="18" fill="#2e7d32" text-anchor="middle" font-weight="bold">4</text>
  <text x="284" y="226" font-family="monospace" font-size="18" fill="#2e7d32" text-anchor="middle" font-weight="bold">5</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 11.4.</strong> The full sort: each pass settles one more value at the right end (amber = settled in place, green = all done).</em></p>

You will use bubble sort to alphabetize names in
[Lab 12](lab12-arrays-2d-strings.md) and to rank student records in
[Lab 13](lab13-data-structures.md).

### Searching, Step by Step

The `search` function in Common Operations above checks each element one by one from left
to right. This is called **linear search**.

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 310 108" style="max-width:300px;display:block;margin:1.5em auto;">
  <title>Linear search scanning array 4 8 15 16 23 42 for target 16. Cells at indices 0 through 2 holding values 4, 8, and 15 are shaded amber indicating they were checked and did not match. A downward-pointing triangle marks index 3 holding value 16 which equals the target, shaded green as found. Cells at indices 4 and 5 are unshaded as not yet checked.</title>
  <text x="8" y="15" font-family="sans-serif" font-size="12" fill="#0b3d66" font-weight="bold">target = 16</text>
  <!-- Pointer triangle above the found cell (index 3, center x=180) -->
  <polygon points="180,37 173,25 187,25" fill="#2e7d32"/>
  <text x="180" y="21" font-family="sans-serif" font-size="10" fill="#2e7d32" text-anchor="middle" font-weight="bold">found!</text>
  <!-- Cells: 0-2 amber (miss), 3 green (found), 4-5 normal -->
  <rect x="15"  y="42" width="42" height="40" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <rect x="63"  y="42" width="42" height="40" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <rect x="111" y="42" width="42" height="40" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="1.5"/>
  <rect x="159" y="42" width="42" height="40" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="2"/>
  <rect x="207" y="42" width="42" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="255" y="42" width="42" height="40" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <!-- Values -->
  <text x="36"  y="67" font-family="monospace" font-size="16" fill="#c07000" text-anchor="middle">4</text>
  <text x="84"  y="67" font-family="monospace" font-size="16" fill="#c07000" text-anchor="middle">8</text>
  <text x="132" y="67" font-family="monospace" font-size="16" fill="#c07000" text-anchor="middle">15</text>
  <text x="180" y="67" font-family="monospace" font-size="16" fill="#2e7d32" text-anchor="middle" font-weight="bold">16</text>
  <text x="228" y="67" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">23</text>
  <text x="276" y="67" font-family="monospace" font-size="16" fill="#0b3d66" text-anchor="middle">42</text>
  <!-- Index labels -->
  <text x="36"  y="96" font-family="monospace" font-size="10" fill="#888" text-anchor="middle">i=0</text>
  <text x="84"  y="96" font-family="monospace" font-size="10" fill="#888" text-anchor="middle">i=1</text>
  <text x="132" y="96" font-family="monospace" font-size="10" fill="#888" text-anchor="middle">i=2</text>
  <text x="180" y="96" font-family="monospace" font-size="10" fill="#2e7d32" text-anchor="middle" font-weight="bold">i=3</text>
  <text x="228" y="96" font-family="monospace" font-size="10" fill="#888" text-anchor="middle">i=4</text>
  <text x="276" y="96" font-family="monospace" font-size="10" fill="#888" text-anchor="middle">i=5</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 11.5.</strong> Linear search scans left to right; amber = miss, green = found at i=3.</em></p>

Trace table for `search({4, 8, 15, 16, 23, 42}, 6, 16)`:

| step | `i` | `a[i]` | `a[i] == target`? | action |
|------|-----|--------|-------------------|--------|
| 1 | 0 | 4 | 4 == 16, no | continue |
| 2 | 1 | 8 | 8 == 16, no | continue |
| 3 | 2 | 15 | 15 == 16, no | continue |
| 4 | 3 | 16 | 16 == 16, yes | return 3 |

Linear search works on **any** array, sorted or not. In the worst case it checks every
element. If the array is already sorted, there is a faster method.

> **In plain words: binary search**
> On a **sorted** array you do not need to scan every element. Check the middle element
> first. If your target is smaller than the middle, discard the entire right half and
> search only the left half. If your target is larger, discard the left half and search
> the right. Repeat on what remains. Each step halves the live range, so finding a value
> in a 1000-element sorted array takes at most 10 comparisons instead of 1000. Binary
> search only works when the data is already sorted, which is one reason sorting matters.

<svg role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 365 220" style="max-width:350px;display:block;margin:1.5em auto;">
  <title>Binary search on sorted array 1 4 8 15 16 23 42 looking for target 16. Three steps shown with labels L for low, M for mid, H for high. Step 1 covers all seven elements with mid at index 3 holding value 15 which is less than 16 so the right half becomes the new range. Step 2 covers indices 4 through 6 with mid at index 5 holding value 23 which is greater than 16 so the left portion is selected. Step 3 finds the target at index 4 where value 16 equals the target shown in green. Cells outside the active range are greyed out.</title>
  <text x="255" y="14" font-family="sans-serif" font-size="11" fill="#0b3d66" font-weight="bold">target = 16</text>
  <!-- === STEP 1: low=0 mid=3 high=6 === -->
  <text x="5" y="58" font-family="sans-serif" font-size="11" fill="#555">step 1:</text>
  <text x="74"  y="26" font-family="monospace" font-size="10" fill="#2e7d32" text-anchor="middle" font-weight="bold">L</text>
  <text x="203" y="26" font-family="monospace" font-size="10" fill="#c07000" text-anchor="middle" font-weight="bold">M</text>
  <text x="332" y="26" font-family="monospace" font-size="10" fill="#c62828" text-anchor="middle" font-weight="bold">H</text>
  <rect x="55"  y="34" width="38" height="38" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="98"  y="34" width="38" height="38" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="141" y="34" width="38" height="38" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="184" y="34" width="38" height="38" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <rect x="227" y="34" width="38" height="38" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="270" y="34" width="38" height="38" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="313" y="34" width="38" height="38" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="74"  y="58" font-family="monospace" font-size="15" fill="#0b3d66" text-anchor="middle">1</text>
  <text x="117" y="58" font-family="monospace" font-size="15" fill="#0b3d66" text-anchor="middle">4</text>
  <text x="160" y="58" font-family="monospace" font-size="15" fill="#0b3d66" text-anchor="middle">8</text>
  <text x="203" y="58" font-family="monospace" font-size="15" fill="#c07000" text-anchor="middle" font-weight="bold">15</text>
  <text x="246" y="58" font-family="monospace" font-size="15" fill="#0b3d66" text-anchor="middle">16</text>
  <text x="289" y="58" font-family="monospace" font-size="15" fill="#0b3d66" text-anchor="middle">23</text>
  <text x="332" y="58" font-family="monospace" font-size="15" fill="#0b3d66" text-anchor="middle">42</text>
  <text x="203" y="80" font-family="sans-serif" font-size="9" fill="#c07000" text-anchor="middle">15 &lt; 16: search right half</text>
  <!-- === STEP 2: low=4 mid=5 high=6 === -->
  <text x="5" y="124" font-family="sans-serif" font-size="11" fill="#555">step 2:</text>
  <text x="246" y="92" font-family="monospace" font-size="10" fill="#2e7d32" text-anchor="middle" font-weight="bold">L</text>
  <text x="289" y="92" font-family="monospace" font-size="10" fill="#c07000" text-anchor="middle" font-weight="bold">M</text>
  <text x="332" y="92" font-family="monospace" font-size="10" fill="#c62828" text-anchor="middle" font-weight="bold">H</text>
  <rect x="55"  y="100" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="98"  y="100" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="141" y="100" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="184" y="100" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="227" y="100" width="38" height="38" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <rect x="270" y="100" width="38" height="38" rx="4" fill="#fff8e6" stroke="#c07000" stroke-width="2"/>
  <rect x="313" y="100" width="38" height="38" rx="4" fill="#eef4fa" stroke="#0b3d66" stroke-width="1.5"/>
  <text x="74"  y="124" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">1</text>
  <text x="117" y="124" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">4</text>
  <text x="160" y="124" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">8</text>
  <text x="203" y="124" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">15</text>
  <text x="246" y="124" font-family="monospace" font-size="15" fill="#0b3d66" text-anchor="middle">16</text>
  <text x="289" y="124" font-family="monospace" font-size="15" fill="#c07000" text-anchor="middle" font-weight="bold">23</text>
  <text x="332" y="124" font-family="monospace" font-size="15" fill="#0b3d66" text-anchor="middle">42</text>
  <text x="289" y="146" font-family="sans-serif" font-size="9" fill="#c07000" text-anchor="middle">23 &gt; 16: search left half</text>
  <!-- === STEP 3: low=mid=high=4, found === -->
  <text x="5" y="190" font-family="sans-serif" font-size="11" fill="#2e7d32" font-weight="bold">found:</text>
  <text x="246" y="158" font-family="monospace" font-size="10" fill="#2e7d32" text-anchor="middle" font-weight="bold">L=M=H</text>
  <rect x="55"  y="166" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="98"  y="166" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="141" y="166" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="184" y="166" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="227" y="166" width="38" height="38" rx="4" fill="#e8f5e9" stroke="#2e7d32" stroke-width="2"/>
  <rect x="270" y="166" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <rect x="313" y="166" width="38" height="38" rx="4" fill="#f5f5f5" stroke="#cccccc" stroke-width="1"/>
  <text x="74"  y="190" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">1</text>
  <text x="117" y="190" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">4</text>
  <text x="160" y="190" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">8</text>
  <text x="203" y="190" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">15</text>
  <text x="246" y="190" font-family="monospace" font-size="15" fill="#2e7d32" text-anchor="middle" font-weight="bold">16</text>
  <text x="289" y="190" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">23</text>
  <text x="332" y="190" font-family="monospace" font-size="15" fill="#bbbbbb" text-anchor="middle">42</text>
</svg>

<p style="text-align:center;font-size:0.9em;color:#555;margin-top:-0.6em;"><em><strong>Figure 11.6.</strong> Binary search on a sorted array: each step halves the live range (grey = eliminated, amber = current mid, green = found). Requires a sorted array.</em></p>

```c
/* Binary search: requires a sorted array. Returns index or -1. */
int binary_search(int a[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target)  low  = mid + 1;
        else                  high = mid - 1;
    }
    return -1;  /* not found */
}
```

This is a preview. Deeper analysis of search and sort efficiency (Big-O notation) is in the
[Data Structures and Algorithms references](../appendix/references.md).

For a step-by-step method to trace these algorithms yourself, see
[Reading and Tracing a Program](../appendix/tracing-a-program.md).

---

## Worked Examples

### Example 1: Statistics on an array

```c
/* lab11_stats.c (outline) */
#include <stdio.h>
#define N 8

int main(void) {
    int a[N] = {34, 17, 88, 5, 62, 41, 99, 23};
    int sum = 0, min = a[0], max = a[0];

    for (int i = 0; i < N; i++) {
        sum += a[i];
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }

    printf("Sum: %d\n", sum);
    printf("Avg: %.2f\n", (double)sum / N);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    return 0;
}
```

### Line by line

| Line | What it does |
|------|-------------|
| `#define N 8` | A named constant. Every occurrence of `N` in the file will be replaced by `8` before compiling. Using `N` everywhere means you change the size in one place and the rest updates automatically. |
| `int a[N] = {34, 17, 88, 5, 62, 41, 99, 23};` | Declares an array of 8 integers and fills it with specific values at the same time. `a[0]` is 34, `a[1]` is 17, and so on. |
| `int sum = 0, min = a[0], max = a[0];` | Start sum at 0 (nothing accumulated yet). Start both min and max at `a[0]`, the first element. This is a standard pattern: assume the first element is both smallest and largest until proven otherwise. |
| `for (int i = 0; i < N; i++)` | Loop from index 0 to index 7 (N-1). We use `i < N`, not `i <= N`, because the last valid index is N-1. |
| `sum += a[i];` | Add the current element to the running total. After the loop, `sum` holds the total of all 8 values. |
| `if (a[i] < min) min = a[i];` | If this element is smaller than the current minimum, update `min`. After the loop, `min` holds the smallest value seen. |
| `if (a[i] > max) max = a[i];` | Same logic for maximum. |
| `printf("Avg: %.2f\n", (double)sum / N);` | Cast `sum` to `double` before dividing. Without the cast, `sum / N` would be integer division and drop the decimal part. |

**Expected output:**
```
Sum: 369
Avg: 46.13
Min: 5
Max: 99
```

### Example 2: Reversing an array

```c
/* Swap a[i] and a[n-1-i] for i = 0 to n/2-1 */
void reverse(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmp;
    }
}
```

---

## Guided In-Lab Exercises

### Exercise 1: Read and summarize (Part B)

Write a program that:
1. Reads N (max 20) integers from the user.
2. Prints sum, average, min, max.
3. Counts how many values are above the average.

File: `lab11_stats.c`

### Exercise 2: Linear search (Part B and C)

Write a function `int search(int a[], int n, int target)`.
Read an array of 10 integers, then repeatedly prompt "Search for: "
until the user enters -1. Print the index if found or "Not found".

File: `lab11_search.c`

### Exercise 3: Rotate left (Part C)

Write a function `void rotate_left(int a[], int n)` that shifts each element
one position to the left, wrapping the first element to the end.
For example: `{1, 2, 3, 4, 5}` becomes `{2, 3, 4, 5, 1}`.

File: `lab11_rotate.c`

---

## Challenge Problem

Write a function that checks whether an array is a **palindrome**
(reads the same forwards and backwards). Return 1 if yes, 0 if no.

File: `lab11_palindrome.c`

---

## Practice Problems

These are ungraded: extra practice for the concepts in this lab. Solutions are not distributed with this page.

### Practice 1: Class attendance counter

Write a program that stores 10 days of attendance for one student in an array of `int`
(1 = present, 0 = absent), prints a day-by-day report ("Day 1: Present", etc.), and
uses a function `int count_present(int attendance[], int n)` to count and print the
total number of present days.

File: `lab11_practice1_attendance.c`

Sample run:
```
Day 1: Present
Day 2: Present
Day 3: Absent
Day 4: Present
Day 5: Present
Day 6: Present
Day 7: Absent
Day 8: Present
Day 9: Present
Day 10: Present
Total present days: 8
```

### Practice 2: Highest temperature day finder

Write a program that stores a week of daily temperatures in an array of `double`,
prints each day's reading, and uses a function `int index_of_max(double a[], int n)` to
find and report which day had the highest temperature.

File: `lab11_practice2_hottemp.c`

Sample run:
```
Day 1: 68.5
Day 2: 72.0
Day 3: 75.3
Day 4: 90.1
Day 5: 81.4
Day 6: 77.7
Day 7: 74.2
Highest temperature: 90.1 on Day 4
```

### Practice 3: Dice roll frequency counter

Write a function `int count_occurrences(int a[], int n, int target)`. Using a fixed
array of 12 dice roll results, prompt the user for a value from 1 to 6 and print how
many times that value appears in the array.

File: `lab11_practice3_dice.c`

Sample run:
```
Enter the value to count (1-6): 5
The value 5 appears 5 times.
```

### Practice 4: Daily sales excluding refunds

Write a function `double net_sales(double a[], int n)` that sums only the non-negative
entries of a sales array (negative entries represent refunds) and a function
`int count_refunds(double a[], int n)` that counts the negative entries. Test both on a
fixed array of 8 sales entries.

File: `lab11_practice4_sales.c`

Sample run:
```
Net sales (excluding refunds): 326.85
Number of refunds: 3
```

### Practice 5: Runner-up score finder

Write a function `int find_highest(int a[], int n)` and a function
`int find_runner_up(int a[], int n, int highest)` that finds the largest value strictly
less than `highest` (so a duplicate of the highest score is skipped). Test both on a
fixed array of 6 scores that contains a tie for first place.

File: `lab11_practice5_runnerup.c`

Sample run:
```
Highest score: 95
Runner-up score: 91
```

### Practice 6: Sort ticket prices ascending

Write a function `void bubble_sort_prices(double a[], int n)` that sorts an array of
concert ticket prices into ascending order using bubble sort. Print the array before
and after sorting.

File: `lab11_practice6_tickets.c`

Sample run:
```
Before sorting: 49.99 12.50 75.00 8.25 33.10 60.00 
After sorting: 8.25 12.50 33.10 49.99 60.00 75.00 
```

### Practice 7: Sorted locker number finder

Write a function `int binary_search_verbose(int a[], int n, int target)` that performs
binary search on a sorted array of 8 locker numbers, printing the index and value it
checks at every step, and returns the index of `target` or -1 if not found. Search for
two different locker numbers: one that exists and one that does not.

File: `lab11_practice7_lockers.c`

Sample run:
```
Searching for locker 124:
Step 1: checking index 3 (value 118)
Step 2: checking index 5 (value 130)
Step 3: checking index 4 (value 124)
Locker 124 found at index 4.

Searching for locker 115:
Step 1: checking index 3 (value 118)
Step 2: checking index 1 (value 105)
Step 3: checking index 2 (value 110)
Locker 115 not found.
```

---

## Common Pitfalls

| Mistake | Symptom | Fix |
|---------|---------|-----|
| Off-by-one: `i <= n` instead of `i < n` | Read/write past end of array (crash or garbage) | Use `i < n`; array indices are 0 to n-1 |
| Accessing uninitialized array | Garbage values | Always initialize or fill with `scanf`/assignment before reading |
| Forgetting to pass size to a function | Wrong results; potential out-of-bounds | Pass `n` as a separate parameter |
| `a = b` to copy arrays | Compilation error | Copy element by element with a loop |

---

## Submission and Rubric

| Deliverable | Filename | Points |
|-------------|----------|--------|
| Read and summarize | `lab11_stats.c` | 4 |
| Linear search | `lab11_search.c` | 3 |
| Rotate left | `lab11_rotate.c` | 3 |

**Total: 10 points**

> **Project assignment:** The take-home individual project will be described in class this week.
> It is due at the **end of Week 14**. Details and tiered options in [Lab 14](lab14-debugging-project.md).

---

## Further Reading

- King, Ch. 8 "Arrays"
- King, Ch. 13 "Strings" (first look; full coverage in Lab 12)
- Bubble sort and faster sorting algorithms / Big-O: see the [Data Structures &amp; Algorithms references](../appendix/references.md)
- K&R, Ch. 5 "Pointers and Arrays" §5.1 to §5.3
- [Reading and Tracing a Program](../appendix/tracing-a-program.md) - the trace-table method for following a search or sort step by step
