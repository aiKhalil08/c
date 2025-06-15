#include <stdio.h>

main() {
    int c, cword;

    cword = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            putchar(c);
            ++cword;
        } else if (cword > 0) { 
                printf("\t");
                int i;
                for (i = 0; i < cword; ++i) {
                    printf("-");
                }
                printf("\n");
                cword = 0;
            // printf("hi");
        } else ;
    }
}