/* 
 * ex1-3a.c	Original temperature conversion program. Precursor
 *              to ex1-3.c.
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table 
    for fahr = 0, 20, ..., 300; floating-point conversion */ 

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 300;		/* upper limit */
	step = 20;		/* step size */

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

}
