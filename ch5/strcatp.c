/* vim:ts=4:sw=4:et:
 *
 * strcatp.c
 *
 */


/* strcatp: concatenate t to the end of s; use pointers */

void strcatp(char s[], char t[]) {

    char *sp;
    char *tp;

    if (!s || !t)
        return;	
    sp = s;
    tp = t;

	while ( *++sp != '\0')          /* find end of s, using pointers */
		;                           /* instead of array notation */
	while ((*sp++ = *tp++) != '\0') /* copy t */
		;
}
