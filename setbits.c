#include <stdio.h>

int setbits(int, int, int, int);

int main() {
    int result;

    result = setbits(0b11111111, 5, 3, 0b01010101);

    printf("%d\n", result);
}

int setbits(int x, int p, int n, int y) {
    return (x & ~((~(~0 << (p + 1))) >> (p+1-n) << (p+1-n))) | ((y & ~(~0 << (p+1-n))) << (p+1-n));
}