#include<stdio.h>

#define MAXLENGTH 5000

void escape(char[], char[]);
void read_line(char[]);

int main() {
    char s[MAXLENGTH], t[MAXLENGTH];
    read_line(t);

    escape(s, t);
    printf("%s\n", s);
}

void escape(char s[], char t[]) {
    int i, j;
    char c;
    for (i = 0, j = 0; (c = t[i]) != EOF; i++) {
        switch(c) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = c;
                break;
        }
    }
}

void read_line(char line[]) {
    int i;
    char c;
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF; ++i) {
        line[i] = c;
    }

    line[i] = '\0';
}