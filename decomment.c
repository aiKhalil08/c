#include <stdio.h>

#define MAXLENGTH 5000

void readProgram(char program[]);
void decomment(char program[], char d_program[]);

int main() {
    char program[MAXLENGTH];
    char d_program[MAXLENGTH];

    readProgram(program);
    decomment(program, d_program);

    printf("---This is the output---\n\n%s\n", d_program);

    return 0;
}

void readProgram(char program[]) {
    int i;
    char c;
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF; ++i) {
        program[i] = c;
    }

    program[i] = '\0';
}

void decomment(char program[], char d_program[]) {
    int i, j, inComment = 0, isMultilineComment = 0;
    char c, nextC;

    for (i = 0, j = 0; (c = program[i]) != '\0'; ++i) {
        if (c == '/' && ((nextC = program[i+1]) == '/' || nextC == '*')) {
            inComment = 1;
            if (nextC == '*')
                isMultilineComment = 1;
        }

        if (inComment == 1 && ((isMultilineComment == 0 && c == '\n') || (isMultilineComment == 1 && c == '*' && program[i+1] == '/'))) {
            inComment = 0;
            if (isMultilineComment == 1) {
                i = i + 2;
                c = program[i];
                isMultilineComment = 0;
            }
        }

        if (inComment == 0) {
            d_program[j] = c;
            ++j;
        }
    }
}