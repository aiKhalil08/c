#include <stdio.h>

#define INTERVAL 8

int main() {
    char c;
    char string[1000];
    char entabbedstring[1000];
    int i, k = 0, l = 0, blankslength = 0;

    for (i = 0; i < 999 && (c = getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;

    string[i] = '\0';

    while ((c = string[k]) != '\0') {

        if (c == ' ') {
            ++blankslength;
        }

        entabbedstring[l] = c;

        if (c != ' ' && blankslength > 1) {
            int tabs = 0, blanks = 0;
            int blanksstart = k - blankslength;
            int nexttabstop = ((blanksstart / INTERVAL) + 1) * INTERVAL;

            if (blanksstart + blankslength < nexttabstop) {
                // blanks are not enough to reach next tab stop
                blanks = blankslength;
            } else {
                int blankstotabstop = nexttabstop - blanksstart;
                printf("blankstotabstop = %d, blankslength = %d, blanksstart = %d, nexttabstop = %d\n", blankstotabstop, blankslength, blanksstart, nexttabstop);
                tabs = 1 + ((blankslength - blankstotabstop) / INTERVAL);
                blanks = blankslength - blankstotabstop - ((tabs - 1) * INTERVAL);
            }

            printf("tabs = %d, blanks = %d\n", tabs, blanks);

            int j = blanksstart;

            for (;tabs > 0; --tabs) {
                entabbedstring[j] = '\t';
                ++j;
            }

            for (;blanks > 0; --blanks) {
                entabbedstring[j] = ' ';
                ++j;
            }

            if (j < k) {
                entabbedstring[j] = c;
                l = j;
            }

            blankslength = 0;
        }

        ++k;
        ++l;
    }
    entabbedstring[l] = '\0';

    printf("%s\n", entabbedstring);
    printf("length of string = %d, length of entabbed string = %d\n", i, l);
}