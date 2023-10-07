/* vim:ts=4:sw=4:et:so=10:
 *
 * ex4-12_main.c
 *      Main driver for recursive itoa(). Part of exercise 4-12 solution.
 *      Details on how the code you're reading implements the design.      
 *
 * Build:
 *      $ gcc -o itoa ex4-12_main.c itoa.c
 *
 * Run:
 *      $ ./itoa
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void itoa(unsigned int n, char *s);

int main(void) {

	int int_max = INT_MAX;
	unsigned int n = 1234;
	char *s;
	int n_max = 1;
	while ((int_max /= 10 ) > 0) n_max++;

	s = malloc(n_max+1);
	if (!s)
		return -1;
	itoa(n, s);	
	printf("%s\n", s);

	return 0;
}
