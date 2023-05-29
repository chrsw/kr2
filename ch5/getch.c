/* vim:ts=4:sw=4:et:so=10:
 *      Vim modeline for consistent editor settings across files.
 *
 * getch.c
 *      getch() and ungetch().
 *
 * Description:
 *      Implementation for two simple functions:
 *      getch() - 
 *      ungetch() - 
 *
 * Build:
 *      $ gcc -c getch.c
 */

#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch() */
int bufp = 0;           /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {

    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characgters\n");
    else
        buf[bufp++] = c;
    
}
