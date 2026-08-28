# Bonus: Bitwise Operators

> **This is optional enrichment**, beyond the CS1 curriculum.
> Bitwise operators are not assessed in this course.
> They are introduced here for students who are curious, and because they appear in Week 4's
> optional demo and in System Programming.

---

## What Are Bitwise Operators?

All data in a computer is stored as **bits** (0s and 1s).
Bitwise operators work directly on the individual bits of an integer value.

| Operator | Name | Example |
|----------|------|---------|
| `&` | AND | `5 & 3` → `1` |
| `\|` | OR | `5 \| 3` → `7` |
| `^` | XOR | `5 ^ 3` → `6` |
| `~` | NOT (complement) | `~5` → `-6` |
| `<<` | Left shift | `5 << 1` → `10` |
| `>>` | Right shift | `5 >> 1` → `2` |

---

## Bit-Level Arithmetic

```
5 in binary:  0000 0101
3 in binary:  0000 0011

5 & 3:        0000 0001  = 1   (AND: 1 only where both are 1)
5 | 3:        0000 0111  = 7   (OR:  1 where either is 1)
5 ^ 3:        0000 0110  = 6   (XOR: 1 where exactly one is 1)
~5:           1111 1010  = -6  (flip all bits; two's complement)
5 << 1:       0000 1010  = 10  (shift left = multiply by 2)
5 >> 1:       0000 0010  = 2   (shift right = divide by 2, integer)
```

---

## Practical Uses

### Check if a number is even or odd

```c
if (n & 1) printf("odd\n");
else       printf("even\n");
```

`n & 1` isolates the last bit; if it is 1, the number is odd.

### Toggle a bit (flip bit k)

```c
int mask = 1 << k;   /* bit k is 1, rest are 0 */
x = x ^ mask;        /* flip bit k of x */
```

### Set a bit

```c
x = x | (1 << k);   /* force bit k to 1 */
```

### Clear a bit

```c
x = x & ~(1 << k);  /* force bit k to 0 */
```

---

## Where You Will See This Again

- **System Programming:** flags passed to `open()`, `chmod()`, `ioctl()` are bit fields.
- **Embedded systems:** controlling hardware registers at the bit level.
- **Network programming:** IP masks, protocol flags.
- **Cryptography:** XOR is a fundamental building block.

---

## A Small Demo Program

```c
/* bitwise_demo.c */
#include <stdio.h>

void print_bits(unsigned int x) {
    for (int i = 7; i >= 0; i--)
        printf("%d", (x >> i) & 1);
    printf("\n");
}

int main(void) {
    unsigned int a = 5, b = 3;
    printf("a       = "); print_bits(a);
    printf("b       = "); print_bits(b);
    printf("a & b   = "); print_bits(a & b);
    printf("a | b   = "); print_bits(a | b);
    printf("a ^ b   = "); print_bits(a ^ b);
    printf("a << 1  = "); print_bits(a << 1);
    return 0;
}
```
