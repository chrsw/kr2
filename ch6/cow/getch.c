/*
 * getch.c
 *      Get a character from standard, get a character from a buffer or
 *      put a character back on a buffer.
 *
 * Description:
 *      Uses a local buffer.
 *
 * Input:
 *      Standard input.
 *
 * TODO:
 *      Add more comments. User either only getch() or getchb().
 */

#include <stdio.h>
#include "getch.h"

static char buf[BUFSIZ];
static int bufp = 0;

/* getch:  Get a (possibly pushed back) character  */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* getchb:  Get a character from a buffer. */
 
int getchb(void)
{
    return ((bufp <= BUFSIZ) && (bufp >= 0)) ? buf[bufp++] : EOF;
}


/* ungetch:  Push character back on input */
void ungetch(int c) {

    if (bufp >= BUFSIZ)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
