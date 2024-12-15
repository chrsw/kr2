/*
 * ch5_reverse.c
 *      Reverse a string. K&R chapter 5 pointer version.
 *      Partial solution to exercise 5-6.
 *
 * Build:
 *      To build full app, define REVERSE_MAIN, ex:
 *      gcc -DREVERSE_MAIN -o reverse ch5_reverse.c
 */

#include <string.h>
#include <stdio.h>

void reverse(char *s);

/* test driver, if desired. */
#ifdef REVERSE_MAIN
int main(void) {

    char s[] = "test me, please";
    printf("original s: %s\n", s);
    reverse(s);
    printf("reversed s: %s\n", s);
    return 0;
}
#endif


/* reverse:	reverse string s in place */
void reverse(char *s) {
	
	int c, i, j;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = *(s+i);
		*(s+i) = *(s+j);
		*(s+j) = c;
	}

}
