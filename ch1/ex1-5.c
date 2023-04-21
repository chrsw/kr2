/* vim:ts=4:sw=4:et:so=10:
 *
 * ex1-5.c	
 *      Modify the temperature conversion program to print the table in
 *      reverse order, that is, from 300 degrees to 0. (See chpater 1,
 *      exercise 4)
 *
 * Description:
 *      From chapter 1, exercise 4:
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

	celsius = upper;                    /* reverse order from previous
                                           exercise. */

	printf("%3.3s %6.6s\n", "C" ,"F"); /* print the heading with the
					                      same spacing and justification
					                      as the table */

    /* iterate through the list of Celsius values and convert to Fahrenheit. */
    /* for this version, start with the highest temperature first. */
	while (celsius >= lower) {
		fahr = ((9.0/5.0) * celsius) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius - step;
	}

    return 0;
}
