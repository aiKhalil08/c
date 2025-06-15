#include <stdio.h>

int rotate(int, int);
int number_of_bits(int);
int extract_bits(int, int, int);

int main() {
    int result;
    int x = 0b10101010;
    int n = 2;

    result = rotate(x, n);

    printf("%d\n", result);
}

int rotate(int x, int n) {
    int rightmost_n_bits = extract_bits(x, n - 1, n);
    int y = number_of_bits(x);
    return (x >> n) | (rightmost_n_bits << (y - n));
}

int number_of_bits(int x) {
    int count = 0;
    while (x != 0) {
        count++;
        x >>= 1;
    }
    return count;
}

int extract_bits(int x, int p, int n) {
    int mask = ~(~0 << (p+1)) >> (p-n+1) << (p-n+1);
    return x & mask;
}