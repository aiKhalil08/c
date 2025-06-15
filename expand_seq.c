#include<stdio.h>

#define MAXLENGTH 5000

void expand_seq(char[], char[]);
void read_line(char[]);

int main() {
    char s[MAXLENGTH], t[MAXLENGTH];
    read_line(t);

    expand_seq(s, t);
    printf("%s\n", s);
}

void expand_seq(char s[], char t[]) {
    int i, j;
    char c;
    for (i = 0, j = 0; (c = t[i]) != EOF; i++) {
        switch(c) {
            case '\\':
                int next_c = t[i+1];
                if (next_c == 'n') {
                    s[j++] = '\n';
                    i++;
                }
                else if (next_c == 't') {
                    s[j++] = '\t';
                    i++;
                }
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