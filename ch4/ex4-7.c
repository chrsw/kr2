/*
 * ex4-7.c
 *      Write a routine ungets(s) that will push back an entire string
 *      onto the input.
 *
 * Build:
 *      $ gcc -c ex4-7.c
 *
 */

#include <stdio.h>

#define BUFSIZE     100             /* BUFSIZ already defined */

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

void ungets(char s[]) {

    if (s != NULL)
        for (int i; s[i] != '\0'; i++) {
            ungetch((int)s[i]);
        }
}
