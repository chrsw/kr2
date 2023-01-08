/* vim:ts=4:sw=4:et:
 *
 * getch.c
 *      Get a character.
 *
 * Description:
 *      Details
 *
 * Input:
 *
 */

#include <stdio.h>

char buf[BUFSIZ];
int bufp = 0;

/*
 * Get a (possibly pushed back) character 
 */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
 * getchb:  Get a character from a buffer.
 */
int getchb(void)
{
    return ((bufp <= BUFSIZ) && (bufp >= 0)) ? buf[bufp++] : EOF;
}


/*
 * Push character back on input
 */
void ungetch(int c) {

    if (bufp >= BUFSIZ)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
