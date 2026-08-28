# Reading and Tracing a Program

Understanding a program is really two skills working together: *reading* it (what does each line say?) and *tracing* it (what does it actually do when the CPU runs it?). Reading gets you the grammar. Tracing gets you the meaning.

This page teaches tracing, the skill that lets you answer "what will this program print?" without running it, and "where is the bug?" without guessing.

---

## What Is Tracing?

> **In plain words: tracing / desk checking**
> *Tracing* (also called *desk checking*) means pretending to be the computer: walk
> through the program one line at a time and write down the value of each variable after
> each step, so you can see what the code *actually* does rather than what you assume it
> does. You do this on paper (or a notepad), either before running the program to predict
> its output, or after, to find where a value first goes wrong.
>
> The name "desk checking" comes from the era before personal computers, when programmers
> traced programs by hand at their desks before any machine was available. The technique
> is just as useful today: a five-minute trace often finds a bug faster than an hour of
> trial-and-error editing and re-running.

---

## The Trace Table

The standard tool for tracing is a **trace table**: a grid with one column per variable (plus one column for any output), and one row per significant step or loop iteration.

**How to fill it in:**

1. Write the variable names as column headers.
2. Add a column for any condition that controls the loop, and one for any output.
3. Fill in the initial values before the loop starts.
4. For each iteration, work across the row: evaluate the condition first, apply the body statements in order, then write the new values.
5. Stop when the condition becomes false (loop exits) or when `return` is reached.

The value in any cell is the value of that variable *after* the step on that row completes.

---

## Worked Example 1: a Counting Loop

Code from Lab 06:

```c
int n = 4, sum = 0, i = 1;
while (i <= n) {
    sum += i;
    i++;
}
printf("Sum = %d\n", sum);
```

Trace with `n = 4`:

| iteration | `i` | `i <= n`? | `sum` | action |
|-----------|-----|-----------|-------|--------|
| (start) | 1 | 1 <= 4, yes | 0 | enter loop |
| 1 | 1 | yes | 0 + 1 = 1 | i becomes 2 |
| 2 | 2 | yes | 1 + 2 = 3 | i becomes 3 |
| 3 | 3 | yes | 3 + 3 = 6 | i becomes 4 |
| 4 | 4 | yes | 6 + 4 = 10 | i becomes 5 |
| (exit) | 5 | 5 <= 4, no | 10 | loop exits |

**Output:** `Sum = 10`

Notice how the `sum` column builds up one piece at a time, and the loop exits the first time `i` exceeds `n`. The trace makes the accumulation pattern visible, something the code alone does not show as clearly.

---

## Worked Example 2: Linear Search

Code from Lab 11:

```c
int search(int a[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (a[i] == target) return i;
    return -1;
}
```

Trace with `a = {4, 8, 15, 16, 23, 42}`, `n = 6`, `target = 16`:

| step | `i` | `a[i]` | `a[i] == target`? | action |
|------|-----|--------|-------------------|--------|
| 1 | 0 | 4 | 4 == 16, no | continue |
| 2 | 1 | 8 | 8 == 16, no | continue |
| 3 | 2 | 15 | 15 == 16, no | continue |
| 4 | 3 | 16 | 16 == 16, yes | return 3 |

**Result:** the function returns `3`, the index where `target` was found.

This matches Figure 11.5 in [Lab 11](../labs/lab11-arrays-1d.md), which shows the same scan as a diagram.

---

## Tips: How to Understand How a Program Works

1. **Read the whole program once before tracing.** Skim it to find the input, the output, and the main loop. Know the overall shape before filling in values row by row.
2. **Follow one variable at a time.** When the code changes `sum`, update only the `sum` column. Resist the urge to jump ahead.
3. **Always trace the first iteration and the last.** Off-by-one bugs (using `<` when you need `<=`, or starting at `0` when you should start at `1`) hide in those two rows more than anywhere else.
4. **When a value surprises you, confirm with `printf`-tracing.** Insert `printf("DEBUG: i=%d, sum=%d\n", i, sum);` inside the loop to let the computer show you the values directly. See [Debugging Tips](debugging-tips.md).
5. **If the branching is complex, sketch a flowchart first.** Map the `if`/`else` paths before tracing values. See [Pseudocode and Flowcharts](pseudocode-flowchart.md).
6. **Finish the trace even when you spot a bug mid-way.** The row where a value first goes wrong is the row that contains the bug, so keep going to confirm.

---

## See Also

- [Lab 06: Loops](../labs/lab06-loops-while.md) - `printf`-tracing technique and the loop debugging moment
- [Lab 11: Arrays](../labs/lab11-arrays-1d.md) - step-by-step diagrams of linear and binary search
- [Lab 14: Debugging](../labs/lab14-debugging-project.md) - the "Tracing an Unfamiliar Program" exercise
- [Pseudocode and Flowcharts](pseudocode-flowchart.md) - visualizing control flow before tracing values
- [Debugging Tips and Common Errors](debugging-tips.md) - `printf`-tracing recipe and debugging checklist
