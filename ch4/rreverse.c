/*
 * vim:ts=4:sw=4:et:
 *
 * rreverse.c
 *      Reverse a string in place, recursively.
 *
 * Build:
 *      To build full app, define REVERSE_MAIN, ex:
 *      gcc -DREVERSE_MAIN -o reverse reverse.c
 */

#include <string.h>
#include <stdio.h>

void rreverse(char s[], int i, int j);


#ifdef REVERSE_MAIN
int main(void) {

    //char s[] = "test me, please";
    char s[] = "test me, please!!!";
    printf("original s: %s\n", s);
    rreverse(s, 0, strlen(s)-1);
    printf("reversed s: %s\n", s);
    return 0;
}
#endif


/* reverse:	reverse string s in place */
void rreverse(char s[], int i, int j) {
	
	int c;
    int start = i, end = j;

    if ((start >= end))
        return;
    else {
        c = s[start];
        s[start++] = s[end];
        s[end--] = c;
        rreverse(s, start, end);	
    }

}
