#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLENGTH 5000

int read_line(char[]);
int convert_to_decimal(char);

int main() {
    char hexstring[MAXLENGTH];
    int value = 0;

    int len = read_line(hexstring);
    int last_index = len - 1;

    printf("len is: %d\n", len);
    printf("last_index is: %d\n", last_index);

    for (int i = last_index; i >= 0; --i) {
        char hexc = hexstring[i];
        int decimal = convert_to_decimal(hexc);
        printf("decimal is: %d\n", decimal);
        int place = last_index - i;

        printf("place is: %d\n", place);

        value = value + pow(16.0, place) * decimal;
    }

    printf("%s in integer is %f\n", hexstring, (double) value);

    return 0;
}

int convert_to_decimal(char c) {
    int decimal;
    if (c >= '0' && c <= '9') {
        decimal = c - '0'; 
    } else if (c >= 'a' && c <= 'f') {
        decimal = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        decimal = c - 'A' + 10;
    }

    return decimal;
}

int read_line(char line[]) {
    int i;
    char c;
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        line[i] = c;
    }

    // if (c == '\n') {
    //     line[i] == '\n';
    //     ++i;
    // }

    line[i] = '\0';

    return i;
}