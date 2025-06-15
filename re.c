#include <stdio.h>

#define INTERVAL 2

int addtabs(char s[], int index);

int main() {
    char c;
    int i;

    while (c != EOF) {
        char str[100];
        for (i = 0; i < 100 && (c = getchar()) != EOF && c != '\n'; ++i) {
            // printf("%d\n", i);
            if (c == '\t')
                i = addtabs(str, i);
            else
                str[i] = c;
        }
        printf("%s\n", str);
    }

}

int addtabs(char s[], int index) {
    int currenttabstops = index / INTERVAL;
    int nexttabstop = currenttabstops + 1;
    int blankstonexttabstop = nexttabstop * INTERVAL - index;
    int i;

    for (i = 0; i < blankstonexttabstop; ++i) {
        s[index] = ' ';
        ++index;
    }

    return index - 1;
}