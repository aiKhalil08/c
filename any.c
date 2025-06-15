#include <stdio.h>

#define MAXLENGTH 5000

void read_line(char[]);
int any(char[], char[]);
int strcontains(char [], char);

int main() {
    char s1[1000], s2[100];
    int pos;

    printf("Input the first string\n");
    read_line(s1);

    printf("Input the second string\n");
    read_line(s2);

    pos = any(s1, s2);

    printf("A character from the second string can be found in position %i of the first string.\n", pos);
}

int any(char s1[], char s2[]) {
    int i;
    char c;
    int pos = -1;

    for (i = 0; pos == -1 && (c = s1[i]) != '\0'; i++)
        if (strcontains(s2, c))
            pos = i;
        
    return pos;
}

int strcontains(char s[], char c) {
    int i, contains = 0;
    char p;

    for (i = 0; contains != 1 && (p = s[i]) != '\0'; i++) {
        if (p == c)
            contains = 1;
    }

    return contains;
}

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