/*
 * getch.c
 *      Get a (possibly pushed back) character.
 *      Push character back on input.
 *
 * Description:
 *      Excerpt from section 4.3 part of Reverse Polish Notation (RPN)
 *      calculator application.
 *
 * Build:
 *      See rpn.c
 *
 */

#include <stdio.h>
#include "calc.h"


char buf[BUFSIZE];                  /* buffer for ungetch() */
int bufp = 0;                       /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {

    return (bufp > 0) ? buf[--bufp]: getchar();
}

/* push character back on input */
void ungetch(int c) {

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c; 
}
