/*
 * ex1-3.c	
 *      Modify the temperature conversion program to print a heading
 * 		above the table.
 *
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table w/ heading
 * for fahr = 0, 20, ..., 300; floating-point conversion 
 */ 
int main(void)
{

	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	fahr = lower;

	printf("%3.3s %6.6s\n", "F" ,"C"); /* print the heading with the
					                      same spacing and justification
					                      as the table */

    /* iterate through the list of fahrenheit values and convert to celcius */
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

}
