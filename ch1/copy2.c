/*
 * copy2.c
 *      Copy input to output; 2nd version.
 *
 * Description:
 *  	2nd copy example from section 1.5.1
 *
 * Build and use:
 * 	$ gcc -o copy copy2.c
 * 	$ ./copy2 < copy2.c
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int c;
	
	c = getchar();
	while ((c = getchar()) != EOF) {
		putchar(c);
	}

	return 0;
}
