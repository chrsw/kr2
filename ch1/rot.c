/* vim:ts=4:sw=4:et:
 *
 * rot.c
 *      Small demo of using the modulus operator (%) to rotate through
 * 	    a repeating sequence of numbers.
 */

#include <stdio.h>
#include <unistd.h>

int main(void) {

	int i = 0;
    // Run forever printing the same
    // sequence of numbers based on modulus
	for (;;) {
		sleep(2);
		i = ++i % 9;
		printf("%d%d\n", i, i);
	}
	return 0;
}

