#include <stdio.h>
#include <math.h>

#define MAXLENGTH 5000

void read_line(char[]);

int main() {
    char line[MAXLENGTH];
    // read_line(line);

    // printf("%d\n", ~077);
    long res = -2147483659;// - 1;
    print_binary(res);
    printf("%ld\n", res);
    return 0;

}

void print_binary(int x) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

// 00000010
// 11111110
// &
// 00000010
// ~
// 10111111

void read_line(char line[]) {
    int i;
    char c;
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] == '\n';
        ++i;
    }

    line[i] = '\0';
}