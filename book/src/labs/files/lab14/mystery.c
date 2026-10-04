/* mystery.c: read an integer and print mystery(n) */
#include <stdio.h>

int mystery(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    printf("%d\n", mystery(n));
    return 0;
}
