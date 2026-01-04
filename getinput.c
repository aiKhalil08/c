#include <stdio.h>

#define MAXLENGTH 5000

void getinput(char[]);

void getinput(char line[]) {
    int i;
    char c;
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n')
        line[i++] = '\n';

    line[i] = '\0';
}