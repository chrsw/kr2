/*
 * ex4-8.c
 *      Suppose there will never be more than one character of pushback.
 *      Modify getch() and ungetch() accordingly.
 *
 * Build:
 *      $ gcc -c ex4-8.c
 *
 */

#include <stdio.h>

int buf = '\0';                           /* buffer for ungetch() */

/* get a (possibly pushed back) character, one character only */
int getch(void) {

    int b = buf;
    if (b != '\0') {
        buf = '\0';
        return b;
    }
    else
        return getchar();
}

/* push character back on input, one character only */
void ungetch(int c) {

    if (buf != '\0')
        printf("ungetch: too many characters\n");
    else
        buf = c; 
}
