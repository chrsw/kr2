/*
 * copy.c
 *      Copy input to output; 1st version.
 *
 * Description:
 *  	Example from section 1.5.1
 *
 * Build and use:
 * 	$ gcc -o copy copy.c
 * 	$ ./copy < copy.c
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int c;
	
	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}

	return 0;
}
