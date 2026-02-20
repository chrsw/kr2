/*
 * getop.c
 *      Get next operator or numeric operand.
 * 
 * Description:
 *      Part of solution to Exercise 4-11.
 *
 * Input:
 *      String of operators and operands.
 *
 */

#include <ctype.h>                              /* for isdigit() */
#include <stdio.h>                              /* for EOF */
#include "calc.h"


int getop(char s[]) {

    int i, c;
    static char gbuf[10];
    static int gbufp = 0;

    while ((s[0] = c = (gbufp > 0) ? gbuf[--gbufp] : getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;                               /* not a number */
    i = 0;
    if (isdigit(c))                             /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                               /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) {
        gbuf[gbufp++] = c;
        printf("getop: c = %d\n", c);
    }

    return NUMBER;
}



