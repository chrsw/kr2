/*
 * getch.c
 *      getch() and ungetch() from Chapter 4.
 *
 * Description:
 *      getch():    get a (possibly pushed back) character.
 *      ungetch():  push a character back on input.
 *
 *
 * Design:
 *      Buffer standard input data to allow for pushing back input
 *      that isn't ready to be processed yet.
 * 
 * Build:
 *      TBD
 *
 */

#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];          /* buffer for ungetch */
int bufp = 0;               /* next free position in buf */

/* getch:  get a (possibly pushed back) character */
int getch(void) {

    return (bufp > 0) ? buf[--bufp] : getchar();
}


/* ungetch:  push character back on input */
void ungetch(int c) {

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
