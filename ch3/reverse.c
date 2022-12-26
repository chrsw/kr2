/*
 * vim:ts=4:sw=4:et:
 *
 * To build full app, define REVERSE_MAIN, ex:
 *      gcc -DREVERSE_MAIN -o reverse reverse.c
 */

#include <string.h>
#include <stdio.h>

void reverse(char s[]);


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
void reverse(char s[]) {
	
	int c, i, j;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}
