#include <stdio.h>

int invert(int, int, int);

int main() {
    int result;
    int x = 0b11010111;
    int p = 5, n = 3;

    result = invert(x, p, n);

    printf("%d\n", result);
}

int invert(int x, int p, int n) {
    return x ^ (~(~0 << (p + 1))) >> (p+1-n) << (p+1-n);
}