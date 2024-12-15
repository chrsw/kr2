/*
 * ex1-15.c
 *      Rewrite the temperature conversion program of Section ??
 *      to use a function for conversion.
 *
 * Description:
 *      Convert Fahrenheit to Celsius.
 *
 * Build:
 *      $ gcc -o ex1-15 ex1-15.c
 *
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float ftoc(float fahr);

int main(int argc, char *argv[]) {

    int fahr;

	printf("%3.3s %6.6s\n", "F" ,"C"); /* print the heading with the
					                      same spacing and justification
					                      as the table */


    /* print a table of temperature conversion */ 
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, ftoc(fahr));

    return 0;
}

/* convert Fahrenheit to Celsius */
float ftoc(float fahr) {

    float c = 0.f;
    c = (5.0/9.0)*(fahr-32);
    return c;
}
