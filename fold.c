#include <stdio.h>

#define LINELENGTH 10

void readInput(char input[]);
void foldInput(char input[], char foldedLine[]);

int main() {
    char input[1000];
    char foldedLine[1100];

    readInput(input);
    foldInput(input, foldedLine);

    printf("%s\n", foldedLine);
}

void readInput(char input[]) {
    char c;
    int i;
    
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        input[i] = c;
    }

    if (c == '\n') {
        input[i] = '\n';
        ++i;
    }

    input[i] = '\0';
}

void foldInput(char input[], char foldedLine[]) {
    int i, j, presentLength, lastNonBlankIndex;
    char c;
    for (i = 0, j = 0, presentLength = 0 ; (c = input[i]) != '\0'; ++i, ++j, ++presentLength) {
        // if (c == '\t' || c == ' ')
        //     lastNonBlankIndex = i - 1;

        // if (presentLenght == (LINELENGTH - 1)) {
        //     j = lastNonBlankIndex + 1;
        //     i = lastNonBlankIndex + 1;
        //     foldedLine[j] = '\n';
        //     presentLenght = -1;
        // } else {
        //     foldedLine[j] = c;
        // }
        if (c == ' ' || c == '\t') {
            lastNonBlankIndex = i - 1;
        }
        if (presentLength == LINELENGTH) {
            j = lastNonBlankIndex + 1;
            foldedLine[j] = '\n';
            i = j;
            // ++j;
            presentLength = -1;
        } else
            if (c == ' ')
                foldedLine[j] = '-';
            else
                foldedLine[j] = c;
        // if (c == ' ')
        //     foldedLine[j] = '-';
        // else
        // foldedLine[j] = c;
        // foldedLine[i] = 0;
    }

    foldedLine[j] = '\0';
    // printf("%d\n", lastNonBlankIndex);
}