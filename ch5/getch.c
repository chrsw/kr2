/*
 * getch.c
 *      getch() and ungetch().
 *
 * Description:
 *      Implementation for two simple functions:
 *      getch() - read a character from input into a buffer
 *      ungetch() - push a character back into buffer
 *      
 *      getch() fetches from a global buffer (shared by the entire
 *      application, so be careful) before trying to fetch from
 *      standartd input with getchar() (standard library function).
 *
 * Build:
 *      $ gcc -c getch.c
 */

#include <stdio.h>          /* for getchar() */

#define BUFSIZE 100

char buf[BUFSIZE];          /* buffer for ungetch() */
int bufp = 0;               /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {

    /* check the global buffer before fetching from standard input */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* put an already feteched character into the global buffer */
void ungetch(int c) {

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characgters\n");
    else
        buf[bufp++] = c;
}
