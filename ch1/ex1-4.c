/*
 * ex1-4.c	
 *      Write a program to print the corresponding Celsius to Fahrenheit
 *      table. (See chapter 1, exercise 3).
 *
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table w/ heading
 * for fahr = 0, 20, ..., 300; floating-point conversion 
 */ 

int main(void)
{

	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	celsius = lower;

	printf("%3.3s %6.6s\n", "C" ,"F"); /* print the heading with the
					                      same spacing and justification
					                      as the table */

    /* iterate through the list of Celsius values and convert to Fahrenheit */
	while (celsius <= upper) {
		fahr = ((9.0/5.0) * celsius) +32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

    return 0;

}
