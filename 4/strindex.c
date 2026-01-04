#include <stdio.h>

int strindex(char string[], char pattern[]);

int main() {
    char string[] = "banana";
    char pattern[] = "";

    int index = strindex(string, pattern);
    printf("the position of '%s' in '%s' is: %d\n", pattern, string, index);
}

int strindex(char string[], char pattern[]) {
    int index = -1, i, j, k;

    for (i = 0; string[i] != '\0'; i++) {
        for (j = i, k = 0; pattern[k] != '\0' && string[j] == pattern[k]; j++, k++)
            ;
        if (k > 0 && pattern[k] == '\0')
            index = i;
            // return i;
    }

    return index;
    // return -1;
}