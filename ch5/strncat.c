/* vim:ts=4:sw=4:et:
 *
 * strncat.c
 * 
 * Part of solution to ex 5-5.
 *
 */

void ch5_strncat(char s[], char t[], int n);


/* ch5_strncat: concatenate t to the end of s; up to n characters */
void ch5_strncat(char s[], char t[], int n) {

    char *sp;
    char *tp;
    int i = n;

    if (!s || !t)
        return;	
    sp = s;
    tp = t;

	while ( *++sp != '\0')          /* find end of s, using pointers */
		;                           /* instead of array notation */
	while (((*sp++ = *tp++) != '\0') &&
            (i-- > 0))
		;
}
