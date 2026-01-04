#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLENGTH 1000

void itoa(int, char[]);
void padded_itoa(int, char[], int);
void itob(int, char[], int);
void read_line(char[]);
void reverse(char[]);


int main() {
    char s1[MAXLENGTH];
    int i = -10, w = 8;

    // printf("%10.10f\n", -(pow(2,(__WORDSIZE-1))));

    // printf("Provide a string:\n");
    // read_line(s1);
    padded_itoa(i, s1, w);

    printf("%d in text is(width: %d): %s\n", i, w, s1);

    return 0;
}

void itob(int n, char s[], int b) {
    int i, sign, m;
    if ((sign = (n < 0))) {
        n = -n;
    }

    i = 0;
    do {
        m = n % b;
        s[i++] = m < 10 ? m + '0' : 'a' + (m-10) ;
    } while ((n /= b) > 0);

    if (sign)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

void padded_itoa(int n, char s[], int w) {
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n;
    /* make n positive */
    i = 0;
    do {
        if (n > 0) {
            /* generate digits in reverse order */
            s[i++] = n % 10 + '0'; /* get next digit */
            n /= 10;
        } else
            s[i++] = '0';
    } while (i < w-1);
    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    else
        s[i++] = '0';

    s[i] = '\0';
    reverse(s);
}

void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n;
    /* make n positive */
    i = 0;
    do {
        /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);
    /* delete it */
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void read_line(char line[]) {
    int i;
    char c;
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n')
        line[i++] = '\n';

    line[i] = '\0';
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}