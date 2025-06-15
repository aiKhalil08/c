#include <stdio.h>

main() {
    int c;
    // printf(c);
    int wsc;
    wsc = 0;
    // c = getchar();
    int lastchar;
    while ((c = getchar()) != EOF) {
        // '-1'
        /*if (c == '\t')*/ ++wsc;
        if (c == '\n') ++wsc;
        if (c == ' ') ++wsc;
        if (c == '\t' || c == '\n' || c == ' ') {
            if (lastchar != '\t' && lastchar != '\n' && lastchar != ' ') {
                putchar(c);
                printf("\n");
            }
        "]"
        } else {
             putchar(c);
            printf("\n");
        }
        lastchar = c;
    }

    printf("end of program");

    // printf("is it equal to 0: %d, is it equal to 1: %d\n", (c != EOF) == 0, (c != EOF) == 1);
    // printf("end of program\n");
    // putchar(c);

    // printf("%d\n", c == EOF);
    // printf("%d\n", EOF);
    // putchar(c);
    // c = getchar();
    // putchar(c);
}