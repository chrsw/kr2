/*
 * strend.c
 *
 */

#include <string.h>

/* strend: test for t at the end of s */

int strend(char s[], char t[]) {

    int i = 0;
    char *sp;
    char *tp;

    if (!s || !t)
        return 0;	

    if (strlen(t) > strlen(s))
        return 0;

    sp = s;
    tp = t;

	while ( *++sp != '\0')          /* find end of s */
		;                           
	while ( *++tp != '\0')          /* find end of t */
		i++;                           
    while (--i)                     /* start comparing the end of s*/
        if (*--sp != *--tp)         /* with the end of t and work */
            break                   /* backwards */;
    return (!i);
}
