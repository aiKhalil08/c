#include <stdio.h>

#define LOWER 0
#define UPPER 400
#define STEP 20
/* compute a fahrenheit - celsius table
sdfaf */

main() {
    float fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%5.0f\t%6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}