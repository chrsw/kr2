/* vim:ts=4:sw=4:et:so=10:
 *
 * ex4-9.c
 *      Change getch() and ungetch() to handle EOF correctly.
 *
 * Description:
 *      According to fgets(3), getchar() returns EOF on end-of-file
 *      or error.
 *      EOF value is -1.
 *
 * Build:
 *      $ gcc -c ex4-9.c
 *
 */

#include <stdio.h>

#define BUFSIZE     100             /* BUFSIZ already defined */

unsigned char buf[BUFSIZE];                  /* buffer for ungetch() */
int bufp = 0;                       /* next free position in buf */

/* get a (possibly pushed back) character, including EOF */
unsigned int getch(void) {
    unsigned int c;
    if (bufp > 0)
        return buf[--bufp];
    else {
        c = getchar();
        return c;
    }
}

/* push character back on input, including EOF */
void ungetch(unsigned int c) {

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c; 
}
