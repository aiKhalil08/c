#include <stdio.h>

#define MAXLENGTH 1000

void expand(char[], char[]);

int main() {
    char s1[MAXLENGTH], s2[2000];

    printf("Provide a string:\n");
    getinput(s1);
    expand(s1, s2);

    printf("Input is: %s\n", s1);
    printf("Output is: %s\n", s2);

    return 0;
}

void expand(char s1[], char s2[]) {
    int i, j;
    char c, next_c, end_c, x;

    for (i = 0, j = 0; (c = s1[i]) != '\0'; i++ ) {
        next_c = s1[i+1];
        s2[j++] = c;

        if (next_c == '-' && (c != ' ' && c != '\t' && c != '\n')) {
            end_c = s1[i+2];
            x = c + 1;
            while (x < end_c) {
                s2[j++] = x;
                x++;
            }
            i++;
        }
    }

}