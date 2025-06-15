#include <stdio.h>

#define MAXLEN 1000
#define THRESHOLD 8

int getInputLine(char line[], int max);
int removeWhiteSpaces(char line[], int len);
int reverseString(char line[], int len);

main() {
    int len; // length of current line
    int lenAfterTrim;
    char line[MAXLEN]; // character array containing current line
    
    while ((len = getInputLine(line, MAXLEN)) > 0) {
        if (len > THRESHOLD) {
            printf("%s has %d characters\n", line, len);
        }

        if (len > 0) {
            lenAfterTrim = removeWhiteSpaces(line, len);
            printf("after trimming white spaces %s has %d chars\n", line, lenAfterTrim);

            reverseString(line, lenAfterTrim);
            printf("reversed: %s\n", line);
        }
    }
    
    return 0;
}

int getInputLine(char line[], int max) {
    int c, i;

    for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

int removeWhiteSpaces(char line[], int len) {
    int i, c;

    for (i = len -1; i >= 0 && ((c = line[i]) == '\t' || c == ' ' || c == '\n'); --i) {
        line[i] = '\0';
        --len;
    }

    return len;
}

int reverseString(char line[], int len) {
    int i, j;
    char scopy[len];

    for (i = 0; i <= len - 1; ++i) {
        scopy[i] = line[i];
    }

    for (j = 0; j <= len - 1; ++j) {
        line[j] = scopy[len - 1 - j];
    }

    return 0;
}

