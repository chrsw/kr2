/* vim:ts=4:sw=4:et:so=10:
 *
 * getint.c
 *      Get next integer from input.
 *
 * Description:
 *      Excerpt from chapter 5, section 2.
 *
 * Input:
 *      Integer pointer.
 *
 */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {

    int c, sign;

    while ( isspace(c = getch()) )      /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);      /* not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
