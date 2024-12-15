/*
 * fahr1_4.c
 *      Fahrenheit-Celsius table from section 1.4.
 *
 * Description:
 *
 * Input:
 *      Describe the expected input.
 *
 * Other info:
 *      Returns, build, notes, etc. 
 *
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(int argc, char *argv[]) {

    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

    return 0;
}
