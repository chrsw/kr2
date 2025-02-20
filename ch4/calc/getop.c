/*
 * getop.c
 *      Get next operator or numeric operand.
 * 
 * Description:
 *      Excerpt from section 4.3 part of Reverse Polish Notation (RPN)
 *      calculator application.
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
    while ((s[0] = c = getch()) == ' ' || c == '\t')
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
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}



